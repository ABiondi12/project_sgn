#!/usr/bin/env python
from time import sleep

from pypozyx import (POZYX_POS_ALG_UWB_ONLY, POZYX_3D, Coordinates, POZYX_SUCCESS, POZYX_ANCHOR_SEL_AUTO,
                     DeviceCoordinates, PozyxSerial, get_first_pozyx_serial_port, SingleRegister, DeviceList, DeviceRange)
from pythonosc.udp_client import SimpleUDPClient
import os.path

class ReadyToLocalize(object):
	def __init__(self, pozyx, osc_udp_client, anchors, anchor_ids, algorithm=POZYX_POS_ALG_UWB_ONLY, dimension=POZYX_3D, height=1000, remote_id=None):
		self.pozyx = pozyx
		self.osc_udp_client = osc_udp_client
		self.anchor_ids = anchor_ids

		self.anchors = anchors
		self.algorithm = algorithm
		self.dimension = dimension
		self.height = height
		self.remote_id = remote_id
		self.pos_error = 0

	def setup(self):
		"""Sets up the Pozyx for positioning by calibrating its anchor list."""
		print("------------POZYX POSITIONING V1.1 -------------")
		print("NOTES: ")
		print("- No parameters required.")
		print()
		print("- System will auto start configuration")
		print()
		print("- System will auto start positioning")
		print()
		self.pozyx.printDeviceInfo(self.remote_id)
		print()
		print("------------POZYX POSITIONING V1.1 --------------")
		print()
		self.pozyx.clearDevices(self.remote_id)

		self.setAnchorsManual()
		self.printPublishConfigurationResult()
  

	def loop(self, out_file=None):
		"""Performs positioning and displays/exports the results."""
		position = Coordinates()
		range = DeviceRange()
		status = self.pozyx.doPositioning(
            position, self.dimension, self.height, self.algorithm, remote_id=self.remote_id)
		if status == POZYX_SUCCESS and not((position.x==0) and (position.y==0) and (position.z==0)):
			out_file.write(str(position.x)+'\t'+str(position.y)+'\t'+str(position.z)+'\t')
        
			count = 0
			for anchor in self.anchor_ids:
				self.pozyx.getDeviceRangeInfo(anchor, range, remote_id)
				out_file.write(str(range.distance)+'\t'+str(range.RSS)+'\t'+str(range.timestamp)+'\t')
				count = count + 1
			out_file.write('\n')
		else:
			self.pos_error += 1
			out_file.write("Err"+'\t'+"Err"+'\t'+"Err"+'\t')
        	
			count = 0
			for anchor in self.anchor_ids:
				self.pozyx.getDeviceRangeInfo(anchor, range, remote_id)
				out_file.write(str(range.distance)+'\t'+str(range.RSS)+'\t'+str(range.timestamp)+'\t')
				count = count + 1
			out_file.write('\n')
			self.printPublishErrorCode("positioning")

	def printPublishPosition(self, position):
		"""Prints the Pozyx's position and possibly sends it as a OSC packet"""
		network_id = self.remote_id
		if network_id is None:
			network_id = 0
		print("POS ID {}, x(mm): {pos.x} y(mm): {pos.y} z(mm): {pos.z}".format(
            "0x%0.4x" % network_id, pos=position))
		if self.osc_udp_client is not None:
			self.osc_udp_client.send_message(
                "/position", [network_id, int(position.x), int(position.y), int(position.z)])

	def printPublishErrorCode(self, operation):
		"""Prints the Pozyx's error and possibly sends it as a OSC packet"""
		error_code = SingleRegister()
		network_id = self.remote_id
		if network_id is None:
			self.pozyx.getErrorCode(error_code)
			print("LOCAL ERROR %s, %s" % (operation, self.pozyx.getErrorMessage(error_code)))
			if self.osc_udp_client is not None:
				self.osc_udp_client.send_message("/error", [operation, 0, error_code[0]])
			return
		status = self.pozyx.getErrorCode(error_code, self.remote_id)
		if status == POZYX_SUCCESS:
			print("ERROR %s on ID %s, %s" %
                  (operation, "0x%0.4x" % network_id, self.pozyx.getErrorMessage(error_code)))
			if self.osc_udp_client is not None:
				self.osc_udp_client.send_message(
                    "/error", [operation, network_id, error_code[0]])
		else:
			self.pozyx.getErrorCode(error_code)
			print("ERROR %s, couldn't retrieve remote error code, LOCAL ERROR %s" %
                  (operation, self.pozyx.getErrorMessage(error_code)))
			if self.osc_udp_client is not None:
				self.osc_udp_client.send_message("/error", [operation, 0, -1])
            # should only happen when not being able to communicate with a remote Pozyx.

	def setAnchorsManual(self):
		status = self.pozyx.clearDevices(self.remote_id)
		for anchor in self.anchors:
			status &= self.pozyx.addDevice(anchor, self.remote_id)
		if len(self.anchors) > 4:
			status &= self.pozyx.setSelectionOfAnchors(POZYX_ANCHOR_SEL_AUTO, len(self.anchors))
		return status

	def printPublishConfigurationResult(self):
		"""Prints and potentially publishes the anchor configuration result in a human-readable way."""
		list_size = SingleRegister()

		self.pozyx.getDeviceListSize(list_size, self.remote_id)
		print("List size: {0}".format(list_size[0]))
		if list_size[0] != len(self.anchors):
			self.printPublishErrorCode("configuration")
			return
		device_list = DeviceList(list_size=list_size[0])
		self.pozyx.getDeviceIds(device_list, self.remote_id)
		print("Calibration result:")
		print("Anchors found: {0}".format(list_size[0]))
		print("Anchor IDs: ", device_list)

		for i in range(list_size[0]):
			anchor_coordinates = Coordinates()
			self.pozyx.getDeviceCoordinates(device_list[i], anchor_coordinates, self.remote_id)
			print("ANCHOR, 0x%0.4x, %s" % (device_list[i], str(anchor_coordinates)))
			if self.osc_udp_client is not None:
				self.osc_udp_client.send_message(
					"/anchor", [device_list[i], int(anchor_coordinates.x), int(anchor_coordinates.y), int(anchor_coordinates.z)])
				sleep(0.025)

	def printPublishAnchorConfiguration(self):
		"""Prints and potentially publishes the anchor configuration"""
		for anchor in self.anchors:
		    print("ANCHOR,0x%0.4x,%s" % (anchor.network_id, str(anchor.coordinates)))
		    if self.osc_udp_client is not None:
		        self.osc_udp_client.send_message(
		            "/anchor", [anchor.network_id, int(anchor.coordinates.x), int(anchor.coordinates.y), int(anchor.coordinates.z)])
		        sleep(0.025)


if __name__ == "__main__":
	# shortcut to not have to find out the port yourself

	serial_port = get_first_pozyx_serial_port()
	print(serial_port)
	if serial_port is None:
		print("No Pozyx connected. Check your USB cable or your driver!")
		quit()

	remote_id = 0x6760            # remote device network ID
	remote = False                # whether to use a remote device
	if not remote:
		remote_id = None

	use_processing = False             # enable to send position data through OSC
	ip = "127.0.0.1"                   # IP for the OSC UDP
	network_port = 8888                # network port for the OSC UDP
	osc_udp_client = None
	if use_processing:
		osc_udp_client = SimpleUDPClient(ip, network_port)
	# necessary data for calibration, change the IDs and coordinates yourself
    
	anchor_ids = [0x6e6c, 0x6e44, 0x6939, 0x6e7a]
	anchors = [DeviceCoordinates(anchor_ids[0], 1, Coordinates(0, 0, 0)),
		       DeviceCoordinates(anchor_ids[1], 1, Coordinates(0, 27407 , 0)),
		       DeviceCoordinates(anchor_ids[2], 1, Coordinates(21835, -1157, 0)),
		       DeviceCoordinates(anchor_ids[3], 1, Coordinates(10865, 10927, 1224))]

	algorithm = POZYX_POS_ALG_UWB_ONLY  # positioning algorithm to use
	dimension = POZYX_3D               # positioning dimension
	height = 1000                      # height of device, required in 2.5D positioning

	pozyx = PozyxSerial(serial_port)
	r = ReadyToLocalize(pozyx, osc_udp_client, anchors, anchor_ids, algorithm, dimension, height, remote_id)
	r.setup()
    
	#Controlla l'apertura del file corretto in modo da non sovrascrivere i dati precedenti
	i=1
	print('PosTag_'+str(i)+'.txt')
	while os.path.isfile('./Dati/PosTag_'+str(i)+'.txt'):
		# print(i)
		i = i + 1

	#Prima riga del file
	name = "./Dati/PosTag_"+str(i)+".txt"
	out_file = open(name, "w")

	#Acquisizioni
	N = 10000  #Number of acquisitions
	dist = 70e3 #Distanza in millimetri della prova
	out_file.write('Distanza: ' + str(dist) + '\n')
	out_file.write('X [mm]'+'\t'+'Y [mm]'+'\t'+'Z [mm]'+'\t' + 'A0 \t RSS \t Time \t A1 \t RSS \t Time \t A2 \t RSS \t Time \t A3 \t RSS \t Time \t \n')
	for i in list(range(N)):
		print(i)
		r.loop(out_file)
        
	fail_percentage = 100 * r.pos_error / N	
	out_file.write("Percentuale di fallimenti nel positioning: " + str(fail_percentage)+ "%")
	out_file.close()
    
   
