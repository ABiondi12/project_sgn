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

class CalibrationPozyx:
	def __init__(self, pozyx, anchor_ids, serial_id, auto_cal, R_mis, ranging_protocol, 
	N_acq,  myUWBSettings=None, dimension = POZYX_3D, height=1000, algorithm=POZYX_POS_ALG_UWB_ONLY, 
	update_interval = 100):
		self.pozyx = pozyx
		self.anchor_ids = anchor_ids
		self.auto_cal = auto_cal
		self.R_mis = R_mis
		self.ranging_protocol = ranging_protocol
		self.dimension = dimension
		self.height = height
		self.algorithm = algorithm
		self.N_acq = N_acq
		self.serial_id = serial_id
		
		self.anchors = []
		self.distances = []
		
		self.UWBSettings = myUWBSettings
		self.UWBChannel = myUWBSettings.channel
		self.defaultUWBSettings = UWBSettings(5,0,2,8,11.5)


	
	def setup(self):
		# Set the UWB parameters for all the anchors, the remote tags and the serial tag
		for remote in anchor_ids:
			if remote != self.serial_id:
				self.pozyx.setRangingProtocol(self.ranging_protocol, remote)			 		
				self.pozyx.setUWBSettings(self.UWBSettings, remote)
				self.pozyx.setUWBChannel(self.UWBChannel, remote)   
		
		self.pozyx.setRangingProtocol(self.ranging_protocol)
		self.pozyx.setUWBSettings(self.UWBSettings)
		self.pozyx.setUWBChannel(self.UWBChannel)
		
		
		
		print("Coordinate iniziali dei dispositivi della rete")
		coordinates = Coordinates()
		for anchor in self.anchor_ids:
			if anchor == self.serial_id:
				status = self.pozyx.getDeviceCoordinates(anchor, coordinates, None)
			else :
				status = self.pozyx.getDeviceCoordinates(anchor, coordinates, anchor)
			
			if status == POZYX_FAILURE:
				print ("Device " + str(hex(anchor)) + "list is empty")
			print(hex(anchor), coordinates.x, coordinates.y, coordinates.z)
		
		### Print UWB configuration results
		for remote in anchor_ids:
			self.printUWBSettings(remote)
		self.printUWBSettings(None)
		
		# Perform autocalibration if needed	
		if not self.auto_cal:
			# Compute algebraic algorithm to determine the anchors' coordinates
			self.anchors = rangesToPos(self.R_mis, self.anchor_ids)
		else:
			print("Performing autocalibration")
			self.getDistances()		# get the distances between the anchors automatically
			self.anchors = rangesToPos(self.R_mis, self.anchor_ids)
			
		self.printConfigurationResults()	#Print anchor coordinates in a readable way
		self.addAnchors()					#Add anchors' to tag internal device list 
		print("Ancore aggiunte alla lista interna dei dispositivi")	
	
	# This function starts a ranging procedure between the anchors of the system in order to get the
	# distances between all possible couples of anchors. The distances are obtained with the 
	# doRanging function of the pozyx library.
	def getDistances(self):
		device_range1 = DeviceRange()
		device_range2 = DeviceRange()
		
		# Conatainer for arrays of distances between anchor pairs
		R = [[],[],[],[],[],[]]
		
		# Possible anchor's pairs
		coppie = [	[anchor_ids[0], anchor_ids[1]],
					[anchor_ids[0], anchor_ids[2]],
					[anchor_ids[0], anchor_ids[3]],
					[anchor_ids[1], anchor_ids[2]],
					[anchor_ids[1], anchor_ids[3]],
					[anchor_ids[2], anchor_ids[3]]	]
		
		# performs ranging between each pair of anchor a number of times equal to the N_acq 
		# parameter. Than performs an avarage of the result and returns the distances between the
		# four possible anchors
		for k in list(range(self.N_acq)):
			i = 0
			for coppia in coppie:
				if coppia[0] == self.serial_id:
					status1 = POZYX_SUCCESS
					status2 = self.pozyx.doRanging(coppia[1], device_range2, None)
					device_range1 = device_range2
				elif coppia[1] == self.serial_id:
					status1 = self.pozyx.doRanging(coppia[0], device_range1, None)
					status2 = POZYX_SUCCESS
					device_range2 = device_range1
				else:
					status1 = self.pozyx.doRanging(coppia[0], device_range1, coppia[1])
					status2 = self.pozyx.doRanging(coppia[1], device_range2, coppia[0])
				
				
				if ((status1 == POZYX_SUCCESS) and (device_range1.distance <= MAX_DISTANCE)):
					if ((status2 == POZYX_SUCCESS) and (device_range2.distance <= MAX_DISTANCE)):
						dist = (device_range1.distance + device_range2.distance)/2
						R[i].append(dist)
				i = i+1
		
		# For each array of anchor distances, the mean value is computed. This mean value will be 
		# given to the rangesToPos function in order to compute the anchors' coordinates.	
		for i in list(range(len(R))):
			R[i] = average(R[i])
		self.R_mis = R
	
	
	# Print anchor coordinates in a readable way
	def printConfigurationResults(self):
		print("Configuration finished: ")
		i=0
		for anchor in self.anchors:
			print("ANCHOR", i, ", 0x%0.4x, %s" % (anchor.network_id, str(anchor.pos)))
			i += 1
		print()
		print()
	
	
	# Print the tag position in a readable way on the screen
	def printPosition(self, position, remote_id=None):
		"""Stampa a video il risultato dell'algoritmo di calibrazione del tag"""
		new_time = int(round(time.time() * 1000))
		if self.use_remote_tag:
			if remote_id is not None:
				print("POS ID {}, x(mm): {pos.x} y(mm): {pos.y} z(mm): {pos.z}".format(
		        "0x%0.4x" % remote_id, pos=position), "  Delta_t [ms]: ", new_time - self.old_time[remote_id])
		else:
			print("Serial pozyx: x(mm): {pos.x} y(mm): {pos.y} z(mm): {pos.z}".format(
		        "0x%0.4x", pos=position), "  Delta_t [ms]: ", new_time - self.old_time[remote_id])
		self.old_time[remote_id] = new_time
	
	
	
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
			if remote_id == self.serial_id:
				return
			print(hex(remote_id), "Failed to receive UWB Settings")
	
	# Add the anchors with their coordinates to the device internal list
	def addAnchors(self):
		for anchor in self.anchors:
			aux_id = anchor.network_id
			if anchor.network_id == self.serial_id:
				aux_id = None
			status = self.pozyx.clearDevices(aux_id)
			status &= self.pozyx.addDevice(anchor, aux_id)
			status &= self.pozyx.saveNetwork(aux_id)
			if status == POZYX_FAILURE or status == POZYX_TIMEOUT:
				raise Exception("Device" + str(hex(aux_id))+": Failed to add anchors to tag's device list")
				quit()
					
							
	
	
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
	
	# Calibrazione automatica-manuale
	auto_cal = True									# False = manuale, True = automatica
	serial_id = 0x675d
	anchor_ids = [0x6939, 0x6e7a, 0x6e44, 0x6e6c]	# !!! Seguire la convenzione di rangesToPos.py
	
	r01 = 5448	# Inserire i valori se si vuole fare una calibrazione manuale
	r02 = 5802
	r03 = 3600
	r12 = 4210
	r13 = 3160
	r23 = 2682
	N_acq = 30
	R_mis = [r01, r02, r03, r12, r13, r23]
	
	# Ranging protocol: POZYX_RANGE_PROTOCOL_FAST or POZYX_RANGE_PROTOCOL_PRECISION
	ranging_protocol = POZYX_RANGE_PROTOCOL_PRECISION
	
	# Impostazioni Ultra Wide Band
	# Canale: 1,2,3,5 o 7
	channel = 5			# Default value = 5
	
	# Bitrate, possibili valori:
		# PozyxConstants.UWB_BITRATE_110_KBPS		Default value
		# PozyxConstants.UWB_BITRATE_850_KBPS
		# PozyxConstants.UWB_BITRATE_6810_KBPS
	bitrate = PozyxConstants.UWB_BITRATE_110_KBPS
	
	# Pulse repeat frequency, possibili valori:
		# PozyxConstants.UWB_PRF_64_MHZ		Default value
		# PozyxConstants.UWB_PRF_16_MHZ
	prf = PozyxConstants.UWB_PRF_64_MHZ
	
	# Preamble length of the UWB packets, possibili valori:
		# PozyxConstants.UWB_PLEN_64
		# PozyxConstants.UWB_PLEN_128
		# PozyxConstants.UWB_PLEN_256
		# PozyxConstants.UWB_PLEN_512
		# PozyxConstants.UWB_PLEN_1024		Default value
		# PozyxConstants.UWB_PLEN_1536
		# PozyxConstants.UWB_PLEN_2048
		# PozyxConstants.UWB_PLEN_4096
	plen = PozyxConstants.UWB_PLEN_64
	
	# UWB Gain, possibili valori: 
		# float tra 0 e 67.1 dB
	gain = 11.5 				# Default value 11.5 dB
	
	myUWBSettings = UWBSettings(channel, bitrate, prf, plen, gain)
	################## -Fine settaggio parametri- #########################
	
	
	
	# Inizializzo pozyx seriale
	serial_tag = CalibrationPozyx(pozyx, anchor_ids, serial_id, auto_cal, R_mis, ranging_protocol, N_acq, myUWBSettings)
	
	# Effettuo il setup della rete
	serial_tag.setup() 
	
	
	# Genero il file di testo Parametri_UWB.txt
	out_file = open("Parametri_UWB.txt", "w")
	out_file.write(str(channel)+'\n')
	out_file.write(str(bitrate)+'\n')
	out_file.write(str(prf)+'\n')
	out_file.write(str(plen)+'\n')
	out_file.write(str(gain)+'\n')
	out_file.close()
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
