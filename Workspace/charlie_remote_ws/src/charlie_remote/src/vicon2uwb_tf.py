#!/usr/bin/env python
# coding=utf-8

# Questo nodo genera il file "vicon_frame2UWB_tf.txt" in cui e` salvata la trasformazione da frame vicon 
# a frame UWB. Sono necessarie le misurazioni dell'ancora 0 (origine) e ancora 1 (asse y) da ripetere ogni
# volta che si spostano le ancore

import rospy
import tf
import numpy as np
from geometry_msgs.msg import Point, PoseStamped

#-------------------------------------------------------
# init global variables
vicon2uwb = PoseStamped()
wand_pose = PoseStamped()
#-------------------------------------------------------
def wand_pose_cb(data):
	global wand_pose
	wand_pose = data

#-------------------------------------------------------
def trasf_homo(angle, d, axis = 'z'):
	'''
		return una matrice 4x4 omogenea, prima trasla poi ruota.
	'''
	# creazione matrice di traslazione
	T_trasl = np.matrixlib.matrix(
			[
				[1, 0, 0, d[0]],
				[0, 1, 0, d[1]],
				[0, 0, 1, d[2]],
				[0, 0, 0, 1]
			])

	# creazione matrice di rotazione
	if axis == 'z':
		T_rot = np.matrixlib.matrix(
			[[np.cos(angle), -np.sin(angle), 0, 0],
			[np.sin(angle), np.cos(angle), 0, 0],
			[0, 0, 1, 0],
			[0, 0, 0, 1]]
			)
	elif axis == 'y':
		T_rot = np.matrixlib.matrix(
			[[np.cos(angle), 0, np.sin(angle), 0],
			[0, 1, 0, 0],
			[-np.sin(angle), 0, np.cos(angle), 0],
			[0, 0, 0, 1]]
			)
	elif axis == 'x':
		R = mat = np.matrixlib.matrix(
			[[1, 0, 0, 0]
			[0, np.cos(angle), -np.sin(angle), 0],
			[0, np.sin(angle), np.cos(angle), 0],
			[0, 0, 0, 1]]
			)

	T = np.dot(T_trasl, T_rot)
	return T

#-------------------------------------------------------
def dot_homo(T, vect):
	vect_1 =  np.transpose(np.append(vect, 1) )
	vect_tmp = np.transpose( np.dot(T, vect_1) )
	return vect_tmp[:-1]

#-------------------------------------------------------
def vicon2uwb_fun(point, vicon2uwb):
	'''
		trasforma un punto da coordinate vicon a coordinate uwb
	'''

	vect = np.array((point[0],point[1],point[2]))

	d = np.array((	-vicon2uwb.pose.position.x, 
					-vicon2uwb.pose.position.y, 
					-vicon2uwb.pose.position.z))
	# il meno e` necessario in quanto si vuole la misura nel frame vicon
	eul = tf.transformations.euler_from_quaternion(
		(	vicon2uwb.pose.orientation.x,
			vicon2uwb.pose.orientation.y,
			vicon2uwb.pose.orientation.z,
			vicon2uwb.pose.orientation.w	),
		axes='szyx')

	# mat = trasf_homo(-np.pi/2, d, axis = 'z')	# T_vicon,uwb espressa nel frame vicon
	mat = trasf_homo(eul[0], d, axis = 'z')	# T_vicon,uwb espressa nel frame vicon
	invmat = np.linalg.inv(mat)	# T_uwb,vicon espressa nel frame uwb

	# vogliamo: p_uwb = T_uwb,vicon * p_vicon
	res = dot_homo(invmat, vect)
	res_array = np.array((res[0,0], res[1,0], res[2,0]))
	return res_array

#-------------------------------------------------------
def get_wand_pos():
	'''
		Return la posizione della wand attuale
	'''
	global wand_pose

	raw_input("Press Enter to get the wand position!\n")

	pos = [0, 0, 0] # init position list
	pos[0] = wand_pose.pose.position.x
	pos[1] = wand_pose.pose.position.y
	pos[2] = wand_pose.pose.position.z

	rospy.loginfo("Wand position captured: (%f, %f, %f)", pos[0], pos[1], pos[2])

	return pos

#-------------------------------------------------------
def save_file():
	global vicon2uwb

	# percorso al file in cui vogliamo salvare la trasformazione
	TF_filename = "/home/francesco/catkin_ws/src/charlie_remote/src/vicon_frame2UWB_tf.txt"

	rospy.loginfo("Saving file...")
	# Scrittura file.txt
	f = open(TF_filename,"w+") # accedi al file in scrittura
	f.write("%f\r\n" %(-vicon2uwb.pose.position.x))
	f.write("%f\r\n" %(-vicon2uwb.pose.position.y))
	f.write("%f\r\n" %0)
	
	f.write("%f\r\n" %vicon2uwb.pose.orientation.x)
	f.write("%f\r\n" %vicon2uwb.pose.orientation.y)
	f.write("%f\r\n" %vicon2uwb.pose.orientation.z)			
	f.write("%f\r\n" %vicon2uwb.pose.orientation.w)	
	f.close()

#-------------------------------------------------------
def check_uwb_frame(anchor0, anchor1, anchor2, anchor3, vicon2uwb):
	'''
		Print le coordinate delle ancore nel frame uwb, come argomenti necessita delle posizioni
		delle ancore in frame vicon_frame e vicon2uwb (PoseStamped) 
	'''

	# anchors positions in Vicon frame
	anchor0_uwb = vicon2uwb_fun(anchor0, vicon2uwb)
	anchor1_uwb = vicon2uwb_fun(anchor1, vicon2uwb)
	anchor2_uwb = vicon2uwb_fun(anchor2, vicon2uwb)
	anchor3_uwb = vicon2uwb_fun(anchor3, vicon2uwb)

	# print messages
	rospy.loginfo("Anchors positions in UWB frame...")
	rospy.loginfo("Anchor0: (%f, %f, %f)", anchor0_uwb[0], anchor0_uwb[1], anchor0_uwb[2])
	rospy.loginfo("Anchor1: (%f, %f, %f)", anchor1_uwb[0], anchor1_uwb[1], anchor1_uwb[2])
	rospy.loginfo("Anchor2: (%f, %f, %f)", anchor2_uwb[0], anchor2_uwb[1], anchor2_uwb[2])
	rospy.loginfo("Anchor3: (%f, %f, %f)", anchor3_uwb[0], anchor3_uwb[1], anchor3_uwb[2])
#-------------------------------------------------------
def main():
	global vicon2uwb
	rospy.init_node('vicon2uwb_tf')

	rospy.loginfo("Initializating vicon2uwb_tf procedure...")

	# subscribing to vrpn publisher
	wand_sub = rospy.Subscriber('/vrpn_client_node/ActiveWandv2OriginTracking/pose', 
		PoseStamped, wand_pose_cb, queue_size=1)

	flag_wand = 1	# to avoid spam warn message
	while wand_pose.pose.position.x == 0:
		if flag_wand == 1:
			flag_wand = 0
			rospy.logwarn('Be sure to have Wand already connected!')

	# getting anchor position
	anchor_ids = [0x6902, 0x6e7a, 0x6e44, 0x6e6c]

	rospy.loginfo("Put wand over anchor0 0x%0.4x (uwb origin) " %anchor_ids[0])
	anchor0 = get_wand_pos() # coordinate in vicon_frame di anchor0 (origine)

	rospy.loginfo("Put wand over anchor1 0x%0.4x (uwb y axis) " %anchor_ids[1])
	anchor1 = get_wand_pos()  # coordinate in vicon_frame di anchor1 (asse y)

	rospy.loginfo("Put wand over anchor2 0x%0.4x (uwb x axis) " %anchor_ids[2])
	anchor2 = get_wand_pos()  # coordinate in vicon_frame di anchor1 (asse x)

	rospy.loginfo("Put wand over anchor3 0x%0.4x (uwb z axis) " %anchor_ids[3])
	anchor3 = get_wand_pos()  # coordinate in vicon_frame di anchor1 (asse z)

	rospy.loginfo("Anchors coordinates succesfully acquired!")
	
	# obtaining trasformation pose (vicon2uwb)
	vicon2uwb.pose.position.x = -anchor0[0]
	vicon2uwb.pose.position.y = -anchor0[1]
	vicon2uwb.pose.position.z = -anchor0[2]

	# supponiamo che ci sia solo la rotazione lungo z tra i due sistemi di riferimento
	offset = np.arctan2(	(anchor1[1] - anchor0[1]), 
	 						(anchor1[0] - anchor0[0]) )

	yaw_uwb = - (np.pi/2 - offset)

	quat = tf.transformations.quaternion_from_euler(yaw_uwb, 0, 0, axes='szyx')
	vicon2uwb.pose.orientation.x = quat[0]
	vicon2uwb.pose.orientation.y = quat[1]
	vicon2uwb.pose.orientation.z = quat[2]
	vicon2uwb.pose.orientation.w = quat[3]


	save_file()	

	rospy.loginfo("Saved file vicon_frame2UWB_tf.txt!")

	# check anchors positions
	check_uwb_frame(anchor0, anchor1, anchor2, anchor3, vicon2uwb)

#-------------------------------------------------------
# main
if __name__ == '__main__':
	try:
		main()
	except rospy.ROSInterruptException:
		pass
