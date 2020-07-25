/*
 * TIMER0.c
 *
 * Created: 7/19/2020 8:17:08 PM
 *  Author: Khaledseif166
 */ 

#include <avr/interrupt.h>
#include "TIMER0.h"
#define F_CPU  16000000UL
#define  MAX_TICKS   256



static void (*Hold_Address)(void);

//Normal mode variables
 uint32  N_OVF=0;
 uint8  init_value=0;
 
 
 //CTC_Mode variables.
 static uint32 OC_MATCH=0;


void TIMER0_INIT(void){
	
/***************************************************************  TIMER0_MODE SELECTION   *********************************************************************/	
	
  #if   TIMER0_MODE  ==  Normal_Mode
  
       CLR_BIT(TCCR0,3);
	   CLR_BIT(TCCR0,6);
	   
 #elif  TIMER0_MODE  ==  PWM_phase_Correct
 
        SET_BIT(TCCR0,6);
			   	
 #elif  TIMER0_MODE  ==  CTC_Mode 
   
        SET_BIT(TCCR0,3);
		
 #elif  TIMER0_MODE==  PWM_fast_Mode
 
       SET_BIT(TCCR0,3);
	   SET_BIT(TCCR0,6);
	   
 #endif 
 
/**************************************************************************  COMPARE MATCH OUTPUT MODE SELECTION  ***********************************************/
 
 #if    OC0_STATUS  ==   Disable_OC0

       CLR_BIT(TCCR0,4);
	   CLR_BIT(TCCR0,5);
	   
 #elif  OC0_STATUS  ==  Toggle_OC0_ONMATCH       //THIS CASE IN NORMAL MODE ONLY (RESERVED IN PWM MODE).
 
       SET_BIT(TCCR0,4);
	   
 #elif  OC0_STATUS  ==  Clear_OC0_ONMATCH 
 
       SET_BIT(TCCR0,5);
	
#elif  	 OC0_STATUS ==  Set_OC0_ONMATCH

      SET_BIT(TCCR0,4);
	  SET_BIT(TCCR0,5);  	   
     	   
#endif


/***************************************************************************   CLOCK SELECTION    ***********************************************************/

//NOTE: timer starts counting Automatically after selecting the clk_source state.

   
 #if   CLK_SELECTION  ==  OSC_CLK
 
    SET_BIT(TCCR0,0);

#elif 	  CLK_SELECTION  ==  PRESACLER_8_CLK

   SET_BIT(TCCR0,1);
   
 
#elif    CLK_SELECTION==   PRESACLER_64_CLK   			
 
 	  SET_BIT(TCCR0,0);
	  SET_BIT(TCCR0,1);
	  
#elif  	CLK_SELECTION==   PRESACLER_256_CLK

    SET_BIT(TCCR0,2);

#elif  	 CLK_SELECTION==   PRESACLER_1024_CLK

  
    SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,2);
	

#elif  	CLK_SELECTION == EXTERNAL1_CLK

    SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	
#elif	 CLK_SELECTION  ==  EXTERNAL2_CLK

     SET_BIT(TCCR0,0);
	 SET_BIT(TCCR0,1);
	 SET_BIT(TCCR0,2);
	 	 
#endif 
	 
  	
/****************************************************************  FORCE OUTPUT COMPARE     ****************************************************************/

#if  Foc0_STATUS ==  DISABLE_FOC0

  CLR_BIT(TCCR0,7);
  

#elif   Foc0_STATUS  == ENABLE_FOC0

  SET_BIT(TCCR0,7);
  
#endif   
  
/****************************************************************   TIMER0_INTERRUPT STATUS   **************************************************************/

#if   INTERRUPT_STATUS  ==  DISABLE_TOIE0

      CLR_BIT(TIMSK,0);
	  
#elif  INTERRUPT_STATUS  ==  ENABLE_TOIE0

   SET_BIT(SREG,7);
   SET_BIT(TIMSK,0);
   

#elif   INTERRUPT_STATUS  ==  DISABLE_OCIE0

      CLR_BIT(TIMSK,1);
	  
#elif  	INTERRUPT_STATUS  ==  ENABLE_OCIE0

    SET_BIT(SREG,7);
    SET_BIT(TIMSK,1);
	
#endif 	    	    	  	  		  
}



void TIMER0_STOP(void){

	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);	
}



//Timer Delay Wave Generation-------->Normal_mode
//Output Compare Match Must be disable at this mode
void TIMER0_DELAY(uint32 Delay_ms){
	
	
	uint32 time_1puls=(1024/16);     //CLK_SELECTION/F_CPU);   //1024kHZ pre-scaler result in (us).
	
	uint32 total_ticks= ((Delay_ms*1000)/time_1puls);  
	
	N_OVF= (total_ticks/MAX_TICKS);
	
	init_value=  MAX_TICKS-(total_ticks%MAX_TICKS);                        // 256-(total_ticks%256);
	
	TCNT0= init_value;
	
	N_OVF++;	
}





//Timer Delay Wave Generation-------->CTC_mode   
void TIMER0_CTC_GENERATE(uint32 Delay){
	
	//OCR0= (16000000/(FREQ*2*256)-1);                          //From Data-sheet
	
	//uint8 pulse_time=(1024/16);
	
	//uint32 total_num=((Delay*1000)/pulse_time);
	OCR0=Delay;
	OC_MATCH= 4;
}



//PWM-FAST-MODE prototype implementation
void PWM0_Generate(uint16 Duty_Cycle){
	
	OCR0= ((Duty_Cycle*256)/100)-1;
}









void TIMER0_CALLBACK (void(*Address)(void)){
	
	Hold_Address = Address;
}


ISR(TIMER0_COMP_vect){

	static uint32 count=0;
	count++;
	if(count==OC_MATCH){
		
		//TCNT0= init_value;
		count=0;
		//Toggle_BIT(PORTC,2);
	    (*Hold_Address)();
	}
}


