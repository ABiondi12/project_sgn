#!/usr/bin/env python
# coding=utf-8

	# Questo nodo si occupa di:
	# 	- leggere dal topic del sistema vicon /vrpn_client_node/Charlie/pose la posa di Charlie 
	# 	- pubblicare su un topic la trasformazione da charlie_vicon a uwb 
	# 	- broadcast la tf da vicon_frame a uwb (per visualizzazione grafica su rviz)



import numpy as np
import rospy
from geometry_msgs.msg import Point, PoseStamped
import tf
import time

#-------------------------------------------------------
# init global variables
charlie_vicon_pose = PoseStamped()

#-------------------------------------------------------
def charlie_vicon_pose_cb(data):
	global charlie_vicon_pose
	charlie_vicon_pose = data	

#-------------------------------------------------------
def read_file(path):
	'''
		legge dal file specificato e crea la "posa" del frame vicon in coordinate uwb
	'''
	vicon2uwb = PoseStamped()

	rospy.loginfo('reading file for TF %s -> %s', "vicon_frame", "UWB")
	# Lettura file contenente vicon_frame2UWB
	# MODIFICARE CON IL FILEPATH GIUSTO!! CONTROLLARE vicon2uwb_tf
	f = open(path,"r") # accedi al file in lettura
	# map_pose conterra' i dati della tf tra UWB e mappa
	vicon2uwb.pose.position.x = float(f.readline()[:-2])
	rospy.loginfo('x: %f',vicon2uwb.pose.position.x)
	vicon2uwb.pose.position.y = float(f.readline()[:-2])
	rospy.loginfo('y: %f',vicon2uwb.pose.position.y)
	vicon2uwb.pose.position.z = float(f.readline()[:-2])
	rospy.loginfo('z: %f',vicon2uwb.pose.position.z)
	vicon2uwb.pose.orientation.x = float(f.readline()[:-2])
	rospy.loginfo('orien.x: %f',vicon2uwb.pose.orientation.x)
	vicon2uwb.pose.orientation.y = float(f.readline()[:-2])
	rospy.loginfo('orien.y: %f',vicon2uwb.pose.orientation.y)
	vicon2uwb.pose.orientation.z = float(f.readline()[:-2])
	rospy.loginfo('orien.z: %f',vicon2uwb.pose.orientation.z)
	vicon2uwb.pose.orientation.w = float(f.readline()[:-2])
	rospy.loginfo('orien.w: %f',vicon2uwb.pose.orientation.w)
	f.close()
	return vicon2uwb

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
def main():
	global charlie_vicon_pose

	# init node
	rospy.init_node('charlie_vicon2map')
	rate = rospy.Rate(50)

	rospy.loginfo("Initializating charlie_vicon2map procedure...")

	# percorso al file da cui vogliamo leggere la trasformazione
	TF_filename = "/home/francesco/catkin_ws/src/charlie_remote/src/vicon_frame2UWB_tf.txt"
	vicon2uwb = read_file(TF_filename)	
	
	# subscribers
	sub_charlie_vicon = rospy.Subscriber("/vrpn_client_node/Charlie/pose", 	
											PoseStamped, 	charlie_vicon_pose_cb)
	
	# publishers
	# charlie_vicon_map e` la posa letta dal sistema vicon espressa in frame map
	pub_charlie_map = rospy.Publisher("charlie_vicon_map", PoseStamped, queue_size=100)
				
	# init broadcaster
	tf_vicon2uwb = tf.TransformBroadcaster()

	tf_tl = tf.TransformListener()

	antispam = 0 # flag per evitare di spammare di loginfo, si resetta se non trova tf

	while not rospy.is_shutdown():

		# send "static" transform
		tf_vicon2uwb.sendTransform(
			(vicon2uwb.pose.position.x,vicon2uwb.pose.position.y, vicon2uwb.pose.position.z),
			(vicon2uwb.pose.orientation.x,vicon2uwb.pose.orientation.y,
				vicon2uwb.pose.orientation.z, vicon2uwb.pose.orientation.w), 
			rospy.Time.now(),
			'UWB',			# child
			'vicon_frame'	# parent
			)


		# get transformation from map to Charlie and publishes it
		try:
			p, q = tf_tl.lookupTransform("UWB", "Charlie", rospy.Time(0))
			
			# preparazione del messaggio
			charlie_vicon_pose = PoseStamped()

			# header
			charlie_vicon_pose.header.frame_id = 'UWB'
			charlie_vicon_pose.header.stamp = rospy.Time.now()
			# posizioni
			charlie_vicon_pose.pose.position.x = p[0] 
			charlie_vicon_pose.pose.position.y = p[1]
			charlie_vicon_pose.pose.position.z = 0 #p[2]
			# quaternioni
			charlie_vicon_pose.pose.orientation.x = q[0]
			charlie_vicon_pose.pose.orientation.y = q[1]
			charlie_vicon_pose.pose.orientation.z = q[2]
			charlie_vicon_pose.pose.orientation.w = q[3]

			# Pubblico sul rispettivo topic
			pub_charlie_map.publish(charlie_vicon_pose)

			if antispam == 0:
				antispam = 1
				rospy.loginfo("Started publishing Charlie_vicon_UWB!")
			
		except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
			rospy.logwarn("No Charlie_vicon_uwb published")
			antispam = 0 # reset antispam
			continue

		# end of while cycle
		rate.sleep()




#-------------------------------------------------------
# main
if __name__ == '__main__':
	try:
		main()
	except rospy.ROSInterruptException:
		pass