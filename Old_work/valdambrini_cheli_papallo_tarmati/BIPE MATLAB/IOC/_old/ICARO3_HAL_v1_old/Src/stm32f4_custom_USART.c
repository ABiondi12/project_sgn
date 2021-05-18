#include "stm32f4_custom_USART.h"

// DRIVER FOR USART 2,3,4,5 


//
//  SELECT PINs and BAUD rate
//

//USART 2
#define USART2_BAUD_RATE 115200
#define USART2_ON_PA2_PA3
//#define USART2_ON_PD5_PD6


//USART 3
#define USART3_BAUD_RATE 115200
#define USART3_ON_PC10_PC11
//#define USART3_ON_PD8_PD9


//USART 4
#define USART4_BAUD_RATE 115200
//#define USART4_ON_PC10_PC11
#define USART4_ON_PA0_PA1

//USART 5 (ONLY ONE PIN PACK FOR THIS)
#define USART5_BAUD_RATE 115200
#define USART5_ON_PC12_PD2


#define USART_BUFFER_DIM 1024


//buffers for USART 2 
static CircularBuffer USART2_RX_CB;
static uint8_t USART2_RX_BUFF[USART_BUFFER_DIM];
static CircularBuffer USART2_TX_CB;
static uint8_t USART2_TX_BUFF[USART_BUFFER_DIM];
//buffers for USART 3 
static CircularBuffer USART3_RX_CB;
static uint8_t USART3_RX_BUFF[USART_BUFFER_DIM];
static CircularBuffer USART3_TX_CB;
static uint8_t USART3_TX_BUFF[USART_BUFFER_DIM];
//buffers for USART 4 
static CircularBuffer USART4_RX_CB;
static uint8_t USART4_RX_BUFF[USART_BUFFER_DIM];
static CircularBuffer USART4_TX_CB;
static uint8_t USART4_TX_BUFF[USART_BUFFER_DIM];
//buffers for USART 5
static CircularBuffer USART5_RX_CB;
static uint8_t USART5_RX_BUFF[USART_BUFFER_DIM];
static CircularBuffer USART5_TX_CB;
static uint8_t USART5_TX_BUFF[USART_BUFFER_DIM];

/* NEW: */
UART_HandleTypeDef 			Uart2Handle;
UART_HandleTypeDef 			Uart3Handle;
UART_HandleTypeDef 			Uart4Handle;		
UART_HandleTypeDef 			Uart5Handle;


void SetLed(uint32_t pin, uint32_t mode){
	
	GPIO_InitTypeDef       GPIO_InitStructure;
	
	GPIO_InitStructure.Pin = pin;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 
    GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
    GPIO_InitStructure.Pull  = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	if(mode == 1)
		HAL_GPIO_WritePin(GPIOD,pin,GPIO_PIN_SET);
	else
		HAL_GPIO_TogglePin(GPIOD,pin);
} 

/** 
  * @brief  USART2 interrupt handler.
  * @note   Use USART_GetITStatus to check what event generated the interrupt.
  * @retval None.
  */
 
  
  
void USART2_IRQHandler()
{		
		
		/* UART1 in mode Receiver ---------------------------------------------------*/
		uint32_t tmp1 = __HAL_UART_GET_FLAG(&Uart2Handle, UART_FLAG_RXNE);
		uint32_t tmp2 = __HAL_UART_GET_IT_SOURCE(&Uart2Handle, UART_IT_RXNE);
        //OLD: if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
		if((tmp1 != RESET) && (tmp2 != RESET))		{
				// RX interrupt: new data received from USART
        CircularBuffer_Write(&USART2_RX_CB, Uart2Handle.Instance->DR); //OLD: USART2->DR);
		
		
		}
		
		/* UART1 in mode Transmitter ------------------------------------------------*/
		tmp1 = __HAL_UART_GET_FLAG(&Uart2Handle, UART_FLAG_TXE);
		tmp2 = __HAL_UART_GET_IT_SOURCE(&Uart2Handle, UART_IT_TXE);
		//OLD: if(USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
		if((tmp1 != RESET) && (tmp2 != RESET)){
			// TX interrupt: data correctly transmitted 
			uint8_t item;
      /* Check if there are data to be transmitted, otherwise disable
       * TX interrupts */
      if(CircularBuffer_Read(&USART2_TX_CB, &item))
            Uart2Handle.Instance->DR = item; //OLD. USART2->DR = item;
      else
			// TX buffer is empty => Disable the UART Transmit data register empty Interrupt
			__HAL_UART_DISABLE_IT(&Uart2Handle, UART_IT_TXE);
					
    }
	
}

/** 
  * @brief  USART3 interrupt handler.
  * @note   Use USART_GetITStatus to check what event generated the interrupt.
  * @retval None.
  */
void USART3_IRQHandler()
{
		
		/* UART1 in mode Receiver ---------------------------------------------------*/
		uint32_t tmp1 = __HAL_UART_GET_FLAG(&Uart3Handle, UART_FLAG_RXNE);
		uint32_t tmp2 = __HAL_UART_GET_IT_SOURCE(&Uart3Handle, UART_IT_RXNE);
        //OLD: if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
		if((tmp1 != RESET) && (tmp2 != RESET))		{
				// RX interrupt: new data received from USART
        CircularBuffer_Write(&USART3_RX_CB, Uart3Handle.Instance->DR); //OLD: USART3->DR);
		}
		
		/* UART1 in mode Transmitter ------------------------------------------------*/
		tmp1 = __HAL_UART_GET_FLAG(&Uart3Handle, UART_FLAG_TXE);
		tmp2 = __HAL_UART_GET_IT_SOURCE(&Uart3Handle, UART_IT_TXE);
		//OLD: if(USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
		if((tmp1 != RESET) && (tmp2 != RESET)){
			// TX interrupt: data correctly transmitted 
			uint8_t item;
      /* Check if there are data to be transmitted, otherwise disable
       * TX interrupts */
      if(CircularBuffer_Read(&USART3_TX_CB, &item))
            Uart3Handle.Instance->DR = item; //OLD. USART3->DR = item;
      else
					// TX buffer is empty => Disable the UART Transmit data register empty Interrupt
					__HAL_UART_DISABLE_IT(&Uart3Handle, UART_IT_TXE);
    }
}

/** 
  * @brief  USART4 interrupt handler.
  * @note   Use USART_GetITStatus to check what event generated the interrupt.
  * @retval None.
  */

void UART4_IRQHandler()
{
		// UART1 in mode Receiver ---------------------------------------------------
		uint32_t tmp1 = __HAL_UART_GET_FLAG(&Uart4Handle, UART_FLAG_RXNE);
		uint32_t tmp2 = __HAL_UART_GET_IT_SOURCE(&Uart4Handle, UART_IT_RXNE);
        //OLD: if(USART_GetITStatus(USART4, USART_IT_RXNE) != RESET)
		if((tmp1 != RESET) && (tmp2 != RESET))		{
				// RX interrupt: new data received from USART
        CircularBuffer_Write(&USART4_RX_CB, Uart4Handle.Instance->DR); //OLD: USART2->DR);
		}
		
		// UART1 in mode Transmitter ------------------------------------------------
		tmp1 = __HAL_UART_GET_FLAG(&Uart4Handle, UART_FLAG_TXE);
		tmp2 = __HAL_UART_GET_IT_SOURCE(&Uart4Handle, UART_IT_TXE);
		//OLD: if(USART_GetITStatus(USART4, USART_IT_TXE) != RESET)
		if((tmp1 != RESET) && (tmp2 != RESET)){
			// TX interrupt: data correctly transmitted 
			uint8_t item;
      // Check if there are data to be transmitted, otherwise disable
       // TX interrupts 
      if(CircularBuffer_Read(&USART4_TX_CB, &item))
            Uart4Handle.Instance->DR = item; //OLD. USART4->DR = item;
      else
					// TX buffer is empty => Diable the UART Transmit data register empty Interrupt
					__HAL_UART_DISABLE_IT(&Uart4Handle, UART_IT_TXE);
    }
}

/** 
  * @brief  USART4 interrupt handler.
  * @note   Use USART_GetITStatus to check what event generated the interrupt.
  * @retval None.
  */

void UART5_IRQHandler()
{
    // UART1 in mode Receiver ---------------------------------------------------
    uint32_t tmp1 = __HAL_UART_GET_FLAG(&Uart5Handle, UART_FLAG_RXNE);
    uint32_t tmp2 = __HAL_UART_GET_IT_SOURCE(&Uart5Handle, UART_IT_RXNE);
        //OLD: if(USART_GetITStatus(USART4, USART_IT_RXNE) != RESET)
    if((tmp1 != RESET) && (tmp2 != RESET))    {
        // RX interrupt: new data received from USART
        CircularBuffer_Write(&USART5_RX_CB, Uart5Handle.Instance->DR); //OLD: USART2->DR);
    }
    
    // UART1 in mode Transmitter ------------------------------------------------
    tmp1 = __HAL_UART_GET_FLAG(&Uart5Handle, UART_FLAG_TXE);
    tmp2 = __HAL_UART_GET_IT_SOURCE(&Uart5Handle, UART_IT_TXE);
    //OLD: if(USART_GetITStatus(USART4, USART_IT_TXE) != RESET)
    if((tmp1 != RESET) && (tmp2 != RESET)){
      // TX interrupt: data correctly transmitted 
      uint8_t item;
      // Check if there are data to be transmitted, otherwise disable
       // TX interrupts 
      if(CircularBuffer_Read(&USART5_TX_CB, &item))
            Uart5Handle.Instance->DR = item; //OLD. USART4->DR = item;
      else
          // TX buffer is empty => Diable the UART Transmit data register empty Interrupt
          __HAL_UART_DISABLE_IT(&Uart5Handle, UART_IT_TXE);
    }
}



/* USARTx INITIALIZATION:                       *
*************************************************/

  /** @brief  USART2 initialization function.
  * @note   Peripheral initialization is performed by ST block. Here RX and
  *         TX CircularBuffer are initialized, and USART interrupt are enabled.
  * @retval None.
  */  

void USART2_Init()
{
	
    // Struct for GPIO and USART initialization
    GPIO_InitTypeDef 		GPIO_InitStruct;
    //USART_InitTypeDef 		USART_InitStruct;
	/*
    USART_ClockInitTypeDef 	USART_ClockInitStruct;
    NVIC_InitTypeDef 		NVIC_InitStruct; 
	*/

#ifdef USART2_ON_PA2_PA3
    // Enable GPIOA clock
	__GPIOA_CLK_ENABLE();
	__USART2_CLK_ENABLE();
	
    // Set USART TX pin (PA2)
    GPIO_InitStruct.Pin 		= GPIO_PIN_2;
    GPIO_InitStruct.Mode 		= GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed 		= GPIO_SPEED_FAST;
    GPIO_InitStruct.Pull 		= GPIO_NOPULL;
    GPIO_InitStruct.Alternate 	= GPIO_AF7_USART2;
	
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	// Set USART RX in (PA3) with Pull-Up resistence on
    GPIO_InitStruct.Pin 		= GPIO_PIN_3;
    GPIO_InitStruct.Pull		= GPIO_PULLUP;
	
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
	
#endif
#ifdef USART2_ON_PD5_PD6
	// Enable GPIOD clock
	__GPIOA_CLK_ENABLE();
	__USART2_CLK_ENABLE();
	
    // Set USART TX pin (PD5)
    GPIO_InitStruct.Pin 		= GPIO_PIN_5;
    GPIO_InitStruct.Mode 		= GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed 		= GPIO_SPEED_FAST;
    GPIO_InitStruct.Pull 		= GPIO_NOPULL;
	GPIO_InitStruct.Alternate 	= GPIO_AF7_USART2;
	
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
    // Set USART RX in (PD6) with Pull-Up resistence on
    GPIO_InitStruct.Pin			= GPIO_PIN_6;
    GPIO_InitStruct.Pull 		= GPIO_PULLUP;
	
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct); 
	
	

	
#endif
    
    // USART clock enable
	__USART2_CLK_ENABLE();
  
	// Configure peripheral
	Uart2Handle.Instance		= USART2;
	Uart2Handle.Init.BaudRate	= USART2_BAUD_RATE;
	Uart2Handle.Init.WordLength = UART_WORDLENGTH_8B;
	Uart2Handle.Init.StopBits	= UART_STOPBITS_1;
	Uart2Handle.Init.Parity		= UART_PARITY_NONE;
	Uart2Handle.Init.HwFlowCtl	= UART_HWCONTROL_NONE;
	Uart2Handle.Init.Mode		= UART_MODE_TX_RX;
	
	//USART internal clock?
	
    // RX and TX CircularBuffer initialization
    CircularBuffer_Init(&USART2_TX_CB, USART2_TX_BUFF, USART_BUFFER_DIM);
    CircularBuffer_Init(&USART2_RX_CB, USART2_RX_BUFF, USART_BUFFER_DIM);
    
    // Enable USART2 RX interrupt
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	
	//Enable the UART Transmit data register empty Interrupt
	//	=> as soon as a byte is received the IRQ handler is called. 
	//	DO NOT enable here the TXE interrupt, it will be enabled whne data is sent 
	//	and automatically disabled when data to be sent is finished (buffer empty)
    __HAL_UART_ENABLE_IT(&Uart2Handle, UART_IT_RXNE);
	
    /* Enable USART */
    //OLD: USART_Cmd(USART2, ENABLE);
		if(HAL_UART_Init(&Uart2Handle) != HAL_OK)
		{
			Error_Handler();
		}
}

/** 
  * @brief  USART3 initialization function.
  * @note   Peripheral initialization is performed by ST block. Here RX and
  *          TX CircularBuffer are initialized, and USART interrupt are enabled.
  * @retval None.
  */
void USART3_Init()
{   
    // Struct for GPIO and USART initialization
    GPIO_InitTypeDef 		GPIO_InitStruct;
    //USART_InitTypeDef 		USART_InitStruct;
	/*
    USART_ClockInitTypeDef 	USART_ClockInitStruct;
    NVIC_InitTypeDef 		NVIC_InitStruct;
	*/

#ifdef USART3_ON_PC10_PC11
    // Enable GPIOC clock
	__GPIOC_CLK_ENABLE();
	__USART3_CLK_ENABLE();
	
    // Set USART TX pin (PC10)
    GPIO_InitStruct.Pin 		= GPIO_PIN_10;
    GPIO_InitStruct.Mode 		= GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed 		= GPIO_SPEED_FAST;
    GPIO_InitStruct.Pull 		= GPIO_NOPULL;
	GPIO_InitStruct.Alternate 	= GPIO_AF7_USART3;
	
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
    // Set USART RX in (PC11) with Pull-Up resistance on
    GPIO_InitStruct.Pin 		= GPIO_PIN_11;
    GPIO_InitStruct.Pull		= GPIO_PULLUP;
	
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

#endif
#ifdef USART3_ON_PD8_PD9
    // Enable GPIOD clock
	__GPIOD_CLK_ENABLE();
	__USART3_CLK_ENABLE();
	
    // Set USART TX pin (PD8)
    GPIO_InitStruct.Pin 		= GPIO_PIN_8;
    GPIO_InitStruct.Mode 		= GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed 		= GPIO_SPEED_FAST;
    GPIO_InitStruct.Pull 		= GPIO_NOPULL;
	GPIO_InitStruct.Alternate 	= GPIO_AF7_USART3;
	
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
    // Set USART RX in (PD9) with Pull-Up resistence on
    GPIO_InitStruct.Pin 		= GPIO_PIN_9;
    GPIO_InitStruct.Pull		= GPIO_PULLUP;
	
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

#endif    
    
    // USART clock enable
	__USART3_CLK_ENABLE(); // ???????
      
	// Configure peripheral
	Uart3Handle.Instance		= USART3;
	Uart3Handle.Init.BaudRate	= USART3_BAUD_RATE;
	Uart3Handle.Init.WordLength = UART_WORDLENGTH_8B;
	Uart3Handle.Init.StopBits	= UART_STOPBITS_1;
	Uart3Handle.Init.Parity		= UART_PARITY_NONE;
	Uart3Handle.Init.HwFlowCtl	= UART_HWCONTROL_NONE;
	Uart3Handle.Init.Mode		= UART_MODE_TX_RX;
    
    // RX and TX CircularBuffer initialization
    CircularBuffer_Init(&USART3_TX_CB, USART3_TX_BUFF, USART_BUFFER_DIM);
    CircularBuffer_Init(&USART3_RX_CB, USART3_RX_BUFF, USART_BUFFER_DIM);
    
    // Enable USART3 RX interrupt
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART3_IRQn);
	
	//Enable the UART Transmit data register empty Interrupt
	//	=> as soon as a byte is received the IRQ handler is called.
	//	DO NOT enable here the TXE interrupt, it will be enabled whne data is sent 
	//	and automatically disabled when data to be sent is finished (buffer empty)
    __HAL_UART_ENABLE_IT(&Uart3Handle, UART_IT_RXNE);
	
    // Enable USART
    //OLD: USART_Cmd(USART3, ENABLE);
		if(HAL_UART_Init(&Uart3Handle) != HAL_OK)
		{
			Error_Handler();
		}
		
}

/** 
  * @brief  USART4 initialization function.
  * @note   Peripheral initialization is performed by ST block. Here RX and
  *          TX CircularBuffer are initialized, and USART interrupt are enabled.
  * @retval None.
  */
  

void USART4_Init()
{
    // Struct for GPIO and USART initialization
    GPIO_InitTypeDef GPIO_InitStruct;
    //USART_InitTypeDef USART_InitStruct;
	
    // USART_ClockInitTypeDef USART_ClockInitStruct;
    // NVIC_InitTypeDef NVIC_InitStruct;
	
  
#ifdef USART4_ON_PA0_PA1
    // Enable GPIOA clock
	__GPIOA_CLK_ENABLE();
	__UART4_CLK_ENABLE();
	
    // Set USART TX pin (PA0)
    GPIO_InitStruct.Pin 		= GPIO_PIN_0;
    GPIO_InitStruct.Mode 		= GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed 		= GPIO_SPEED_FAST;
    GPIO_InitStruct.Pull 		= GPIO_NOPULL;
	GPIO_InitStruct.Alternate 	= GPIO_AF8_UART4;
	
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
    // Set USART RX in (PA1) with Pull-Up resistence on
    GPIO_InitStruct.Pin 		= GPIO_PIN_1;
    GPIO_InitStruct.Pull		= GPIO_PULLUP;
	
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

#endif
#ifdef USART4_ON_PC10_PC11
    // Enable GPIOC clock
	__GPIOC_CLK_ENABLE();
	__UART4_CLK_ENABLE();
	
    // Set USART TX pin (PA0)
    GPIO_InitStruct.Pin 		= GPIO_PIN_10;
    GPIO_InitStruct.Mode 		= GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed 		= GPIO_SPEED_FAST;
    GPIO_InitStruct.Pull 		= GPIO_NOPULL;
	GPIO_InitStruct.Alternate 	= GPIO_AF8_UART4;
	
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
    // Set USART RX in (PC11) with Pull-Up resistence on
    GPIO_InitStruct.Pin 		= GPIO_PIN_11;
    GPIO_InitStruct.Pull		= GPIO_PULLUP;
	
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

#endif  
    
    // USART clock enable
	__UART4_CLK_ENABLE();
  
	// Configure peripheral
	Uart4Handle.Instance		= UART4;
	Uart4Handle.Init.BaudRate	= USART4_BAUD_RATE;
	Uart4Handle.Init.WordLength = UART_WORDLENGTH_8B;
	Uart4Handle.Init.StopBits	= UART_STOPBITS_1;
	Uart4Handle.Init.Parity		= UART_PARITY_NONE;
	Uart4Handle.Init.HwFlowCtl	= UART_HWCONTROL_NONE;
	Uart4Handle.Init.Mode		= UART_MODE_TX_RX;
    
    // RX and TX CircularBuffer initialization 
    CircularBuffer_Init(&USART4_TX_CB, USART4_TX_BUFF, USART_BUFFER_DIM);
    CircularBuffer_Init(&USART4_RX_CB, USART4_RX_BUFF, USART_BUFFER_DIM);
    
    // Enable USART3 RX interrupt
    HAL_NVIC_SetPriority(UART4_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(UART4_IRQn);
	
	//Enable the UART Transmit data register empty Interrupt
	//	=> as soon as a byte is received the IRQ handler is called.
	//	DO NOT enable here the TXE interrupt, it will be enabled whne data is sent 
	//	and automatically disabled when data to be sent is finished (buffer empty)
    __HAL_UART_ENABLE_IT(&Uart4Handle, UART_IT_RXNE);
	
    // Enable USART 
    //OLD: USART_Cmd(USART2, ENABLE);
		if(HAL_UART_Init(&Uart4Handle) != HAL_OK)
		{
			Error_Handler();
		}
}


/** 
  * @brief  USART5 initialization function.
  * @note   Peripheral initialization is performed by ST block. Here RX and
  *          TX CircularBuffer are initialized, and USART interrupt are enabled.
  * @retval None.
  */
  

void USART5_Init()
{
    // Struct for GPIO and USART initialization
    GPIO_InitTypeDef GPIO_InitStruct;
    //USART_InitTypeDef USART_InitStruct;
  
    // USART_ClockInitTypeDef USART_ClockInitStruct;
    // NVIC_InitTypeDef NVIC_InitStruct;
  
  
#ifdef USART5_ON_PC12_PD2
    // Enable GPIOA clock
  __GPIOC_CLK_ENABLE();
  __GPIOD_CLK_ENABLE();
  __UART5_CLK_ENABLE();
  
    // Set USART TX pin (PC12)
    GPIO_InitStruct.Pin     = GPIO_PIN_12;
    GPIO_InitStruct.Mode    = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
    GPIO_InitStruct.Pull    = GPIO_NOPULL;
    GPIO_InitStruct.Alternate   = GPIO_AF8_UART5;
  
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  
    // Set USART RX in (PD2) with Pull-Up resistence on
    GPIO_InitStruct.Pin     = GPIO_PIN_2;
    GPIO_InitStruct.Pull    = GPIO_PULLUP;
  
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

#endif
    
    // USART clock enable
  __UART5_CLK_ENABLE();
  
  // Configure peripheral
  Uart5Handle.Instance    = UART5;
  Uart5Handle.Init.BaudRate = USART5_BAUD_RATE;
  Uart5Handle.Init.WordLength = UART_WORDLENGTH_8B;
  Uart5Handle.Init.StopBits = UART_STOPBITS_1;
  Uart5Handle.Init.Parity   = UART_PARITY_NONE;
  Uart5Handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  Uart5Handle.Init.Mode   = UART_MODE_TX_RX;
    
    // RX and TX CircularBuffer initialization 
    CircularBuffer_Init(&USART5_TX_CB, USART5_TX_BUFF, USART_BUFFER_DIM);
    CircularBuffer_Init(&USART5_RX_CB, USART5_RX_BUFF, USART_BUFFER_DIM);
    
    // Enable USART3 RX interrupt
    HAL_NVIC_SetPriority(UART5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(UART5_IRQn);
  
  //Enable the UART Transmit data register empty Interrupt
  //  => as soon as a byte is received the IRQ handler is called.
  //  DO NOT enable here the TXE interrupt, it will be enabled whne data is sent 
  //  and automatically disabled when data to be sent is finished (buffer empty)
    __HAL_UART_ENABLE_IT(&Uart5Handle, UART_IT_RXNE);
  
    // Enable USART 
    //OLD: USART_Cmd(USART2, ENABLE);
    if(HAL_UART_Init(&Uart5Handle) != HAL_OK)
    {
      Error_Handler();
    }
}



/* USARTx SEND/RECEIVE:                       *
*************************************************/

/** 
  * @brief  USART2 send function.
  * @param  data: uint8_t to send. 
  * @retval The function returns
  *          - 1: if data is correctly written into the TX CircularBuffer.
  *          - 0: otherwise.
  * @note   To allow data transmission, TX interrupt must be enabled when
  *          a new data is inserted into the TX CircularBuffer.
  */
uint8_t USART2_Send(uint8_t data)
{
    if(CircularBuffer_Write(&USART2_TX_CB, data))
    {
			  /* Enable the UART Data Register not empty Interrupt */
				__HAL_UART_ENABLE_IT(&Uart2Handle, UART_IT_TXE);
        return 1;
    }
    else
        return 0;
}

/** 
  * @brief  USART3 send function.
  * @param  data: uint8_t to send. 
  * @retval The function returns
  *          - 1: if data is correctly written into the TX CircularBuffer.
  *          - 0: otherwise.
  * @note   To allow data transmission, TX interrupt must be enabled when
  *          a new data is inserted into the TX CircularBuffer.
  */
uint8_t USART3_Send(uint8_t data)
{
    if(CircularBuffer_Write(&USART3_TX_CB, data))
    {
			  /* Enable the UART Data Register not empty Interrupt */
				__HAL_UART_ENABLE_IT(&Uart3Handle, UART_IT_TXE);
        return 1;
    }
    else
        return 0;
}


/** 
  * @brief  USART4 send function.
  * @param  data: uint8_t to send. 
  * @retval The function returns
  *          - 1: if data is correctly written into the TX CircularBuffer.
  *          - 0: otherwise.
  * @note   To allow data transmission, TX interrupt must be enabled when
  *          a new data is inserted into the TX CircularBuffer.
  */
uint8_t USART4_Send(uint8_t data)
{
    if(CircularBuffer_Write(&USART4_TX_CB, data))
    {
        /* Enable the UART Data Register not empty Interrupt */
        __HAL_UART_ENABLE_IT(&Uart4Handle, UART_IT_TXE);
        return 1;
    }
    else
        return 0;
}

/** 
  * @brief  USART5 send function.
  * @param  data: uint8_t to send. 
  * @retval The function returns
  *          - 1: if data is correctly written into the TX CircularBuffer.
  *          - 0: otherwise.
  * @note   To allow data transmission, TX interrupt must be enabled when
  *          a new data is inserted into the TX CircularBuffer.
  */
uint8_t USART5_Send(uint8_t data)
{
    if(CircularBuffer_Write(&USART5_TX_CB, data))
    {
        /* Enable the UART Data Register not empty Interrupt */
        __HAL_UART_ENABLE_IT(&Uart5Handle, UART_IT_TXE);
        return 1;
    }
    else
        return 0;
}


/** 
  * @brief  USART2 receive function.
  * @param  data: pointer to the memory area where the data will be stored. 
  * @retval The function returns
  *          - 1: if a data is correctly read from the receive CircularBuffer;
  *          - 0: otherwise.
  */
uint8_t USART2_Receive(uint8_t* data)
{
    return CircularBuffer_Read(&USART2_RX_CB, data);
}

/** 
  * @brief  USART3 receive function.
  * @param  data: pointer to the memory area where the data will be stored. 
  * @retval The function returns
  *          - 1: if a data is correctly read from the receive CircularBuffer;
  *          - 0: otherwise.
  */
uint8_t USART3_Receive(uint8_t* data)
{
    return CircularBuffer_Read(&USART3_RX_CB, data);
}

/** 
  * @brief  USART4 receive function.
  * @param  data: pointer to the memory area where the data will be stored. 
  * @retval The function returns
  *          - 1: if a data is correctly read from the receive CircularBuffer;
  *          - 0: otherwise.
  */
  
uint8_t USART4_Receive(uint8_t* data)
{
    return CircularBuffer_Read(&USART4_RX_CB, data);
}


/** 
  * @brief  USART5 receive function.
  * @param  data: pointer to the memory area where the data will be stored. 
  * @retval The function returns
  *          - 1: if a data is correctly read from the receive CircularBuffer;
  *          - 0: otherwise.
  */
  
uint8_t USART5_Receive(uint8_t* data)
{
    return CircularBuffer_Read(&USART5_RX_CB, data);
}


void Error_Handler(void)
{
	SetLed(GPIO_PIN_14,1); //Error Led. (Red?)
  while(1);
}
