#!/usr/bin/env python

from pypozyx import (PozyxSerial, POZYX_RANGE_PROTOCOL_FAST, POZYX_RANGE_PROTOCOL_PRECISION,
                     SingleRegister, DeviceRange, POZYX_SUCCESS, POZYX_FAILURE, get_first_pozyx_serial_port)

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

    def loop(self, output_file=None):
        """Performs ranging and sets the LEDs accordingly"""
        device_range = DeviceRange()
        status = self.pozyx.doRanging(
            self.destination_id, device_range, self.remote_id)
        if status == POZYX_SUCCESS:
            print(device_range)
            if self.ledControl(device_range.distance) == POZYX_FAILURE:
                print("ERROR: setting (remote) leds")
            out_file.write(str(device_range.distance)+'\n')    # Scrive sul file di output
        else:
            error_code = SingleRegister()
            status = self.pozyx.getErrorCode(error_code)
            if status == POZYX_SUCCESS:
                print("ERROR Ranging, local %s" %
                      self.pozyx.getErrorMessage(error_code))
            else:
                print("ERROR Ranging, couldn't retrieve local error")

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

    remote_id = 0x6e44        # the network ID of the remote device
    remote = False             # whether to use the given remote device for ranging
    if not remote:
        remote_id = None

    destination_id = 0x6e7a   # network ID of the ranging destination
    range_step_mm = 1000      # distance that separates the amount of LEDs lighting up.

    ranging_protocol = POZYX_RANGE_PROTOCOL_PRECISION   # the ranging protocol

    pozyx = PozyxSerial(serial_port)
    r = ReadyToRange(pozyx, destination_id, range_step_mm,
                     ranging_protocol, remote_id)
    r.setup()
    
    # Check the opening of the file so as not to overwrite the previous data
    i=1
    print('distanza_due_antenne_'+str(i)+'.txt')
    while os.path.isfile('./data/distanza_due_antenne_'+str(i)+'.txt'):
        print(i)
        i = i + 1
    
    # First raw of file .txt
    name = "./data/distanza_due_antenne_"+str(i)+".txt"
    out_file = open(name, "w")
    
    
    # Data acquisition
    N = 1000    #number of samples
    for i in list(range(N)):
        r.loop(out_file)
    out_file.close()
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
       