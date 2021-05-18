
#include "stm32f4_LED_debug.h"

void LED_OnOff(uint16_t LED_Pin, uint8_t status)
{
    if(status == 1)
        HAL_GPIO_WritePin(GPIOD, LED_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(GPIOD, LED_Pin, GPIO_PIN_RESET);
}

	
	