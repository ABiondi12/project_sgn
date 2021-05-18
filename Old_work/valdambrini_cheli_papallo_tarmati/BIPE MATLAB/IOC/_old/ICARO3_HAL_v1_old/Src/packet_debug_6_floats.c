#include "packet_debug_6_floats.h"
#include <stdlib.h>

struct Debug_6_floats debug_6_floats_data;

unsigned char debug_6_floats_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct Debug_6_floats);
    
    #ifdef _WIN_32
    b = ((unsigned char*)&debug_6_floats_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    size = size*2;
    b = (unsigned char)__byte(((int*)&debug_6_floats_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char debug_6_floats_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct Debug_6_floats);
    
    #ifdef _WIN_32
    ((unsigned char*)&debug_6_floats_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&debug_6_floats_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* debug_6_floats_alloc(void)
{
    unsigned char size = sizeof(struct Debug_6_floats);
    
	return malloc(size);
}

void debug_6_floats_reset(void)
{
}
