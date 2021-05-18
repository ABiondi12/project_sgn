#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Point
from pypozyx import *
import sys

MAX_DISTANCE = 100000

class SerialTag:
	def __init__(self, id_n, pozyx, anchor_ids, ranging_protocol, myUWBSettings=None, dimension = POZYX_3D, height=620, algorithm=POZYX_POS_ALG_UWB_ONLY):
		self.pozyx = pozyx
		self.id = id_n
		self.anchor_ids = anchor_ids
		self.ranging_protocol = ranging_protocol
		self.dimension = dimension
		self.height = height
		self.algorithm = algorithm
		self.Pointmsg = Point()
		self.pub=rospy.Publisher('/tag_pose'+str(id_n), Point, queue_size=10)
		
		self.anchors = []
		self.distances = []
		
		self.UWBSettings = myUWBSettings
		self.UWBChannel = myUWBSettings.channel
		self.defaultUWBSettings = UWBSettings(5,0,2,8,11.5)
		
		self.pos_error = 0			# Conta il numero di errori nel positioning del tag


	
	def setup(self):			
		self.pozyx.setRangingProtocol(self.ranging_protocol)
		self.pozyx.setUWBSettings(self.UWBSettings)
		self.pozyx.setUWBChannel(self.UWBChannel)
		
		print("Coordinate iniziali dei dispositivi della rete")
		coordinates = Coordinates()
		for anchor in self.anchor_ids:
			status = self.pozyx.getDeviceCoordinates(anchor, coordinates, anchor)
			if status == POZYX_FAILURE:
				print ("Device " + str(hex(anchor)) + "list is empty")
			print(hex(anchor), coordinates.x, coordinates.y, coordinates.z)
		
		### Print UWB configuration results
		for remote in anchor_ids:
			self.printUWBSettings(remote)
		self.printUWBSettings(None)
		
			
		self.addAnchors()					#Salve le ancore nella lista interna dei dispositivi 
											#dei due tag	
		self.printConfigurationResults()
		print("Ancore aggiunte alla lista interna dei Tag")	
			
	
	
	def loop(self):
		position = Coordinates()
		status = self.pozyx.doPositioning(position, self.dimension, self.height, self.algorithm)
		if status == POZYX_SUCCESS and position.x != 0 and position.y !=0 and position.z !=0:
			self.printPosition(position)
			self.Pointmsg.x=position.x
			self.Pointmsg.y=position.y
			self.Pointmsg.z=position.z
			self.pub.publish(self.Pointmsg)
		else:
			self.pos_error = self.pos_error + 1
			print("Failed positioning")
	
	
	
	def printConfigurationResults(self):
		print("Anchors identified: ")
		i=0
		for anchor in self.anchors:
			print("ANCHOR", i, ", 0x%0.4x, %s" % (anchor.network_id, str(anchor.pos)))
			i += 1
		print()
		print()
	
	
	def printPosition(self, position, remote_id=None):
		"""Stampa a video il risultato dell'algoritmo di calibrazione del tag"""
		print("Tag " + self.id + ": (x) " + str(position.x) + ", (y) " + str(position.y) + ", (z) " + str(position.z))

	
	
	
	def addAnchors(self):
		status = self.pozyx.clearDevices()
		coordinates = Coordinates()
		
		for anchor_id in anchor_ids:
			status &= self.pozyx.getDeviceCoordinates(anchor_id, coordinates, anchor_id)
			self.anchors.append(DeviceCoordinates(anchor_id, 1, coordinates))
			if status != POZYX_SUCCESS:
				raise Exception(str(hex(anchor_id)) + ": failed to get anchor's coordinates from anchor's internal list")
				quit()
		
		for anchor in self.anchors:
			status &= self.pozyx.addDevice(anchor)
		if status == POZYX_FAILURE or status == POZYX_TIMEOUT:
			raise Exception("Failed to add anchors to tag's device list")
			quit()
	
	
	
	def printUWBSettings(self, remote_id):
		aux = UWBSettings()
		status = self.pozyx.getUWBSettings(aux, remote_id)
		if status == POZYX_SUCCESS:
			if remote_id == None:
				print("Serial ", aux.channel, aux.bitrate, aux.prf, hex(aux.plen), aux.gain_db)
			else:
				print(hex(remote_id), "Channel: ", aux.channel, "Bitrate: ", aux.bitrate, 
				       "Prf: ", aux.prf, "Plen: ", hex(aux.plen), "Gain: ", aux.gain_db)
		else:
			print(hex(remote_id), "Failed to receive UWB Settings")
		
					
	
	
if __name__ == "__main__":
	# Inizializzazione del nodo ROS e recupero degli argomenti passati
	rospy.init_node('pos_tag_receiver', anonymous=True)
	
	tag_id0=rospy.myargv(argv=sys.argv)[1]
	tag_id1=rospy.myargv(argv=sys.argv)[2]
	
	serial_port0 = '/dev/ttyACM' + tag_id0
	serial_port1 = '/dev/ttyACM' + tag_id1
	
	print(serial_port0)
	print(serial_port1)
	if serial_port0  is None:
		raise Exception("No Pozyx 0 connected. Check your USB cable or your driver")
		quit()
	if serial_port1  is None:
		raise Exception("No Pozyx 1 connected. Check your USB cable or your driver")
		quit()
		
	pozyx0 = PozyxSerial(serial_port0)
	pozyx1 = PozyxSerial(serial_port1)
	
	
	################################################################
	####						-PARAMETRI-						####			
	################################################################

	# ID delle ancore utilizzate 
	anchor_ids = [0x6902, 0x6e7a, 0x6e44, 0x6e6c]	# !!! Seguire la convenzione di rangesToPos.py
	
	# Ranging protocol: POZYX_RANGE_PROTOCOL_FAST or POZYX_RANGE_PROTOCOL_PRECISION
	ranging_protocol = POZYX_RANGE_PROTOCOL_PRECISION

	
	myUWBSettings = UWBSettings(5, 3, 2, 1, 33)
	# Inizializzo pozyx seriale

	serial_tag0 = SerialTag(tag_id0, pozyx0, anchor_ids, ranging_protocol, myUWBSettings)
	serial_tag1 = SerialTag(tag_id1, pozyx1, anchor_ids, ranging_protocol, myUWBSettings)
	
	# Effettuo il setup della rete
	serial_tag0.setup()
	serial_tag1.setup()
	
	rate = rospy.Rate(5) # 5Hz 

	# Loop Function
	while not rospy.is_shutdown():
		serial_tag0.loop()
		serial_tag1.loop()
	
	
	
	
	"""input_file = open("Parametri_UWB.txt")
	channel = int(input_file.readline())
	bitrate = int(input_file.readline())
	prf = int(input_file.readline())
	plen = int(input_file.readline())
	gain = float(input_file.readline())"""
	
	
