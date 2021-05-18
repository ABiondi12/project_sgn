import pypozyx as pp
from pypozyx.structures.device_information import DeviceDetails
import time
# import numpy as np

def save_anchors_in_tags(pozyx_0, pozyx_1):
	'''
		Get anchor coordinates from anchors' flash memory and saves to tags' memory. 
		Requires two tags connected and already started a pypozyx.serial instance.
		Args: 
			pozyx_0: serial instance connected to tag0 
			pozyx_1: serial instance connected to tag1 
		Returns:
			POZYX_SUCCESS, POZYX_FAILURE

	'''
	# after serial comm activation
	tag0_ID = 0x6760 # Fronte
	tag1_ID = 0x675d # Retro
	anchor_ids = [0x6902, 0x6e7a, 0x6e44, 0x6e6c]	# anchor id

	#connect to anchors using pozyx_0 and saving their coordinates
	# anchor0
	coordinates0 = pp.Coordinates()
	status = pozyx_0.getDeviceCoordinates(anchor_ids[0], coordinates0, anchor_ids[0])

	# anchor1
	coordinates1 = pp.Coordinates()
	status &= pozyx_0.getDeviceCoordinates(anchor_ids[1], coordinates1, anchor_ids[1])

	# anchor2
	coordinates2 = pp.Coordinates()
	status &= pozyx_0.getDeviceCoordinates(anchor_ids[2], coordinates2, anchor_ids[2])

	# anchor3
	coordinates3 = pp.Coordinates()
	status &= pozyx_0.getDeviceCoordinates(anchor_ids[3], coordinates3, anchor_ids[3])

	#---------------------------------------------------------
	# saving in the tags the anchors coordinates
	anchors_list = [	pp.DeviceCoordinates(anchor_ids[0], 1, coordinates0),
						pp.DeviceCoordinates(anchor_ids[1], 1, coordinates1),
						pp.DeviceCoordinates(anchor_ids[2], 1, coordinates2),
						pp.DeviceCoordinates(anchor_ids[3], 1, coordinates3)]
	
	#saving in front tag (tag0)
	status_tag0 = pozyx_0.clearDevices(None) # clear previous saved stuff in device's flash
	for anchor_i in anchors_list:
		status_tag0 &= pozyx_0.addDevice(anchor_i, None)
	status_tag0 &= pozyx_0.saveNetwork(None)

	if status_tag0 == pp.POZYX_SUCCESS:
		print("Updated memory on tag0 with id", hex(tag0_ID))
	else:
		print("Update of tag0 failed, check connection.")

	#saving in rear tag (tag1)
	status_tag1 = pozyx_1.clearDevices(None) # clear previous saved stuff in device's flash
	for anchor_i in anchors_list:
		status_tag1 &= pozyx_1.addDevice(anchor_i, None)
	status_tag1 &= pozyx_1.saveNetwork(None)
	if status_tag1 == pp.POZYX_SUCCESS:
		print("Updated memory on tag1 with id", hex(tag1_ID))
	else:
		print("Update of tag1 failed, check connection.")

	return status

def anchors_tf():

	# init serial communication with one tag
	# serial_id = 0x675d 	# tag id (should not be needed)
	anchor_ids = [0x6902, 0x6e7a, 0x6e44, 0x6e6c]	# anchor id
	

	tag0_ID = 0x6760 # Fronte
	tag1_ID = 0x675d # Retro

	remote_id = None

	print("Connecting to tags...")
	serial_port_0 = pp.get_pozyx_ports()[0]
	serial_port_1 = pp.get_pozyx_ports()[1]
	pozyx_0 = pp.PozyxSerial(serial_port_0)
	pozyx_1 = pp.PozyxSerial(serial_port_1)

	print("Connected to tags! Checking if a name switch is required...")

	system_details_first = DeviceDetails()
	pozyx_0.getDeviceDetails(system_details_first, remote_id=None)  #Serve per ottenere l'ID della tag che in questo momento viene vista come pozyx_0 e che dovrebbe essere la testa
	tag_first_ID = system_details_first.id

	system_details_second = DeviceDetails()
	pozyx_1.getDeviceDetails(system_details_second, remote_id=None)  #Serve per ottenere l'ID della tag che in questo momento viene vista come pozyx_0 e che dovrebbe essere la testa
	tag_second_ID = system_details_second.id

	print("On ", serial_port_0, " is connected tag with ID: 0x%0.4x" % tag_first_ID)
	print("On ", serial_port_1, " is connected tag with ID: 0x%0.4x" % tag_second_ID)


	print("Front tag desired id 0x%0.4x, right now pozyx_0 has id 0x%0.4x" % (tag0_ID, tag_first_ID))

	if tag_first_ID != tag0_ID :
		pozyx_0_tmp = pozyx_0
		pozyx_0 = pozyx_1
		pozyx_1 = pozyx_0_tmp
		
		system_details = DeviceDetails()
		pozyx_0.getDeviceDetails(system_details, remote_id=None)
		print("Now front tag is 0x%0.4x" % (system_details.id) )	


	# #---------------------------------------------------------------------------
	# #connect to anchors using pozyx_0 and saving their coordinates
	# # anchor0
	# anchor0 = anchor_ids[0]
	# coordinates0 = pp.Coordinates()
	# status0 = pozyx_0.getDeviceCoordinates(anchor0, coordinates0, anchor0)

	# # anchor1
	# anchor1 = anchor_ids[1]
	# coordinates1 = pp.Coordinates()
	# status1 = pozyx_0.getDeviceCoordinates(anchor1, coordinates1, anchor1)

	# # anchor2
	# anchor2 = anchor_ids[2]
	# coordinates2 = pp.Coordinates()
	# status2 = pozyx_0.getDeviceCoordinates(anchor2, coordinates2, anchor2)

	# # anchor3
	# anchor3 = anchor_ids[3]
	# coordinates3 = pp.Coordinates()
	# status3 = pozyx_0.getDeviceCoordinates(anchor3, coordinates3, anchor3)

	# if status0 != pp.POZYX_SUCCESS or status1 != pp.POZYX_SUCCESS or status2 != pp.POZYX_SUCCESS or status3 != pp.POZYX_SUCCESS:
	# 	print("Communication failed")
	# 	quit()
	# else:
	# 	print("Coordinates of anchors found on the anchors' memory ")
	# 	print("anchor0 (origin), with id", hex(anchor0), "has coordinates: X:", coordinates0.x, "Y:", coordinates0.y, "Z:", coordinates0.z)
	# 	print("anchor1 (y axis), with id", hex(anchor1), "has coordinates: X:", coordinates1.x, "Y:", coordinates1.y, "Z:", coordinates1.z)
	# 	print("anchor2 (x axis), with id", hex(anchor2), "has coordinates: X:", coordinates2.x, "Y:", coordinates2.y, "Z:", coordinates2.z)
	# 	print("anchor3 (z axis), with id", hex(anchor3), "has coordinates: X:", coordinates3.x, "Y:", coordinates3.y, "Z:", coordinates3.z)

	
	# #---------------------------------------------------------
	# # saving in the tags the anchors coordinates
	# anchors_list = [	pp.DeviceCoordinates(anchor_ids[0], 1, coordinates0),
	# 					pp.DeviceCoordinates(anchor_ids[1], 1, coordinates1),
	# 					pp.DeviceCoordinates(anchor_ids[2], 1, coordinates2),
	# 					pp.DeviceCoordinates(anchor_ids[3], 1, coordinates3)]
	
	# #saving in front tag (tag0)
	# status_tag0 = pozyx_0.clearDevices(None) # clear previous saved stuff in device's flash
	# for anchor_i in anchors_list:
	# 	status_tag0 &= pozyx_0.addDevice(anchor_i, None)
	# status_tag0 &= pozyx_0.saveNetwork(None)

	# if status_tag0 == pp.POZYX_SUCCESS:
	# 	print("Updated memory on tag0 with id", hex(tag0_ID))
	# else:
	# 	print("Update of tag0 failed, check connection.")

	# #saving in rear tag (tag1)
	# status_tag1 = pozyx_1.clearDevices(None) # clear previous saved stuff in device's flash
	# for anchor_i in anchors_list:
	# 	status_tag1 &= pozyx_1.addDevice(anchor_i, None)
	# status_tag1 &= pozyx_1.saveNetwork(None)
	# if status_tag1 == pp.POZYX_SUCCESS:
	# 	print("Updated memory on tag1 with id", hex(tag1_ID))
	# else:
	# 	print("Update of tag1 failed, check connection.")

	status = save_anchors_in_tags(pozyx_0, pozyx_1) # versione compatta dei commenti sopra
	if status != pp.POZYX_SUCCESS:
		print("Failed to save device coordinates in the connected tags.")


	#-------------------------------------------------------------
	#Verifichiamo tag0:

	# anchor0
	anchor0 = anchor_ids[0]
	coordinates0 = pp.Coordinates()
	status0 = pozyx_0.getDeviceCoordinates(anchor0, coordinates0, None)

	# anchor1
	anchor1 = anchor_ids[1]
	coordinates1 = pp.Coordinates()
	status1 = pozyx_0.getDeviceCoordinates(anchor1, coordinates1, None)

	# anchor2
	anchor2 = anchor_ids[2]
	coordinates2 = pp.Coordinates()
	status2 = pozyx_0.getDeviceCoordinates(anchor2, coordinates2, None)

	# anchor3
	anchor3 = anchor_ids[3]
	coordinates3 = pp.Coordinates()
	status3 = pozyx_0.getDeviceCoordinates(anchor3, coordinates3, None)

	if status0 != pp.POZYX_SUCCESS or status1 != pp.POZYX_SUCCESS or status2 != pp.POZYX_SUCCESS or status3 != pp.POZYX_SUCCESS:
		print("Communication failed")
		quit()
	else:
		print("Coordinates of anchors found on tag0",  hex(tag0_ID))
		print("anchor0 (origin), with id", hex(anchor0), "has coordinates: X:", coordinates0.x, "Y:", coordinates0.y, "Z:", coordinates0.z)
		print("anchor1 (y axis), with id", hex(anchor1), "has coordinates: X:", coordinates1.x, "Y:", coordinates1.y, "Z:", coordinates1.z)
		print("anchor2 (x axis), with id", hex(anchor2), "has coordinates: X:", coordinates2.x, "Y:", coordinates2.y, "Z:", coordinates2.z)
		print("anchor3 (z axis), with id", hex(anchor3), "has coordinates: X:", coordinates3.x, "Y:", coordinates3.y, "Z:", coordinates3.z)

	#Verifichiamo tag1:

	# anchor0
	anchor0 = anchor_ids[0]
	coordinates0 = pp.Coordinates()
	status0 = pozyx_1.getDeviceCoordinates(anchor0, coordinates0, None)

	# anchor1
	anchor1 = anchor_ids[1]
	coordinates1 = pp.Coordinates()
	status1 = pozyx_1.getDeviceCoordinates(anchor1, coordinates1, None)

	# anchor2
	anchor2 = anchor_ids[2]
	coordinates2 = pp.Coordinates()
	status2 = pozyx_1.getDeviceCoordinates(anchor2, coordinates2, None)

	# anchor3
	anchor3 = anchor_ids[3]
	coordinates3 = pp.Coordinates()
	status3 = pozyx_1.getDeviceCoordinates(anchor3, coordinates3, None)

	if status0 != pp.POZYX_SUCCESS or status1 != pp.POZYX_SUCCESS or status2 != pp.POZYX_SUCCESS or status3 != pp.POZYX_SUCCESS:
		print("Communication failed")
		quit()
	else:
		print("Coordinates of anchors found on tag1",  hex(tag1_ID))
		print("anchor0 (origin), with id", hex(anchor0), "has coordinates: X:", coordinates0.x, "Y:", coordinates0.y, "Z:", coordinates0.z)
		print("anchor1 (y axis), with id", hex(anchor1), "has coordinates: X:", coordinates1.x, "Y:", coordinates1.y, "Z:", coordinates1.z)
		print("anchor2 (x axis), with id", hex(anchor2), "has coordinates: X:", coordinates2.x, "Y:", coordinates2.y, "Z:", coordinates2.z)
		print("anchor3 (z axis), with id", hex(anchor3), "has coordinates: X:", coordinates3.x, "Y:", coordinates3.y, "Z:", coordinates3.z)




if __name__ == '__main__':
	try:
		anchors_tf()
	except:
		pass


