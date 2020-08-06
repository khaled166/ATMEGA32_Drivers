/*
 * DCmotor_Driver.c
 *
 * Created: 7/29/2020 6:19:16 PM
 * Author : Khaledseif166
 */ 

//#include <avr/io.h>

#include "DCmotor.h"
int main(void)
{
	DCmotor_init();
	DCmotor_Move(27);
	DCmotor_Direction(Anti_clkwise_dir);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

