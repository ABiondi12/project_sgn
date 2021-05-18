 /* ADC wrap for ICARO 3.1
   Authors: Lorenzo Tiberi, Davide Fabbroni, Francesco Bufalo. */
   
#include "rtwtypes.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_adc.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_adc_ex.h"
#include "stm32f4xx_hal_dma_ex.h"
#include "stm32f4_custom_USART.h"




/* Global Variables ********************************************************/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma1;


uint32_t uhADCxConvertedValue[4]; //Array for DMA transfer
volatile uint8_t adc_data_ready = 0; //Flag set to 1 by end of DMA transfer handler


/* Private Function Prototypes *********************************************/
void ADC1_Init(void); //ADC initialization
void ADC_Config(void); //DMA Initialization


void wrap_ADC_Receive_start_fcn(void)
{
	ADC_Config();
	ADC1_Init();
	
	/* Initialize DMA transfer */
	if (HAL_ADC_Start_DMA(&hadc1, uhADCxConvertedValue,4) != HAL_OK)
		Error_Handler();
}

void wrap_ADC_Receive_output_fcn(uint32_t *adcval)
{
	
  	if (adc_data_ready){
			adc_data_ready = 0;
			
			for (int i=0; i<4; i++)
				adcval[i] = uhADCxConvertedValue[i];
			
			HAL_ADC_Start_DMA(&hadc1, uhADCxConvertedValue,4);
						}
}


void ADC_Config() {
GPIO_InitTypeDef  GPIO_InitStruct;


	__GPIOC_CLK_ENABLE();
	__GPIOA_CLK_ENABLE();
	__ADC1_CLK_ENABLE();
	__DMA2_CLK_ENABLE();

//PC0,PC1,PC2,PC3
	GPIO_InitStruct.Pin       = GPIO_PIN_0+GPIO_PIN_3+GPIO_PIN_2+GPIO_PIN_1;
	GPIO_InitStruct.Mode      = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull      = GPIO_NOPULL;
	GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	//configure DMA
	hdma1.Instance = DMA2_Stream0;
	hdma1.Init.Channel  = DMA_CHANNEL_0;
	hdma1.Init.Direction = DMA_PERIPH_TO_MEMORY;
	hdma1.Init.PeriphInc = DMA_PINC_DISABLE;
	hdma1.Init.MemInc = DMA_MINC_ENABLE;
	hdma1.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	hdma1.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
	hdma1.Init.Mode = DMA_NORMAL;
	hdma1.Init.Priority = DMA_PRIORITY_HIGH;
	hdma1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	hdma1.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_HALFFULL;
	hdma1.Init.MemBurst = DMA_MBURST_SINGLE;
	hdma1.Init.PeriphBurst = DMA_PBURST_SINGLE;

	HAL_DMA_Init(&hdma1);

	/* Associate the initialized DMA handle to the the ADC handle */
	__HAL_LINKDMA(&hadc1, DMA_Handle, hdma1);

	/* NVIC configuration for DMA transfer complete interrupt */
	HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 6, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}

void ADC1_Init(void)
{

	
  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION12b;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.NbrOfDiscConversion = 0;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 4;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = DISABLE;
	
  if(HAL_ADC_Init(&hadc1) != HAL_OK)
	  Error_Handler();


   //Configure ADC regular channels
  sConfig.Channel = ADC_CHANNEL_10; //PC0
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;
  sConfig.Offset = 0;

  if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		Error_Handler();
  
	
  sConfig.Channel = ADC_CHANNEL_13; //PC3
  sConfig.Rank = 2;
  if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		Error_Handler();
	
	
  sConfig.Channel = ADC_CHANNEL_12; //PC2
  sConfig.Rank = 3;
  if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		Error_Handler();
	
  sConfig.Channel = ADC_CHANNEL_11; //PC1
  sConfig.Rank = 4;
  if(HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		Error_Handler();
	
}


//Interrupt Handler DMA2
void DMA2_Stream0_IRQHandler()
{
	HAL_DMA_IRQHandler(&hdma1);
}
	
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
{
	HAL_ADC_Stop_DMA(AdcHandle);
	adc_data_ready = 1;

}



