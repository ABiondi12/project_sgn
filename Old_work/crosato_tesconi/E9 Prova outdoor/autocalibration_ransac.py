# Questo script python permette di effettuare un'acquisizione automatica delle posizioni dei tag,
# utilizzando l'algoritmo di posizionamento della pozyx.
# La posizione dei tag determinata dall'algoritmo viene comunicata sulla linea UWB al dispositivo
# che è connesso alla porta USB del PC. Sullo schermo vengono stampate le posizioni dei due tag.
# E' possibile calibrare le ancore sia manualmente che automaticamente. I parametri da modificare 
# si trovano nella funzione "main" in fondo al programma. Il programma è pensato per una 
# configurazione minima che prevede l'utilizzo di 4 ancore per la calibrazione.

# Su linux:
# da terminale digitare >> sudo python3 test_UWB.py
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
	def __init__(self, pozyx, anchor_ids, serial_id, auto_cal, R_mis, ranging_protocol, 
	N_acq, n_percentage, k, t, d_percentage, plot_ransac_error = False, myUWBSettings=None, saveUWBSettings = False, setUWBSettings = False):
		# Argument variables
		self.pozyx = pozyx					# PozyxSerial class' instance
		self.anchor_ids = anchor_ids		# list of anchor ids [A0, A1, A2, A3]
		self.auto_cal = auto_cal			# True if you want to perform autocalibration
		self.R_mis = R_mis					# Container for measured distances. It's a list of lists
		
		self.ranging_protocol = ranging_protocol	# Pozyx ranging protocol used
		self.N_acq = N_acq							# number of acquisitions t be performed
		self.serial_id = serial_id					# Id of serial pozyx device
		self.UWBSettings = myUWBSettings			
		
		# Ransac parameters: explained in main function
		self.n_percentage = n_percentage
		self.k = k
		self.t = t
		self.d_percentage = d_percentage
		self.plot_ransac_error = plot_ransac_error
		
		
		# Internal class variables
		self.R = self.init_empty_list(6)	# Each element of this list is a vector containing all 
											# measurements of the distance between all possible 
											# anchor pairs. Each measurement is the average between 
											# the measurment from anchor i to j and from anchor j
											# to i.		
		self.R_avg = []						# Container for average values of the anchor distances
		self.anchors = []					# Container for anchor ids and coordinates. It stores 
											# the data obtained with rangesToPos algorithm.		
		self.coppie = [[anchor_ids[0], anchor_ids[1]],		# List of all possible anchor pairs
					[anchor_ids[0], anchor_ids[2]],
					[anchor_ids[0], anchor_ids[3]],
					[anchor_ids[1], anchor_ids[2]],
					[anchor_ids[1], anchor_ids[3]],
					[anchor_ids[2], anchor_ids[3]]	]	

		self.UWBChannel = myUWBSettings.channel			# UWB channel to be setted
		self.defaultUWBSettings = UWBSettings(5,0,2,8,11.5)		# Default UWB Settings. These are 
											# the settings that are found when turning on an anchor.
		self.saveUWBSettings = saveUWBSettings
		self.setUWBSettings = setUWBSettings

	
	##############################################################
	##############			SETUP METHOD 			##############
	##############################################################
	def setup(self):
		# Set the UWB parameters for all the anchors, the remote tags and the serial tag
		if self.setUWBSettings:
			print("Setting UWB Settings... \n")
			for remote in anchor_ids:
				gain_db = Data([self.UWBSettings.gain_db], 'f')
				if remote != self.serial_id:
					self.pozyx.setRangingProtocol(self.ranging_protocol, remote)			 		
					self.pozyx.setUWBSettings(self.UWBSettings, remote)
					self.pozyx.setUWBChannel(self.UWBChannel, remote)
					self.pozyx.setTxPower(gain_db, remote)    
		
			self.pozyx.setRangingProtocol(self.ranging_protocol)
			self.pozyx.setUWBSettings(self.UWBSettings)
			self.pozyx.setUWBChannel(self.UWBChannel)
			self.pozyx.setTxPower(gain_db, None) 
		
		
		#Print Device coordinates when system is turned on
		print("Device coordinates at starting:")
		coordinates = Coordinates()
		i=0
		for anchor in self.anchor_ids:
			if anchor == self.serial_id:
				status = self.pozyx.getDeviceCoordinates(anchor, coordinates, None)
			else:
				status = self.pozyx.getDeviceCoordinates(anchor, coordinates, anchor)
			
			if status == POZYX_FAILURE:
				print ("Couldn't connect to device ", str(hex(anchor)))
			print("ANCHOR ", i, str(hex(anchor)), ", X:", coordinates.x, ", Y:", coordinates.y, 
					", Z:", coordinates.z)
			i += 1
		print()
		
		### Print UWB configuration results
		print("Current UWB configuration:")
		for remote in anchor_ids:
			self.printUWBSettings(remote)
		self.printUWBSettings(None)
		print()
		if self.saveUWBSettings:
			status_uwb = self.pozyx.saveUWBSettings()
			for anchor in self.anchor_ids:
				status_uwb &= self.pozyx.saveUWBSettings(anchor)
			if status_uwb == POZYX_SUCCESS:
				print("UWB Settings saved\n")
			else:
				print("Failed to save UWB Settings\n")
		
		# Perform autocalibration if needed, then plot results
		if not self.auto_cal:
			# Compute algebraic algorithm to determine the anchors' coordinates
			self.anchors = rangesToPos(self.R_mis, self.anchor_ids)
			self.printConfigurationResults()	#Print anchor coordinates in a readable way
		else:
			print("Performing autocalibration")
			self.getDistances()		# get the distances between the anchors automatically
			
			ransac_again = 'y'
			while ransac_again == 'y':
				self.R_mis = []
				self.ransac()
				try:
					print("\nAverage distances between the anchors, NO ransac: \n [r01,r02,r03,r12,r13,r23] =", self.R_avg)
					self.anchors = rangesToPos(self.R_mis, self.anchor_ids, self.z)
					self.printConfigurationResults()	#Print anchor coordinates in a readable way
				except:
					print("Configuration failed\n")
				plt.show()
				
				#User interface for running RANSAC algorithm ###################################
				ransac_again = input("Perform algorithm to obtain distances again? y/n\t")
				if ransac_again == 'y':
					change_ransac_param = input("Do you want to change ransac parameters? y/n\t")
					if change_ransac_param == 'y':
						print("Current values n:", self.n_percentage, "   k", self.k, "   t", self.t, "   d", self.d_percentage)
						self.n_percentage = float(input("Percentage of data initially chosen n:\t"))
						self.k = int(input("Number of iterations k:\t"))
						self.t = float(input("Tolerance t:\t"))
						self.d_percentage = float(input("Percentage of desired inliers d:\t"))
						
				plt.close('all')
	
		
		# User interface to save results ###################
		save_results = input("Save current results? y/n\t")
		if save_results == 'y':
			
			attempts = 'y'
			success = False
			while attempts =='y':
				try:
					print("Saving...")
					self.addAnchors()		#Add anchors' to tag internal device list
					success = True
					break
				except:
					attempts = input("Failed to add anchors to anchors's device list, try saving again? y/n\t")
			if success == False:
				raise Exception("Quitting...")
				quit()		
			print("Success: each anchor has been added to its internal device list and saved in its flash memory")	
		else:
			print("Quitting...")
			quit()				 
	############### End of SETUP METHOD	###########################################################
	
	
	
	
	######################################################################
	##############			getDistances METHOD 			##############
	######################################################################
	
	# This function starts a ranging procedure between the anchors of the system in order to get the
	# distances between all possible couples of anchors. The distances are obtained with the 
	# doRanging function of the pozyx library. The data are stored in the self.R variable.
	
	def getDistances(self):
		device_range1 = DeviceRange()  	# Container for distance between anchor i and anchor j
		device_range2 = DeviceRange()	# Container for distance between anchor j and anchor i
		
		# Possible anchor's pairs

		for k in list(range(self.N_acq)):
			i = 0
			
			if k%20==0:
				print("Acquisition ", k+1, "of ", N_acq)
			for coppia in self.coppie:	
				# call doRanging with None argument when the considered anchor's id is serial_id
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
				
				# Take average result
				MAX_DISTANCE = 1e6
				if ((status1 == POZYX_SUCCESS) and (device_range1.distance <= MAX_DISTANCE)):
					if ((status2 == POZYX_SUCCESS) and (device_range2.distance <= MAX_DISTANCE)):
						dist = (device_range1.distance + device_range2.distance)/2
						self.R[i].append(dist)
				i = i+1
	
				
		# Plot raw data and save it in raw_distances.png
		data_fig, axarr = plt.subplots(2,3,figsize=(16,9))
		plt.suptitle('Measured distances between the anchors, raw data only')
		for i in list(range(len(self.R))):
			n_samples = len(self.R[i])
			if n_samples < (self.N_acq)*0.15:
				print("Could not measure the distances between the anchors properly")
				print("only " ,n_samples, "of ",  self.N_acq, "acquisitions were completed")
				print("check if the anchors can communicate properly")
				quit()
			row = int(i/3)
			col = int(i%3)
			curr_ax = axarr[row,col]
			curr_ax.plot(np.arange(n_samples), np.array(self.R[i]), 'k.', label='data')
			curr_title = self.create_subplot_title(row,col,self.coppie[i])
			curr_ax.set_title(curr_title, fontsize=10)
			curr_ax.set_ylabel('distance [mm]')
		data_fig.savefig('raw_distances.png')
		plt.close(data_fig)
	############### End of getDistances METHOD	###############################################
	
	
	
	
	######################################################################
	##############			RANSAC METHOD 					##############
	######################################################################
	# This method performs a fitting of the data acquired by getDistances with the ransac algorithm.
	# It is possible to plot the errors at the end of each ransac algorithm call.
	# The distances obtained and a figure with the ransac results is shown. It is possible to 
	# perform multiple ransac algorithms and change the ransac parameters 
	# and than accept or reject the results.
	
	def ransac(self):
		# Conatainer for arrays of distances between anchor pairs. These lists should be as long as
		# the number of anchor pairs		
		R_fitted = self.init_empty_list(6)	# Container for fitted anchor's distances
		
		R_avg = self.init_empty_list(6)		# Container for average results (no ransac algorithm). 
											# Each element of this list is the average of the 
											# the elements in the vectors of list R.
		
		r = self.init_empty_list(6)			# Auxialiry variable, R is a list of lists, r is a list
											# of numpy.array. Convertion is needed because of 
											# ransac.py
		
		indexes = self.init_empty_list(6)	# list of lists. Each list contains the indexes that are
											# the output of the RANSAC algorithm. This indexes 
											# represent the points chosen for the fit.
		
		# Compute R_avg
		for i in list(range(6)):
			R_avg[i] = average(self.R[i])
		self.R_avg = R_avg
		
		# Perform ransac algorithm									
		print()
		ransac_success = True
		for i in list(range(len(self.R))):
			r[i] = np.array(self.R[i])[:,np.newaxis]		# Converts R in a format suitable for ransac.py
			N = np.shape(r[i])[0]   				# get the length of the i-th vector of distances
			print("Successful acquisitions between anchors ",str(hex(self.coppie[i][0])), 
											str(hex(self.coppie[i][1])),": ", N)
			regressor = np.ones([N,1])				# Creates the matrix used for linear regression
		
			if N < 100:
				print("Warning: only", N, "distances between anchors", str(hex(self.coppie[i][0])), 
						str(hex(self.coppie[i][1])),"were acquired, this number is considered small for autocalibration")

			# Performs a ransac algorithm with a model based on linear regression in the form of 
			# A*x=b. A is the regressor, its number of rows is equal to the number of measurements.
			# Its number of columns is equal to the number of parameters that will be estimated.
			# b is also containing measurements. In this case we set A = numpy.ones([N,1]) as our 
			# parameter is a simple constant. b contains the measurments of the distances (R[i]).
			n_inputs = 1		# Number of columns of the regressor (usually small number)
			n_outputs = 1		# Number of columns of the output
			all_data = np.hstack( (regressor, r[i]) )
			input_columns = range(n_inputs) 			# indexes of the first columns of the array
			output_columns = [n_inputs+i for i in range(n_outputs)] # the last columns of the array
			debug = False
			model = LinearLeastSquaresModel(input_columns,output_columns,debug=debug)
		
			n = int(self.n_percentage*N)
			d = int(self.d_percentage*N)
			
			try:
				# Here the function ransac.ransac from imported ransac module is called. It's not a 
				# self.ransac, so it's not a recursive function
				R_fitted[i], indexes[i], errors_arr, iteration_arr = ransac(all_data, model, n, self.k, self.t, d, 
													debug=debug, return_all=True)
				print("Errors in successful iteration of RANSAC: ", errors_arr)
				print("The above error were found at iteration: ", iteration_arr)
				try:
					print("Deviazione standard: ", math.sqrt(errors_arr[-1]))
				except:
					print("Could not access element -1 of errors_arr to compute its variance.")
				print()
				print()
				if self.plot_ransac_error:
					figure, ax = plt.subplots()
					ax.plot(iteration_arr, errors_arr, 'kx-', label='data')
					row = int(i/3)
					col = int(i%3)
					title = self.create_subplot_title(row, col, self.coppie[i])
					ax.set(xlabel='iteration', ylabel='variance [mm^2]')
					ax.set_title(title)
					plt.show()
					plt.close(figure)
			except:
				ransac_success = False

		#Plot results
		if ransac_success:
			fig, axarr = plt.subplots(2,3,figsize=(16,9))
			plt.suptitle('Measured distances between the anchors')
			for i in list(range(len(self.R))):
				n_samples = len(self.R[i])
				n_inliers = indexes[i]['inliers'].shape[0]
				row = int(i/3)
				col = int(i%3)
				curr_ax = axarr[row,col]
				line1 = curr_ax.plot(np.arange(n_samples), np.array(self.R[i]), 'k.', label='data')
				line4 = curr_ax.plot(np.arange(n_samples)[indexes[i]['inliers']], r[i][indexes[i]['inliers'],0],'bx',label='RANSAC data')
				line2 = curr_ax.plot(np.arange(n_samples), np.ones(n_samples)*R_fitted[i][0][0], 
									'r-', label='ransac_fit')
				line3 = curr_ax.plot(np.arange(n_samples), np.ones(n_samples)*R_avg[i], 'g-',
									label='simple average')
				curr_title = self.create_subplot_title(row,col,self.coppie[i])		
				curr_ax.set_title(curr_title, fontsize=10)
				curr_ax.set_ylabel('distance [mm]')
				if row==0 and col==0:
					curr_ax.legend( ncol = 4, shadow=True, bbox_to_anchor=[0, 1.2], loc='upper left')
			fig.savefig('autocalibration_results.png')
			self.R_mis = self.convert_back_to_list(R_fitted)		# Data that will be given to the
																	# algebraic alg to compute anchor 
																	# coordinates
		else:
			print("Failed to obtain anchor distances with current RANSAC parameters")
	############### End of RANSAC METHOD	###################################################
			
	
	
	
	######################################################################
	##############			auxiliary METHODS	 			##############
	######################################################################		
	def create_subplot_title(self,row, col, coppia):
		if row==0:
				curr_title = 'r'+str(row)+str(col+1)+': '+str(hex(coppia[0]))+' '+str(hex(coppia[1]))
		if row==1:
			if col!=2:
				curr_title = 'r'+str(row)+str(col+2)+': '+str(hex(coppia[0]))+' '+str(hex(coppia[1]))
			if col==2:
				curr_title = 'r'+str(row+1)+str(col+1)+': '+str(hex(coppia[0]))+' '+str(hex(coppia[1]))
		return curr_title
	
	def convert_back_to_list(self, R_fitted):
		R_aux = [[],[],[],[],[],[]]
		for i in list(range(len(R_fitted))):
			R_aux[i] = R_fitted[i].tolist()
			R_aux[i] = R_aux[i][0][0]
		return R_aux
	
	# initializes an empty list of n empty elements: [[], [], ... , []]
	def init_empty_list(self, n):
		list_obj = []
		for i in list(range(n)):
			list_obj.append([])
		return list_obj
	
	# Add the anchors with their coordinates to the device internal list. Each anchor stores its own
	# coordinates. This storage will last even if the anchor is turned off.
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
	##############################################################################################						
	
	
	
	
	######################################################################
	##############			Printing METHODS	 			##############
	######################################################################
	
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
		
	# Print anchor coordinates in a readable way
	def printConfigurationResults(self):
		print("Configuration finished: ")
		i=0
		for anchor in self.anchors:
			print("ANCHOR", i, ", 0x%0.4x, %s" % (anchor.network_id, str(anchor.pos)))
			i += 1
		print()
		print()
		print("Please check data figure and close it when you are ready\n\n")
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
	
	
	################################################################
	####						-PARAMETRI-						####			
	################################################################
	
	# Calibrazione automatica-manuale
	auto_cal = False									# False = manuale, True = automatica
	serial_id = 0x675d
	anchor_ids = [0x6e6c, 0x6e44, 0x6939, 0x6e7a]	# !!! Seguire la convenzione di rangesToPos.py
	
	r01 = 27407	# Inserire i valori se si vuole fare una calibrazione manuale
	r02 = 21866
	r03 = 15292
	r12 = 35954
	r13 = 19647
	r23 = 16210
	z = 2099-875
	
	# Parameters of the ransac algorithm to eliminate outliers
	N_acq = 200
	n_percentage = 0.1				# Percentage of elements extracted at each iteration of ransac
	k = 1e4							# Maximum number of iterations of ransac algorithm
	t = 1e5							# Tolerance. Values with variance greater than t will not be
									# added to the initial extracted data
	d_percentage = 0.2 				# minimum percentage of points to consider ransac iteration good
	plot_ransac_error = False		# True se si vogliono mostrare gli errori
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
	plen = PozyxConstants.UWB_PLEN_1024
	
	# UWB Gain, possibili valori: 
		# float tra 0 e 67.1 dB
	gain = 33 				# Default value 11.5 dB
	
	myUWBSettings = UWBSettings(channel, bitrate, prf, plen, gain)
	saveUWBSettings = False		# Save UWB settings permanently to Flash memory
	setUWBSettings = False		# Set (not permanently) UWB settings to all anchors for the current setup.
	################## -Fine settaggio parametri- #########################
	
	
	#######################################################################
	################## 		Start autocalibration 		###################
	#######################################################################
	# Initialize serial connection with the class CalibrationPozyx
	serial_tag = CalibrationPozyx(pozyx, anchor_ids, serial_id, auto_cal, R_mis, ranging_protocol, 
								N_acq, n_percentage, k, t, d_percentage, plot_ransac_error, myUWBSettings, saveUWBSettings, setUWBSettings)
	
	# Performs a network setup: gets anchor distances and performs autocalibration, save anchor
	# coordinates.
	serial_tag.setup() 
	
	# Generate text file Parametri_UWB.txt that will be used by doPositioning.py
	out_file = open("Parametri_UWB.txt", "w")
	out_file.write(str(channel)+'\n')
	out_file.write(str(bitrate)+'\n')
	out_file.write(str(prf)+'\n')
	out_file.write(str(plen)+'\n')
	out_file.write(str(gain)+'\n')
	out_file.close()
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
