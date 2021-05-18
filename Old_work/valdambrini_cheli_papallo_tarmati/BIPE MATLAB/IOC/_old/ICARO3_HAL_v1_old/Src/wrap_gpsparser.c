//#include "drv_scibtx.h"
//#include "drv_scicrx.h"
#include "c2000_type.h"
#include "circular_buffer.h"

#define GPS_BUFFSIZE 256 // plenty big

unsigned char buffer[GPS_BUFFSIZE];
unsigned char *parseptr;

void wrap_gpsparser_start_fcn()
{

}

void wrap_gpsparser_output_fcn(double* gpsoutput, double* newpacket)
{
    unsigned char ch;
    char i;
    
    // parser working variables
	static unsigned char state = 0;
	static unsigned char payload_length = 0;
	static unsigned char payload_read = 0;
	static unsigned char checksum = 0;
	unsigned char calculated_checksum = 0;
    
    // gps data variables
    i_int32 latitude = 0;
    i_int32 longitude = 0;
    i_int32 altitude_msl = 0;
    i_uint16 fix_mode = 0;
    i_uint16 hdop = 0;
    
    // Aggiunta di nuove variabili
    i_int32 ECEFx = 0;
    i_int32 ECEFy = 0;
    i_int32 ECEFz = 0;
    i_int32 ECEFvx = 0;
    i_int32 ECEFvy = 0;
    i_int32 ECEFvz = 0;
    
    // set newpacket output to 0 for now, parse() will set it to 1 if a valid packet was received
    newpacket[0] = 0;
    
    while (drv_scic_recv(&ch))
    {
		switch (state)
		{
		case 0: // wait for 0xA0
			// if A0 is received go to state 1
			state = (ch == 0xA0) ? 1 : 0;

			// reset everything, on parse error we always start with state == 0 therefore resetting the state variables
			// here is correct
			payload_length = 0;
			payload_read = 0;
			checksum = 0;
			break;

		case 1: // wait for 0xA1
			// if A1 is received go to state 2
			state = (ch == 0xA1) ? 2 : 0;
			break;

		case 2: // wait for first byte of 'payload length'
			payload_length = ch;
			payload_length = payload_length << 8;
			state = 3;
			break;

		case 3: // wait for second byte of 'payload length'
			payload_length |= ch;
			state = 4;
			break;

		case 4: // read message id (1 byte) and 'payload length' bytes
			buffer[payload_read] = ch;
			payload_read++;
         
            // avoid buffer overflow
            if (payload_read == GPS_BUFFSIZE) {
                state = 0;
            } else if (payload_read == payload_length) {
				state = 5;
			}
			break;

		case 5: // read the checksum byte
			checksum = ch;
			state = 6;
			break;

		case 6: // read the termination byte 0x0D
			state = (ch == 0x0D) ? 7 : 0;
			break;

		case 7: // read the termination byte 0x0A
			if (ch == 0x0A) {
				// verify the checksum
				for (i = 0; i < payload_length; i++)
					calculated_checksum ^= buffer[i];

				if (calculated_checksum == checksum)
				{                    
					// parse the payload, data can be found in 'buffer' array
					if (buffer[0] == 0xA8)
                    {
                        /*__byte(((int*)&latitude), 3) = (int)buffer[9];
                        __byte(((int*)&latitude), 2) = (int)buffer[10];
                        __byte(((int*)&latitude), 1) = (int)buffer[11];
                        __byte(((int*)&latitude), 0) = (int)buffer[12];*/


                        // VENUS NAV Packet 
                        //Legend: Field (1 based) Name Example(hex) Description Type Unit
                        // 
                        // 1 Message ID A8 UINT8
                        // 
                        // 2 Fix Mode 02
                        // Quality of fix
                        // 0: no fix
                        // 1: 2D
                        // 2: 3D
                        // 3: 3D+DGPS
                        // UINT8
                        // 
                        // 3
                        // Number of SV in
                        // fix
                        // 08
                        // Number of SV in fix
                        // 0-12
                        // UINT8
                        // 
                        // 4-5 GPS Week 0604 GPS week number UINT16
                        // 
                        // 6-9 TOW 02321818
                        // GPS time of week
                        // Scaling 0.01
                        // UINT32
                        // 1/100
                        // sec
                        // 
                        // 10-13 Latitude 0EC5E199
                        // > 0: North Hemisphere
                        // < 0: South Hemisphere
                        // Scaling 1e-7
                        // SINT32
                        // 1/1e-7
                        // degree
                        // 
                        // 14-17 Longitude 482078ED
                        // > 0: East Hemisphere
                        // < 0: West Hemisphere
                        // SINT32
                        // 1/1e-7
                        // degree
                        // 
                        // 18-21 ellipsoid altitude, 00002E3B
                        // height above ellipsoid
                        // Scaling 0.01
                        // UINT32
                        // 1/100
                        // meter
                        // 
                        // 22-25
                        // mean sea level
                        // altitude
                        // 00002693
                        // height above mean sea level
                        // Scaling 0.01
                        // UINT32
                        // 1/100
                        // meter
                        // 
                        // 26-27 GDOP 0093
                        // Geometric dilution of precision
                        // Scaling 0.01
                        // UINT16 1/100
                        // 
                        // 28-29 PDOP 0093
                        // Position dilution of precision
                        // Scaling 0.01
                        // UINT16 1/100
                        // 
                        // 30-31 HDOP 0093
                        // Horizontal dilution of precision
                        // Scaling 0.01
                        // UINT16 1/100
                        // 
                        // 32-33 VDOP 0093
                        // Vertical dilution of precision
                        // Scaling 0.01
                        // UINT16 1/100
                        // 
                        // 34-35 TDOP 0093
                        // Time dilution of precision
                        // Scaling 0.01
                        // UINT16 1/100
                        // 
                        // 36-39 ECEF-X EE354D30
                        // ECEF X coordinate
                        // Scaling 0.01
                        // SINT32
                        // 1/100
                        // meter
                        // 
                        // 40-43 ECEF-Y 1D99AA37
                        // ECEF Y coordinate
                        // Scaling 0.01
                        // SINT32
                        // 1/100
                        // meter
                        // 
                        // 44-47 ECEF-Z 0FD70B74
                        // ECEF Z coordinate
                        // Scaling 0.01
                        // SINT32
                        // 1/100
                        // meter
                        // 
                        // 48-51 ECEF-VX 00000000
                        // ECEF X Veolcity
                        // Scaling 0.01
                        // SINT32
                        // 1/100
                        // m/s
                        // 
                        // 52-55 ECEF-VY 00000000
                        // ECEF Y Veolcity
                        // Scaling 0.01
                        // SINT32
                        // 1/100
                        // m/s
                        // 
                        // 56-59 ECEF-VZ 00000000
                        // ECEF Z Veolcity
                        // Scaling 0.01
                        // SINT32
                        // 1/100
                        // m/s
                        // 
                        // Payload Length : 59 bytes

                        
                        
                        latitude = ((i_int32)buffer[9] << 24) | ((i_int32)buffer[10] << 16) | ((i_int32)buffer[11] << 8) | ((i_int32)buffer[12] << 0);
                        longitude = ((i_int32)buffer[13] << 24) | ((i_int32)buffer[14] << 16) | ((i_int32)buffer[15] << 8) | ((i_int32)buffer[16] << 0);
                        altitude_msl = ((i_int32)buffer[21] << 24) | ((i_int32)buffer[22] << 16) | ((i_int32)buffer[23] << 8) | ((i_int32)buffer[24] << 0);                        
                        fix_mode = buffer[1];
                        hdop = ((i_int32)buffer[29] << 8) | ((i_int32)buffer[30] << 0);
                        
                        
                        // Aggiunto estrazione delle coordinate ECEF
                        // ECEF position
                        ECEFx = ((i_int32)buffer[35] << 24) | ((i_int32)buffer[36] << 16) | ((i_int32)buffer[37] << 8) | ((i_int32)buffer[38] << 0);
                        ECEFy = ((i_int32)buffer[39] << 24) | ((i_int32)buffer[40] << 16) | ((i_int32)buffer[41] << 8) | ((i_int32)buffer[42] << 0);
                        ECEFz = ((i_int32)buffer[43] << 24) | ((i_int32)buffer[44] << 16) | ((i_int32)buffer[45] << 8) | ((i_int32)buffer[46] << 0);
                        // ECEF velocity
                        ECEFvx = ((i_int32)buffer[47] << 24) | ((i_int32)buffer[48] << 16) | ((i_int32)buffer[49] << 8) | ((i_int32)buffer[50] << 0);
                        ECEFvy = ((i_int32)buffer[51] << 24) | ((i_int32)buffer[52] << 16) | ((i_int32)buffer[53] << 8) | ((i_int32)buffer[54] << 0);
                        ECEFvz = ((i_int32)buffer[55] << 24) | ((i_int32)buffer[56] << 16) | ((i_int32)buffer[57] << 8) | ((i_int32)buffer[58] << 0);
                        
                        
                      
                        //modified output to make it compatible with NMEA_v3 (used with ublox lea-4h) 
                        // 0: lat
                        // 1: lon
                        // 2: status
                        // 3: speed over ground
                        // 4: course over ground
                        // 5: gps quality indicator
                        // 6: number of satellites
                        // 7: hdop
                        // 8: altitude
                        // 9: dgps station id

                        // set s-function output wires
                        // set s-function output wires

                        
                        gpsoutput[0] = latitude/(double)1e7;
                        gpsoutput[1] = longitude/(double)1e7;
                        gpsoutput[2] = buffer[1];
                        gpsoutput[3] = 0.0; //speed over ground zero for now
                        gpsoutput[4] = 0.0; //course over ground zero for now
                        gpsoutput[5] = 0.0; //gps quality zero for now
                        gpsoutput[6] = buffer[2];
                        gpsoutput[7] = hdop/(double)100.0;
                        gpsoutput[8] = altitude_msl/(double)100.0;
                        gpsoutput[9] = 0.0; //dgps station id zero for now
                        
                        // GPS Nuovi pacchetti ECEF
                        gpsoutput[10]=ECEFx/(double)100.0;
                        gpsoutput[11]=ECEFy/(double)100.0;
                        gpsoutput[12]=ECEFz/(double)100.0;
                        
                        gpsoutput[13]=ECEFvx/(double)100.0;
                        gpsoutput[14]=ECEFvy/(double)100.0;
                        gpsoutput[15]=ECEFvz/(double)100.0;           
                        
                        newpacket[0] = 1;                        
                    }
				}
			}
			state = 0;
			break;
		}                               
    }
}
