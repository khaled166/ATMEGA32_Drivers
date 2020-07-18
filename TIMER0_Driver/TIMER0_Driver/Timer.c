
#define  F_CPU 16000000UL
#include "Timer.h"



void Timer_Init(void)
{
	SET_BIT(TCCR0,3);         // Sit_bit3 in TCCR0 To work in CTC-Mode 
	
	SET_BIT(TIMSK,1);         // Active Timer/Counter0 Output Compare Match Interrupt Enable
	
	SET_BIT(SREG,7);          // Active General Interrupt Enable 
	
}

void Timer_Start(void){
	
	//Configure bits to work at timescales of(256KHZ).
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	
}

void Timer_Stop(void){
	
	//Disable TIMER0
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}


void Timer_SetDelay(uint32 Delay_Ms){
	
	OCR0= (F_CPU/(Delay_Ms*2*256)-1);
}
