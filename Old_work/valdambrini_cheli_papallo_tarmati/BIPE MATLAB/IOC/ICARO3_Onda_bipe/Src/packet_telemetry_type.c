#include "packet_telemetry_type.h"
#include <stdlib.h>

struct Telemetry_type telemetry_type_data;

unsigned char telemetry_type_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    
    b = ((unsigned char*)&telemetry_type_data)[s_idx++];
    
    if (s_idx == sizeof(struct Telemetry_type)) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    
    return b;    
}

char telemetry_type_deserialize(unsigned char ch)
{
	static int d_idx = 0;        
    
    ((unsigned char*)&telemetry_type_data)[d_idx++] = ch;
    
    if (d_idx == sizeof(struct Telemetry_type)) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
}

void* telemetry_type_alloc(void)
{
	return malloc(sizeof(struct Telemetry_type));
}

void telemetry_type_reset(void)
{
}
