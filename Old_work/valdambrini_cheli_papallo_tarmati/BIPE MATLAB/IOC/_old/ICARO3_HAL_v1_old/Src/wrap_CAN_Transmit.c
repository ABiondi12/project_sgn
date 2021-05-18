/************************************
* #include "rtwtypes.h"             *
* #include <stdio.h>                *
* #include "stm32f4xx.h"            *
* #include "stm32f4xx_can.h"        *
* #include "stm32f4xx_gpio.h"       *
* #include "stm32f4xx_rcc.h"        *
* #include "stm32f4xx_tim.h"        *
* #include "misc.h"                 *
* #include "stm32f4_custom_USART.h" *
*************************************/
#include "rtwtypes.h"
#include <stdio.h>
#include  "stm32f4xx_hal.h"
#include  "stm32f4xx_hal_can.h"
#include  "stm32f4xx_hal_gpio.h"
#include  "stm32f4xx_hal_rcc.h"
#include  "stm32f4xx_hal_tim.h"
//#include  "misc.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4_custom_USART.h"

#define CANx                       CAN1


extern CAN_HandleTypeDef CAN_HandleStructure;

void wrap_CAN_Transmit_start_fcn()
{   
}



void wrap_CAN_Transmit_output_fcn(double id, uint8_T* data,uint8_T dlc){
int i=0;  

CanTxMsgTypeDef msg;


// CanTxMsg msg;
 
  // Preparazione del messaggio
  msg.StdId = (uint32_T) id;
  msg.ExtId = 0x0; 
  msg.RTR = CAN_RTR_DATA;
  msg.IDE = CAN_ID_STD;
  msg.DLC = dlc;
  for (i=0;i<dlc;i++)
    msg.Data[i] = data[i];  
  
/*******************************************************************
* Nel passaggio da SPL a HAL è cambiata la funzione CAN_Transmit   *
* e in particolare il modo in cui gli vengono forniti gli ingressi *
* quindi risulta necessario definire i campi della nuova struttura *
* Can_HandleTypeDef:											   *
********************************************************************/

 /*
  CAN_HandleStructure.Instance = CAN1;
  CAN_HandleStructure.Init.Prescaler = 8;
  CAN_HandleStructure.Init.Mode = CAN_MODE_NORMAL;
  CAN_HandleStructure.Init.SJW = CAN_SJW_1TQ;
  CAN_HandleStructure.Init.BS1 = CAN_BS1_14TQ;
  CAN_HandleStructure.Init.BS2 = CAN_BS2_6TQ;
  CAN_HandleStructure.Init.TTCM = DISABLE;
  CAN_HandleStructure.Init.ABOM = DISABLE;
  CAN_HandleStructure.Init.AWUM = DISABLE;
  CAN_HandleStructure.Init.NART = DISABLE;
  CAN_HandleStructure.Init.RFLM = DISABLE;
  CAN_HandleStructure.Init.TXFP = DISABLE; 
 */
  CAN_HandleStructure.pTxMsg = &msg;
  
  if (HAL_CAN_Init(&CAN_HandleStructure) != HAL_OK)
	  SetLed(GPIO_PIN_14,1);

  if(HAL_CAN_Transmit(&CAN_HandleStructure,1) != HAL_OK)
		SetLed(GPIO_PIN_15,1);
  //Debugging USART2
  /*for (int i=0;i<dlc;i++)
	USART2_Send((uint8_t)msg.Data[i]);*/
		



// CAN_Transmit(CANx,&msg);
}

