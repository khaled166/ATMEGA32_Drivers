/*
 * Timer0.c
 *
 * Created: 7/19/2020 4:42:02 PM
 * Author : Khaledseif166
 */ 

#include "TIMER0.h"

extern  uint32  N_OVF;
extern  uint8  init_value;



int main(void)
{

  SET_BIT(DDRB,3);
  SET_BIT(DDRC,2);
  SET_BIT(PORTC,2);
  
  TIMER0_CALLBACK(Toggle_BIT(PORTC,2));
  
  TIMER0_INIT();
  //TIMER0_DELAY(2000);
  TIMER0_CTC_GENERATE(250);
  PWM0_Generate(100);

 	
    /* Replace with your application code */
    while (1) 
    {
    }
}












/*
ISR(TIMER0_OVF_vect){
	
	static uint32 count=0;
	count++;
	if(count==N_OVF){
     
	  TCNT0= init_value;
	  count=0;
	 Toggle_BIT(PORTC,2);
	}
}
*/
