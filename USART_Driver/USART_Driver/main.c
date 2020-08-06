/*
 * USART_Driver.c
 *
 * Created: 8/1/2020 5:28:41 AM
 * Author : Khaledseif166
 */ 

#include "UART.h"
#include <avr/interrupt.h>

 uint8 Data_rec=0;

int main(void)
{
	USART_INIT();
	LCD_Init();
	LCD_WriteChar();
	 //USART_TX_CHAR('a');
	 USART_TX_STRING("Hello");
	 

    while (1) 
    {
	}
}

ISR(USART_RXC_vect){
	
	Data_rec=USART_RX_STRING();
	LCD_WriteString(Data_rec);
}