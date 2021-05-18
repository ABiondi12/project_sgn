# Questo script python permette di effettuare impostare i parametri UWB di un dispositivo collegato
# alla porta seriale del PC.

# Su linux:
# da terminale digitare >> sudo python3 set_UWB_parameters.py
from ransac import (ransac, LinearLeastSquaresModel)
import numpy as np
import matplotlib.pyplot as plt
import time
import math
from rangesToPos import (rangesToPos, average)
from pypozyx import *



######################################################################
##############			CalibrationPozyx class 			##############
######################################################################
class CalibrationPozyx:
	def __init__(self, pozyx, ranging_protocol, myUWBSettings=None, saveUWBSettings = False):
		# Argument variables
		self.pozyx = pozyx					# PozyxSerial class' instance
		self.ranging_protocol = ranging_protocol	# Pozyx ranging protocol used
		self.UWBSettings = myUWBSettings			

		self.UWBChannel = myUWBSettings.channel			# UWB channel to be setted
		self.defaultUWBSettings = UWBSettings(5,0,2,8,11.5)		# Default UWB Settings. These are 
											# the settings that are found when turning on an anchor.
		self.saveUWBSettings = saveUWBSettings


	
	##############################################################
	##############			SETUP METHOD 			##############
	##############################################################
	def setup(self):
		### Print UWB configuration results
		print("Current UWB configuration:")
		self.printUWBSettings(None)
		print()
			
		print("Changing UWB parameters...")	
		print()
		self.pozyx.setRangingProtocol(self.ranging_protocol)
		self.pozyx.setUWBSettings(self.UWBSettings)
		self.pozyx.setUWBChannel(self.UWBChannel)
		time.sleep(1)
		gain_db = Data([self.UWBSettings.gain_db], 'f')
		self.pozyx.setTxPower(gain_db, None)
		
		"""
		print(self.UWBSettings.gain_db <= 33)

		if ((self.UWBSettings.gain_db >= 0.0) and (self.UWBSettings.gain_db <= 33)):
			print("Done")
			doublegain_db = Data([int(2.0 * self.UWBSettings.gain_db + 0.5)])
		
		print("sono qui:", doublegain_db[0] < 0x67)
		print(type(doublegain_db))
		PozyxLib.setWrite(PozyxRegisters.UWB_GAIN, doublegain_db, None)
		"""
	
		### Print UWB configuration results
		print("Updated UWB configuration:")
		self.printUWBSettings(None)
		print()
		print("Saving UWB settings...")
		if self.saveUWBSettings:
			status_uwb = self.pozyx.saveUWBSettings()
			
			if status_uwb == POZYX_SUCCESS:
				print("UWB Settings saved\n")
			else:
				print("Failed to save UWB Settings\n")

	
	
	######################################################################
	##############			Printing METHODS	 			##############
	######################################################################	
	def printUWBSettings(self, remote_id):
		bitrate_dict = {PozyxConstants.UWB_BITRATE_110_KBPS : "Bitrate: 110 kb/s, ",
				PozyxConstants.UWB_BITRATE_850_KBPS : "Bitrate: 850 kb/s, ",
				PozyxConstants.UWB_BITRATE_6810_KBPS : "Bitrate: 6810 kb/s, "}
		prf_dict  = {PozyxConstants.UWB_PRF_64_MHZ : "PRF: 64 MHz, ",
					PozyxConstants.UWB_PRF_16_MHZ : "PRF: 16 MHz, "}
		plen_dict = {PozyxConstants.UWB_PLEN_64 : "Preamble length: 64 symbols, ", 
					PozyxConstants.UWB_PLEN_128 : "Preamble length: 128 symbols, ",
					PozyxConstants.UWB_PLEN_256 : "Preamble length: 256 symbols, ",
					PozyxConstants.UWB_PLEN_512 : "Preamble length: 512 symbols, ",
					PozyxConstants.UWB_PLEN_1024 : "Preamble length: 1024 symbols, ",
					PozyxConstants.UWB_PLEN_1536 : "Preamble length: 1536 symbols, ",
					PozyxConstants.UWB_PLEN_2048 : "Preamble length: 2048 symbols, ", 
					PozyxConstants.UWB_PLEN_4096 : "Preamble length: 4096 symbols, "}
		protocol_dict = {POZYX_RANGE_PROTOCOL_PRECISION : "Ranging protocol: PRECISION",
					POZYX_RANGE_PROTOCOL_FAST : "Ranging protocol: FAST"}
		aux = UWBSettings()
		status = self.pozyx.getUWBSettings(aux, remote_id)
		
		
		if status == POZYX_SUCCESS:
			if remote_id == None:
				print("Serial ", bitrate_dict[aux.bitrate], 
				       prf_dict[aux.prf], plen_dict[aux.plen], "Gain: ", aux.gain_db)
			else:
				print(hex(remote_id), "Channel: ", aux.channel, bitrate_dict[aux.bitrate], 
				       prf_dict[aux.prf], plen_dict[aux.plen], "Gain: ", aux.gain_db)
		else:
			if remote_id == self.serial_id:
				return
			print(hex(remote_id), "Failed to receive UWB Settings")
	
	def printProtocol(self):
		protocol_dict = {POZYX_RANGE_PROTOCOL_PRECISION : "Ranging protocol: PRECISION",
					POZYX_RANGE_PROTOCOL_FAST : "Ranging protocol: FAST"}
		print(protocol_dict[self.ranging_protocol])
		
	################################################################################
	
########### End of class CalibrationPozyx ####################################	
		






#################################################################
##########					MAIN				#################
#################################################################
if __name__ == "__main__":
	# Riconosce se ci sono dispositivi Pozyx connessi alla porta USB del PC
	serial_port = get_first_pozyx_serial_port()
	print("Pozyx device found in port: ", serial_port, '\n')
	if serial_port is None:
		raise Exception("No Pozyx connected. Check your USB cable or your driver")
		quit()
	pozyx = PozyxSerial(serial_port)


	# Ranging protocol: POZYX_RANGE_PROTOCOL_FAST or POZYX_RANGE_PROTOCOL_PRECISION
	ranging_protocol = POZYX_RANGE_PROTOCOL_PRECISION
	
	# Impostazioni Ultra Wide Band
	# Canale: 1,2,3,5 o 7
	channel = 5			# Default value = 5
	
	# Bitrate, possibili valori:
		# PozyxConstants.UWB_BITRATE_110_KBPS		Default value
		# PozyxConstants.UWB_BITRATE_850_KBPS
		# PozyxConstants.UWB_BITRATE_6810_KBPS
	bitrate = PozyxConstants.UWB_BITRATE_6810_KBPS

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
	gain_db = 33.5				# Default value 11.5 dB
	
	myUWBSettings = UWBSettings(channel, bitrate, prf, plen, gain_db)
	saveUWBSettings = True		# Save UWB settings permanently to Flash memory
	################## -Fine settaggio parametri- #########################
	
	
	#######################################################################
	################## 		Start autocalibration 		###################
	#######################################################################
	# Initialize serial connection with the class CalibrationPozyx
	serial_tag = CalibrationPozyx(pozyx, ranging_protocol, myUWBSettings, saveUWBSettings)
	
	# Performs a network setup: gets anchor distances and performs autocalibration, save anchor
	# coordinates.
	serial_tag.setup() 
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
