  //++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++
#include <math.h>
#include "packet_manager.h"
#include "packet_manager_c2k.h"
#include "packet_debug_6_floats.h"
#include "packet_ids.h"
//#include "DSP2833x_Device.h"
//++++++++++++++++++++++++++++

// Output wires:
// 0:1 PWM motore e sterzo
// 2: packet valid

extern struct Debug_6_floats debug_6_floats_data;

double* output_wires = 0; 


unsigned char pckcmd_recv = 0;
unsigned short recv_from_bs_cnt = 1;

void new_packet(unsigned char header)
{
    if (output_wires)
    {
        if (header == PCK_DEBUG_6_FLOATS)
        {
            output_wires[0] = (double)(debug_6_floats_data.f1);
            output_wires[1] = (double)(debug_6_floats_data.f2);
            
            //set cmd data_valid bit to 1 (valid)
            output_wires[2] = 1;
           
        }
        else{
            output_wires[2] = 0;
        }
    }
}

void err_d(unsigned char header, unsigned char errno)
{
	if (header == 1 && errno == 0)
	{
		
	}
}

void err_s(unsigned char header, unsigned char errno)
{
	if (header == 1 && errno == 0)
	{
		
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//mdlStart Wrapper Function Definition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void wrap_recv_pwm_from_bs_start_fcn(double* output, double* telemetry_control, double* waypoint, double* fuzzyguidance)
{
    // Init outputs
    output_wires = output;
    output_wires[0] = 0;
    output_wires[1] = 0;
    output_wires[2] = 0;
}

void wrap_recv_pwm_from_bs_output_fcn(double* output, double* telemetry_control, double* waypoint, double* fuzzyguidance)
{

    //set data_valid bits to 0 (not valid)
    output_wires[2] = 0;
        
    pm_read_packet_c2k();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
