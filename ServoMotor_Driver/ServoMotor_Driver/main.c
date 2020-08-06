/*
 * ServoMotor_Driver.c
 *
 * Created: 7/28/2020 10:42:40 AM
 * Author : Khaledseif166
 */ 

//#include <avr/io.h>


#include "Servo_Motor.h"


int main(void)
{
	Servo_init();
	//TIMER1_FAST_PWM1(5);
	Servo_Posetion(90);
    /* Replace with your application code */
    while (1) 
    {
			
    }
}
