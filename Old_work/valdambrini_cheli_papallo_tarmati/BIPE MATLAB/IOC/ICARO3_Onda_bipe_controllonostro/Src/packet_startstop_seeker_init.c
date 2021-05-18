#include "packet_startstop_seeker_init.h"
#include <stdlib.h>

#define _WIN_32

// in totale sono (16 float +1 char) 65 byte a cui si sommano 3 di header e 1 di checksum = 69 byte totali a pacchetto
struct Startstop_seeker_init startstop_seeker_init_data;

unsigned char startstop_seeker_init_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct Startstop_seeker_init);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(float) = 4 
    //  and the floats inside startstop_seeker_init_data are accessed byte by byte 
    b = ((unsigned char*)&startstop_seeker_init_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    //in the TI TNS320F28335 run time environment 
    //  the 8bit (unsigned char) does NOT exist!
    //  sizeof(float) = 2, thus the floats inside startstop_seeker_init_data 
    //  must be accessed as two 16 bit words 
    //  and each single byte in a 16 bit word can be accessed 
    //  via the _byte macro !!!!!
    size = size*2;
    b = (unsigned char)__byte(((int*)&startstop_seeker_init_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char startstop_seeker_init_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct Startstop_seeker_init);
    
    #ifdef _WIN_32
    ((unsigned char*)&startstop_seeker_init_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&startstop_seeker_init_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* startstop_seeker_init_alloc(void)
{
    unsigned char size = sizeof(struct Startstop_seeker_init);
    
	return malloc(size);
}

void startstop_seeker_init_reset(void)
{
}
