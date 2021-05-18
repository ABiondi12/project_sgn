#!/usr/bin/env python
"""
Script per ottenere ID delle tag o delle ancore dell'uwb.
"""

import pypozyx
from pypozyx.structures.device_information import DeviceDetails

serial_port_name = pypozyx.get_pozyx_ports()[0]

device = pypozyx.PozyxSerial(serial_port_name)

system_details = DeviceDetails()

device.getDeviceDetails(system_details, remote_id=None) 

device_id = system_details.id

print(device_id)
print("id device: 0x%0.4x" % (device_id))
