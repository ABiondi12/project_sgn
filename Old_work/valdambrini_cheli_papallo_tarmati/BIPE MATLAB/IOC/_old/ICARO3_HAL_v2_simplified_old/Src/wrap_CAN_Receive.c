#include "rtwtypes.h"
#include <stdio.h>
#include "stm32f4_custom_USART.h"
#include  "stm32f4xx_hal.h"
#include  "stm32f4xx_hal_can.h"
#include  "stm32f4xx_hal_gpio.h"
#include  "stm32f4xx_hal_rcc.h"
#include  "stm32f4xx_hal_tim.h"
//#include  "misc.h"
#include "stm32f4xx_hal_cortex.h" //HAL version of "misc.h"

    

#define CANx                       CAN1
//#define CAN_CLK                    RCC_APB1Periph_CAN1
#define CAN_RX_PIN                 GPIO_PIN_0
#define CAN_TX_PIN                 GPIO_PIN_1
#define CAN_GPIO_PORT              GPIOD
//#define CAN_GPIO_CLK               RCC_AHB1Periph_GPIOD
#define CAN_AF_PORT                GPIO_AF_CAN1
//#define CAN_RX_SOURCE              GPIO_PinSource0
//#define CAN_TX_SOURCE              GPIO_PinSource1
#define MAX_ID 10 // INDICA IL MASSIMO NUMERO DI ID CONSENTITO

/* Private function prototypes -----------------------------------------------*/
static void NVIC_Config(void); // Configura le interrupt
static void CAN_Config(void);  // Configura la periferica 


 // Variabili messaggio, utilizzate per il doppio buffer  GLOBALI   
CanRxMsgTypeDef  msgA;
CanRxMsgTypeDef  msgB;

CAN_HandleTypeDef  CAN_HandleStructure; 



// Variabili utilizzate per tenere in memoria i messaggi inviati
uint8_T msg_memA[8*MAX_ID],msg_memB[8*MAX_ID];
int num_id;// numero id
uint32_T ids[MAX_ID]; // Array contenente gli id


// Serve per selezionare msgA o msgB (buffer su cui leggere/scrivere)
int sel=0; 



void wrap_CAN_Receive_start_fcn(uint32_T* id,double nid)
{  
   int i=0;
  // Mi creo una variabile globale per memorizzare quanti sono gli id  
  num_id=nid;  
  // Mi creo una variabile globale con tutti gli id
  for (i=0;i<nid;i++)
      ids[i]=id[i];
    
  /* NVIC configuration */
  NVIC_Config();
   
  /* CAN configuration */
  CAN_Config();   
}




void wrap_CAN_Receive_output_fcn(uint8_T* data,uint32_T* id,double nid,uint8_T* newpacket)
{ 
    int i=0; // Contatore ID
    static uint8_T oldsel=0; // Valore di sel fino al passo precedente
    
    // Lettura dal buffer A
    if (sel == 1){
        if (oldsel!=sel)
            newpacket[0]=1; // L'uscita è stata aggiornata
        else
            newpacket[0]=0; // L'uscita non è stata aggiornata
        
        oldsel=sel; // Aggiorna oldsel
        
        for(i=0;i<nid*8;i++)
            data[i]=msg_memA[i];
		// Scrittura in uscita del Buffer
    }
        
    // Lettura dal buffer B
    else{
        if (oldsel!=sel)
            newpacket[0]=1; // L'uscita è stata oggiornata
        else
            newpacket[0]=0; // L'uscita non è stata oggiornata
        
        oldsel=sel; // Aggiorna oldsel
        
        for(i=0;i<nid*8;i++)
            data[i]=msg_memB[i];
	// Scrittura in uscita del Buffer
    }
    
}


// Handler attivato quando arriva un messaggio CAN (MAT-TARGET 3)
void CAN1_RX0_IRQHandler(void){
	

   int i=0;
   int j=0;
   int k=0;
   static int state=0;

  // Scrittura sul buffer msgA
  if (sel == 0){
      
        //CAN_Receive(CAN1, CAN_FIFO0, &msgA); // Ricezione Messaggio
		CAN_HandleStructure.pRxMsg = &msgA;
		HAL_CAN_Init(&CAN_HandleStructure);
		
		
		
		if(HAL_CAN_Receive(&CAN_HandleStructure, CAN_FIFO0,2) != HAL_OK)
			SetLed(GPIO_PIN_12,1);
		
		
		
        for (j=0;j<num_id;j++){
            if (state==3 & msgA.StdId==ids[4]) state++; // Ignora l'eventuale mancanza del
                   // messaggio con il quarto ID perché viene inviato con frequenza minore
            
            if (msgA.StdId == ids[j]) // Check ID Messaggio
                if (state == j){
                    // Aggiornamento Stato
                    state++; 
                    // Copia del Messaggio sul Buffer
                    for(k=0;k<8;k++) {
                      msg_memA[j*8+k]=msgA.Data[k];	 
						USART2_Send((uint8_t)msgA.Data[k]); //Debug
					}
                }
                else {
                    // Ritorno Stato Iniziale
                    state = 0;
                    break;
                }
        }
        if (state==num_id){ // Check Sequenza Completata
            state=0; // Ritorno Stato Iniziale
            sel=1;  // Cambio Buffer
        }
    }
   
   
  // Scrittura sul buffer msgB
    else{
		CAN_HandleStructure.pRxMsg = &msgB;
		HAL_CAN_Init(&CAN_HandleStructure);
		
		
		
        
		if(HAL_CAN_Receive(&CAN_HandleStructure, CAN_FIFO0,2) != HAL_OK)
			SetLed(GPIO_PIN_13,1);
		
			
        for (j=0;j<num_id;j++){
            if (state==3 & msgB.StdId==ids[4]) state++; // Ignora l'eventuale mancanza del
                   // messaggio con il quarto ID perché viene inviato con frequenza minore
            
            if (msgB.StdId == ids[j]) // Check ID Messaggio
                if (state == j){
                    // Aggiornamento Stato
                    state++; 
                    // Copia del Messaggio sul Buffer
                    for(k=0;k<8;k++) {
                      msg_memB[j*8+k]=msgB.Data[k];
					  USART2_Send((uint8_t)msgB.Data[k]);
					}
                }
                else {
                    // Ritorno Stato Iniziale
                    state = 0;
                    break;
                }
        }
        if (state==num_id){ // Check Sequenza Completata
            state=0; // Ritorno Stato Iniziale
            sel=0;  // Cambio Buffer
        }
  }
}



//Nested Vector Interrupt Controller (HAL New implementation)
static void NVIC_Config(void)
{
  HAL_NVIC_SetPriority(CAN1_RX0_IRQn,0,0); //Priority and Sub Priority
  HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
}



static void CAN_Config(void)
{
  //CAN_InitTypeDef        CAN_InitStructure;
  CAN_FilterConfTypeDef  CAN_FilterConfStructure;
  GPIO_InitTypeDef       GPIO_InitStructure;
 
  /* CAN GPIOs configuration **************************************************/

  /* Enable CAN and GPIO clock */
  //RCC_AHB1PeriphClockCmd(CAN_GPIO_CLK, ENABLE);
  
  __HAL_RCC_CAN1_CLK_ENABLE();
  
  __GPIOD_CLK_ENABLE();

  /* Connect CAN pins to AF9. Alternate di HAL? */
  // GPIO_PinAFConfig(CAN_GPIO_PORT, CAN_RX_SOURCE, CAN_AF_PORT);
  // GPIO_PinAFConfig(CAN_GPIO_PORT, CAN_TX_SOURCE, CAN_AF_PORT); 
  
  /* Configure CAN RX and TX pins */
  GPIO_InitStructure.Pin = CAN_RX_PIN | CAN_TX_PIN;
  GPIO_InitStructure.Mode = GPIO_MODE_AF_PP; 
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH; //Correspond to 100 MHz
  //GPIO_InitStructure.OType = GPIO_OType_PP;
  GPIO_InitStructure.Pull  = GPIO_PULLUP;
  GPIO_InitStructure.Alternate = GPIO_AF9_CAN1; //DOMANDARE AL PROF.
  HAL_GPIO_Init(CAN_GPIO_PORT, &GPIO_InitStructure);
  

  /* CAN configuration ********************************************************/  
  /* Enable CAN clock */
  //RCC_APB1PeriphClockCmd(CAN_CLK, ENABLE);
  
  
  
  /* CAN register init */
  HAL_CAN_DeInit(&CAN_HandleStructure); // DOMANDARE AL PROF.
  

  /* CAN cell init */
  CAN_HandleStructure.Init.TTCM = DISABLE;
  CAN_HandleStructure.Init.ABOM = DISABLE;
  CAN_HandleStructure.Init.AWUM = DISABLE;
  CAN_HandleStructure.Init.NART = DISABLE;
  CAN_HandleStructure.Init.RFLM = DISABLE;
  CAN_HandleStructure.Init.TXFP = DISABLE;
  CAN_HandleStructure.Init.Mode = CAN_MODE_NORMAL;
  CAN_HandleStructure.Init.SJW = CAN_SJW_1TQ; // CAN Baudrate = 168MHz/[(SJW+BS1+BS2)*Prescaler]
  CAN_HandleStructure.Init.BS1 = CAN_BS1_14TQ;
  CAN_HandleStructure.Init.BS2 = CAN_BS2_6TQ;
  CAN_HandleStructure.Init.Prescaler = 2; 
  
  
  
  //Experimental.
  CAN_HandleStructure.Instance = CAN1;
  //CAN_HandleStructure.Init = CAN_InitStructure;

  
  
  if(HAL_CAN_Init(&CAN_HandleStructure) != HAL_OK) //pag 135
	SetLed(GPIO_PIN_15,1);
	
  
  /* CAN filter init HAL */
  CAN_FilterConfStructure.FilterNumber = 1;
  CAN_FilterConfStructure.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_FilterConfStructure.FilterScale = CAN_FILTERSCALE_32BIT;
  
  /* Ogni campo di FilterId e FilterMask va shiftato di 5 a sinistra,
   data la non perfetta corrispondenza di SID e di EID 
   (tra libreria e hardware)*/
   
   
  CAN_FilterConfStructure.FilterIdHigh = 0x0000 << 5;
  CAN_FilterConfStructure.FilterIdLow = 0x0000 << 5;
  CAN_FilterConfStructure.FilterMaskIdHigh = 0x0000 << 5;
  CAN_FilterConfStructure.FilterMaskIdLow = 0x0000 << 5;
  CAN_FilterConfStructure.FilterFIFOAssignment = CAN_FILTER_FIFO0;
  CAN_FilterConfStructure.FilterActivation = ENABLE;
  
  if(HAL_CAN_ConfigFilter(&CAN_HandleStructure,&CAN_FilterConfStructure) != HAL_OK)
	  SetLed(GPIO_PIN_12,1);
 
	  
  
  /* Enable FIFO 0 message pending Interrupt */
    //CAN_ITConfig(CANx, CAN_IT_FMP0, ENABLE);	
  
  __HAL_CAN_ENABLE_IT(&CAN_HandleStructure,CAN_IT_FMP0); //CAN_Handle_TypeDef
  
  
  
  
}




