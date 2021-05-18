'''main.py
    file generico utile per debugging
'''

import numpy
import pypozyx
import time
import datetime
from pypozyx.structures.device_information import DeviceDetails

tag0_ID = 0x6760 # Fronte
tag1_ID = 0x675d # Retro

remote_id = None

print("Connecting to tags...")
serial_port_0 = pypozyx.get_pozyx_ports()[0]
serial_port_1 = pypozyx.get_pozyx_ports()[1]
pozyx_0 = pypozyx.PozyxSerial(serial_port_0)
pozyx_1 = pypozyx.PozyxSerial(serial_port_1)

print("Connected to tags! Checking if a name switch is required...")

system_details_first = DeviceDetails()
pozyx_0.getDeviceDetails(system_details_first, remote_id=None)  #Serve per ottenere l'ID della tag che in questo momento viene vista come pozyx_0 e che dovrebbe essere la testa
tag_first_ID = system_details_first.id

system_details_second = DeviceDetails()
pozyx_1.getDeviceDetails(system_details_second, remote_id=None)  #Serve per ottenere l'ID della tag che in questo momento viene vista come pozyx_0 e che dovrebbe essere la testa
tag_second_ID = system_details_second.id

print("On ", serial_port_0, " is connected tag with ID: 0x%0.4x" % tag_first_ID)
print("On ", serial_port_1, " is connected tag with ID: 0x%0.4x" % tag_second_ID)


print("Front tag desired id 0x%0.4x, right now pozyx_0 has id 0x%0.4x" % (tag0_ID, tag_first_ID))

if tag_first_ID != tag0_ID :
    pozyx_0_tmp = pozyx_0
    pozyx_0 = pozyx_1
    pozyx_1 = pozyx_0_tmp
    
    system_details = DeviceDetails()
    pozyx_0.getDeviceDetails(system_details, remote_id=None)
    print("Now front tag is 0x%0.4x" % (system_details.id) )

input("Press Enter to continue\n")

# variables init
coords_0    = pypozyx.Coordinates()
quat_0      = pypozyx.Quaternion()

coords_1    = pypozyx.Coordinates()
quat_1      = pypozyx.Quaternion()

time_pause = 0.02
print("Frequenza finta: ", 1/time_pause)

time.sleep(2)

counter_zeri_0 = 0
counter_errori_0 = 0
counter_zeri_1 = 0
counter_errori_1 = 0


for i in range(200):
    begin = time.time()
    status_0        = pozyx_0.doPositioning(coords_0, pypozyx.POZYX_3D, remote_id=remote_id)
    status_quat_0   = pozyx_0.getQuaternion(quat_0, remote_id=remote_id)
    end = time.time()
    if status_0 == pypozyx.POZYX_SUCCESS:
        print(datetime.datetime.now().strftime("__%Y_%b_%d_%H:%M:%S_%f_"), "tag_0", coords_0.x, coords_0.y, coords_0.z, "tempo di esecuzione: ", end-begin)
        print(datetime.datetime.now().strftime("__%Y_%b_%d_%H:%M:%S_%f_"), "tag_0", quat_0.x, quat_0.y, quat_0.z, quat_0.w, "tempo di esecuzione: ", end-begin)
        if (coords_0.x == 0.0 and coords_0.y == 0.0 and coords_0.z == 0.0):
            counter_zeri_0 = counter_zeri_0 + 1
    elif status_0 != pypozyx.POZYX_SUCCESS:
        counter_errori_0 = counter_errori_0 + 1


    time.sleep(time_pause)

    begin = time.time()
    status_1        = pozyx_1.doPositioning(coords_1, pypozyx.POZYX_3D, remote_id=remote_id)
    status_quat_1   = pozyx_1.getQuaternion(quat_1, remote_id=remote_id)
    end = time.time()
    if status_1 == pypozyx.POZYX_SUCCESS:
        print(datetime.datetime.now().strftime("__%Y_%b_%d_%H:%M:%S_%f_"), "tag_1", coords_1.x, coords_1.y, coords_1.z,  "tempo di esecuzione: ", end-begin)
        print(datetime.datetime.now().strftime("__%Y_%b_%d_%H:%M:%S_%f_"), "tag_1", quat_1.x, quat_1.y, quat_1.z, quat_1.w, "tempo di esecuzione: ", end-begin)
        if (coords_1.x == 0.0 and coords_1.y == 0.0 and coords_1.z == 0.0):
            counter_zeri_1 = counter_zeri_1 + 1
    elif status_1 != pypozyx.POZYX_SUCCESS:
        counter_errori_1 = counter_errori_1 + 1
    
    time.sleep(time_pause)
print("tag_0, letture pari a zero:", counter_zeri_0, ",   n errori", counter_errori_0)
print("tag_1, letture pari a zero:", counter_zeri_1, ",   n errori", counter_errori_1)