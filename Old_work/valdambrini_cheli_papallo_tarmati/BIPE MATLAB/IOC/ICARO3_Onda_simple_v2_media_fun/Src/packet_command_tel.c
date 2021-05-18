#include "packet_command_tel.h"
#include <stdlib.h>

struct CommandTel command_tel_data;

unsigned char command_tel_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    
    b = ((unsigned char*)&command_tel_data)[s_idx++];
    
    if (s_idx == sizeof(struct CommandTel)) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    
    return b;    
}

char command_tel_deserialize(unsigned char ch)
{
	static int d_idx = 0;        
    
    ((unsigned char*)&command_tel_data)[d_idx++] = ch;
    
    if (d_idx == sizeof(struct CommandTel)) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
}

void* command_tel_alloc(void)
{
	return malloc(sizeof(struct CommandTel));
}

void command_tel_reset(void)
{
}
