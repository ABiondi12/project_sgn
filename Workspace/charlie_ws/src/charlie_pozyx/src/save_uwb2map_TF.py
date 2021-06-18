#!/usr/bin/env python
# coding=utf-8
'''
	Questo file si occupa di lanciare un nodo ros che salva in un file.txt la posa del centro della mappa 
	(coincidente con il centro del veicolo fermo prima di avviare l'acquisizione della mappa) rispetto al
	frame UWB. Una volta terminato il salvataggio, interrompe anche il nodo
'''

import pypozyx
import rospy
from geometry_msgs.msg import Point, PoseStamped, Quaternion
import tf
import pandas as pd
from scipy import stats
import matplotlib.pyplot as plt
import numpy as np
import time

from defs import* # my definitions 


# INIT variabili callbacks ------------------------------------------------------------
orientation = Point()

# init 'pose' as a pose stamped msg (all zeros)
pose_0 = PoseStamped()
pose_1 = PoseStamped()
tag_center = PoseStamped()

# a list for pose records for tag 0
pose_rec_0 = []
rcvd_msgs_0 = 0

# a list for pose records for tag 1
pose_rec_1 = []
rcvd_msgs_1 = 0

# number of samples to collect for both tag 0 and 1 
n_samples = 100

remote_id = None

# percorso al file in cui vogliamo salvare la trasformazione
TF_filename = "/home/pi/charlie_ws/src/charlie_pozyx/src/scripts/my_pozyx/UWB2map_TF.txt"
status = 'collecting_data'

# Callbacks ---------------------------------------------------------------------------
def store_msg_callback_0(data):
	global pose_rec_0
	global rcvd_msgs_0
	
	if rcvd_msgs_0 < n_samples :
		pose_rec_0.append(data)		
		rcvd_msgs_0 += 1

def store_msg_callback_1(data):
	global pose_rec_1
	global rcvd_msgs_1
	
	if rcvd_msgs_1 < n_samples :
		pose_rec_1.append(data)		
		rcvd_msgs_1 += 1
			
def orientation_callback(data):
	global orient_stm
	
	orient_stm = data

# eval_frame --------------------------------------------------------------------------s
def eval_frame():
	# init of global variables
	global pose_0
	global pose_rec_0
	global rcvd_msgs_0
	
	global pose_1
	global pose_rec_1
	global rcvd_msgs_1

	global tag_center

	z_limit = 3  # z score limite accettabile

	# check lunghezze	
	if len(pose_rec_0) != n_samples or len(pose_rec_1) != n_samples:
		rospy.loginfo('Error in collecting messages, wrong number.')
		return
	
	#-----------------------------------------------------------------------
	# let's begin proper stuff!!
	rospy.loginfo('Filter outliers in collected data...')
	
	## tag 0
	data=[]
	# calcola la norma due al quadrato di ogni dato
	for i in range(len(pose_rec_0)):
		data.append( pose_rec_0[i].pose.position.x**2 + pose_rec_0[i].pose.position.y**2 + pose_rec_0[i].pose.position.z**2 )

	# identifica gli outlier basandoti sulla norma due al quadrato e salva il loro indice
	df= pd.DataFrame({'data':data})
	df['z_score']=stats.zscore(df['data'])
	indexes = df.loc[df['z_score'].abs()>=z_limit].index 	# prendi gli indici che hanno z-score piu alto di z_limit
	
	# prepara plot sequenza originale
	newdata = np.squeeze(df.data)	
	plt.plot(newdata)
	#plt.show()
	
	# rimuovi gli elementi corrispondenti agli outliers, in base agli indici che hanno avuto z-score troppo alto
	for i in indexes:
		del pose_rec_0[i]
		del data[i]
		
	# prepara plot sequenza filtrata da outliers
	newdata = np.squeeze(data)
	plt.plot(data)
	plt.show()
	
	rospy.loginfo('In tag0 measurements, %d samples has been removed!', rcvd_msgs_0-len(pose_rec_0))
	
	## tag 1
	data=[]
	# calcola la norma due al quadrato di ogni dato
	for i in range (len(pose_rec_1)):
		data.append( pose_rec_1[i].pose.position.x**2 + pose_rec_1[i].pose.position.y**2 + pose_rec_1[i].pose.position.z**2 )
		
	# identifica gli outlier basandoti sulla norma due al quadrato e salva il loro indice
	df= pd.DataFrame({'data':data})
	df['z_score']=stats.zscore(df['data'])
	indexes = df.loc[df['z_score'].abs()>=z_limit].index 
	
	newdata = np.squeeze(df.data)
	plt.plot(newdata)
	
	# rimuovi gli elementi in base agli indici degli outlier
	for i in indexes:
		del pose_rec_1[i]
		del data[i]
		
	newdata = np.squeeze(data)
	plt.plot(data)
	plt.show()
	
	rospy.loginfo('In tag1 measurements, %d samples has been removed!', rcvd_msgs_1-len(pose_rec_1) )

	
	#------------------------------------------------------------------------	
	# Calcolo media delle pose dei due tag
	# sum all vectors di tag0
	for i in range(len(pose_rec_0)):
		pose_0.pose.position.x += pose_rec_0[i].pose.position.x
		pose_0.pose.position.y += pose_rec_0[i].pose.position.y
		pose_0.pose.position.z += pose_rec_0[i].pose.position.z

		pose_0.pose.orientation.x += pose_rec_0[i].pose.orientation.x
		pose_0.pose.orientation.y += pose_rec_0[i].pose.orientation.y
		pose_0.pose.orientation.z += pose_rec_0[i].pose.orientation.z
		pose_0.pose.orientation.w += pose_rec_0[i].pose.orientation.w

	# evaluate mean value di tag0
	pose_0.pose.position.x /=  len(pose_rec_0)
	pose_0.pose.position.y /=  len(pose_rec_0)
	pose_0.pose.position.z /=  len(pose_rec_0)
	
	pose_0.pose.orientation.x /= len(pose_rec_0)
	pose_0.pose.orientation.y /= len(pose_rec_0)
	pose_0.pose.orientation.z /= len(pose_rec_0)
	pose_0.pose.orientation.w /= len(pose_rec_0) # not sure if legit (si spera stia fermo!)

	# sum all vectors di tag1
	for i in range(len(pose_rec_1)):
		pose_1.pose.position.x += pose_rec_1[i].pose.position.x
		pose_1.pose.position.y += pose_rec_1[i].pose.position.y
		pose_1.pose.position.z += pose_rec_1[i].pose.position.z

		pose_1.pose.orientation.x += pose_rec_1[i].pose.orientation.x
		pose_1.pose.orientation.y += pose_rec_1[i].pose.orientation.y
		pose_1.pose.orientation.z += pose_rec_1[i].pose.orientation.z
		pose_1.pose.orientation.w += pose_rec_1[i].pose.orientation.w

	# evaluate mean value di tag1
	pose_1.pose.position.x /=  len(pose_rec_1)
	pose_1.pose.position.y /=  len(pose_rec_1)
	pose_1.pose.position.z /=  len(pose_rec_1)
	
	pose_1.pose.orientation.x /= len(pose_rec_1)
	pose_1.pose.orientation.y /= len(pose_rec_1)
	pose_1.pose.orientation.z /= len(pose_rec_1)
	pose_1.pose.orientation.w /= len(pose_rec_1) # not sure if legit

	#------------------------------------------------------------------------	
	# evaluate center position between tags 
	tag_center.pose.position.x =  (pose_0.pose.position.x + pose_1.pose.position.x) * 0.5
	tag_center.pose.position.y =  (pose_0.pose.position.y + pose_1.pose.position.y) * 0.5
	tag_center.pose.position.z =  0 #(pose_0.pose.position.z + pose_1.pose.position.z) * 0.5
	
	# heading = np.arctan2(	(pose_0.pose.position.y - pose_1.pose.position.y), 
	# 						(pose_0.pose.position.x - pose_1.pose.position.x))  # volendo bypassare stm

	heading = -(orient_stm.z)	#correzione z-down a z-up 
	lidar_quat = tf.transformations.quaternion_from_euler(heading, 0, 0, axes='szyx')
	
	tag_center.pose.orientation.x = lidar_quat[0]
	tag_center.pose.orientation.y = lidar_quat[1]
	tag_center.pose.orientation.z = lidar_quat[2]
	tag_center.pose.orientation.w = lidar_quat[3]


# save_map_TF -------------------------------------------------------------------------
def save_map_TF():
	global rcvd_msgs_0
	global n_samples
	global pose_0
	global rcvd_msgs_1
	global n_samples
	global pose_1
	global status	
	global tag_center
	global TF_filename

	rospy.init_node('uwb_map_TF')

	# subscribe to uwb tag pose topic
	tag_0_sub = rospy.Subscriber(tag0_topic_ID, PoseStamped, store_msg_callback_0, queue_size=100)
	tag_1_sub = rospy.Subscriber(tag1_topic_ID, PoseStamped, store_msg_callback_1, queue_size=100)
	orie_sub  = rospy.Subscriber('orientation', Point, orientation_callback, queue_size=100)

	
	while not rospy.is_shutdown():
		if status == 'done' :
					
			#br = tf.TransformBroadcaster()
			#br.sendTransform((tag_center.pose.position.x,tag_center.pose.position.y,0.),
			#(tag_center.pose.orientation.x,tag_center.pose.orientation.y,tag_center.pose.orientation.z, tag_center.pose.orientation.w), 
			#rospy.Time.now(),
			#map_frame_ID,
			#UWB_frame_ID)
			
			#rospy.loginfo('publishing TF %s -> %s', UWB_frame_ID, map_frame_ID)
			rospy.loginfo('Saved TF from %s to %s in %s ', UWB_frame_ID, map_frame_ID, TF_filename)
			rospy.loginfo('Shutting down node...')
			
			break

		elif status == 'collecting_data' and rcvd_msgs_0 == n_samples and rcvd_msgs_1 == n_samples :
			rospy.loginfo('data collection terminated... \n\t TAG_0: %d / %d samples collected \n\t TAG_1: %d / %d samples collected', rcvd_msgs_0, n_samples, rcvd_msgs_1, n_samples, )
			rospy.loginfo('evaluating TF: %s -> %s', UWB_frame_ID, odom_frame_ID)
			
			# unsubscribe to stop listening (and appending) samples
			tag_0_sub.unregister()
			tag_1_sub.unregister()

			# prima di salvare, attendi per sicurezza almeno il tempo di convergenza del filtro AHRS implemetato su STM
			rospy.loginfo('waiting for yaw to settle ... (35s)')
			time.sleep(35)	
			rospy.loginfo('done')
			orie_sub.unregister()	
			
			# valuta posa
			eval_frame()

			# Scrittura file.txt
			f = open(TF_filename,"w+") # accedi al file in scrittura
			f.write("%f\r\n" %float(tag_center.pose.position.x))
			f.write("%f\r\n" %float(tag_center.pose.position.y))
			f.write("%f\r\n" %float(tag_center.pose.position.z))
			
			f.write("%f\r\n" %float(tag_center.pose.orientation.x))
			f.write("%f\r\n" %float(tag_center.pose.orientation.y))
			f.write("%f\r\n" %float(tag_center.pose.orientation.z))			
			f.write("%f\r\n" %float(tag_center.pose.orientation.w))	
			f.close()

			# inform that frame setup is complete
			status = 'done'
	
		else:
			rospy.loginfo('collecting data... \n\t TAG_0: %d / %d samples collected \n\t TAG_1: %d / %d samples collected', rcvd_msgs_0, n_samples, rcvd_msgs_1, n_samples, )

#--------------------------------------------------------------------------
# main
if __name__ == '__main__':
	try:
		save_map_TF()
	except rospy.ROSInterruptException:
		pass