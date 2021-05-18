#include "packet_fuzzyGuidance.h"
#include <stdlib.h>

#define _WIN_32

struct fuzzyGuidance fuzzyGuidance_data;
struct fuzzyGuidanceEnable fuzzyGuidanceEnable_data;

unsigned char fuzzyGuidance_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct fuzzyGuidance);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(int16) = 2
    //thus sizeof(struct attitude_data) = 6
    //then, with the cast below, bytes in the struct can be accessed one by one
    b = ((unsigned char*)&fuzzyGuidance_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    //in the TI TNS320F28335 run time environment 
    //  the 8bit (unsigned char) does NOT exist!
    //  sizeof(int16) = 1, 
    //  thus sizeof(struct attitude_data) = 3,        
    //  thus the ints inside attitude_data 
    //  can be accessed as three 16 bit words 
    //  and each single byte in a 16 bit word can be accessed 
    //  via the _byte macro !!!!!
    size = size*2;
    b = (unsigned char)__byte(((int*)&fuzzyGuidance_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char fuzzyGuidance_deserialize(unsigned char ch)
{
    static int d_idx = 0;   
    unsigned char size = sizeof(struct fuzzyGuidance);
    
    #ifdef _WIN_32
    ((unsigned char*)&fuzzyGuidance_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&fuzzyGuidance_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* fuzzyGuidance_alloc(void)
{
	return malloc(sizeof(struct fuzzyGuidance));
}

void fuzzyGuidance_reset(void)
{
}

unsigned char fuzzyGuidanceEnable_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct fuzzyGuidanceEnable);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(int16) = 2
    //thus sizeof(struct attitude_data) = 6
    //then, with the cast below, bytes in the struct can be accessed one by one
    b = ((unsigned char*)&fuzzyGuidanceEnable_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    //in the TI TNS320F28335 run time environment 
    //  the 8bit (unsigned char) does NOT exist!
    //  sizeof(int16) = 1, 
    //  thus sizeof(struct attitude_data) = 3,        
    //  thus the ints inside attitude_data 
    //  can be accessed as three 16 bit words 
    //  and each single byte in a 16 bit word can be accessed 
    //  via the _byte macro !!!!!
    size = size*2;
    b = (unsigned char)__byte(((int*)&fuzzyGuidanceEnable_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char fuzzyGuidanceEnable_deserialize(unsigned char ch)
{
    static int d_idx = 0;   
    unsigned char size = sizeof(struct fuzzyGuidanceEnable);
    
    #ifdef _WIN_32
    ((unsigned char*)&fuzzyGuidanceEnable_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&fuzzyGuidanceEnable_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* fuzzyGuidanceEnable_alloc(void)
{
	return malloc(sizeof(struct fuzzyGuidanceEnable));
}

void fuzzyGuidanceEnable_reset(void)
{
}