


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

#include "STD.h"



/******************************************************Digital Input/Output pins Register Addressess***********************************************************************************************/

#define PORTA (*(volatile uint8*)(0x3B))
#define PINA  (*(volatile uint8*)(0x39))
#define DDRA  (*(volatile uint8*)(0x3A))

#define PORTB (*(volatile uint8*)(0x38))
#define PINB  (*(volatile uint8*)(0x36))
#define DDRB  (*(volatile uint8*)(0x37))

#define PORTC (*((volatile uint8*)(0x35)))
#define PINC  (*((volatile uint8*)(0x33)))
#define DDRC  (*((volatile uint8*)(0x34)))

#define PORTD (*(volatile uint8*)(0x32))
#define PIND  (*(volatile uint8*)(0x30))
#define DDRD  (*(volatile uint8*)(0x31))




/*************************************************************    External Interrupts Addressess    *********************************************************************/

#define SREG     (*(volatile uint8*)(0X5F))                //Status Register Memory Address(ATMEGA32 MICROCHIP)

#define GICR     (*(volatile uint8*)(0x5B))                //General Interrupt Control Register Memory Address(ATMEGA32 MICROCHIP)

#define GIFR     (*(volatile uint8*)(0x5A))                //General Interrupt Flag Register Memory Address(ATMEGA32 MICROCHIP)

#define MCUCR    (*(volatile uint8*)(0x55))                //MicroController Control Register Memory Address(ATMEGA32 MICROCHIP)

#define MCUCSR   (*(volatile uint8*)(0x54))                //MicroController Control&Status Register Memory Address(ATMEGA32 MICROCHIP)




/****************************************************************     ADC Memory Addresses    *******************************************************************************/
       
#define ADMUX  (*(volatile uint8*)(0x27))                   //Analog To Digital Converter Multiplexer Selection Register 

#define ADCSRA (*(volatile uint8*)(0x26))                   //Analog To Digital Converter Control&Status Register A 

#define  ADCH  (*(volatile uint8*)(0x25))                   //Analog To Digital Converter Highest Register

#define ADCL   (*(volatile uint8*)(0x24))                   //Analog To Digital Converter Lowest Register

#define ADC_Result (*(volatile uint16*)(0x24))               //Analog To Digital Converter ADCH+ADCL Register 

#define SFIOR  (*(volatile uint8*)(0x50))                   //Special FunctionIO Register






#endif /* ATMEGA32_REG_H_ */