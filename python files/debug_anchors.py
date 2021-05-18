import pypozyx as pp
import time
# import numpy as np

def anchors_tf():

	# init rate

	# init serial communication with one tag
	# serial_id = 0x675d 	# tag id (should not be needed)
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
	status0 = pozyx.getDeviceCoordinates(anchor0, coordinates0, None)

	# anchor1
	anchor1 = anchor_ids[1]
	coordinates1 = pp.Coordinates()
	status1 = pozyx.getDeviceCoordinates(anchor1, coordinates1, None)

	# anchor2
	anchor2 = anchor_ids[2]
	coordinates2 = pp.Coordinates()
	status2 = pozyx.getDeviceCoordinates(anchor2, coordinates2, None)

	# anchor3
	anchor3 = anchor_ids[3]
	coordinates3 = pp.Coordinates()
	status3 = pozyx.getDeviceCoordinates(anchor3, coordinates3, None)

	if status0 != pp.POZYX_SUCCESS or status1 != pp.POZYX_SUCCESS or status2 != pp.POZYX_SUCCESS or status3 != pp.POZYX_SUCCESS:
		print("Failed trying to obtain the anchors' coordinates saved on the tag")
		# quit()
	else:
		print("anchor0 (origin), with id", hex(anchor0), "has coordinates: X:", coordinates0.x, "Y:", coordinates0.y, "Z:", coordinates0.z)
		print("anchor1 (y axis), with id", hex(anchor1), "has coordinates: X:", coordinates1.x, "Y:", coordinates1.y, "Z:", coordinates1.z)
		print("anchor2 (x axis), with id", hex(anchor2), "has coordinates: X:", coordinates2.x, "Y:", coordinates2.y, "Z:", coordinates2.z)
		print("anchor3 (z axis), with id", hex(anchor3), "has coordinates: X:", coordinates3.x, "Y:", coordinates3.y, "Z:", coordinates3.z)


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
		print("Failed trying to obtain the anchors' coordinates saved on the anchors")
		quit()
	else:
		print("anchor0 (origin), with id", hex(anchor0), "has coordinates: X:", float(coordinates0.x)/1000, "Y:", float(coordinates0.y)/1000, "Z:", float(coordinates0.z)/1000)
		print("anchor1 (y axis), with id", hex(anchor1), "has coordinates: X:", float(coordinates1.x)/1000, "Y:", float(coordinates1.y)/1000, "Z:", float(coordinates1.z)/1000)
		print("anchor2 (x axis), with id", hex(anchor2), "has coordinates: X:", float(coordinates2.x)/1000, "Y:", float(coordinates2.y)/1000, "Z:", float(coordinates2.z)/1000)
		print("anchor3 (z axis), with id", hex(anchor3), "has coordinates: X:", float(coordinates3.x)/1000, "Y:", float(coordinates3.y)/1000, "Z:", float(coordinates3.z)/1000)

	while 1:
		aa = pp.Coordinates()
		bb = pp.Coordinates()
		
		status0_a = pozyx.doPositioning(aa, pp.POZYX_3D)
		time.sleep(0.1)
		status0_b = pozyx.doPositioning(bb, pp.POZYX_3D, remote_id=0x675d)
		if status0_a == pp.POZYX_SUCCESS and status0_b == pp.POZYX_SUCCESS:
			print("without remote_ID tag0:", aa)
			print("with    remote_ID tag1:", bb)
		else:
			print("error")
		time.sleep(0.5)

if __name__ == '__main__':
	try:
		anchors_tf()
	except:
		pass


