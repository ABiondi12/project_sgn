#!/usr/bin/env python
"""
FAMMI
"""
import numpy
import pypozyx
import rospy
from geometry_msgs.msg import Point, PoseStamped, Quaternion
import tf
import decimal 

# my definitions 
from defs import*


rviz_goal	= PoseStamped()	# init per il waypoint pubblicato da rviz
stm_wayp 	= Point()		# init per il punto da far trasmettere in seriale (x,y,yaw)

def rviz_goal_cb(data):
    global rviz_goal
    rviz_goal = data

def move2waypoint():
	global rviz_goal
	global stm_wayp

	rospy.init_node('navgoal')
	rate = rospy.Rate(100.0)

	rviz_goal_sub = rospy.Subscriber("move_base_simple/goal", PoseStamped, rviz_goal_cb)
	stm_wayp_pub = rospy.Publisher("waypoint_publisher", Point, queue_size=1)
	
	while not rospy.is_shutdown():

		# estrai x,y
		x_wayp = rviz_goal.pose.position.x
		y_wayp = rviz_goal.pose.position.y

		# estrai euler angles
		euler_wayp = tf.transformations.euler_from_quaternion(
			(rviz_goal.pose.orientation.x, rviz_goal.pose.orientation.y, 
			rviz_goal.pose.orientation.z, rviz_goal.pose.orientation.w)
			)
		yaw_wayp = euler_wayp[2]

		stm_wayp.x = x_wayp
		stm_wayp.y = y_wayp
		stm_wayp.z = yaw_wayp

		# publish	
		stm_wayp_pub.publish(stm_wayp)
			

		rate.sleep()
		

if __name__ == '__main__':
	try:
		move2waypoint()
	except rospy.ROSInterruptException:
		pass
