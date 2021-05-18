//++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++
#include <math.h>
#include "packet_manager.h"
#include "packet_manager_c2k.h"
#include "packet_telemetry.h"
#include "packet_config.h" //NEW
#include "packet_pwr_stats.h" //07/07/2015
#include "packet_gps.h"
#include "packet_telemetry_LF.h"
#include "packet_command_tel.h"
#include "packet_ids.h"
#include "packet_debug_6_floats.h"
#include "packet_statistics_telemetry.h"
#include "packet_statistics_i2c_telemetry.h"
#include "packet_attitude.h"
#include "packet_waypoint.h"
#include "packet_fuzzyguidance.h"
#include "circular_buffer.h"
//++++++++++++++++++++++++++++

extern struct Telemetry telemetry_data; 
extern struct Telemetry_LF telemetry_LF_data;
extern struct Config config_data; //NEW
extern struct Pwr_Stats pwr_stats_data;
extern struct Gps gps_data;
extern struct Gps_status gps_status_data;
extern struct CommandTel command_tel_data;
//extern int    CntOverrun;
extern struct Debug_6_floats debug_6_floats_data;
extern struct Statistics_telemetry Statistics_telemetry_data;
extern struct Statistics_i2c_telemetry Statistics_i2c_telemetry_data;

//for waypoint response data
/***********************************************/
extern struct WaypointAck waypoint_ack_data;
extern struct WaypointExt waypoint_ext_rcv_data;
/***********************************************/



void err_s(unsigned char header, unsigned char errno)
{
	
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//mdlStart Wrapper Function Definition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void wrap_send_to_bs_start_fcn()
{
   
}

void wrap_send_to_bs_output_fcn(double* input, double* debug_data, double* telemetry_control, double* waypoint_send, double* fuzzyguidance_input)
{
    static unsigned char pr1Hz  = 0; 
    static unsigned char pr2Hz  = 0; 
    static unsigned char pr5Hz  = 0; 
    static unsigned char pr10Hz = 0; 
    static unsigned char pr20Hz = 0; 
    static unsigned char pr50Hz = 0; 
    
    //retrieve current telemetry_type
    int current_telemetry_type         = (int)telemetry_control[0];
    int must_send_control_gains_packet = (int)telemetry_control[1];
    int must_send_DP_data_packet       = (int)telemetry_control[2];
    
    
    //prescalerS w.r.t. base rate : 100Hz
    pr1Hz++;    //1 Hz
    pr2Hz++;    //2 Hz
    pr5Hz++;    //5 Hz
    pr10Hz++;   //10 Hz
    pr20Hz++;   //20 Hz
    pr50Hz++;   //50 Hz

#define PR1HZ_LIM  100
#define PR2HZ_LIM  50
#define PR5HZ_LIM  20
#define PR10HZ_LIM 10
#define PR20HZ_LIM 5
#define PR50HZ_LIM 2
    
    
    if (current_telemetry_type==1) {
        //see file: packet_telemtry_type.h
        //  1: standard telemetry: 
        //      * PCK_CMDTEL at 20 Hz
        //      * PCK_TEL at 20 Hz
        //      * PCK_GPS at 5 Hz
        //      / PCK_TLF at 1 Hz
        //      * PCK_STATS at 2 Hz
        //      * PCK_I2C_STATS at 2 Hz
        // 
        //total: 439 bytes/sec
        //(max value was 488 with GPS at 10 Hz, TLF at 1 Hz) 
    
        if (pr20Hz == PR20HZ_LIM)
        {
            command_tel_data.c1 = input[14];
            command_tel_data.c2 = input[15];
            command_tel_data.c3 = input[16];
            command_tel_data.c4 = input[17];
            pm_send_packet_c2k(PCK_CMDTEL); //4 bytes payload + ( 2 bytes header + 1 byte checksum ) : 7 bytes 

            //NOTE: when casting a float to a int8 on the F28335 hw architecture 
            //      it must be considered that in8 is actually a int16 on the hw 
            //      thus the cast below do not normally saturate to -128 and +127 
            //      since the float is actually converted to a 16 bit signed integer
            //      that saturates at +32767 - 32768 
            //          =>
            //      when the data inside the int8 (that is actually a int16) is sent by the packet manager 
            //      only the first 8 bits are sent 
            //          => 
            //      the cast below produces a value to be sent that is the 8 least significant bits
            //      of the the 16 bit integer to which the double was cast.
            //      The mani effect of this is that the value sent do not saturate (to 127, -128)
            //      but rolls, for instance, when going up from ... 125, 126, 127 to -128 -127 ....
            //      and the actual value can be recovered from the rolled-over value by adding
            //      or subtracting 255 depending on the direction the ramp was going !!!
            telemetry_data.roll_adis   = input[0]*350; 
            telemetry_data.pitch_adis  = input[1]*350;
            telemetry_data.yaw_adis    = input[2]*40;
            telemetry_data.roll_stick  = input[20]*350;
            telemetry_data.pitch_stick = input[21]*350;
            telemetry_data.yaw_stick   = input[22]*40;
            pm_send_packet_c2k(PCK_TEL);    //6 bytes + 3 = 9 bytes
        }

        if (pr5Hz == PR5HZ_LIM)
        {
            gps_data.lat = input[11];
            gps_data.lon = input[12];
            gps_data.h   = input[13];
            pm_send_packet_c2k(PCK_GPS);  //3 floats = 4*3 + 3 = 15 bytes
        }

        if (0) { //disable old telemetry with gains 
            if (pr1Hz == PR1HZ_LIM) {
               //OLD telemetry packet
            /*
            telemetry_LF_data.en    = (unsigned char)(input[3]);
            telemetry_LF_data.kprp  = (unsigned char)(input[5]*200);
            telemetry_LF_data.kirp  = (unsigned char)(input[6]*200);
            telemetry_LF_data.kdrp  = (unsigned char)(input[7]*200);
            telemetry_LF_data.kpyv  = (unsigned char)(input[8]*200);
            telemetry_LF_data.kiyv  = (unsigned char)(input[9]*200);
            telemetry_LF_data.kph   = (unsigned char)(input[23]*200);
            telemetry_LF_data.kih   = (unsigned char)(input[24]*200);
            telemetry_LF_data.kdh   = (unsigned char)(input[25]*200);
            telemetry_LF_data.kpy   = (unsigned char)(input[26]*50);
            telemetry_LF_data.kiy   = (unsigned char)(input[27]*50);
            telemetry_LF_data.kpp   = (unsigned char)(input[28]*1000);
            telemetry_LF_data.vbatt = (unsigned char)(input[10]*15);
            telemetry_LF_data.T     = (char)(input[18]);
            telemetry_LF_data.cnt_overrun = (unsigned char)(CntOverrun);
                //Use Packet_Config for these data
                //DONT send PCK_TLF
            pm_send_packet_c2k(PCK_TLF);  //15 + 3 bytes = 18 bytes
            */
               
               //NEW telemetry packet sended to bs (PCK_CFG)
            config_data.en = (unsigned char)(input[3]);
            
            config_data.kprp = (i_float)(input[5]);
            config_data.kirp = (i_float)(input[6]);
            config_data.kdrp = (i_float)(input[7]);
            config_data.kpyv = (i_float)(input[8]);
            config_data.kiyv = (i_float)(input[9]);
            config_data.kph  = (i_float)(input[23]);
            config_data.kih  = (i_float)(input[24]);
            config_data.kdh  = (i_float)(input[25]);
            config_data.kpy  = (i_float)(input[26]);
            config_data.kiy  = (i_float)(input[27]);
            config_data.kpp  = (i_float)(input[28]);
            
            config_data.vbatt       = (i_float)(input[10]);
            config_data.T           = (i_float)(input[18]);
            config_data.cnt_overrun = (i_float)(CntOverrun);
            
            config_data.RPconv  = (i_float)(input[4]);
            config_data.param_2 = (i_float)2;
            config_data.param_3 = (i_float)3;
            config_data.param_4 = (i_float)4;
            config_data.param_5 = (i_float)5;
            pm_send_packet_c2k(PCK_CFG);
            }
        }
        if (pr2Hz == PR2HZ_LIM)
        {
            Statistics_telemetry_data.en          = (unsigned char)(input[3]);
            Statistics_telemetry_data.cnt_overrun = (unsigned char)(CntOverrun);
            Statistics_telemetry_data.cmd_age     = (unsigned char)(debug_data[1]);//mean 
            Statistics_telemetry_data.cmd_age_max = (unsigned char)(debug_data[0]);//max
            Statistics_telemetry_data.rc_age      = (unsigned char)(debug_data[3]);//mean 
            Statistics_telemetry_data.rc_age_max  = (unsigned char)(debug_data[2]);//max
            Statistics_telemetry_data.gps_age     = (unsigned char)(debug_data[5]);//mean 
            Statistics_telemetry_data.gps_age_max = (unsigned char)(debug_data[4]);//max
            Statistics_telemetry_data.v_batt      = (unsigned char)(input[10]*15);
            pm_send_packet_c2k(PCK_STATS_TELEMETRY);  //9 + 3 bytes = 12 bytes
        }
        if (pr2Hz == PR2HZ_LIM)
        {
            Statistics_i2c_telemetry_data.err_cnt           = (unsigned char)(debug_data[6]);
            Statistics_i2c_telemetry_data.i2c_enabled_flags = (unsigned char)(debug_data[7]);
            Statistics_i2c_telemetry_data.motor_err_cnt_max = (unsigned char)(debug_data[8]);
            Statistics_i2c_telemetry_data.press_err_cnt_max = (unsigned char)(debug_data[9]);
            Statistics_i2c_telemetry_data.gyro_err_cnt_max  = (unsigned char)(debug_data[10]);
            Statistics_i2c_telemetry_data.acc_err_cnt_max   = (unsigned char)(debug_data[11]);
            Statistics_i2c_telemetry_data.mag_err_cnt_max   = (unsigned char)(debug_data[12]);
            pm_send_packet_c2k(PCK_STATS_I2C_TELEMETRY);  //7 + 3 bytes = 10 bytes
        }
    } else if (current_telemetry_type==2 || current_telemetry_type==3) {
        //see file: packet_telemtry_type.h
        //      * PCK_CMDTEL at 10 Hz
        //      * PCK_TEL at 10 Hz
        //      * PCK_GPS at 5 Hz
        //      * PCK_GPS_STATUS at 1 Hz
        //      / PCK_TLF at 1 Hz
        //      * PCK_DEBUG_6_FLOATS at 2 Hz    
        //      * PCK_STATS at 2 Hz
        //      * PCK_I2C_STATS at 2 Hz
        // 
        //total: 279 bytes/sec + 54 bytes/sec (debug_6_floats) = 333 bytes /sec

        if (pr10Hz == PR10HZ_LIM)
        {
            command_tel_data.c1 = input[14];
            command_tel_data.c2 = input[15];
            command_tel_data.c3 = input[16];
            command_tel_data.c4 = input[17];
            //dont send motors command to BS (these information must sent with
            //                               debug_telemetry)
            //pm_send_packet_c2k(PCK_CMDTEL);

//             telemetry_data.roll_adis  = input[0]*350;
//             telemetry_data.pitch_adis = input[1]*350;
//             telemetry_data.yaw_adis   = input[2]*40;
//             telemetry_data.roll_stick  = input[20]*350;
//             telemetry_data.pitch_stick = input[21]*350;
//             telemetry_data.yaw_stick   = input[22]*40;
//             pm_send_packet_c2k(PCK_TEL);
            
            attitude_data.roll  = input[20]*10000; //conversion factor: -pi +pi radians to -2^15, 2^15 = 32768/3.141592 = 10435 = approx 10000 
            attitude_data.pitch = input[21]*10000;
            attitude_data.yaw   = input[22]*10000;
            pm_send_packet_c2k(PCK_ATT);
        }

        if (pr5Hz == PR5HZ_LIM)
        {
            gps_data.lat = input[11];
            gps_data.lon = input[12];
            gps_data.h   = input[13];
            pm_send_packet_c2k(PCK_GPS);      
        }
        
        if (pr1Hz == PR1HZ_LIM)
        {
            gps_status_data.hdop = input[50];
            gps_status_data.vdop = input[51];
            gps_status_data.gps_fix_type = input[52];
            gps_status_data.sat_num      = input[53];
            pm_send_packet_c2k(PCK_GPS_STATUS);      
        }

        
        if (must_send_control_gains_packet==1) {
            //if (pr1Hz == PR1HZ_LIM)   //the prescaler was removed since this signal is connected to the 
            //telemetry control input that is pulsed for 1/500 sec every time the gains are uploaded
            //  the 1/500 sec pulse is translated into a 1/100 sec pulse thus the PCK_TLF packet should be sent just once
            /*
            {
                telemetry_LF_data.en    = (unsigned char)(input[3]);
                telemetry_LF_data.kprp  = (unsigned char)(input[5]*200);
                telemetry_LF_data.kirp  = (unsigned char)(input[6]*200);
                telemetry_LF_data.kdrp  = (unsigned char)(input[7]*200);
                telemetry_LF_data.kpyv  = (unsigned char)(input[8]*200);
                telemetry_LF_data.kiyv  = (unsigned char)(input[9]*200);
                telemetry_LF_data.kph   = (unsigned char)(input[23]*200);
                telemetry_LF_data.kih   = (unsigned char)(input[24]*200);
                telemetry_LF_data.kdh   = (unsigned char)(input[25]*200);
                telemetry_LF_data.kpy   = (unsigned char)(input[26]*50);
                telemetry_LF_data.kiy   = (unsigned char)(input[27]*50);
                telemetry_LF_data.kpp   = (unsigned char)(input[28]*1000);
                telemetry_LF_data.vbatt = (unsigned char)(input[10]*15);
                telemetry_LF_data.T     = (char)(input[18]);
                telemetry_LF_data.cnt_overrun = (unsigned char)(CntOverrun);
                    //Use Packet_Config for these data
                    //DONT send PCK_TLF
                //pm_send_packet_c2k(PCK_TLF);
            }
            */
               //send new control data with new packet type (packet_config)
            config_data.en   = (unsigned char)(input[3]);
            
            config_data.kprp = (i_float)(input[5]);
            config_data.kirp = (i_float)(input[6]);
            config_data.kdrp = (i_float)(input[7]);
            config_data.kpyv = (i_float)(input[8]);
            config_data.kiyv = (i_float)(input[9]);
            config_data.kph  = (i_float)(input[23]);
            config_data.kih  = (i_float)(input[24]);
            config_data.kdh  = (i_float)(input[25]);
            config_data.kpy  = (i_float)(input[26]);
            config_data.kiy  = (i_float)(input[27]);
            config_data.kpp  = (i_float)(input[28]);
         
            config_data.vbatt        = (i_float)(input[10]);
            config_data.T            = (i_float)(input[18]);
            config_data.cnt_overrun  = (i_float)(CntOverrun);
            
            config_data.RPconv  = (i_float)(input[4]);
            config_data.param_2 = (i_float)2;
            config_data.param_3 = (i_float)3;
            config_data.param_4 = (i_float)4;
            config_data.param_5 = (i_float)5;
            
            pm_send_packet_c2k(PCK_CFG);
        }
        //2 feb 2012 : added 8-th input to mux with 5x3 raw imu data: starting pos [28]
        //acc_adis, gyro_adis, gyro_itg, acc_adxl, mag_hmc
        //28-       31-        34-        37-      40-42
        //3 feb 2012 : added 9-th input to mux with 6 dp ctrl data: starting pos [43]
        //43 altitude ctrl error
        //44 yaw ctrl error
        //45 x position reference
        //46 x position
        //47 y position reference
        //48 y position
        
        if (pr2Hz == PR2HZ_LIM)
        {
            Statistics_telemetry_data.en          = (unsigned char)(input[3]);
            Statistics_telemetry_data.cnt_overrun = (unsigned char)(CntOverrun);
            Statistics_telemetry_data.cmd_age     = (unsigned char)(debug_data[1]);//mean 
            Statistics_telemetry_data.cmd_age_max = (unsigned char)(debug_data[0]);//max
            Statistics_telemetry_data.rc_age      = (unsigned char)(debug_data[3]);//mean 
            Statistics_telemetry_data.rc_age_max  = (unsigned char)(debug_data[2]);//max
            Statistics_telemetry_data.gps_age     = (unsigned char)(debug_data[5]);//mean 
            Statistics_telemetry_data.gps_age_max = (unsigned char)(debug_data[4]);//max
            Statistics_telemetry_data.v_batt      = (unsigned char)(input[10]*15);
            pm_send_packet_c2k(PCK_STATS_TELEMETRY);  //9 + 3 bytes = 12 bytes
        }
        if (pr2Hz == PR2HZ_LIM)
        {
            Statistics_i2c_telemetry_data.err_cnt           = (unsigned char)(debug_data[6]);
            Statistics_i2c_telemetry_data.i2c_enabled_flags = (unsigned char)(debug_data[7]);
            Statistics_i2c_telemetry_data.motor_err_cnt_max = (unsigned char)(debug_data[8]);
            Statistics_i2c_telemetry_data.press_err_cnt_max = (unsigned char)(debug_data[9]);
            Statistics_i2c_telemetry_data.gyro_err_cnt_max  = (unsigned char)(debug_data[10]);
            Statistics_i2c_telemetry_data.acc_err_cnt_max   = (unsigned char)(debug_data[11]);
            Statistics_i2c_telemetry_data.mag_err_cnt_max   = (unsigned char)(debug_data[12]);
            //These data are not registred in BS -> dont send (10/07/2015)
            //pm_send_packet_c2k(PCK_STATS_I2C_TELEMETRY);  //7 + 3 bytes = 10 bytes
        }
        //New Packet type : Power_Statistics : PCK_PWR_STATS (07/07/2015)
        if (pr2Hz == PR2HZ_LIM) {
            pwr_stats_data.vbatt = input[44]; //v_batt
            pwr_stats_data.ibatt = input[45]; //i_batt
            pwr_stats_data.vbatt_filt = input[46]; //v_batt_filt
            pwr_stats_data.ibatt_filt = input[47]; //i_batt_filt
            pwr_stats_data.pbatt_filt = input[48]; //p_batt_filt
            pwr_stats_data.icons_Ah   = input[49]; //i_cons_Ah
            //pm_send_packet_c2k(PCK_PWR_STATS);
        }

        if (0) {
            if (current_telemetry_type==2)
            {
                if (pr2Hz == PR2HZ_LIM) {
                    debug_6_floats_data.f1 = input[41];     //mag_x_hmc
                    debug_6_floats_data.f2 = input[42];     //mag_y_hmc
                    debug_6_floats_data.f3 = input[43];     //mag_z_hmc
                    debug_6_floats_data.f4 = input[34];     //gyro_z_used(ADIS or MPU9150)
                    debug_6_floats_data.f5 = input[37];     //gyro_z_sstick
                    debug_6_floats_data.f6 = input[31];     //acc_z_used(ADIS or MPU9150)
                    //debug_6_floats_data.f6 = input[38];     //acc_z_sstick
                    //not need to send this packet (new packet were created)
                    //pm_send_packet_c2k(PCK_DEBUG_6_FLOATS); //6 floats = 6x4 +3 = 27 bytes 
                }
            }
            else if (current_telemetry_type==3) {
                if (must_send_DP_data_packet) {
                    if (pr2Hz == PR2HZ_LIM) {
                        debug_6_floats_data.f1 = input[44]; //v_batt
                        debug_6_floats_data.f2 = input[45]; //i_batt
                        debug_6_floats_data.f3 = input[46]; //v_batt_filt
                        debug_6_floats_data.f4 = input[47]; //i_batt_filt
                        debug_6_floats_data.f5 = input[48]; //p_batt_filt
                        debug_6_floats_data.f6 = input[49]; //i_cons_Ah
                        //not need to send this packet (new packet were created)
                        //pm_send_packet_c2k(PCK_DEBUG_6_FLOATS);
                    }
                }
            }
        } //if(0)
        
        //FUZZY GUIDANCE DATA
        if (current_telemetry_type==3)
        {
            if (pr5Hz == PR5HZ_LIM) {
                //first check if fuzzy guidance is enabled
                if (fuzzyguidance_input[0]==1) {
                    //copy input data into packet structure then send it 
                    fuzzyGuidance_data.dist    = (i_int16)(fuzzyguidance_input[1]*10.0);
                    fuzzyGuidance_data.posx    = (i_int16)(fuzzyguidance_input[2]*10.0);
                    fuzzyGuidance_data.posy    = (i_int16)(fuzzyguidance_input[3]*10.0);
                    fuzzyGuidance_data.ldsdmix = (i_int16)(fuzzyguidance_input[4]*100.0);
                    fuzzyGuidance_data.yawdes  = (i_int16)(fuzzyguidance_input[5]*100.0);
                    fuzzyGuidance_data.yawwayp = (i_int16)(fuzzyguidance_input[6]*100.0);
                    //send it 
                    //pm_send_packet_c2k(PCK_FUZZYGUIDANCE); //6 floats = 6x4 +3 = 27 bytes 
                }
            }
        }   
    }

    if (waypoint_send[0] == 1) { //sync signal for ack response 
        //PCK_WAYP_ACK
        waypoint_ack_data.ack_code = (i_int8)(waypoint_send[1]);
        waypoint_ack_data.id       = (i_uint8)(waypoint_send[2]);
        pm_send_packet_c2k(PCK_WAYP_ACK);
    }
    
    if(waypoint_send[0] == 2) { //sync signal => transmit packet
        //PCK_WAYP_RCV_EXT
        waypoint_ext_rcv_data.lat  = (i_float)(waypoint_send[1]);
        waypoint_ext_rcv_data.lon  = (i_float)(waypoint_send[2]);
        waypoint_ext_rcv_data.hdg  = (i_float)(waypoint_send[3]);
        waypoint_ext_rcv_data.h    = (i_int16)(waypoint_send[4]);
        waypoint_ext_rcv_data.act  = (i_uint16)(waypoint_send[5]);
        waypoint_ext_rcv_data.id_n = (i_uint16)(waypoint_send[6]);
        pm_send_packet_c2k(PCK_WAYP_RCV_EXT);
    }

    //reset prescalers when needed
    if (pr1Hz >= PR1HZ_LIM) pr1Hz    = 0;
    if (pr2Hz >= PR2HZ_LIM) pr2Hz    = 0;
    if (pr5Hz >= PR5HZ_LIM) pr5Hz    = 0;
    if (pr10Hz >= PR10HZ_LIM) pr10Hz = 0;
    if (pr20Hz >= PR20HZ_LIM) pr20Hz = 0;
    if (pr50Hz >= PR50HZ_LIM) pr50Hz = 0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
