#!/usr/bin/env python

import pypozyx as pp
import tf
import rospy


def anchors_tf():

	# init rate
	rate = rospy.Rate(0.1)

	# init serial communication with one tag
	anchor_ids = [0x6902, 0x6e7a, 0x6e44, 0x6e6c]	# anchor id

	serial_port = pp.get_first_pozyx_serial_port()
	if serial_port is None:
		raise Exception("No Pozyx connected. Check your USB cable or your driver")
		quit()
	print("Pozyx device found in port: ", serial_port, '\n')
	pozyx = pp.PozyxSerial(serial_port)


	#---------------------------------------------------------------------------
	#connect to anchors
	# anchor0
	anchor0 = anchor_ids[0]
	coordinates0 = pp.Coordinates()
	status0 = pozyx.getDeviceCoordinates(anchor0, coordinates0, anchor0)

	# anchor1
	anchor1 = anchor_ids[1]
	coordinates1 = pp.Coordinates()
	status1 = pozyx.getDeviceCoordinates(anchor1, coordinates1, anchor1)

	# anchor2
	anchor2 = anchor_ids[2]
	coordinates2 = pp.Coordinates()
	status2 = pozyx.getDeviceCoordinates(anchor2, coordinates2, anchor2)

	# anchor3
	anchor3 = anchor_ids[3]
	coordinates3 = pp.Coordinates()
	status3 = pozyx.getDeviceCoordinates(anchor3, coordinates3, anchor3)

	if status0 != pp.POZYX_SUCCESS or status1 != pp.POZYX_SUCCESS or status2 != pp.POZYX_SUCCESS or status3 != pp.POZYX_SUCCESS:
		rospy.loginfo("Device communication failed, check connections!")
		quit()
	else:
			
		print("anchor0 (origin), with id", hex(anchor0), "has coordinates: X:", float(coordinates0.x)/1000, "Y:", float(coordinates0.y)/1000, "Z:", float(coordinates0.z)/1000)
		print("anchor1 (y axis), with id", hex(anchor1), "has coordinates: X:", float(coordinates1.x)/1000, "Y:", float(coordinates1.y)/1000, "Z:", float(coordinates1.z)/1000)
		print("anchor2 (x axis), with id", hex(anchor2), "has coordinates: X:", float(coordinates2.x)/1000, "Y:", float(coordinates2.y)/1000, "Z:", float(coordinates2.z)/1000)
		print("anchor3 (z axis), with id", hex(anchor3), "has coordinates: X:", float(coordinates3.x)/1000, "Y:", float(coordinates3.y)/1000, "Z:", float(coordinates3.z)/1000)



	#---------------------------------------------------------------------------
	# while
	while not rospy.is_shutdown():
		#anchor 0
		br_0 = tf.TransformBroadcaster() #init broadcaster
		br_0.sendTransform(
			(float(coordinates0.x)/1000.0, float(coordinates0.y)/1000, float(coordinates0.z)/1000), 	# posizione
			(0, 0, 0, 1),			# orientazione
			rospy.Time.now(),		# tempo
			'uwb_anchor_0',			# child sdr
			'UWB'					# parent sdr
		)
		#anchor 1
		br_1 = tf.TransformBroadcaster() #init broadcaster
		br_1.sendTransform(
			(float(coordinates1.x)/1000, float(coordinates1.y)/1000, float(coordinates1.z)/1000), 	# posizione
			(0, 0, 0, 1),			# orientazione
			rospy.Time.now(),		# tempo
			'uwb_anchor_1',			# child sdr
			'UWB'					# parent sdr
		)
		#anchor 2
		br_2 = tf.TransformBroadcaster() #init broadcaster
		br_2.sendTransform(
			(float(coordinates2.x)/1000, float(coordinates2.y)/1000, float(coordinates2.z)/1000), 	# posizione
			(0, 0, 0, 1),			# orientazione
			rospy.Time.now(),		# tempo
			'uwb_anchor_2',			# child sdr
			'UWB'					# parent sdr
		)
		#anchor 3
		br_3 = tf.TransformBroadcaster() #init broadcaster
		br_3.sendTransform(
			(float(coordinates3.x)/1000, float(coordinates3.y)/1000, float(coordinates3.z)/1000), 	# posizione
			(0, 0, 0, 1),			# orientazione
			rospy.Time.now(),		# tempo
			'uwb_anchor_3',			# child sdr
			'UWB'					# parent sdr
		)

		rate.sleep()


if __name__ == '__main__':

	rospy.init_node('pub_anchors_tf')

	try:
		anchors_tf()
	except rospy.ROSInterruptException:
		pass
