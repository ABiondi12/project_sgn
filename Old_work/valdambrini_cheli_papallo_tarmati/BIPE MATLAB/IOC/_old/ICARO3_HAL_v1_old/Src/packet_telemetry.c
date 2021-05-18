#include "packet_telemetry.h"
#include <stdlib.h>

struct Telemetry telemetry_data;

unsigned char telemetry_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    
    b = ((unsigned char*)&telemetry_data)[s_idx++];
    
    if (s_idx == sizeof(struct Telemetry)) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    
    return b;    
}

char telemetry_deserialize(unsigned char ch)
{
	static int d_idx = 0;        
    
    ((unsigned char*)&telemetry_data)[d_idx++] = ch;
    
    if (d_idx == sizeof(struct Telemetry)) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
}

void* telemetry_alloc(void)
{
	return malloc(sizeof(struct Telemetry));
}

void telemetry_reset(void)
{
}
