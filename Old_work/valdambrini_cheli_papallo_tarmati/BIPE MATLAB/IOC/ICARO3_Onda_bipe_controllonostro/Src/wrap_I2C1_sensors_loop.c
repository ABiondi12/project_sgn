/* Wrap Sensors Loop, HAL version */


#include "rtwtypes.h"
#include "stm32f4_I2C1_sensors.h"
#include "stm32f4_I2C1_peripheral.h"


//#define I2C1_SENSORS_TEST


#ifdef I2C1_SENSORS_TEST
#include "stm32f4_custom_USART.h"
#include "stm32f4_LED_debug.h"
#endif

extern I2C_HandleTypeDef I2CHandle;

//variables for i2c error stats 
static uint8_t I2C1_ErrorCounter[I2C1_SENSORS_NUMBER];
static uint8_t I2C1_ErrorCounterNoReset[I2C1_SENSORS_NUMBER];
static uint8_t max_number_of_consecutive_i2c_reset = 0;
static int 	total_number_of_i2c_resets = 0;

uint8_t I2C1_HAL_Err_Status;
uint8_t temp0 = 0;

void wrap_I2C1_sensors_loop_start_fcn(uint8_T* output, uint16_T* output2)
{

    /* Initialize I2C1 peripheral */
    I2C1_Init(); //Defined in peripheral.c
    
    /* Initialize sensors */
    I2C1_SensorEnabled[ADXL345_ID] = ADXL345_Init();
    I2C1_SensorEnabled[ITG3200_ID] = ITG3200_Init();
    I2C1_SensorEnabled[HMC5883L_ID] = HMC5883L_Init();
    I2C1_SensorEnabled[BMP085_ID] = BMP085_Init(&output[32]);
    I2C1_SensorEnabled[MPU9150_ID] = MPU9150_Init();

    
    /* Initialize error counters */
    I2C1_ErrorCounter[ADXL345_ID] = 0;
    I2C1_ErrorCounter[ITG3200_ID] = 0;
    I2C1_ErrorCounter[HMC5883L_ID] = 0;
    I2C1_ErrorCounter[BMP085_ID] = 0;
    I2C1_ErrorCounter[MPU9150_ID] = 0;
    I2C1_ErrorCounterNoReset[ADXL345_ID] = 0;
    I2C1_ErrorCounterNoReset[ITG3200_ID] = 0;
    I2C1_ErrorCounterNoReset[HMC5883L_ID] = 0;
    I2C1_ErrorCounterNoReset[BMP085_ID] = 0;
    I2C1_ErrorCounterNoReset[MPU9150_ID] = 0;

	
    
#ifdef I2C1_ERROR_CAN_LIKE_MANAGEMENT
    /* Initialize CAN prescalers */
    I2C1_CANPrescaler[ADXL345_ID] = 0;
    I2C1_CANPrescaler[ITG3200_ID] = 0;
    I2C1_CANPrescaler[HMC5883L_ID] = 0;
    I2C1_CANPrescaler[BMP085_ID] = 0;
#endif
    
    /* Initialize I2C1 measurements flag */
    I2C1_MeasFlag = 0;
    
    /* Set I2C1_ProcSensor to end of chain to tell the output function that everything is ok */
    I2C1_ProcSensor = I2C1_SENSORS_NUMBER;
    
    /* s-function output: error counters */
    output[23] = I2C1_ErrorCounter[ADXL345_ID];
    output[24] = I2C1_ErrorCounter[ITG3200_ID];
    output[25] = I2C1_ErrorCounter[HMC5883L_ID];
    output[26] = I2C1_ErrorCounter[BMP085_ID];

    output[68] = I2C1_ErrorCounter[MPU9150_ID];
    
    /* s-function output: sensors enabled */
    output[27] = I2C1_SensorEnabled[ADXL345_ID];
    output[28] = I2C1_SensorEnabled[ITG3200_ID];
    output[29] = I2C1_SensorEnabled[HMC5883L_ID];
    output[30] = I2C1_SensorEnabled[BMP085_ID];

    output[69] = I2C1_SensorEnabled[MPU9150_ID];
    
    /* s-function output2: measurement flag */
    output2[0] = I2C1_MeasFlag;
}


void wrap_I2C1_sensors_loop_output_fcn(uint8_T* input, uint8_T* output, uint16_T* output2)
{   
    uint8_t I2C1_ResetRequested = 0;

    if(I2C1_ProcSensor == I2C1_SENSORS_NUMBER) 
    {
        /******************************************************************
         * Sensors reading completed without errors:
         * Update error counters if sensors performed an I2C communication
         ******************************************************************/

        /* BMP085 command sent successfully if no error occured */
        if(I2C1_SensorEnabled[BMP085_ID] && \
           (BMP085_Prescaler == 1 || BMP085_Prescaler == 6))
            BMP085_CommandSent = 1;
        
#ifdef I2C1_ERROR_CAN_LIKE_MANAGEMENT
        /* Update ADXL345 error counter */
        if(I2C1_SensorEnabled[ADXL345_ID] && \
           ++I2C1_CANPrescaler[ADXL345_ID] >= I2C_CAN_PR_THR)
        {
            if(I2C1_ErrorCounter[ADXL345_ID]) 
                I2C1_ErrorCounter[ADXL345_ID]--;
            I2C1_CANPrescaler[ADXL345_ID] = 0;
        }
        
        /* Update ITG3200 error counter */    
        if(I2C1_SensorEnabled[ITG3200_ID] && \
           ++I2C1_CANPrescaler[ITG3200_ID] >= I2C_CAN_PR_THR)
        {
            if(I2C1_ErrorCounter[ITG3200_ID]) 
                I2C1_ErrorCounter[ITG3200_ID]--;
            I2C1_CANPrescaler[ITG3200_ID] = 0;
        }
        
        /* Update HMC5883L error counter if performed an I2C operation */
        if(I2C1_SensorEnabled[HMC5883L_ID] && \
           HMC5883L_Prescaler == 5 && \
           ++I2C1_CANPrescaler[HMC5883L_ID] >= I2C_CAN_PR_THR)
        {
            if(I2C1_ErrorCounter[HMC5883L_ID]) 
                I2C1_ErrorCounter[HMC5883L_ID]--;
            I2C1_CANPrescaler[HMC5883L_ID] = 0;
        }
        
        /* Update BMP085 error counter if performed an I2C operation */
        if(I2C1_SensorEnabled[BMP085_ID] && \
           ( BMP085_Prescaler == 1 || \
           (BMP085_Prescaler == 5 && BMP085_CommandSent) || \
           BMP085_Prescaler == 6 || \
           (BMP085_Prescaler == 24 && BMP085_CommandSent) ) && \
           ++I2C1_CANPrescaler[BMP085_ID] >= I2C_CAN_PR_THR)
        {
            if(I2C1_ErrorCounter[BMP085_ID]) 
                I2C1_ErrorCounter[BMP085_ID]--;
            I2C1_CANPrescaler[BMP085_ID] = 0;
        }
#else        
        /* Update ADXL345 error counter */
        if(I2C1_SensorEnabled[ADXL345_ID]) 
            I2C1_ErrorCounter[ADXL345_ID] = 0;
        
        /* Update ITG3200 error counter */
        if(I2C1_SensorEnabled[ITG3200_ID])
            I2C1_ErrorCounter[ITG3200_ID] = 0;
        
        /* Update HMC5883L error counter if performed an I2C operation */
        if(I2C1_SensorEnabled[HMC5883L_ID] && HMC5883L_Prescaler == 5)
            I2C1_ErrorCounter[HMC5883L_ID] = 0;
        
        /* Update BMP085 error counter if performed an I2C operation */
        if(I2C1_SensorEnabled[BMP085_ID] && \
           ( BMP085_Prescaler == 1 || \
           (BMP085_Prescaler == 5 && BMP085_CommandSent) || \
           BMP085_Prescaler == 6 || \
           (BMP085_Prescaler == 24 && BMP085_CommandSent) ))
            I2C1_ErrorCounter[BMP085_ID] = 0;

        /* Update MPU9150 error counter */
        if(I2C1_SensorEnabled[MPU9150_ID]) 
            I2C1_ErrorCounter[MPU9150_ID] = 0;


#endif   
    }
    else
    {
        /******************************************************************
         * Sensors reading not completed: 
         * I2C1_Proc Sensor is the sensor where problem occurs.
         ******************************************************************/
        
#ifdef I2C1_SENSORS_TEST //coomentato daB
        USART3_Send('n');
        USART3_Send(I2C1_ProcSensor+48);
#endif
        /* Reset I2C1 peripheral */
			{
				static int trial = 0;
				trial++;
				
				if (trial > 100)
				{
					// for debug only
					//while(1);
				}					

				//run the I2C1 requested procedure at most 6 times
				I2C1_ResetRequested = 1;
				int reset_counter;
				for (reset_counter=0; reset_counter<6; reset_counter++) {
					I2C1_Reset();
					if (__HAL_I2C_GET_FLAG(&I2CHandle, I2C_FLAG_BUSY) == RESET) break;
				}
				//keep trace of total number of resets issued
				total_number_of_i2c_resets++;
				//keep stats of max number necessary resets
				if (reset_counter > max_number_of_consecutive_i2c_reset) 
					max_number_of_consecutive_i2c_reset = reset_counter;
			}
        /* Increase sensor error counter */
        if(++I2C1_ErrorCounter[I2C1_ProcSensor] >= MAX_ERROR_NUMBER)
            I2C1_SensorEnabled[I2C1_ProcSensor] = 0;
        
				//always increase total error counter for debug and stats only
				I2C1_ErrorCounterNoReset[I2C1_ProcSensor]++;
				
        /* Reset sensor measurement flag */
        switch(I2C1_ProcSensor)
        {
            case ADXL345_ID:
                I2C1_MeasFlag &= ~I2C1_ACC_MEAS;
                break;
            case ITG3200_ID:
                I2C1_MeasFlag &= ~I2C1_GYRO_MEAS;
                break;
            case HMC5883L_ID:
                I2C1_MeasFlag &= ~I2C1_MAG_MEAS;
                break;
            case BMP085_ID:
                I2C1_MeasFlag &= ~(I2C1_TEMP_MEAS | I2C1_PRES_MEAS);
                break;

            case MPU9150_ID:
                I2C1_MeasFlag &= ~I2C1_MPU_MEAS;
                break;
        }
    }
    
    /* Update input */
    BMP085_oss = input[0];
    
    /* s-function output: BMP085 new temperature measurement */
    if((I2C1_MeasFlag & I2C1_TEMP_MEAS) != 0 )
    {
        output[0] = BMP085_TempBuffer[0];
        output[1] = BMP085_TempBuffer[1];
    }
    
    /* s-function output: BMP085 new preassure measurement */
    if((I2C1_MeasFlag & I2C1_PRES_MEAS) != 0)
    {
        output[2] = BMP085_PressBuffer[0];
        output[3] = BMP085_PressBuffer[1];
        output[4] = BMP085_PressBuffer[2];
    }
    
    /* s-function output: ITG3200 new measurement */
    if((I2C1_MeasFlag & I2C1_GYRO_MEAS) != 0)
    {
        output[5] = ITG3200_Buffer[0];
        output[6] = ITG3200_Buffer[1];
        output[7] = ITG3200_Buffer[2];
        output[8] = ITG3200_Buffer[3];
        output[9] = ITG3200_Buffer[4];
        output[10] = ITG3200_Buffer[5];
    }
    
    /* s-function output: ADXL345 new measurement */
    if((I2C1_MeasFlag & I2C1_ACC_MEAS) != 0)
    {
        output[11] = ADXL345_Buffer[0];
        output[12] = ADXL345_Buffer[1];
        output[13] = ADXL345_Buffer[2];
        output[14] = ADXL345_Buffer[3];
        output[15] = ADXL345_Buffer[4];
        output[16] = ADXL345_Buffer[5];
    }
    
    /* s-function output: HMC5883L new measurement */
    if((I2C1_MeasFlag & I2C1_MAG_MEAS) != 0)
    {
        output[17] = HMC5883L_Buffer[0];
        output[18] = HMC5883L_Buffer[1];
        output[19] = HMC5883L_Buffer[2];
        output[20] = HMC5883L_Buffer[3];
        output[21] = HMC5883L_Buffer[4];
        output[22] = HMC5883L_Buffer[5];
    }

    /* s-function output: error counters */
    output[23] = I2C1_ErrorCounter[ADXL345_ID];
    output[24] = I2C1_ErrorCounter[ITG3200_ID];
    output[25] = I2C1_ErrorCounter[HMC5883L_ID];
    output[26] = I2C1_ErrorCounter[BMP085_ID];
    
    /* s-function output: sensors enabled */
    output[27] = I2C1_SensorEnabled[ADXL345_ID];
    output[28] = I2C1_SensorEnabled[ITG3200_ID];
    output[29] = I2C1_SensorEnabled[HMC5883L_ID];
    output[30] = I2C1_SensorEnabled[BMP085_ID];
    
    /* s-function output: reset requested */
    output[31] = I2C1_ResetRequested;
    
    /* s-function output[32:53] : BMP085 calibration parameters */


    /* MPU9150 section ******************************/

    /* s-function output: MPU9150 new measurement */
    if((I2C1_MeasFlag & I2C1_MPU_MEAS) != 0)
    {
        output[54] = MPU9150_Buffer[0];
        output[55] = MPU9150_Buffer[1];
        output[56] = MPU9150_Buffer[2];
        output[57] = MPU9150_Buffer[3];
        output[58] = MPU9150_Buffer[4];
        output[59] = MPU9150_Buffer[5];
        output[60] = MPU9150_Buffer[6];
        output[61] = MPU9150_Buffer[7];
        output[62] = MPU9150_Buffer[8];
        output[63] = MPU9150_Buffer[9];
        output[64] = MPU9150_Buffer[10];
        output[65] = MPU9150_Buffer[11];
        output[66] = MPU9150_Buffer[12];
        output[67] = MPU9150_Buffer[13];
    }

    /* s-function output: error counters */
    output[68] = I2C1_ErrorCounter[MPU9150_ID];
    /* s-function output: sensors enabled */
    output[69] = I2C1_SensorEnabled[MPU9150_ID];

     /* s-function output[54] : HAL status */
    output[70] = I2C1_HAL_Err_Status;

    
    /* s-function output2: measurement flags */
    output2[0] = I2C1_MeasFlag;
    
#ifdef I2C1_SENSORS_TEST
    //Single Sensors Debug.
    /*
    LED_Rosso(I2C1_SensorEnabled[ITG3200_ID]);
    LED_Verde(I2C1_SensorEnabled[ADXL345_ID]);
    LED_Blu(I2C1_SensorEnabled[HMC5883L_ID]);
    LED_Arancione(I2C1_SensorEnabled[BMP085_ID]);
    */


//NOTE: LP this section was commented out since the blue led is toggled now when i2c_reset is called
//
//All sensors Debug.
//    if (I2C1_SensorEnabled[ITG3200_ID] && I2C1_SensorEnabled[ADXL345_ID] && I2C1_SensorEnabled[HMC5883L_ID] && \
//        I2C1_SensorEnabled[BMP085_ID] && I2C1_SensorEnabled[MPU9150_ID])
//        LED_Blu(1);
//    else
//        LED_Blu(0);


    

    if(I2C1_HAL_Err_Status != HAL_OK && temp0 != 25)
    {
        USART3_Send(0x0D);
        USART3_Send('S'); USART3_Send(':'); //Sensor Enabled
        USART3_Send(output[27]+48);
        USART3_Send('.');
        USART3_Send(output[28]+48);
        USART3_Send('.');
        USART3_Send(output[29]+48);
        USART3_Send('.');
        USART3_Send(output[30]+48);
        USART3_Send('.');
	    USART3_Send(output[69]+48);
        USART3_Send(0x0D);

        USART3_Send('E'); USART3_Send(':'); //Error Counter
        USART3_Send(output[23]+48);
        USART3_Send('.');
        USART3_Send(output[24]+48);
        USART3_Send('.');
        USART3_Send(output[25]+48);
        USART3_Send('.');
        USART3_Send(output[26]+48);
        USART3_Send('.');
        USART3_Send(output[68]+48);
        USART3_Send(0x0D);

        USART3_Send('H'); USART3_Send(':'); //Hal Status
        USART3_Send(I2C1_HAL_Err_Status+48);
        USART3_Send(0x0D);
    }
    temp0 = I2C1_ErrorCounter[0] + I2C1_ErrorCounter[1] +I2C1_ErrorCounter[2] +I2C1_ErrorCounter[3] +I2C1_ErrorCounter[4];
    
#endif

    // Start new reading operation
		// if a i2c reset was not requested
		//	otherwise skip a cycle
		if (!I2C1_ResetRequested) {
			//reset I2C1_ProcSensor 
			I2C1_ProcSensor = 0;
			//set NO sensors read => the value will be filled in by the IRQ handler
			I2C1_MeasFlag = 0;
			//start new reading operation
			I2C1_ReadSensor();
		} else {
			//set fake I2C1_ProcSensor to the total numer of sensors to notify 
			//that the i2c communication chain has finished correctly 
			I2C1_ProcSensor = I2C1_SENSORS_NUMBER;
			//set NO sensors read => it will remain 0 at the next call => thus 
			//	no data will be copied from the buffer into the output wires
			I2C1_MeasFlag = 0;
			//DO NOT start new reading operation
			// => DO NOT CALL I2C1_ReadSensor();
		}
}
