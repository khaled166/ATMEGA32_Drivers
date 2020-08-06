/*
 * DCmotor.c
 *
 * Created: 7/29/2020 6:27:46 PM
 *  Author: Khaledseif166
 */ 

#include "DCmotor.h"



void DCmotor_init(void){
	
	    DIO_SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
		DIO_SetPinDir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
		DIO_SetPinDir(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
		
		TIMER0_INIT();

}

void DCmotor_Direction(uint32 dir){
	
	switch(dir){
	
	   case   clk_wise_dir:
	   DIO_WritePin(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
	   DIO_WritePin(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	      break;
		  
	  case   Anti_clkwise_dir:
	  DIO_WritePin(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
	  DIO_WritePin(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	      break;
	
      default:
	      break;
	
	}
	
}

void DCmotor_Move(uint8 speed){
	
	PWM0_Generate(speed);
}