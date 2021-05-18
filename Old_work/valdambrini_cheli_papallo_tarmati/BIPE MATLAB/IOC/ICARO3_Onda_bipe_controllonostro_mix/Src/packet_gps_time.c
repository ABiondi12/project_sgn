#include "packet_gps_time.h"
#include <stdlib.h>

#define _WIN_32

// in totale sono 32 byte a cui si sommano 3 di header e 1 di checksum = 36 byte totali a pacchetto
struct Gps_time gps_time_data;

unsigned char gps_time_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct Gps_time);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(float) = 4 
    //  and the floats inside gps_time_data are accessed byte by byte 
    b = ((unsigned char*)&gps_time_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    //in the TI TNS320F28335 run time environment 
    //  the 8bit (unsigned char) does NOT exist!
    //  sizeof(float) = 2, thus the floats inside gps_time_data 
    //  must be accessed as two 16 bit words 
    //  and each single byte in a 16 bit word can be accessed 
    //  via the _byte macro !!!!!
    size = size*2;
    b = (unsigned char)__byte(((int*)&gps_time_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char gps_time_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct Gps_time);
    
    #ifdef _WIN_32
    ((unsigned char*)&gps_time_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&gps_time_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* gps_time_alloc(void)
{
    unsigned char size = sizeof(struct Gps_time);
    
	return malloc(size);
}

void gps_time_reset(void)
{
}
