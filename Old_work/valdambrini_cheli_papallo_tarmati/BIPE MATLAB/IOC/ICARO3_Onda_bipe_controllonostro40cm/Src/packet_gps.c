#include "packet_gps.h"
#include <stdlib.h>

#define _WIN_32

struct Gps gps_data;
struct Gps_status gps_status_data;


unsigned char gps_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct Gps);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(float) = 4 
    //  and the floats inside gps_data are accessed byte by byte 
    b = ((unsigned char*)&gps_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    //in the TI TNS320F28335 run time environment 
    //  the 8bit (unsigned char) does NOT exist!
    //  sizeof(float) = 2, thus the floats inside gps_data 
    //  must be accessed as two 16 bit words 
    //  and each single byte in a 16 bit word can be accessed 
    //  via the _byte macro !!!!!
    size = size*2;
    b = (unsigned char)__byte(((int*)&gps_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char gps_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct Gps);
    
    #ifdef _WIN_32
    ((unsigned char*)&gps_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&gps_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* gps_alloc(void)
{
    unsigned char size = sizeof(struct Gps);
    
	return malloc(size);
}

void gps_reset(void)
{
}

unsigned char gps_status_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    
    b = ((unsigned char*)&gps_status_data)[s_idx++];

    //in a win_32 run time environment, a struct of byte 
    //  can be accessed byte by byte if the pointer is cast as (unsigned char*)
    //in the TI TNS320F28335 run time environment 
    //  the 8bit (unsigned char) does NOT exist!
    //  each byte of the struct is actually stored a 16 bit word
    //  and returned by this function (as 16 bit) 
    //  BUT, when the 16 bit word is used to send data to the serial port,
    //  only the first 8 bit are send !!!!
    //  thus it apperas here that we are working with 8 bits char
    //  while we work with 16 bits char 
    //  but it is not relevant whne this are used to send data via SCI ports!!!!!
    if (s_idx == sizeof(struct Gps_status)) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    
    return b;    
}

char gps_status_deserialize(unsigned char ch)
{
	static int d_idx = 0;        
    
    ((unsigned char*)&gps_status_data)[d_idx++] = ch;
    
    if (d_idx == sizeof(struct Gps_status)) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
}

void* gps_status_alloc(void)
{
	return malloc(sizeof(struct Gps_status));
}

void gps_status_reset(void)
{
}
