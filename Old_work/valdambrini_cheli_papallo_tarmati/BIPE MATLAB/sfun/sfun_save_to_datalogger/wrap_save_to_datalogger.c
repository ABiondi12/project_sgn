#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>
#define DEBUG


void wrap_save_to_datalogger_start_fcn()
{	
    char s[100];
    sprintf(s, "ID");
    for (uint8_t i = 0; s[i] != '\0'; i++){
		USART3_Send(s[i]);
	}
}

void wrap_save_to_datalogger_output_fcn(uint32_t* arduino_id,  int32_t* arduino_x, int32_t* arduino_y, int8_t* arduino_dx, int8_t* arduino_dy, uint8_t* arduino_squal, real_T* acc_adxl, real_T* mag_hmc, real_T* gyro_itg, real_T* gps_data, real_T* gps_data_ecef, real_T* pwm) {
	char s[400];
	char s_adxl[100];
	char s_mag[100];
	char s_gps[100];

	sprintf(s, "%d,%d,%d,%d,%d,%d", arduino_id[0], arduino_x[0], arduino_y[0], arduino_dx[0], arduino_dy[0], arduino_squal[0]);
	sprintf(s_adxl, ",%f,%f,%f", acc_adxl[0], acc_adxl[1], acc_adxl[2]);
	sprintf(s_mag, ",%f,%f,%f", gyro_itg[0], gyro_itg[1], gyro_itg[2]); 	
	sprintf(s_gps, ",%f,%f,%f", gps_data[0], gps_data[1], gps_data[3]);
	sprintf(s_gps, ",%f,%f,%f,%f", gps_data_ecef[0], gps_data_ecef[1], gps_data_ecef[2], pwm[0]); 
    
	
	strcat(s, s_adxl);
	strcat(s, s_mag);
	strcat(s, s_gps);
		
	for (uint8_t i = 0; s[i] != '\0'; i++){
		USART3_Send(s[i]);
	}
	USART3_Send(';');
	USART3_Send('\n'); USART3_Send('\r');
}
