/*
 * ADC.c
 *
 * Created: 7/14/2020 10:59:57 AM
 *  Author: Khaledseif166
 */ 

#include "ADC.h"

void ADC_INIT(){
	
/*********************************************    Voltage Reference Selection For ADC.     ****************************************************************/
	
#if     VOLTAGE_STATUS==Internal_Vref_off

     CLR_BIT(ADMUX,6);
     CLR_BIT(ADMUX,7);

#elif   VOLTAGE_STATUS==Internal_Vref_on

     SET_BIT(ADMUX,6);
	 SET_BIT(ADMUX,7);

#elif   VOLTAGE_STATUS==External_AVCC

     SET_BIT(ADMUX,6);
	 CLR_BIT(ADMUX,7);

#elif   VOLTAGE_STATUS==Reserved

     CLR_BIT(ADMUX,6);
	 SET_BIT(ADMUX,7);	     
#endif

/*************************************************     ADC Adjust Data Result.      ***********************************************************************/

#if     ADJUCENT_STATUS==Right_Adjust
    
	 CLR_BIT(ADMUX,5);

#elif   ADJUCENT_STATUS==Left_Adjust
    
	 SET_BIT(ADMUX,5); 	
       
#endif

/******************************************   Analog Channel And Gain Selection Bits    ********************************************************************/

#if     CHANNEL_SELECTION==ADC0
   
     CLR_BIT(ADMUX,0);
     CLR_BIT(ADMUX,1);
     CLR_BIT(ADMUX,2);
     CLR_BIT(ADMUX,3);
     CLR_BIT(ADMUX,4);
   
#elif   CHANNEL_SELECTION==ADC1
   
     SET_BIT(ADMUX,0);
     CLR_BIT(ADMUX,1);
     CLR_BIT(ADMUX,2);
     CLR_BIT(ADMUX,3);
     CLR_BIT(ADMUX,4);
   
#elif   CHANNEL_SELECTION==ADC2
 
     CLR_BIT(ADMUX,0);
     SET_BIT(ADMUX,1);
     CLR_BIT(ADMUX,2);
     CLR_BIT(ADMUX,3);
     CLR_BIT(ADMUX,4); 
	
#elif   CHANNEL_SELECTION==ADC3
  
     SET_BIT(ADMUX,0);
     SET_BIT(ADMUX,1);
     CLR_BIT(ADMUX,2);
     CLR_BIT(ADMUX,3);
     CLR_BIT(ADMUX,4); 

#endif

/********************************************************    AUTO TRIGGER SELECTION      *********************************************************************/

#if     AUTO_TRIGGER_STATUS==AUTO_TRIGGER_DISABLE

     CLR_BIT(ADCSRA,5);
	
#elif  	AUTO_TRIGGER_STATUS==AUTO_TRIGGER_ENABLE

     SET_BIT(ADCSRA,5);
		
/******************************************************       INTERRUPT STATUS       ************************************************************************/

#if     INTERRUPT_STATUS==ADIE_DISABLE

     CLR_BIT(ADCSRA,3);
	
#elif 	INTERRUPT_STATUS==ADIE_ENABLE

     SET_BIT(SREG,7);
	 SET_BIT(ADCSRA,3);
	      	
#endif

/******************************************      ADC Pre-scaler Select Bits     ***************************************************************************/

#if     PRESCALER_SLECTION==ADC_SCALE0

     CLR_BIT(ADCSRA,0);
     CLR_BIT(ADCSRA,1);
     CLR_BIT(ADCSRA,2);
 
#elif   PRESCALER_SLECTION== ADC_SCALE1

     CLR_BIT(ADCSRA,0);
     SET_BIT(ADCSRA,1);
     CLR_BIT(ADCSRA,2);
   
#elif   PRESCALER_SLECTION== ADC_SCALE2

     SET_BIT(ADCSRA,0);
     SET_BIT(ADCSRA,1);
     CLR_BIT(ADCSRA,2);
   
#elif   PRESCALER_SLECTION== ADC_SCALE3
     
     CLR_BIT(ADCSRA,0);
     CLR_BIT(ADCSRA,1);
     SET_BIT(ADCSRA,2); 
   
#elif   PRESCALER_SLECTION== ADC_SCALE4

     SET_BIT(ADCSRA,0);
     CLR_BIT(ADCSRA,1);
     SET_BIT(ADCSRA,2);
  
#elif   PRESCALER_SLECTION== ADC_SCALE5
   
     CLR_BIT(ADCSRA,0);
	 SET_BIT(ADCSRA,1);
	 SET_BIT(ADCSRA,2);

#elif 	PRESCALER_SLECTION== ADC_SCALE6

     SET_BIT(ADCSRA,0);
	 SET_BIT(ADCSRA,1);
	 SET_BIT(ADCSRA,2); 
	 
#endif	 
 
     SET_BIT(ADCSRA,7);    
}

/*********************************************       ADC Start Conversion Function       ******************************************************************/

void ADC_Read(uint16* Analog_Value){
	
	uint16 Digital_Value = 0;
	
	SET_BIT(ADCSRA,6);
	
	#if  ADC_INTERRUPT_STATUS   ==  ADC_INTERRUPT_DISABLE
	
	while( ! GET_BIT(ADCSRA,4) );
	
	Digital_Value = ADC_Result; //(ADCH << 2) | (ADCL >>6);
	
	*Analog_Value = ((Digital_Value * 500) / 1024) ;
	
	#endif
}