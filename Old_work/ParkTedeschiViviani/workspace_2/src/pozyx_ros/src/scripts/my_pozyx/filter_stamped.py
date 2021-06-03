#!/usr/bin/env python
"""
ROS node that publishes the pose (position + quaternion) of the Pozyx

This is an example of how to combine sensor data and positioning into a single
channel output.

Quite overkill using _Pose, as this consists of 7 float64s, while the source
data comes from integers. Suggestions to replace this are quite welcomed.
"""
import numpy
import pypozyx
import rospy
from geometry_msgs.msg import Point, PoseStamped, Quaternion
import tf
import decimal 
import math


def quaternion_to_euler_angle(w, x, y, z):
	ysqr = y * y

	t0 = +2.0 * (w * x + y * z)
	t1 = +1.0 - 2.0 * (x * x + ysqr)
	X = math.degrees(math.atan2(t0, t1))

	t2 = +2.0 * (w * y - z * x)
	t2 = +1.0 if t2 > +1.0 else t2
	t2 = -1.0 if t2 < -1.0 else t2
	Y = math.degrees(math.asin(t2))

	t3 = +2.0 * (w * z + x * y)
	t4 = +1.0 - 2.0 * (ysqr + z * z)
	Z = math.degrees(math.atan2(t3, t4))

	return X, Y, Z

# my definitions 
from defs import*

# a list for pose records
rec_x = []
rec_y = []
rec_z = []


# number of samples to collect 
n_samples = 10
rcvd_msgs = 0 


pose = PoseStamped()
pose_f = PoseStamped()

def callback(data):
	global rcvd_msgs
	global n_samples
	global pose
	# read incoming message and save into pose
	
	#pose.header.frame_id = UWB_frame_ID
	#pose.header.stamp = rospy.Time.now()
	pose.pose.position.x = data.pose.position.x
	pose.pose.position.y = data.pose.position.y
	pose.pose.position.z = data.pose.position.z
	
	#pose.pose.orientation.x =	data.pose.orientation.x
	#pose.pose.orientation.y =	data.pose.orientation.y
	#pose.pose.orientation.z =	data.pose.orientation.z
	#pose.pose.orientation.w =	data.pose.orientation.w

	
	# DONE AFTER n_samples received messages
   # if received messages are enough, move 1 step forwar the moving window
	#					+-----------+-----------+-----------+-----------+
	#	<--pop(0)--	|				|				|				|				|   <--append--
	#					+-----------+-----------+-----------+-----------+
	#
	# then evaluate the mean
	if rcvd_msgs == n_samples :
		rec_x.append(pose.pose.position.x)
		rec_y.append(pose.pose.position.y)
		rec_z.append(pose.pose.position.z)
		rec_x.pop(0)
		rec_y.pop(0)
		rec_z.pop(0)

		# mean
		pose_f.pose.position.x = sum(rec_x) / len(rec_x)
		pose_f.pose.position.y = sum(rec_y) / len(rec_y)
		pose_f.pose.position.z = sum(rec_z) / len(rec_z)
		
		pose_f.pose.orientation.x =	data.pose.orientation.x
		pose_f.pose.orientation.y =	data.pose.orientation.y
		pose_f.pose.orientation.z =	data.pose.orientation.z
		pose_f.pose.orientation.w =	data.pose.orientation.w
		
		
		pose_f.header.frame_id = UWB_frame_ID
		pose_f.header.stamp = rospy.Time.now()

		
		
		
		
			
	# fullfill the moving window for the first time with n samples
	elif rcvd_msgs < n_samples:
		rec_x.append(pose.pose.position.x)
		rec_y.append(pose.pose.position.y)
		rec_z.append(pose.pose.position.z)
		rcvd_msgs += 1
		rospy.loginfo("collecting samples: %d / %d collected", rcvd_msgs, n_samples)
		if rcvd_msgs == n_samples :
			rospy.loginfo("DONE - starting to publish")
			pose_f.pose.position.x = sum(rec_x) / n_samples
			pose_f.pose.position.y = sum(rec_y) / n_samples
			pose_f.pose.position.z = sum(rec_z) / n_samples


	else:
		print('error')

			

def filter():
	global coords

	rospy.init_node('filter_node')
	#rate = rospy.Rate(100.0)

	filter_sub = rospy.Subscriber(tag0_topic_ID, PoseStamped, callback)
	filter_pub = rospy.Publisher(tag0_topic_ID_f, PoseStamped, queue_size=100)
	
	#pose_pub = rospy.Publisher(robot_pose_topic_ID, Point, queue_size=100)
	
	# tag 1 fake
	
	#tag1_fake_pub = rospy.Publisher(tag1_topic_ID_f, PoseStamped, queue_size=100)
	
	pose = PoseStamped()
	
	while not rospy.is_shutdown():
	
		filter_pub.publish(pose_f)
		
		##############
		
		(tag0_roll,tag0_pitch,tag0_yaw) = quaternion_to_euler_angle(pose_f.pose.orientation.w, pose_f.pose.orientation.x , pose_f.pose.orientation.y, pose_f.pose.orientation.z)
		
		tag0_yaw = numpy.deg2rad(tag0_yaw) 
		
		if (tag0_yaw > 3.1459): 
			tag0_yaw -= 6.2918 

		if (tag0_yaw < -3.1459):
			tag0_yaw += 6.2918
		
		##############
		
		#pose_pub.publish(Point(pose_f.pose.position.x, pose_f.pose.position.y, tag0_yaw))
		
		
		
		# -------------------------- TF --------------------------
		tf_euler = tf.transformations.euler_from_quaternion((pose_f.pose.orientation.x, pose_f.pose.orientation.y, pose_f.pose.orientation.z, pose_f.pose.orientation.w))
		heading = tf_euler[2]
		tf_quat = tf.transformations.quaternion_from_euler(0, 0, heading)
		# publish TF	
		br_0 = tf.TransformBroadcaster()
		br_0.sendTransform((pose_f.pose.position.x, pose_f.pose.position.y, 0),
		tf_quat,
		rospy.Time.now(),
		tag0_frame_ID_f,
		UWB_frame_ID
		)
		
		#tag 1 fake
		#pose_fake = PoseStamped()
		#pose_fake.header.stamp = rospy.Time.now()
		#pose_fake.pose.position.x = pose_f.pose.position.x + 0.5
		#pose_fake.pose.position.y = pose_f.pose.position.y
		#pose_fake.pose.position.z = pose_f.pose.position.x
		
		#pose_fake.pose.orientation.x = pose_f.pose.orientation.x
		#pose_fake.pose.orientation.y = pose_f.pose.orientation.y
		#pose_fake.pose.orientation.z = pose_f.pose.orientation.x
			
		#tag1_fake_pub.publish(pose_fake)
		

		#rate.sleep()
		


if __name__ == '__main__':
    try:
        filter()
    except rospy.ROSInterruptException:
        pass