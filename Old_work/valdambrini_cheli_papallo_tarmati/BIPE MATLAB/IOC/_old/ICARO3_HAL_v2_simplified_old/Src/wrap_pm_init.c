//++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++
#include <math.h>
#include "circular_buffer.h"
#include "packet_manager.h"
#include "packet_manager_c2k.h"
#include "packet_telemetry.h"
#include "packet_gps.h"
#include "packet_gps2.h"
#include "packet_debug_6_floats.h"
#include "packet_telemetry_LF.h"
#include "packet_command.h"
#include "packet_command_tel.h"
#include "packet_status.h"
#include "packet_config.h" //New configuration packet type
#include "packet_pwr_stats.h" //New packet for battery information (07/07/2015)
#include "packet_telemetry_type.h"
#include "packet_statistics_telemetry.h"
#include "packet_statistics_i2c_telemetry.h"
#include "packet_attitude.h"
#include "packet_waypoint.h"
#include "packet_fuzzyguidance.h"

#include "packet_ids.h"
//++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//mdlStart Wrapper Function Definition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void wrap_pm_init_start_fcn()
{
    pm_init(new_packet, err_d, err_s);
	pm_register_packet(PCK_CMD, command_serialize, command_deserialize, command_reset);
    pm_register_packet(PCK_CMDTEL, command_tel_serialize, command_tel_deserialize, command_tel_reset);
    pm_register_packet(PCK_TEL, telemetry_serialize, telemetry_deserialize, telemetry_reset);
    pm_register_packet(PCK_STA, status_serialize, status_deserialize, status_reset);
    pm_register_packet(PCK_TLF, telemetry_LF_serialize, telemetry_LF_deserialize, telemetry_LF_reset);
    pm_register_packet(PCK_GPS, gps_serialize, gps_deserialize, gps_reset);
    pm_register_packet(PCK_GPS_STATUS, gps_status_serialize, gps_status_deserialize, gps_status_reset);
    pm_register_packet(PCK_GPS2, gps2_serialize, gps2_deserialize, gps2_reset);
    pm_register_packet(PCK_DEBUG_6_FLOATS, debug_6_floats_serialize, debug_6_floats_deserialize, debug_6_floats_reset);
    pm_register_packet(PCK_TELEMETRY_TYPE, telemetry_type_serialize, telemetry_type_deserialize, telemetry_type_reset);
    pm_register_packet(PCK_STATS_TELEMETRY, Statistics_telemetry_serialize, Statistics_telemetry_deserialize, Statistics_telemetry_reset);
    pm_register_packet(PCK_STATS_I2C_TELEMETRY, Statistics_i2c_telemetry_serialize, Statistics_i2c_telemetry_deserialize, Statistics_i2c_telemetry_reset);
    pm_register_packet(PCK_ATT, attitude_serialize, attitude_deserialize, attitude_reset);
    /**********************************************************************************************************************/
    pm_register_packet(PCK_CFG, config_serialize, config_deserialize, config_reset);
    pm_register_packet(PCK_PWR_STATS, pwr_stats_serialize, pwr_stats_deserialize, pwr_stats_reset);
    /**********************************************************************************************************************/
    pm_register_packet(PCK_WAYP, waypoint_serialize, waypoint_deserialize, waypoint_reset);
    pm_register_packet(PCK_WAYP_EXT, waypoint_ext_serialize, waypoint_ext_deserialize, waypoint_ext_reset);
    pm_register_packet(PCK_WAYP_ACK,  waypoint_ack_serialize, waypoint_ack_deserialize, waypoint_ack_reset);
    pm_register_packet(PCK_WAYP_CMD,  waypoint_cmd_serialize, waypoint_cmd_deserialize, waypoint_cmd_reset);
    pm_register_packet(PCK_WAYP_RCV_EXT, waypoint_ext_rcv_serialize, waypoint_ext_rcv_deserialize, waypoint_ext_rcv_reset);
    pm_register_packet(PCK_WAYP_REQ_ACK,  waypoint_ack_req_serialize, waypoint_ack_req_deserialize, waypoint_ack_req_reset);    
    /**********************************************************************************************************************/
    pm_register_packet(PCK_FUZZYGUIDANCE,  fuzzyGuidance_serialize, fuzzyGuidance_deserialize, fuzzyGuidance_reset);
    pm_register_packet(PCK_FUZZYGUIDANCE_ENABLE,  fuzzyGuidanceEnable_serialize, fuzzyGuidanceEnable_deserialize, fuzzyGuidanceEnable_reset);
   
}

void wrap_pm_init_output_fcn(double* input)
{
    
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
