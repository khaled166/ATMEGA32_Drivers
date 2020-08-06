


#include "Timer1.h"



void TIMER1_INIT(void){
	
	/***************************************************************  TIMER0_MODE SELECTION   *********************************************************************/
	
	#if   TIMER1_MODE  ==  Normal_Mode
	
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

	
	#elif  TIMER1_MODE  ==  PWM_phaseCorrect_8bit
	
	SET_BIT(TCCR1A,0);
	
	#elif  TIMER1_MODE  ==  PWM_phaseCorrect_9bit
	
	SET_BIT(TCCR1A,1);
	
	#elif  TIMER1_MODE==  PWM_phaseCorrect_10bit
	
	SET_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	
	#elif  TIMER1_MODE  == CTC_Mode
	
	  SET_BIT(TCCR1B,3);
	  
	  #elif  TIMER1_MODE  == FAST_PWM_8BIT
	  
	  SET_BIT(TCCR1A,0);
	  SET_BIT(TCCR1B,3);
	  
	  #elif  TIMER1_MODE  == FAST_PWM_9bit
	  
	  SET_BIT(TCCR1A,1);
	  SET_BIT(TCCR1B,3);
	  
	  #elif  TIMER1_MODE  == FAST_PWM_10bit
	  
	  
	  SET_BIT(TCCR1A,0);
	  SET_BIT(TCCR1A,1);
	  SET_BIT(TCCR1B,3);
	  
	  #elif  TIMER1_MODE  == PWM_phase_Freq1
	  
	  SET_BIT(TCCR1B,4);
	  
	  #elif  TIMER1_MODE  == PWM_phase_Freq2
	  
	  SET_BIT(TCCR1B,3);
	  
	  #elif  TIMER1_MODE  == CTC_Mode
	  
	  SET_BIT(TCCR1A,0);
	  SET_BIT(TCCR1B,4);
	  
	  #elif  TIMER1_MODE  == PWM_phase_Correct1
	  
	  SET_BIT(TCCR1A,1);
	  SET_BIT(TCCR1B,4);
	  
	  #elif  TIMER1_MODE  == PWM_phase_Correct2
	 
	  SET_BIT(TCCR1A,0);
	  SET_BIT(TCCR1B,3);
	  
	  #elif  TIMER1_MODE  == CTC_Mode2
	  
	  SET_BIT(TCCR1B,3);
	  SET_BIT(TCCR1B,4);
	  
	  
	  #elif  TIMER1_MODE  == Reserved
	  
	  SET_BIT(TCCR1A,0);
	  SET_BIT(TCCR1B,3);
	  SET_BIT(TCCR1B,4);
	  
	  #elif  TIMER1_MODE  == FAST_PWM1
	  
	  SET_BIT(TCCR1A,1);
	  SET_BIT(TCCR1B,3);
	  SET_BIT(TCCR1B,4);
	  
	  #elif  TIMER1_MODE  == FAST_PWM2
	  
	  SET_BIT(TCCR1A,0);
	  SET_BIT(TCCR1A,1);
	  SET_BIT(TCCR1B,3);
	  SET_BIT(TCCR1B,4);
	
	#endif
	
	/**************************************************************************  COMPARE MATCH OUTPUT MODE SELECTION  ***********************************************/
	
	
	//COMPARE MATCH OUTPUT MODE SELECTION CHANNEL A.
	
	#if    OC1_STATUS  ==   Disable_OC1A

	CLR_BIT(TCCR1A,6);
	CLR_BIT(TCCR1A,7);
	
	#elif  OC1_STATUS  ==  Toggle_OC1A_ONMATCH       
	
	SET_BIT(TCCR1A,6);
	
	#elif  OC1_STATUS  ==  Clear_OC1A_ONMATCH
	
	SET_BIT(TCCR1A,7);
	
	#elif  	 OC1_STATUS ==  Set_OC1A_ONMATCH

	SET_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);

	
	//COMPARE MATCH OUTPUT MODE SELECTION CHANNEL B.
	
	#elif      OC1_STATUS ==  Disable_OC1B                         

	CLR_BIT(TCCR1A,4);
	CLR_BIT(TCCR1A,5);
	
	#elif  OC1_STATUS  ==  Toggle_OC1B_ONMATCH
	
	SET_BIT(TCCR1A,4);
	
	#elif  OC1_STATUS  ==  Clear_OC1B_ONMATCH
	
	SET_BIT(TCCR1A,5);
	
	#elif  	 OC1_STATUS ==  Set_OC1B_ONMATCH

	SET_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);
	
	#endif


	/***************************************************************************   CLOCK SELECTION    ***********************************************************/

	//NOTE: timer starts counting Automatically after selecting the clk_source state.

	
	#if   CLK_SELECTION  ==  OSC_CLK
	
	SET_BIT(TCCR1B,0);

	#elif 	  CLK_SELECTION  ==  PRESACLER_8_CLK

	SET_BIT(TCCR1B,1);
	
	
	#elif    CLK_SELECTION==   PRESACLER_64_CLK
	
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	
	#elif  	CLK_SELECTION==   PRESACLER_256_CLK

	SET_BIT(TCCR1B,2);

	#elif  	 CLK_SELECTION==   PRESACLER_1024_CLK

	
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,2);
	

	#elif  	CLK_SELECTION == EXTERNAL1_CLK

	SET_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
	#elif	 CLK_SELECTION  ==  EXTERNAL2_CLK

	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
	#endif
	
	
	/****************************************************************  FORCE OUTPUT COMPARE     ****************************************************************/


    //FORCE OUTPUT COMPARE CHANNEL A.
	#if  Foc1_STATUS ==  DISABLE_FOC1A

	CLR_BIT(TCCR1A,3);
	

	#elif   Foc1_STATUS  == ENABLE_FOC1A

	SET_BIT(TCCR1A,3);
	
	
	
	//FORCE OUTPUT COMPARE CHANNEL b.
	#elif   Foc1_STATUS ==  DISABLE_FOC1B
                         
	CLR_BIT(TCCR1A,2);
	

	#elif   Foc1_STATUS  == ENABLE_FOC1B
                                                    
	SET_BIT(TCCR1A,2);
	

	#endif
	
	/****************************************************************   TIMER1_INTERRUPT STATUS   **************************************************************/

	#if   INTERRUPT_STATUS  ==  DISABLE_TOIE1

	CLR_BIT(TIMSK,2);
	
	#elif  INTERRUPT_STATUS  ==  ENABLE_TOIE1

	SET_BIT(SREG,7);
	SET_BIT(TIMSK,2);
	
	
	

	#elif   INTERRUPT_STATUS  ==  DISABLE_OCIE1A

	CLR_BIT(TIMSK,4);
	
	#elif  	INTERRUPT_STATUS  ==  ENABLE_OCIE1A

	SET_BIT(SREG,7);
	SET_BIT(TIMSK,4);
	
	
	
	#elif   INTERRUPT_STATUS  ==  DISABLE_OCIE1B

	CLR_BIT(TIMSK,3);
	
	#elif  	INTERRUPT_STATUS  ==  ENABLE_OCIE1B

	SET_BIT(SREG,7);
	SET_BIT(TIMSK,3);
	
	
	
	#elif   INTERRUPT_STATUS  ==  DISABLE_TICIE1

	CLR_BIT(TIMSK,5);
	
	#elif  	INTERRUPT_STATUS  ==  ENABLE_TICIE1

	SET_BIT(SREG,7);
	SET_BIT(TIMSK,5);
	
	#endif
}



void TIMER1_STOP(void){

	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}


void TIMER1_FAST_PWM1(uint8 Duty_Cycle){
	
	ICR1= 625;       //Configured according to Proteus Clock Source 
	
	OCR1A= ((Duty_Cycle*ICR1)/100)-1;
	
}
