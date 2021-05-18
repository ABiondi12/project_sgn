
#include "stm32f4xx_hal.h"
#include <stddef.h>

void LED_OnOff(uint16_t LED_Pin, uint8_t status);

#define LED_BluPin              (uint16_t)32768
#define LED_RossoPin            (uint16_t)16384
#define LED_ArancionePin        (uint16_t)8192
#define LED_VerdePin            (uint16_t)4096
#define LED_GialloPin			(uint16_t)128

#define LED_Blu(status)         LED_OnOff(LED_BluPin, status)
#define LED_Rosso(status)       LED_OnOff(LED_RossoPin, status)
#define LED_Arancione(status)   LED_OnOff(LED_ArancionePin, status)
#define LED_Verde(status)       LED_OnOff(LED_VerdePin, status)
#define LED_Giallo(status)		HAL_GPIO_WritePin(GPIOA, LED_GialloPin, status)
