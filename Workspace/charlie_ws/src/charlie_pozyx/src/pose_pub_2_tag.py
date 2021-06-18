#!/usr/bin/env python
"""
Nodo ROS che pubblica la posa delle due tag (posizione + quaternione)
By ABiondi FPetracci 
"""

import numpy
import pypozyx
from pypozyx.structures.device_information import DeviceDetails
import rospy
from geometry_msgs.msg import Point, PoseStamped, Quaternion
import tf
from defs import* # Definizioni che vengono importate da defs.py

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
	coordinates0 = pypozyx.Coordinates()
	status = pozyx_0.getDeviceCoordinates(anchor_ids[0], coordinates0, anchor_ids[0])

	# anchor1
	coordinates1 = pypozyx.Coordinates()
	status &= pozyx_0.getDeviceCoordinates(anchor_ids[1], coordinates1, anchor_ids[1])

	# anchor2
	coordinates2 = pypozyx.Coordinates()
	status &= pozyx_0.getDeviceCoordinates(anchor_ids[2], coordinates2, anchor_ids[2])

	# anchor3
	coordinates3 = pypozyx.Coordinates()
	status &= pozyx_0.getDeviceCoordinates(anchor_ids[3], coordinates3, anchor_ids[3])

	#---------------------------------------------------------
	# saving in the tags the anchors coordinates
	anchors_list = [	pypozyx.DeviceCoordinates(anchor_ids[0], 1, coordinates0),
						pypozyx.DeviceCoordinates(anchor_ids[1], 1, coordinates1),
						pypozyx.DeviceCoordinates(anchor_ids[2], 1, coordinates2),
						pypozyx.DeviceCoordinates(anchor_ids[3], 1, coordinates3)]
	
	#saving in front tag (tag0)
	status_tag0 = pozyx_0.clearDevices(None) # clear previous saved stuff in device's flash
	for anchor_i in anchors_list:
		status_tag0 &= pozyx_0.addDevice(anchor_i, None)
	status_tag0 &= pozyx_0.saveNetwork(None)

	if status_tag0 == pypozyx.POZYX_SUCCESS:
		rospy.loginfo("Updated memory on tag0 with id 0x%0.4x" % tag0_ID)
	else:
		rospy.loginfo("Failed to update memory on tag0 with id 0x%0.4x" %tag0_ID)

	#saving in rear tag (tag1)
	status_tag1 = pozyx_1.clearDevices(None) # clear previous saved stuff in device's flash
	for anchor_i in anchors_list:
		status_tag1 &= pozyx_1.addDevice(anchor_i, None)
	status_tag1 &= pozyx_1.saveNetwork(None)
	if status_tag1 == pypozyx.POZYX_SUCCESS:
		rospy.loginfo("Updated memory on tag1 with id 0x%0.4x" %tag1_ID)
	else:
		rospy.loginfo("Failed to update memory on tag1 with id 0x%0.4x" %tag1_ID)

	return status

def doPos_pubtf(tag_serial, tag_id, pose_pub):
	'''
		This function does positioning (doPositioning) of a pozyx-tag serial connected and publishes its
		tf to the tf-broadcaster
		Args:
			tag_serial: serial instance connected to tag
			tag_id:	tag id of the connected tag through tag_serial
			pose_pub: instance of the ros publisher we want to use
	'''
	# check name
	if tag_id == 0x6760:
		tag_name = "tag0"
		tag_framename = tag0_frame_ID
	elif tag_id == 0x675d:
		tag_name = "tag1"
		tag_framename = tag1_frame_ID
	else:
		rospy.loginfo("Check id of the connected tag!")
	

	
	# Inizializzazione delle variabili
	pose 			= PoseStamped()
	coords			= pypozyx.Coordinates()
	quat 			= pypozyx.Quaternion()
	euler_angles 	= pypozyx.EulerAngles()

	status =	tag_serial.doPositioning(coords, pypozyx.POZYX_3D, remote_id=None)
	status &= 	tag_serial.getQuaternion(quat, remote_id=None)
	status &= 	tag_serial.getEulerAngles_deg(euler_angles, remote_id=None)

	if status != pypozyx.POZYX_SUCCESS:
		rospy.loginfo("%s failed ", tag_name)

	if status == pypozyx.POZYX_SUCCESS and not (coords.x == 0.0 and coords.y == 0.0 and coords.z == 0.0):
		pose.header.frame_id = UWB_frame_ID
		pose.header.stamp = rospy.Time.now()
		# Converto da [mm] a [m]
		pose.pose.position.x = coords.x / 1000.0
		pose.pose.position.y = coords.y / 1000.0
		pose.pose.position.z = coords.z / 1000.0
		# Quaternioni
		pose.pose.orientation.x = quat.x
		pose.pose.orientation.y = quat.y
		pose.pose.orientation.z = quat.z
		pose.pose.orientation.w = quat.w

		# Pubblico sul rispettivo topic
		pose_pub.publish(pose)

		br = tf.TransformBroadcaster() #init broadcaster

		br.sendTransform(
			(pose.pose.position.x, pose.pose.position.y, pose.pose.position.z), 	# posizione
			(pose.pose.orientation.x, pose.pose.orientation.y, 
				pose.pose.orientation.z, pose.pose.orientation.w),					# orientazione
			rospy.Time.now(),														# tempo
			tag_framename,															# child sdr
			UWB_frame_ID															# parent sdr
		)
		rospy.loginfo("%s || POS-> X: %f Y: %f Z: %f \t | ANGLE-> roll: %f pitch: %f yaw: %f ||" , tag_name,
					pose.pose.position.x, pose.pose.position.y, pose.pose.position.z, 
					euler_angles.roll, euler_angles.pitch, euler_angles.heading)

# ID delle tag, si suppone che tag0 sia quello frontale
tag0_ID 	= 0x6760 	# Fronte
tag1_ID 	= 0x675d 	# Retro
remote_id 	= None 		# id del device pozyx su cui vogliamo utilizzare le funzioni di registro, lasciare None per connettersi al sistema locale

def pozyx_pose_pub():

	# ------------------ PUBLISHERS ------------------ #
	pose_pub_0 = rospy.Publisher(tag0_topic_ID, PoseStamped, queue_size=100)
	pose_pub_1 = rospy.Publisher(tag1_topic_ID, PoseStamped, queue_size=100)

	rospy.init_node('pozyx_pose_node_2_tags')
	rate = rospy.Rate(20)
	
	# Inizializzazione delle porte seriali, cerca automaticamente 2 tag (se si lascia una sola tag connessa non funziona e richiede di connettere un dispositivo Pozyx)
	try: 
		serial_port_0 	= pypozyx.get_pozyx_ports()[0]			# prende la stringa contentente l'indirizzo della seriale a cui e` connesso un tag
		pozyx_0 		= pypozyx.PozyxSerial(serial_port_0)	# crea la comunicazione seriale

		serial_port_1 	= pypozyx.get_pozyx_ports()[1]			# prende la stringa contentente l'indirizzo della seriale a cui e` connesso un tag
		pozyx_1 		= pypozyx.PozyxSerial(serial_port_1)	# crea la comunicazione seriale
		
		# Verifichiamo che il tag posizionato in testa corrisponda effettivamente a pozyx_0 da cui leggeremo
		# altrimenti i due tag vengono scambiati. Questo perche' ad ogni riavvio le porte seriali vengono reinizializzate

		system_details = DeviceDetails()
		
		pozyx_0.getDeviceDetails(system_details, remote_id=None)  #Serve per ottenere l'ID della tag che in questo momento viene vista come pozyx_0 e che dovrebbe essere la testa
		tag_ID = system_details.id

		# Se l'ID trovato non corrisponde a quello desiderato per la tag frontale, i due vengono scambiati
		print("Front tag desired id 0x%0.4x, right now pozyx_0 has id 0x%0.4x" % (tag0_ID, system_details.id))

		if tag_ID != tag0_ID:
			pozyx_0_tmp = pozyx_0
			pozyx_0 	= pozyx_1
			pozyx_1 	= pozyx_0_tmp
			
			system_details = DeviceDetails()
			pozyx_0.getDeviceDetails(system_details, remote_id=None)
			print("Switched! Now front tag is 0x%0.4x" % (system_details.id) )		
	except:
		rospy.loginfo("Pozyx not connected")
		return
		
	# Stampa le porte seriali attive con tag connesse, poi iniziare a pubblicare
	rospy.loginfo("Using tags connected to : \n %s \n %s", serial_port_0, serial_port_1)
		
	# Salvataggio delle coordinate delle ancore nei device list dei tag connessi 
	status = save_anchors_in_tags(pozyx_0, pozyx_1) # versione compatta dei commenti sopra
	if status == pypozyx.POZYX_SUCCESS:
		rospy.loginfo("Saved anchors coordinates in the connected tags!")
	else:
		rospy.loginfo("Failed to save anchors coordinates in the connected tags.")


	while not rospy.is_shutdown():

		doPos_pubtf(pozyx_0, tag0_ID , pose_pub_0)

		rate.sleep()

		doPos_pubtf(pozyx_1, tag1_ID , pose_pub_1)

		rate.sleep()


if __name__ == '__main__':
    try:
        pozyx_pose_pub()
    except rospy.ROSInterruptException:
        pass
