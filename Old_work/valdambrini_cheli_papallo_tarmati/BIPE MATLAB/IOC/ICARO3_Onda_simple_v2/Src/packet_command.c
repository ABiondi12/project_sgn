#include "packet_command.h"
#include <stdlib.h>

struct Command command_data;

unsigned char command_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    
    b = ((unsigned char*)&command_data)[s_idx++];
    
    if (s_idx == sizeof(struct Command)) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    
    return b;    
}

char command_deserialize(unsigned char ch)
{
	static int d_idx = 0;        
    
    ((unsigned char*)&command_data)[d_idx++] = ch;
    
    if (d_idx == sizeof(struct Command)) {
#ifndef _WIN_32
        
//CAZZUS ! THIS SHOULD NEVER BE COMPILED ON WIN32 !!!!
         // Onto F28335 int8 don't exist, you have to compute manually
        // 2-complement on 8-bit data 
        if (command_data.roll_cmd > 127)
        {
            command_data.roll_cmd = command_data.roll_cmd - 256;
        }
        
        if (command_data.pitch_cmd > 127)
        {
            command_data.pitch_cmd = command_data.pitch_cmd - 256;
        }
        
        if (command_data.yaw_cmd > 127)
        {
            command_data.yaw_cmd = command_data.yaw_cmd - 256;
        }
#endif
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
}

void* command_alloc(void)
{
	return malloc(sizeof(struct Command));
}

void command_reset(void)
{
}
