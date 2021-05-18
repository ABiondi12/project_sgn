#include "packet_statistics_i2c_telemetry.h"
#include <stdlib.h>

struct Statistics_i2c_telemetry Statistics_i2c_telemetry_data;

unsigned char Statistics_i2c_telemetry_serialize(char* done)
{
	static int s_idx = 0;
    unsigned char b;
    
    b = ((unsigned char*)&Statistics_i2c_telemetry_data)[s_idx++];
    
    if (s_idx == sizeof(struct Statistics_i2c_telemetry)) {
        s_idx = 0;        
        *done = 1;
    } else {
        *done = 0;
    }
    
    return b;    
}

char Statistics_i2c_telemetry_deserialize(unsigned char ch)
{
	static int d_idx = 0;        
    
    ((unsigned char*)&Statistics_i2c_telemetry_data)[d_idx++] = ch;
    
    if (d_idx == sizeof(struct Statistics_i2c_telemetry)) {
        d_idx = 0;
        return 1;
    } else {
        return 0;
    }	
}

void* Statistics_i2c_telemetry_alloc(void)
{
	return malloc(sizeof(struct Statistics_i2c_telemetry));
}

void Statistics_i2c_telemetry_reset(void)
{
}

// #ifdef _WIN_32
// std::string Statistics_telemetry_dump(void)
// {
//     std::string res;
//     sprintf(res.c_str(),"%d STATS_TEL %d %d %d %d %d %d",Statistics_telemetry_data.en, Statistics_telemetry_data.cnt_overrun, Statistics_telemetry_data.cmd_age, 
//             Statistics_telemetry_data.rc_age, Statistics_telemetry_data.gps_age, Statistics_telemetry_data.v_batt);
//     return res;
// }
// #endif
