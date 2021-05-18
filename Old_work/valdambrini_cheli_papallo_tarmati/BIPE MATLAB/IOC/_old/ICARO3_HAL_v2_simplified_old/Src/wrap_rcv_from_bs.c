  //++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++
#include <math.h>
#include "packet_manager.h"
#include "packet_manager_c2k.h"
#include "packet_command.h"
#include "packet_gps2.h"
#include "packet_status.h"
#include "packet_telemetry_type.h"
#include "packet_config.h" //packet for parameters configuration (28/06/2015)
#include "packet_waypoint.h"
#include "packet_fuzzyguidance.h"
#include "packet_ids.h"
//#include "DSP2833x_Device.h"
//++++++++++++++++++++++++++++

//define lower/upper bound for Roll-Pitch conversion factor param
#define MIN_RP_FACT 0
#define MAX_RP_FACT 35 
#define DEF_RP_FACT 15 //default value

// Output wires:
// 0:3 commands
// 4:15 status
// 16 command data valid
// 17 status data valid
// 18 command packet received in the last 1 seconds

extern struct Command command_data;
extern struct Status status_data;
extern struct Config config_data; //(28/06/2015)
extern struct Gps2 gps2_data;
extern struct Telemetry_type telemetry_type_data;

/************************************************/
extern struct Waypoint    waypoint_data;
extern struct WaypointExt waypoint_ext_data;
extern struct WaypointAck waypoint_ack_req_data;
extern struct WaypointCmd waypoint_cmd_data;
/************************************************/



double* output_wires = 0; 
double* telemetry_control_wires = 0; 
double* waypoint_wires = 0; 
double* fuzzyguidance_wires = 0;

unsigned char pckcmd_recv       = 0;
unsigned short recv_from_bs_cnt = 0;

void new_packet(unsigned char header)
{
    if (output_wires)
    {
        if (header == PCK_CMD)
        {
            output_wires[0] = (double)(command_data.force_cmd)/255;
            output_wires[1] = (double)(command_data.roll_cmd)/127;
            output_wires[2] = (double)(command_data.pitch_cmd)/127;
            output_wires[3] = (double)(command_data.yaw_cmd)/127;
            pckcmd_recv++;
            
            //set cmd data_valid bit to 1 (valid)
            output_wires[16] = 1;
            
            // PCK_CMD is used to reset the watchdog counter
//             EALLOW;
//             SysCtrlRegs.WDKEY = 0x0055;
//             SysCtrlRegs.WDKEY = 0x00AA;
//             EDIS;
        }
        
//         else if (header == PCK_STA)
//         {
//             output_wires[15] = (double)(status_data.en);
//             output_wires[4]  = (double)(status_data.kprp)/200;
//             output_wires[5]  = (double)(status_data.kirp)/200;
//             output_wires[6]  = (double)(status_data.kdrp)/200;
//             output_wires[7]  = (double)(status_data.kpyv)/200;
//             output_wires[8]  = (double)(status_data.kiyv)/200;
//             output_wires[9]  = (double)(status_data.kph)/200;
//             output_wires[10] = (double)(status_data.kih)/200;
//             output_wires[11] = (double)(status_data.kdh)/200;
//             output_wires[12] = (double)(status_data.kpy)/50;
//             output_wires[13] = (double)(status_data.kiy)/50;
//             output_wires[14] = (double)(status_data.kpp)/1000;
//             
//             //set status data_valid bit to 1 (valid)
//             output_wires[17] = 1;
//             
//             telemetry_control_wires[1] = 1; 
//             
//         }
         
        //Change PCK_STA with new packet PCK_CFG for controllers
        //configuration (28/06/2015)
        else if (header == PCK_CFG)
        {
            output_wires[15] = (double)(config_data.en);
            output_wires[4]  = (double)(config_data.kprp);
            output_wires[5]  = (double)(config_data.kirp);
            output_wires[6]  = (double)(config_data.kdrp);
            output_wires[7]  = (double)(config_data.kpyv);
            output_wires[8]  = (double)(config_data.kiyv);
            output_wires[9]  = (double)(config_data.kph);
            output_wires[10] = (double)(config_data.kih);
            output_wires[11] = (double)(config_data.kdh);
            output_wires[12] = (double)(config_data.kpy);
            output_wires[13] = (double)(config_data.kiy);
            output_wires[14] = (double)(config_data.kpp);
            if((double)(config_data.RPconv) > MIN_RP_FACT && (double)(config_data.RPconv) < MAX_RP_FACT)
                output_wires[19] = (double)(config_data.RPconv);
            
            //set status data_valid bit to 1 (valid)
            output_wires[17] = 1;
            
            telemetry_control_wires[1] = 1;  
        }
        
        else if (header == PCK_GPS2)
        {
            
        }
    }
    
    if (telemetry_control_wires)
    {
        if (header == PCK_TELEMETRY_TYPE)
        {
            telemetry_control_wires[0] = (double)telemetry_type_data.telemetry_request;
            //use the unused flag to trigger gain sending 
            if (telemetry_type_data.unused>0) telemetry_control_wires[1] = 1; 
        }
    }
   
    if (waypoint_wires) {
        if (header == PCK_WAYP) {
            waypoint_wires[0] = 1; //sync value for waypoint PCK_WAYP
            waypoint_wires[1] = (double)(waypoint_data.lat);
            waypoint_wires[2] = (double)(waypoint_data.lon);
            waypoint_wires[3] = (double)(waypoint_data.h);
            waypoint_wires[4] = (double)((waypoint_data.id_n) - 256*(waypoint_data.id_n/255)); //id of wp
            waypoint_wires[5] = (double)(waypoint_data.id_n/256); //number of wp
        }
        else if (header == PCK_WAYP_EXT) {
             waypoint_wires[0] = 2; //sync value for PCK_WAYP_EXT
             waypoint_wires[1] = (double)(waypoint_ext_data.lat);
             waypoint_wires[2] = (double)(waypoint_ext_data.lon);
             waypoint_wires[3] = (double)(waypoint_ext_data.h);
             waypoint_wires[4] = (double)((waypoint_ext_data.id_n) - 256*(waypoint_ext_data.id_n/255)); //id of wp
             waypoint_wires[5] = (double)(waypoint_ext_data.id_n/256); //number of wp
             waypoint_wires[6] = (double)(waypoint_ext_data.hdg); //heading
             waypoint_wires[7] = (double)(waypoint_ext_data.act); //action
        } 
        else if (header == PCK_WAYP_CMD) {
            waypoint_wires[0] = 3; //sync value for PCK_WAYP_CMD
            waypoint_wires[1] = (double)(waypoint_cmd_data.id_n_del/256); //number of wp to delete N
            waypoint_wires[2] = (double)((waypoint_cmd_data.id_n_del) - 256*(waypoint_cmd_data.id_n_del/255)); //id of wp to delete
        }
        else if (header == PCK_WAYP_REQ_ACK){
            waypoint_wires[0] = 4; //sync for PCK_WAYP_REQ_ACK
            waypoint_wires[1] = (double)(waypoint_ack_req_data.ack_code); //ack_code
            waypoint_wires[2] = (double)(waypoint_ack_req_data.id); //ack_id
        }   
    }
    
    //  FUZZY GUIDANCE PACKETS
    if (fuzzyguidance_wires) {
        if (header == PCK_FUZZYGUIDANCE_ENABLE) {
            fuzzyguidance_wires[0] =(double)fuzzyGuidanceEnable_data.enable;
        } 
    }


}

void err_d(unsigned char header, unsigned char errno)
{
	if (header == 1 && errno == 0)
	{
		
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//mdlStart Wrapper Function Definition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void wrap_rcv_from_bs_start_fcn(double* output, double* telemetry_control, double* waypoint, double* fuzzyguidance)
{
    // Init outputs
    output_wires = output;
    output_wires[0]  = 0;
    output_wires[1]  = 0;
    output_wires[2]  = 0;
    output_wires[3]  = 0;
    output_wires[4]  = 0.46;
    output_wires[5]  = 0;
    output_wires[6]  = 0.15;
    output_wires[7]  = 0.15;
    output_wires[8]  = 0;
    output_wires[9]  = 0.12;
    output_wires[10] = 0;
    output_wires[11] = 0.15;
    output_wires[12] = 4;
    output_wires[13] = 0;
    output_wires[14] = 0.05;
    output_wires[15] = 0;
    output_wires[16] = 0;
    output_wires[17] = 0;
    output_wires[18] = 0;
    output_wires[19] = DEF_RP_FACT;
    
    telemetry_control_wires = telemetry_control;
    telemetry_control_wires[0] = 3;  //control type of telemetry (default: 3)
    telemetry_control_wires[1] = 0;  //flag triggered when a packet containing gains is transmitted so that a feedbcak may be sent
    telemetry_control_wires[2] = 0;
    telemetry_control_wires[3] = 0;
    
    waypoint_wires = waypoint;
    waypoint_wires[0] = 0;  
    waypoint_wires[1] = 0;  
    waypoint_wires[2] = 0;  
    waypoint_wires[3] = 0;  
    waypoint_wires[4] = 0;  
    waypoint_wires[5] = 0;   
    waypoint_wires[6] = 0;  
    waypoint_wires[7] = 0;
    waypoint_wires[8] = 0;
    waypoint_wires[9] = 0;
         
    fuzzyguidance_wires = fuzzyguidance;
    fuzzyguidance_wires[0] = 0; // enable off
    
}

void wrap_rcv_from_bs_output_fcn(double* output, double* telemetry_control, double* waypoint, double* fuzzyguidance)
{
    
        // reset watchdog counter
//     EALLOW;
//     SysCtrlRegs.WDKEY = 0x0055;
//     SysCtrlRegs.WDKEY = 0x00AA;
//     EDIS;

    //set data_valid bits to 0 (not valid)
    output_wires[16] = 0;
    output_wires[17] = 0; //gain packet received flag
    
    waypoint_wires[0] = 0; 
    
    //fuzzyguidance_wires[0] = 0; // output last value 
    telemetry_control_wires[1] = 0; //reset gain packet flag
   
    recv_from_bs_cnt++;
    if (recv_from_bs_cnt >= 500)
    {
        recv_from_bs_cnt = 1;
        output_wires[18] = pckcmd_recv;
        pckcmd_recv = 0;
    }
        
    pm_read_packet_c2k();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
