/*
 * UART.c
 *
 * Created: 8/1/2020 5:30:06 AM
 *  Author: Khaledseif166
 */ 

#include "UART.h"

void USART_INIT(void){
	
	
	 DIO_SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	 DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	/*****************  USART SYNCH/ASYNCH MODE DELECTION  ************/
	#if  Mode_select  ==  UMSEL_ASYNCH
	
	 CLR_BIT(UCSRC,6);
	
	#elif Mode_select  ==  UMSEL_SYNCH
	
	 SET_BIT(UCSRC,6);
	
	#endif
	
	/*******************   USART REG_SEL UCSRC/UBRRH  ******************/
	#if Reg_select  ==  URSEL_UCSRC
	
	 SET_BIT(UCSRC,7);
	
	#elif Reg_select  == URSEL_UBRRH
	
	 CLR_BIT(UCSRC,7);
	
	#endif 
	
    /*********************  parity mode selection  *********************/
	#if PARITY_mode  ==  UPM_DISABLE
	  
	  CLR_BIT(UCSRC,4);
	  CLR_BIT(UCSRC,5);
	  
	#elif  PARITY_mode  == UPM_RESEVED
	
	 SET_BIT(UCSRC,4);
	 
	#elif  PARITY_mode  == UPM_EVEN
	 
	 SET_BIT(UCSRC,5);
	 
	#elif  PARITY_mode  == UPM_EVEN
     
	 SET_BIT(UCSRC,4);
	 SET_BIT(UCSRC,5);
	 
	#endif 
	
	/**********************  stop bit number select   *****************/
	#if stop_bits_num  ==  USBS_1BIT
	
	 CLR_BIT(UCSRC,3);
	 
	#elif  stop_bits_num  ==  USBS_2BIT
	
	 SET_BIT(UCSRC,3);
	 
	#endif 
	
	/**********************  number of data bits in frame **************/
	#if Data_bits_num  ==  UCSZ_5BITS
	 
	 CLR_BIT(UCSRC,1);
	 CLR_BIT(UCSRC,2);
	 CLR_BIT(UCSRB,2);
	 
	#elif  Data_bits_num  ==  UCSZ_6BITS
	
	 SET_BIT(UCSRC,1);
	 
	#elif  Data_bits_num  ==  UCSZ_7BITS
      
	 SET_BIT(UCSRC,2);
	 
	#elif  Data_bits_num  ==  UCSZ_8BITS
	
	 SET_BIT(UCSRC,1);
	 SET_BIT(UCSRC,2);
	 
    #elif  Data_bits_num  ==  UCSZ_RES1
	
	 SET_BIT(UCSRB,2);
	 
    #elif  Data_bits_num  ==  UCSZ_RES2
	
	 SET_BIT(UCSRB,2);
	 SET_BIT(UCSRC,1);
	 
    #elif  Data_bits_num  ==  UCSZ_RES3
   
     SET_BIT(UCSRC,2);
	 SET_BIT(UCSRB,2);
	
    #elif  Data_bits_num  ==  UCSZ_9BITS
  
     SET_BIT(UCSRC,2);
     SET_BIT(UCSRB,2);
     SET_BIT(UCSRC,1);
   
    #endif 
  
   /*****************   Activation transmitter mode   ***********************/
   #if Transmitter_status  ==  TXEN_ENABLE
   
	 SET_BIT(UCSRB,3);
	 
   #elif Transmitter_status  ==  TXEN_DISABLE
    
	 CLR_BIT(UCSRB,3);
	 
	#endif 
	
	/*******************  Activation Recevier mode   *********************/
	#if Recevier_status  ==  RXEN_ENABLE
	
	 SET_BIT(UCSRB,4);
	 
	#elif  Recevier_status  ==  RXEN_DISABLE
	
	 CLR_BIT(UCSRB,4);
	 
	#endif
	
	/****************** Transmit Data Bit 8  **********************/
	#if TX_9bit_status  ==  TXB8_DISABLE
	 
	 CLR_BIT(UCSRB,0);
	 
	#elif TX_9bit_status  ==  TXB8_ENABLE
	
	 SET_BIT(UCSRB,0);
	 
	#endif        
   
   /******************* Receive Data Bit 8   ************************/
   #if RX_9bit_status  ==  RXB8_DISABLE
   
    CLR_BIT(UCSRB,1);
	
   #elif RX_9bit_status  ==  RXB8_ENABLE
   
    SET_BIT(UCSRB,1);
	
  #endif
    	 	
  /**********************  Receiver Interrupt status   *****************/
  #if RX_interrupt_status  ==  RXCIE_DISABLE
  
   CLR_BIT(UCSRB,7);
   
  #elif RX_interrupt_status  ==  RXCIE_ENABLE
  
   SET_BIT(SREG,7);
   SET_BIT(UCSRB,7);
   
  #endif
  
  /*****************    Transmitter Interrupt status   **********************/
  #if TX_interrupt_status  == TXCIE_DISABLE
  
   CLR_BIT(UCSRB,5);
   
  #elif TX_interrupt_status  ==  TXCIE_ENABLE
  
   SET_BIT(SREG,7);
   SET_BIT(UCSRB,5);
   
  #endif
  
  /********************  Frame error status   ***************************/
  #if FE_status  ==  FE_DISABLE
  
   CLR_BIT(UCSRA,4);
   
  #elif FE_status  == FE_ENABLE
  
   SET_BIT(UCSRA,4);
   
  #endif        
  
  /*********************** Data overrun status  *****************/
  #if DOR_STATUS  ==  DOR_DISABLE
   
   CLR_BIT(UCSRA,3);
   
  #elif DOR_STATUS  ==  DOR_ENABLE
  
   SET_BIT(UCSRA,3);
   
  #endif
  
  /*****************  parity error status   *****************/
  #if parity_status  ==  PE_DISABLE
  
   CLR_BIT(UCSRA,2);
   
  #elif parity_status  ==  PE_ENABLE
  
   SET_BIT(UCSRA,2);
   
  #endif
  
  /**************** Double the USART Transmission Speed   **************/      
  #if Speed_status  ==  U2X_NORMAL
  
   CLR_BIT(UCSRA,1);
   
  #elif Speed_status  == U2X_DOUPLE
  
   SET_BIT(UCSRA,1);
   
  #endif
  
  /****************  Multi-processor Communication Mode   ***************/
  #if MPCM_status  ==  MPCM_DISAPLE
  
   CLR_BIT(UCSRA,0);
   
  #elif MPCM_status  ==  MPCM_ENABLE
  
   SET_BIT(UCSRA,0);
   
  #endif       
 
 /******************  baud rate calculation   ***********************/
 
 UBRRL = 51;  //((F_CPU/baud_rate*Speed))-1;
	  
}




//Transmit Data bit by bit 
void USART_TX_CHAR(uint8 data){
	
	while(GET_BIT(UCSRA,5)==0);
	 
	 UDR = data;
}

//Transmit Data complete String
void USART_TX_STRING(uint8* str){
	
	uint8 i=0;
	while(str[i]!='\0'){
		USART_TX_CHAR(str[i]);
		i++;
	}
}

//Receive Data bit by bit.
uint8 USART_RX_CHAR(void){
	
	uint8 Data=0;
	
	while(GET_BIT(UCSRA,7)==0);
	Data= UDR;
	return Data;
}


//Receive Data complete String.
uint8 USART_RX_STRING(void){
	
	  static uint8 DATA[16];
	  uint8 i=0;
	  uint8 val;
	  for(i=0;i<16;i++){
		  val=USART_RX_CHAR();
		  if(val=='\n')
		   break;
		  DATA[i]=val;
	  }
	      DATA[i+1]=0;
		  return DATA;
	  
}