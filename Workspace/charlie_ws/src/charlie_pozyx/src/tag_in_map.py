#!/usr/bin/env python
'''
	Questo nodo si iscrive ai topic delle tag (UWB) ed al topic di orientazione (dell'STM) proveniente dalla seriale;
	legge il file "UWB2map_TF.txt" da cui ricava la roto-traslazione tra i frame UWB e map, dopodiche'
	calcola la posa del punto centrale tra le due tag in coordinate map e la pubblica assieme ad una TF
'''
import pypozyx
from pypozyx.definitions.constants import POZYX_ANCHOR_SEL_AUTO
import rospy
import numpy as np
from math import *
from geometry_msgs.msg import Point, PoseStamped, Quaternion, PoseWithCovarianceStamped
import tf
import sys

from defs import *

#-------------------------------------------------
# init variabili
tag0_pose 	= PoseStamped()
tag1_pose 	= PoseStamped()
map_pose 	= PoseStamped()
map_yaw 	= 0.0

orient = Point()

#-------------------------------------------------
# definizioni callbacks per subscriber
def tag0_cb(data):
    global tag0_pose
    tag0_pose = data
    
def tag1_cb(data):
    global tag1_pose
    tag1_pose = data
      
def orient_cb(data):
    global orient
    orient = data

#-------------------------------------------------
# trasforma da frame UWB a frame map	
def UWB2map(data):
		global map_pose
		global map_yaw
		
		new_pose = PoseStamped()
		new_pose.header.frame_id = map_frame_ID
		
		# ricava gli angoli di eulero della mappa rispetto al sistema UWB
		map_angles = tf.transformations.euler_from_quaternion(
						[map_pose.pose.orientation.x, map_pose.pose.orientation.y, 
						 map_pose.pose.orientation.z, map_pose.pose.orientation.w])
		map_yaw = map_angles[2] #seleziona la componente di rotazione verticale (asse z, verso l'alto)
		
		# ricava gli angoli di eulero della tag rispetto al sistema UWB
		tag_angles = tf.transformations.euler_from_quaternion([data.pose.orientation.x, data.pose.orientation.y, data.pose.orientation.z, data.pose.orientation.w])
		tag_yaw = tag_angles[2]
		
		# matrice di rotazione da UWB a MAP 
		# descrive il passaggio di coordinate da MAP a UWB 
		#	cos(th) -sin(th)		 
		#	sin(th)  cos(th)			th = angolo da UWB a MAP
		#
		#	dato che voglio portare le coordinate da UWB a MAP devo usare la trasposta
		#	
		#	 cos(th) +sin(th)		 
		#	-sin(th)  cos(th)			th = angolo da UWB a MAP
		
		
		# prima trasla poi ruota, porta i dati della tag da coordinate uwb in coordinate map
		new_pose.pose.position.x = cos(map_yaw) * (data.pose.position.x - map_pose.pose.position.x) + sin(map_yaw) * (data.pose.position.y - map_pose.pose.position.y)
		new_pose.pose.position.y = -sin(map_yaw) * (data.pose.position.x - map_pose.pose.position.x) + cos(map_yaw) * (data.pose.position.y - map_pose.pose.position.y)
		new_pose.pose.position.z = 0.0 #(data.pose.position.z - map_pose.pose.position.z)
		
		# ruota
		new_pose.pose.orientation = tf.transformations.quaternion_from_euler(0.0, 0.0, tag_yaw - map_yaw)
		 
		return new_pose
				
tag_center_UWB	= PoseStamped() 	# init of tag_center pose in UWB frame
tag_center 		= PoseStamped()		# init of tag_center pose in MAP frame

def pozyx_tag_center_pub():
	# variabili globali
	global tag0_pose
	global tag1_pose
	global tag_center
	global tag_center_UWB

	# subscribers
	sub_tag_0 = rospy.Subscriber(tag0_topic_ID_f, 	PoseStamped, 	tag0_cb)
	sub_tag_1 = rospy.Subscriber(tag1_topic_ID_f, 	PoseStamped, 	tag1_cb)
	sub_orien = rospy.Subscriber("orientation", 	Point, 			orient_cb)
	
	# publishers
	pub = rospy.Publisher(tag_in_map_topic_ID, PoseStamped, queue_size=100)
	
	# init nodo
	rospy.init_node('map_center')
	rate = rospy.Rate(50)	
	rospy.loginfo('reading file for TF %s -> %s', UWB_frame_ID, map_frame_ID)

	# Lettura file contenente UWB2MAP
	# MODIFICARE CON IL FILEPATH GIUSTO!! CONTROLLARE SAVE_MAP_ORIGIN
	f = open("/home/pi/charlie_ws/src/charlie_pozyx/src/scripts/my_pozyx/UWB2map_TF.txt","r") # accedi al file in lettura
	# map_pose conterra' i dati della tf tra UWB e mappa
	map_pose.pose.position.x = float(f.readline()[:-2])
	rospy.loginfo('x: %f',map_pose.pose.position.x)
	map_pose.pose.position.y = float(f.readline()[:-2])
	rospy.loginfo('y: %f',map_pose.pose.position.y)
	map_pose.pose.position.z = float(f.readline()[:-2])
	rospy.loginfo('z: %f',map_pose.pose.position.z)
	map_pose.pose.orientation.x = float(f.readline()[:-2])
	rospy.loginfo('orien.x: %f',map_pose.pose.orientation.x)
	map_pose.pose.orientation.y = float(f.readline()[:-2])
	rospy.loginfo('orien.y: %f',map_pose.pose.orientation.y)
	map_pose.pose.orientation.z = float(f.readline()[:-2])
	rospy.loginfo('orien.z: %f',map_pose.pose.orientation.z)
	map_pose.pose.orientation.w = float(f.readline()[:-2])
	rospy.loginfo('orien.w: %f',map_pose.pose.orientation.w)
	f.close()

	rospy.loginfo('reading file for TF %s -> %s DONE', UWB_frame_ID, map_frame_ID)

	# init broadcaster
	tf_UWB_map = tf.TransformBroadcaster()
	
	# while
	while not rospy.is_shutdown():

		# send "static" transform
		tf_UWB_map.sendTransform(
			(map_pose.pose.position.x,map_pose.pose.position.y, 0.),
			(map_pose.pose.orientation.x,map_pose.pose.orientation.y,
				map_pose.pose.orientation.z, map_pose.pose.orientation.w), 
			rospy.Time.now(),
			map_frame_ID,
			UWB_frame_ID
			)	
		

		# # porta le coordinate dei tag nel frame map
		# tag_0_map = UWB2map(tag0_pose)
		# tag_1_map = UWB2map(tag1_pose)
		
		# prendi la media tra le posizioni delle tag come positione del laser data dal sistema UWB 
		# tag_center.pose.position.x = ( tag_0_map.pose.position.x + tag_1_map.pose.position.x ) / 2.0
		# tag_center.pose.position.y = ( tag_0_map.pose.position.y + tag_1_map.pose.position.y ) / 2.0
		tag_center_UWB.pose.position.x = ( tag0_pose.pose.position.x + tag1_pose.pose.position.x) / 2.0
		tag_center_UWB.pose.position.y = ( tag0_pose.pose.position.y + tag1_pose.pose.position.y) / 2.0
		
		# tag center in map
		temp_pose = UWB2map(tag_center_UWB) # salviamo la posa in una variabile temporanea
		
		# orientazione dei tag bypassata, si usa lo yaw proveniente da Icaro (STM)
		theta = -orient.z - map_yaw	#STM in z-down, viene convertito in z-up
		z_quat = tf.transformations.quaternion_from_euler(0, 0, theta)
		tag_center.pose.orientation.x = z_quat[0]
		tag_center.pose.orientation.y = z_quat[1]
		tag_center.pose.orientation.z = z_quat[2]
		tag_center.pose.orientation.w = z_quat[3]
		
		# correzione offset legato al montaggio laterale delle tag rispetto al lidar
		offset_montaggio_tag = 0.125
		offset_montaggio_tagx = offset_montaggio_tag * sin(theta)
		offset_montaggio_tagy = -offset_montaggio_tag * cos(theta)

		# assegnazione posizione
		tag_center.pose.position.x = temp_pose.pose.position.x + offset_montaggio_tagx
		tag_center.pose.position.y = temp_pose.pose.position.y + offset_montaggio_tagy
		tag_center.pose.position.z = 0		# always zero

		# send to broadcaster
		br = tf.TransformBroadcaster()
		br.sendTransform((tag_center.pose.position.x, tag_center.pose.position.y, 0.00),
			[tag_center.pose.orientation.x, tag_center.pose.orientation.y, 
			 tag_center.pose.orientation.z, tag_center.pose.orientation.w], 
			rospy.Time.now(),
			tag_in_map_frame_ID,
			map_frame_ID)

		# publisher
		pub.publish(tag_center)
		#rospy.loginfo('Publishing TF and pose from %s -> %s', map_frame_ID, tag_in_map_frame_ID);
		
		# sleep
		rate.sleep()	

#-------------------------------------------------
# main
if __name__ == '__main__':
    try:
        pozyx_tag_center_pub()
    except rospy.ROSInterruptException:
        pass
