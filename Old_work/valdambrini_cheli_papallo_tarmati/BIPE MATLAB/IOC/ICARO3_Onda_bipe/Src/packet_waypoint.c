#include "packet_waypoint.h"
#include <stdlib.h>

#define _WIN_32

struct Waypoint waypoint_data;
struct WaypointExt waypoint_ext_data;
struct WaypointAck waypoint_ack_data;
struct WaypointCmd waypoint_cmd_data;

struct WaypointExt waypoint_ext_rcv_data;
struct WaypointAck waypoint_ack_req_data;


unsigned char waypoint_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct Waypoint);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(float) = 4 
    //  and the floats inside gps_data are accessed byte by byte 
    b = ((unsigned char*)&waypoint_data)[s_idx++];
    
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
    b = (unsigned char)__byte(((int*)&waypoint_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char waypoint_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct Waypoint);
    
    #ifdef _WIN_32
    ((unsigned char*)&waypoint_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&waypoint_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* waypoint_alloc(void)
{
    unsigned char size = sizeof(struct Waypoint);
    
	return malloc(size);
}

void waypoint_reset(void)
{
}

unsigned char waypoint_ext_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct WaypointExt);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(float) = 4 
    //  and the floats inside gps_data are accessed byte by byte 
    b = ((unsigned char*)&waypoint_ext_data)[s_idx++];
    
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
    b = (unsigned char)__byte(((int*)&waypoint_ext_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char waypoint_ext_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct WaypointExt);
    
    #ifdef _WIN_32
    ((unsigned char*)&waypoint_ext_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&waypoint_ext_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* waypoint_ext_alloc(void)
{
    unsigned char size = sizeof(struct WaypointExt);
    
	return malloc(size);
}

void waypoint_ext_reset(void)
{
}

unsigned char waypoint_ack_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct WaypointAck);
    
    b = ((unsigned char*)&waypoint_ack_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }

    return b;   
}

char waypoint_ack_deserialize(unsigned char ch)
{
    static int d_idx = 0;   
    unsigned char size = sizeof(struct WaypointAck);
    
    ((unsigned char*)&waypoint_ack_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	     	
}

void* waypoint_ack_alloc(void)
{
	return malloc(sizeof(struct WaypointAck));
}

void waypoint_ack_reset(void)
{
}

unsigned char waypoint_cmd_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct WaypointCmd);
    
    #ifdef _WIN_32
    b = ((unsigned char*)&waypoint_cmd_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    #else
    size = size*2;
    b = (unsigned char)__byte(((int*)&waypoint_cmd_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char waypoint_cmd_deserialize(unsigned char ch)
{
    static int d_idx = 0;   
    unsigned char size = sizeof(struct WaypointCmd);
    
    #ifdef _WIN_32
    ((unsigned char*)&waypoint_cmd_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&waypoint_cmd_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* waypoint_cmd_alloc(void)
{
	return malloc(sizeof(struct WaypointCmd));
}

void waypoint_cmd_reset(void)
{
}


/********************************************************************/
unsigned char waypoint_ext_rcv_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct WaypointExt);
    
    #ifdef _WIN_32
    //in a win_32 run time environment, sizeof(float) = 4 
    //  and the floats inside gps_data are accessed byte by byte 
    b = ((unsigned char*)&waypoint_ext_rcv_data)[s_idx++];
    
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
    b = (unsigned char)__byte(((int*)&waypoint_ext_rcv_data), s_idx++);
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }       
    #endif
    
    return b;    
}

char waypoint_ext_rcv_deserialize(unsigned char ch)
{
	static int d_idx = 0;   
    unsigned char size = sizeof(struct WaypointExt);
    
    #ifdef _WIN_32
    ((unsigned char*)&waypoint_ext_rcv_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
    #else
    size = size*2;
    __byte(((int*)&waypoint_ext_rcv_data), d_idx++) = (int)ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	        
    #endif
}

void* waypoint_ext_rcv_alloc(void)
{
    unsigned char size = sizeof(struct WaypointExt);
    
	return malloc(size);
}

void waypoint_ext_rcv_reset(void)
{
}

unsigned char waypoint_ack_req_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    unsigned char size = sizeof(struct WaypointAck);
    
    b = ((unsigned char*)&waypoint_ack_req_data)[s_idx++];
    
    if (s_idx == size) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }

    return b;   
}

char waypoint_ack_req_deserialize(unsigned char ch)
{
    static int d_idx = 0;   
    unsigned char size = sizeof(struct WaypointAck);
    
    ((unsigned char*)&waypoint_ack_req_data)[d_idx++] = ch;
    
    if (d_idx == size) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	     	
}

void* waypoint_ack_req_alloc(void)
{
	return malloc(sizeof(struct WaypointAck));
}

void waypoint_ack_req_reset(void)
{
}
/********************************************************************/


