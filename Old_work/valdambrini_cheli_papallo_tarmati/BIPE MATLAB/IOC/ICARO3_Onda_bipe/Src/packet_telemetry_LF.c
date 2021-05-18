#include "packet_telemetry_LF.h"
#include <stdlib.h>

struct Telemetry_LF telemetry_LF_data;

unsigned char telemetry_LF_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    
    b = ((unsigned char*)&telemetry_LF_data)[s_idx++];
    
    if (s_idx == sizeof(struct Telemetry_LF)) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    
    return b;    
}

char telemetry_LF_deserialize(unsigned char ch)
{
	static int d_idx = 0;        
    
    ((unsigned char*)&telemetry_LF_data)[d_idx++] = ch;
    
    if (d_idx == sizeof(struct Telemetry_LF)) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
}

void* telemetry_LF_alloc(void)
{
	return malloc(sizeof(struct Telemetry_LF));
}

void telemetry_LF_reset(void)
{
}
