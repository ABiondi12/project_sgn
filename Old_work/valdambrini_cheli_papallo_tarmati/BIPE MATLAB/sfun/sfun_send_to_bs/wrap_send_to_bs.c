//++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++
#include <math.h>
#include "packet_manager.h"
#include "packet_manager_c2k_car.h"
#include "packet_car_telemetry.h"
#include "packet_ids.h"
#include "stm32f4_LED_debug.h"

#define PC 10
#define BROADCAST 255
#define CAR1 1
#define CAR2 2

extern struct Car_telemetry car_telemetry_data;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//mdlStart Wrapper Function Definition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void wrap_send_to_bs_start_fcn(){
}

void wrap_send_to_bs_output_fcn(double* input)
{
    // gps ecef position
    car_telemetry_data.ecef_px = input[0];
    car_telemetry_data.ecef_py = input[1];
    car_telemetry_data.ecef_pz = input[2];
    // gps ecef velocity
    car_telemetry_data.ecef_vx = input[3];
    car_telemetry_data.ecef_vy = input[4];
    car_telemetry_data.ecef_vz = input[5];
    // gps_fix
    car_telemetry_data.fix = (unsigned char)input[6];
    // gps time fix
    car_telemetry_data.time_fix = input[7];

    // magnetometer data
    car_telemetry_data.mag_x = input[8];
    car_telemetry_data.mag_y = input[9];
    car_telemetry_data.mag_z = input[10];

    //execution mode / car_ned_vel
    car_telemetry_data.mode = input[14] ; //(unsigned char)input[14];

    //pi commands / car ned pos / waypoint [17-18]
    car_telemetry_data.pi_motore = input[17];
    car_telemetry_data.pi_sterzo = input[18];

    //pwm commands / ned car
    car_telemetry_data.pwm_motore = input[12];
    car_telemetry_data.pwm_sterzo = input[13];

    //heading error
    car_telemetry_data.heading_error = input[16];

    //selezione del mittente del pacchetto da inviare
    //il PC per convenzione ha ID 10
    //volendo in base al protocollo utilizzato, si potrebbe cambiare PC in BROADCAST (ID 255) 
    if (input[17]==1)
    {
        pm_send_packet_car(PCK_CAR_TELEMETRY, CAR1, PC);    
    }
    else if (input[17]==2)
    {
        pm_send_packet_car(PCK_CAR_TELEMETRY, CAR2, PC);
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
