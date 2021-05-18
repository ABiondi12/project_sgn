#include "packet_gps2.h"
#include <stdlib.h>

struct Gps2 gps2_data;

unsigned char gps2_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct Gps2);
    
    #ifdef _WIN_32
    b = ((unsigned char*)&gps2_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    size = size*2;
    b = __byte(((int*)&gps2_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char gps2_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct Gps2);
    
    #ifdef _WIN_32
    ((unsigned char*)&gps2_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&gps2_data), d_idx++) = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* gps2_alloc(void)
{
    unsigned char size = sizeof(struct Gps2);
    
	return malloc(size);
}

void gps2_reset(void)
{
}
