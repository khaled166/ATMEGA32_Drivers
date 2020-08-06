/*
 * Servo_Motor.c
 *
 * Created: 7/28/2020 10:44:58 AM
 *  Author: Khaledseif166
 */ 

#include "Servo_Motor.h"

void Servo_init(void){
	
	DIO_SetPinDir(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	TIMER1_INIT();
}
void Servo_Posetion(sint8 Degree){
	
	sint8 Val=5;
	Val=+Degree/9;
	TIMER1_FAST_PWM1(Val);
}

