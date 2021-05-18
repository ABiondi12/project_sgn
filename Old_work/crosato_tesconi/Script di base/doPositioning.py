# Questo script python permette di effettuare un'acquisizione automatica delle posizioni dei tag,
# utilizzando l'algoritmo di posizionamento della pozyx.
# La posizione dei tag determinata dall'algoritmo viene comunicata sulla linea UWB al dispositivo
# che è connesso alla porta USB del PC. Sullo schermo vengono stampate le posizioni dei due tag.
# E' possibile calibrare le ancore sia manualmente che automaticamente. I parametri da modificare 
# si trovano nella funzione "main" in fondo al programma. Il programma è pensato per una 
# configurazione minima che prevede l'utilizzo di 4 ancore per la calibrazione.

# Su linux:
# da terminale digitare >> sudo python3 test_UWB.py

import time
from rangesToPos import (rangesToPos, average)
from pypozyx import *

MAX_DISTANCE = 100000

class SerialTag:
	def __init__(self, pozyx, anchor_ids, ranging_protocol, myUWBSettings=None, dimension = POZYX_3D, height=1000, algorithm=POZYX_POS_ALG_UWB_ONLY):
		self.pozyx = pozyx
		self.anchor_ids = anchor_ids
		self.ranging_protocol = ranging_protocol
		self.dimension = dimension
		self.height = height
		self.algorithm = algorithm
		
		self.anchors = []
		self.distances = []
		self.old_time = {None:0}
		
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
		new_time = int(round(time.time() * 1000))
		print("Serial pozyx: x(mm): {pos.x} y(mm): {pos.y} z(mm): {pos.z}".format("0x%0.4x", pos=position), "  Delta_t [ms]: ", new_time - self.old_time[remote_id])
		self.old_time[remote_id] = new_time
	
	
	
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
	# Riconosce se ci sono dispositivi Pozyx connessi alla porta USB del PC
	serial_port = get_first_pozyx_serial_port()
	print(serial_port)
	if serial_port is None:
		raise Exception("No Pozyx connected. Check your USB cable or your driver")
		quit()
	pozyx = PozyxSerial(serial_port)
	
	
	################################################################
	####						-PARAMETRI-						####			
	################################################################

	# ID delle ancore utilizzate 
	anchor_ids = [0x6e44, 0x6e7a, 0x6e6c, 0x6939]	# !!! Seguire la convenzione di rangesToPos.py
	
	# Ranging protocol: POZYX_RANGE_PROTOCOL_FAST or POZYX_RANGE_PROTOCOL_PRECISION
	ranging_protocol = POZYX_RANGE_PROTOCOL_PRECISION
	
	input_file = open("Parametri_UWB.txt")
	channel = int(input_file.readline())
	bitrate = int(input_file.readline())
	prf = int(input_file.readline())
	plen = int(input_file.readline())
	gain = float(input_file.readline())
	
	myUWBSettings = UWBSettings(channel, bitrate, prf, plen, gain)
	# Inizializzo pozyx seriale
	serial_tag = SerialTag(pozyx, anchor_ids, ranging_protocol, myUWBSettings)
	
	# Effettuo il setup della rete
	serial_tag.setup() 
	

	# Loop Function
	try:
		while True:
			serial_tag.loop()	
	except KeyboardInterrupt:
		print("interrupted!")

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
