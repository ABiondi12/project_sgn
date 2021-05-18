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
import os.path
from math import sqrt

MAX_DISTANCE = 100000

class SerialTag:
	def __init__(self, pozyx, anchor_ids, remote_tag_ids, auto_cal, R_mis, ranging_protocol, 
	N_acq, use_remote_tag, myUWBSettings=None, dimension = POZYX_3D, height=1000, algorithm=POZYX_POS_ALG_UWB_ONLY, 
	update_interval = 100):
		self.pozyx = pozyx
		self.anchor_ids = anchor_ids
		self.remote_tag_ids = remote_tag_ids
		self.auto_cal = auto_cal
		self.R_mis = R_mis
		self.ranging_protocol = ranging_protocol
		self.dimension = dimension
		self.height = height
		self.algorithm = algorithm
		self.N_acq = N_acq
		
		self.anchors = []
		self.distances = []
		self.old_time = {remote_tag_ids[0]:0, remote_tag_ids[1] :0}
		
		self.UWBSettings = myUWBSettings
		self.UWBChannel = myUWBSettings.channel
		self.use_remote_tag = use_remote_tag
		self.defaultUWBSettings = UWBSettings(5,0,2,8,11.5)
		
		self.pos_error = 0			# Conta il numero di errori nel positioning del tag


	
	def setup(self):
		# Set UWB Parameters
		for remote in anchor_ids:
			self.pozyx.setRangingProtocol(self.ranging_protocol, remote)			 		
			self.pozyx.setUWBSettings(self.UWBSettings, remote)
			self.pozyx.setUWBChannel(self.UWBChannel, remote)   
			
		for tag in remote_tag_ids:
			if tag is not None:
				self.pozyx.setRangingProtocol(self.ranging_protocol, tag)
				self.pozyx.setUWBSettings(self.UWBSettings, remote)
				self.pozyx.setUWBChannel(self.UWBChannel, tag)
		
		self.pozyx.setRangingProtocol(self.ranging_protocol)
		self.pozyx.setUWBSettings(self.UWBSettings)
		self.pozyx.setUWBChannel(self.UWBChannel)
		
		### Print UWB configuration results
		for remote in anchor_ids:
			self.printUWBSettings(remote)
		for tag in remote_tag_ids:
			self.printUWBSettings(tag)
		self.printUWBSettings(None)
		
		# Perform autocalibration if needed	
		if not self.auto_cal:
			self.anchors = rangesToPos(self.R_mis, self.anchor_ids)
		else:
			print("Performing autocalibration")
			self.getDistances()
			self.anchors = rangesToPos(self.R_mis, self.anchor_ids)
			
		self.printConfigurationResults()
		self.addAnchors()					#Salve le ancore nella lista interna dei dispositivi 
											#dei due tag
		print("Ancore aggiunte alla lista interna dei Tag")	
	
	
	
	def loop(self, out_file):
		if use_remote_tag:
			position1 = Coordinates()
			position2 = Coordinates()
			flag = [False, False]
			position = [position1, position2]
		
			k = 0
			for tag in self.remote_tag_ids:				
				if tag is not None:
					status = self.pozyx.doPositioning(position[k], self.dimension, self.height, self.algorithm, tag)
					
					if status == POZYX_SUCCESS and position[k].x != 0 and position[k].y !=0 and position[k].z !=0:
						flag[k] = True
					else:
						self.pos_error = self.pos_error + 1
						print("Failed Positioning")
				k += 1
				
			if flag[0] and flag[1]:
				self.writePosition_asta(position[0], False, out_file)
				self.writePosition_asta(position[1], False, out_file)	
				d = sqrt(	(position[0].x - position[1].x)**2 + 
							(position[0].y - position[1].y)**2 + 
							(position[0].z - position[1].z)**2	)
				out_file.write(str(round(d)) + '\n')

	
	
	def getDistances(self):
		device_range1 = DeviceRange()
		device_range2 = DeviceRange()
		R = [[],[],[],[],[],[]]
		
		coppie = [	[anchor_ids[0], anchor_ids[1]],
					[anchor_ids[0], anchor_ids[2]],
					[anchor_ids[0], anchor_ids[3]],
					[anchor_ids[1], anchor_ids[2]],
					[anchor_ids[1], anchor_ids[3]],
					[anchor_ids[2], anchor_ids[3]]	]
		
		for k in list(range(self.N_acq)):
			i = 0
			for coppia in coppie:
				status1 = self.pozyx.doRanging(coppia[0], device_range1, coppia[1])
				status2 = self.pozyx.doRanging(coppia[1], device_range2, coppia[0])
				
				
				if ((status1 == POZYX_SUCCESS) and (device_range1.distance <= MAX_DISTANCE)):
					if ((status2 == POZYX_SUCCESS) and (device_range2.distance <= MAX_DISTANCE)):
						dist = (device_range1.distance + device_range2.distance)/2
						R[i].append(dist)
				i = i+1
				
		for i in list(range(len(R))):
			R[i] = average(R[i])
		self.R_mis = R
	
	
	
	def printConfigurationResults(self):
		print("Configuration finished: ")
		i=0
		for anchor in self.anchors:
			print("ANCHOR", i, ", 0x%0.4x, %s" % (anchor.network_id, str(anchor.pos)))
			i += 1
		print()
		print()
	
	
	
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
	
	def writePosition(self, position, remote_id = None, out_file = None):
		new_time = int(round(time.time() * 1000))
		out_file.write(str(position.x)+'\t'+str(position.y)+'\t'+str(position.z)+'\t'+ str(new_time - self.old_time[remote_id])+'\t')
		self.old_time[remote_id] = new_time
	
	def writePosition_asta(self, position, error = False, out_file = None):
		if not error:
			out_file.write(str(position.x)+'\t'+str(position.y)+'\t'+str(position.z)+'\t'+ str(int(round(time.time()*1000))%1000000)+'\t')
		else:
			out_file.write("Err\t"*3+ str(int(round(time.time()*1000)))+'\t')
	def addAnchors(self):
		for tag in self.remote_tag_ids:
			status = self.pozyx.clearDevices(tag)
			for anchor in self.anchors:
				status &= self.pozyx.addDevice(anchor, tag)
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
		
					



def write_uwb_parameters(myUWBSettings, protocol, out_file = None):
	bitrate_dict = {PozyxConstants.UWB_BITRATE_110_KBPS : "Bitrate: 110 kb/s",
				PozyxConstants.UWB_BITRATE_850_KBPS : "Bitrate: 850 kb/s",
				PozyxConstants.UWB_BITRATE_6810_KBPS : "Bitrate: 6810 kb/s"}
	prf_dict  = {PozyxConstants.UWB_PRF_64_MHZ : "PRF: 64 MHz",
				PozyxConstants.UWB_PRF_16_MHZ : "PRF: 16 MHz"}
	plen_dict = {PozyxConstants.UWB_PLEN_64 : "Preamble length: 64 symbols", 
				PozyxConstants.UWB_PLEN_128 : "Preamble length: 128 symbols",
				PozyxConstants.UWB_PLEN_256 : "Preamble length: 256 symbols",
				PozyxConstants.UWB_PLEN_512 : "Preamble length: 512 symbols",
				PozyxConstants.UWB_PLEN_1024 : "Preamble length: 1024 symbols",
				PozyxConstants.UWB_PLEN_1536 : "Preamble length: 1536 symbols",
				PozyxConstants.UWB_PLEN_2048 : "Preamble length: 2048 symbols", 
				PozyxConstants.UWB_PLEN_4096 : "Preamble length: 4096 symbols"}
	protocol_dict = {POZYX_RANGE_PROTOCOL_PRECISION : "Ranging protocol: PRECISION",
				POZYX_RANGE_PROTOCOL_FAST : "Ranging protocol: FAST"}
	out_file.write("#### UWB SETTINGS ####\n")
	out_file.write(protocol_dict[protocol] + '\n')
	out_file.write("Channel: " + str(myUWBSettings.channel) + '\n')
	out_file.write(bitrate_dict[myUWBSettings.bitrate] + '\n')
	out_file.write(prf_dict[myUWBSettings.prf] + '\n')
	out_file.write(plen_dict[myUWBSettings.plen] + '\n')
	out_file.write("Gain: " + str(myUWBSettings.gain_db) + "\n")
	out_file.write("######################\n\n\n")
		






	
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
	
	# Configurazione dei due tag remoti
	# N.B: per il tag remoto sono solo possibili i valori di default dell'UWB !!!!
	use_tag = [True, True]					# [True, True] se si usano due Tag remoti
	remote_tag_ids = [0x675e, 0x675d]			
	use_remote_tag = use_tag[0] or use_tag[1]
	i=0
	for tag in use_tag:
		if not tag:
			remote_tag_ids[i] = None
		i = i+1
		
	# Calibrazione automatica-manuale
	auto_cal = False									# False = manuale, True = automatica
	anchor_ids = [0x6939, 0x6e7a, 0x6e44, 0x6e6c]	# !!! Seguire la convenzione di rangesToPos.py
	
	r01 = 5650	# Inserire i valori se si vuole fare una calibrazione manuale
	r02 = 6111
	r03 = 3830
	r12 = 4150
	r13 = 3176
	r23 = 2717
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
	plen = PozyxConstants.UWB_PLEN_1024
	
	# UWB Gain, possibili valori: 
		# float tra 0 e 67.1 dB
	gain = 11.5 				# Default value 11.5 dB
	
	myUWBSettings = UWBSettings(channel, bitrate, prf, plen, gain)
	################## -Fine settaggio parametri- #########################
	
	
	
	# Inizializzo pozyx seriale
	serial_tag = SerialTag(pozyx, anchor_ids, remote_tag_ids, auto_cal, R_mis, ranging_protocol, N_acq, use_remote_tag, myUWBSettings)
	serial_tag.setup()
	
	# Open file
	#Controlla l'apertura del file corretto in modo da non sovrascrivere i dati precedenti
	k = 0
	while os.path.isfile('./dati/asta_'+str(k)+'.txt'):
		k += 1
    
    #Prima riga del file
	name = "./dati/asta_"+str(k)+".txt"
	print(name)
	out_file = open(name, "w")
	
	if out_file is None:
		raise Exception("Couldn't open file, quitting...")
		quit()
    
	# Write anchor's configuration
	i = 0
	for anchor in serial_tag.anchors:
		string = "Anchor" + str(i) + ", 0x%0.4x, %s \n" % (anchor.network_id, str(anchor.pos))
		out_file.write(string)
		i += 1
	out_file.write('\n')
	out_file.write('\n') 
    
    # Write UWB Settings
	write_uwb_parameters(myUWBSettings, ranging_protocol, out_file)
    
	
	# Acquisizioni
	N = 1000 		#Numero di acquisizioni
	out_file.write("Misure in [mm] e [ms]\n\n")
	out_file.write("X1\tY1\t\tZ1\ttime1\tX2\tY2\t\tZ2\ttime2\td\n")
	
	try:
		for i in list(range(N)):
			print(i)
			serial_tag.loop(out_file)
					
		fail_percentage = 100 * serial_tag.pos_error / (2*N)	
		out_file.write("Percentuale di fallimenti nel positioning: " + str(fail_percentage)+ "%")
		out_file.close()
	except KeyboardInterrupt:
		print("interrupted!")

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
