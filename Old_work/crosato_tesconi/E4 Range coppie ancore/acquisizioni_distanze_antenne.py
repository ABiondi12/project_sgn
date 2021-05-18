#!/usr/bin/env python

from pypozyx import (PozyxSerial, POZYX_RANGE_PROTOCOL_FAST, POZYX_RANGE_PROTOCOL_PRECISION,
                     SingleRegister, DeviceRange, POZYX_SUCCESS, POZYX_FAILURE, get_first_pozyx_serial_port)
                     
import os.path


class ReadyToRange(object):
    """Continuously performs ranging between the Pozyx and a destination and sets their LEDs"""

    def __init__(self, pozyx, anchor_ids, protocol=POZYX_RANGE_PROTOCOL_FAST,remote_id=None):
        self.pozyx = pozyx
        self.anchor_ids = anchor_ids
        self.protocol = protocol
        self.remote_id = remote_id

    def setup(self):
        # set the ranging protocol
        for remote in anchor_ids:
            self.pozyx.setRangingProtocol(self.protocol, remote)
        self.pozyx.setRangingProtocol(self.protocol, self.remote_id)

    def loop(self, output_file=None):
        """Performs ranging and sets the LEDs accordingly"""
        device_range = DeviceRange()
        
        for remote in anchor_ids:
            for anchor in anchor_ids:
                if remote != anchor:
                    status = self.pozyx.doRanging(anchor, device_range, remote)
                    
                    if status == POZYX_SUCCESS:
                        if device_range.distance <= 100000:
                            out_file.write(str(device_range.distance)+'\t\t')
                        else:
                            out_file.write('Err\t\t')
                    else:
                        error_code = SingleRegister()
                        status = self.pozyx.getErrorCode(error_code)
                        if status == POZYX_SUCCESS:
                            print("ERROR Ranging, local %s" %
                                self.pozyx.getErrorMessage(error_code))
                        else:
                            print("ERROR Ranging, couldn't retrieve local error")
                        out_file.write('Err\t\t')
        out_file.write('\n')


if __name__ == "__main__":

    #Connesione alla seriale del pozyx
    serial_port = get_first_pozyx_serial_port()
    if serial_port is None:
        print("No Pozyx connected. Check your USB cable or your driver!")
        quit()
        
    anchor0 = 0x6939
    anchor1 = 0x6e7a
    anchor2 = 0x6e44
    anchor3 = 0x6e6c
    anchor_ids = [anchor0, anchor1, anchor2, anchor3]
    
    remote_id = 0x6760              # remote device network ID
    remote = False                # whether to use a remote device
    if not remote:
        remote_id = None

    ranging_protocol = POZYX_RANGE_PROTOCOL_PRECISION   # the ranging protocol

    pozyx = PozyxSerial(serial_port)
    r = ReadyToRange(pozyx, anchor_ids, ranging_protocol, remote_id)
    r.setup()
    
    #Controlla l'apertura del file corretto in modo da non sovrascrivere i dati precedenti
    i=0
    print('distanza_coppie_antenne_'+str(i)+'.txt')
    while os.path.isfile('./dati/distanza_coppie_antenne_'+str(i)+'.txt'):
        print(i)
        i = i + 1
    
    #Prima riga del file
    name = "./dati/distanza_coppie_antenne_"+str(i)+".txt"
    out_file = open(name, "w")
    for i in list(range(4)):
        for j in list (range(4)):
            if (i!=j):
                out_file.write('r'+str(i)+str(j)+'\t\t')
    out_file.write('\n')            
    
    
    #Acquisizioni
    N = 20               #Number of acquisitions
    for i in list(range(N)):
        print(i)
        r.loop(out_file)
    out_file.close()
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
       