
#include <avr/interrupt.h>
#include "LED.h"



int main(void)
{
	
	
	LED0_Init();
	LED0_ON();
	Timer_Init();
	Timer_SetDelay(1000);
	Timer_Start();
	
	
	while (1){
		
	}
}


ISR(TIMER0_COMP_vect){
		
	LED0_toggle();	
}