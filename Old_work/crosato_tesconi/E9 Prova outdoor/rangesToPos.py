import math
from pypozyx import (DeviceCoordinates, Coordinates)

def rangesToPos ( R_mis, anchor_ids, z=0 ):
	print("\nDistances between the anchors, fitted with ransac algorithm: \n [r01,r02,r03,r12,r13,r23] =", R_mis)
	print()
	for r in R_mis:
		if r<0 :
			raise Exception("Negative distance inserted '\n'")
			return
	r01 = R_mis[0]
	r02 = R_mis[1]
	r03 = R_mis[2]
	r12 = R_mis[3]
	r13 = R_mis[4]
	r23 = R_mis[5]
    
	C = (r01**2+r02**2-r12**2)/(2*r01*r02)
    
	if abs(C) <= 1:
		y1 = r01;
		y2 = (r01**2 - r12**2 + r02**2)/ (2*r01)
		aux1 = r02**2 - y2**2
		
		if aux1 < 0:
			raise Exception("Too much noise in the measurements, uncompatible distances, x2")
			return
			
		x2 = math.sqrt(r02**2 - y2**2)
		y3 = (r03**2 - r13**2 + y1**2)/(2*y1)
		x3 = (x2**2 - 2*y3*y2 + y2**2 - r23**2 + r03**2)/(2*x2)
		
		aux2 = r03**2 - x3**2 - y3**2
		if aux2 < 0:
			# Patch fatta il 19/09/2018
			# raise Exception("Too much noise in the measurements, uncompatible distances, z3")
			z3 = 2099-875
		else:
			z3 = math.sqrt(r03**2 - x3**2 - y3**2)
		
		y1 = int(y1)
		x2 = int(x2)
		y2 = int(y2)
		x3 = int(x3)
		y3 = int(y3)
		z3 = int(z3)
		    	
		anchors = [DeviceCoordinates(anchor_ids[0], 1, Coordinates(0, 0, 0)),
               DeviceCoordinates(anchor_ids[1], 1, Coordinates(0, y1, 0)),
               DeviceCoordinates(anchor_ids[2], 1, Coordinates(x2, y2, 0)),
               DeviceCoordinates(anchor_ids[3], 1, Coordinates(x3, y3, z3))]	
		return anchors				
	else:
		raise Exception("Uncompatible distances, autocalibration failed")
		return
    	
	
    
def average(x):
	av = 0
	if len(x) == 0:
		raise Exception("Trying to average an empty list")
	for i in list(range(len(x))):
		av = av + x[i]
	av = av / len(x)
	return av


    
