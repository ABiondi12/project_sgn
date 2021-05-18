#!/usr/bin/env python
"""
The Pozyx ready to range tutorial (c) Pozyx Labs
Please read the tutorial that accompanies this sketch: https://www.pozyx.io/Documentation/Tutorials/ready_to_range/Python

This demo requires two Pozyx devices. It demonstrates the ranging capabilities and the functionality to
to remotely control a Pozyx device. Move around with the other Pozyx device.

This demo measures the range between the two devices. The closer the devices are to each other, the more LEDs will
light up on both devices.
"""
from pypozyx import (PozyxSerial, POZYX_RANGE_PROTOCOL_FAST, POZYX_RANGE_PROTOCOL_PRECISION,
                     SingleRegister, DeviceRange, POZYX_SUCCESS, POZYX_FAILURE, get_first_pozyx_serial_port, PozyxConstants, Coordinates)
import os.path   


class ReadyToRange(object):
    """Continuously performs ranging between the Pozyx and a destination and sets their LEDs"""

    def __init__(self, pozyx, destination_id, range_step_mm=1000, protocol=POZYX_RANGE_PROTOCOL_FAST, remote_id=None):
        self.pozyx = pozyx
        self.destination_id = destination_id
        self.range_step_mm = range_step_mm
        self.remote_id = remote_id
        self.protocol = protocol 

    def setup(self):
        """Sets up both the ranging and destination Pozyx's LED configuration"""
        print("------------POZYX RANGING V1.1 -------------")
        print("NOTES: ")
        print(" - Change the parameters: ")
        print("\tdestination_id(target device)")
        print("\trange_step(mm)")
        print()
        print("- Approach target device to see range and")
        print("led control")
        print()
        self.pozyx.printDeviceInfo(self.remote_id)
        print()
        print("- -----------POZYX RANGING V1.1 ------------")
        print()
        print("START Ranging: ")

        # make sure the local/remote pozyx system has no control over the LEDs.
        led_config = 0x0
        self.pozyx.setLedConfig(led_config, self.remote_id)
        # do the same for the destination.
        self.pozyx.setLedConfig(led_config, self.destination_id)
        # set the ranging protocol
        self.pozyx.setRangingProtocol(self.protocol, self.remote_id)

    def ledControl(self, distance):
        """Sets LEDs according to the distance between two devices"""
        status = POZYX_SUCCESS
        ids = [self.remote_id, self.destination_id]
        # set the leds of both local/remote and destination pozyx device
        for id in ids:
            status &= self.pozyx.setLed(4, (distance < range_step_mm), id)
            status &= self.pozyx.setLed(3, (distance < 2 * range_step_mm), id)
            status &= self.pozyx.setLed(2, (distance < 3 * range_step_mm), id)
            status &= self.pozyx.setLed(1, (distance < 4 * range_step_mm), id)
        return status


if __name__ == "__main__":
    # hardcoded way to assign a serial port of the Pozyx
    serial_port = 'COM12'

    # the easier way
    serial_port = get_first_pozyx_serial_port()
    if serial_port is None:
        print("No Pozyx connected. Check your USB cable or your driver!")
        quit()
    
    anchor_id1 = 0x6e7a
    anchor_id2 = 0x6e44
    anchor_id3 = 0x6934
    anchor_id4 = 0x6e1d
    
    anchor_id1_str  = '0x6e7a'
    anchor_id2_str  = '0x6e44'
    anchor_id3_str  = '0x6934'
    anchor_id4_str  = '0x6e1d'
    
    anchors = [anchor_id1, anchor_id2, anchor_id3, anchor_id4]
    
    dimension = PozyxConstants.DIMENSION_2_5D
    
    num_measurements = 50
   
    remote_id = 0x6e7e
    remote = False      # whether to use the given remote device for ranging
    if not remote:
        remote_id = None

   #   range_step_mm = 1000

   #   ranging_protocol = POZYX_RANGE_PROTOCOL_PRECISION   # the ranging protocol

    pozyx = PozyxSerial(serial_port)
    pozyx.doAnchorCalibration(dimension, num_measurements, anchors)
    coordinates = Coordinates()
    pozyx.getDeviceCoordinates(anchor_id1, coordinates)
    print(anchor_id1_str+'\t'+str(coordinates))
    pozyx.getDeviceCoordinates(anchor_id2, coordinates)
    print(anchor_id2_str+'\t'+str(coordinates))
    pozyx.getDeviceCoordinates(anchor_id3, coordinates)
    print(anchor_id3_str+'\t'+str(coordinates))
    pozyx.getDeviceCoordinates(anchor_id4, coordinates)
    print(anchor_id4_str+'\t'+str(coordinates))
    
    #Controlla l'apertura del file corretto in modo da non sovrascrivere i dati precedenti
    i=1
    print('auto_calibrazione_2D_geometria_'+str(i)+'.txt')
    while os.path.isfile('./dati/auto_calibrazione_2D_geometria_'+str(i)+'.txt'):
        print(i)
        i = i + 1
    
    #Prima riga del file
    name = "./dati/auto_calibrazione_2D_geometria_"+str(i)+".txt"
    out_file = open(name, "w")
    
    #Acquisizioni
    N = 10
    for i in list(range(N)):
        print(i)
        pozyx.doAnchorCalibration(dimension,num_measurements, anchors)
        pozyx.getDeviceCoordinates(anchor_id1, coordinates)
        out_file.write(anchor_id1_str+'\t'+str(coordinates)+'\n')
        pozyx.getDeviceCoordinates(anchor_id2, coordinates)
        out_file.write(anchor_id2_str+'\t'+str(coordinates)+'\n')
        pozyx.getDeviceCoordinates(anchor_id3, coordinates)
        out_file.write(anchor_id3_str+'\t'+str(coordinates)+'\n')
        pozyx.getDeviceCoordinates(anchor_id4, coordinates)
        out_file.write(anchor_id4_str+'\t'+str(coordinates)+'\n')
    out_file.close()
        