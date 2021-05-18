#include "packet_bs_to_car.h"
#include <stdlib.h>

#define _WIN_32

// in totale sono (16 float +1 char) 65 byte a cui si sommano 3 di header e 1 di checksum = 69 byte totali a pacchetto
struct Bs_to_car bs_to_car_data;

unsigned char bs_to_car_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct Bs_to_car);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(float) = 4 
    //  and the floats inside bs_to_car_data are accessed byte by byte 
    b = ((unsigned char*)&bs_to_car_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    //in the TI TNS320F28335 run time environment 
    //  the 8bit (unsigned char) does NOT exist!
    //  sizeof(float) = 2, thus the floats inside bs_to_car_data 
    //  must be accessed as two 16 bit words 
    //  and each single byte in a 16 bit word can be accessed 
    //  via the _byte macro !!!!!
    size = size*2;
    b = (unsigned char)__byte(((int*)&bs_to_car_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char bs_to_car_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct Bs_to_car);
    
    #ifdef _WIN_32
    ((unsigned char*)&bs_to_car_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&bs_to_car_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* bs_to_car_alloc(void)
{
    unsigned char size = sizeof(struct Bs_to_car);
    
	return malloc(size);
}

void bs_to_car_reset(void)
{
}
