#include "packet_status.h"
#include <stdlib.h>

struct Status status_data;

unsigned char status_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    
    b = ((unsigned char*)&status_data)[s_idx++];
    
    if (s_idx == sizeof(struct Status)) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    
    return b;    
}

char status_deserialize(unsigned char ch)
{
	static int d_idx = 0;        
    
    ((unsigned char*)&status_data)[d_idx++] = ch;
    
    if (d_idx == sizeof(struct Status)) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
}

void* status_alloc(void)
{
	return malloc(sizeof(struct Status));
}

void status_reset(void)
{
}
