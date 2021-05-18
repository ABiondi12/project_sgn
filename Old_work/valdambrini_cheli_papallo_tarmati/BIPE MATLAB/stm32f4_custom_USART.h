#ifndef __STM32F4_CUSTOM_USART_H__
#define __STM32F4_CUSTOM_USART_H__

/**
  * @brief  Include ST libraries (for USART peripheral management) and
  *         CircularBuffer header.
  */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_usart.h"
#include "stm32f4xx_hal_uart.h"
#include "circular_buffer.h"

/* ERROR HANDLER */
void Error_Handler(void);
void SetLed(uint32_t pin, uint32_t mode);

/* USART interrupt handlers ***********************************************/
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void UART4_IRQHandler(void);
void UART5_IRQHandler(void);


/* USART initialization functions *****************************************/
void USART2_Init(void);
void USART3_Init(void);
void USART4_Init(void);
void USART5_Init(void);

/* Send and receive functions *********************************************/
uint8_t USART2_Send(uint8_t data);
uint8_t USART2_Receive(uint8_t* data);
uint8_t USART3_Send(uint8_t data);
uint8_t USART3_Receive(uint8_t* data);
uint8_t USART4_Send(uint8_t data);
uint8_t USART4_Receive(uint8_t* data);
uint8_t USART5_Send(uint8_t data);
uint8_t USART5_Receive(uint8_t* data);


#endif
