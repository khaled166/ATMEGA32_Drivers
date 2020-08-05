


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

#include "STD.h"

/******************************************* External Interrupt Memory Addresses **************************************************************************************************************/


#define SREG   (*(volatile uint8*)(0x5F))

#define GICR   (*(volatile uint8*)(0x5B))

#define GIFR   (*(volatile uint8*)(0x5A))

#define MCUCR  (*(volatile uint8*)(0x55))

#define MCUCSR (*(volatile uint8*)(0x54))


/******************************************* DIO Memory Addresses **************************************************************************************************************************/


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

/****************************************************                 ADC Memory Addresses                ***************************************************/

#define ADMUX           (*(volatile uint8 *)(0x27))
#define ADCSRA          (*(volatile uint8 *)(0x26))
#define ADCH            (*(volatile uint8 *)(0x25))
#define ADCL            (*(volatile uint8 *)(0x24))
#define ADC_Adjust      (*(volatile uint16*)(0x24))
#define SFIOR           (*(volatile uint8 *)(0x50))

/****************************************************               Timer Memory Addresses               *************************************************/

//Timer0 Registers Memory Addresses 
#define TCNT0  (*(volatile uint8*)(0x52))
#define TCCR0  (*(volatile uint8*)(0x53))
#define OCR0   (*(volatile uint8*)(0x5C))
#define TIMSK  (*(volatile uint8*)(0x59))             //Timers(timer0-timer1-timer2) Accessing on this Register to Active Interrupt Status
#define TIFR   (*(volatile uint8*)(0x58))

//Timer1 Registers Memory Addresses
#define TCCR1A   (*(volatile uint8*)(0x4F))
#define TCCR1B  ( *(volatile uint8*)(0x4E))
#define TCNT1  (*(volatile uint16*)(0x4C))           //Timer1 Counter Register Accessing Both (TCNT1L+TCNT1H)
#define OCR1A   (*(volatile uint16*)(0x4A))          //Timer1 Output Compare Match RegistersA (OCR1AL+OCR1AH)
#define OCR1B   (*(volatile uint16*)(0x48))          //Timer1 Output Compare Match RegistersB (OCR1BL+OCR1BH)
#define ICR1    (*(volatile uint16*)(0x46))          //Timer1 Input Capture Registers (ICR1L+ICR1H)

//Timer2 Register Memory Addresses
#define TCCR2   (*(volatile uint8*)(0x45))
#define TCNT2   (*(volatile uint8*)(0x44))
#define OCR2    (*(volatile uint8*)(0x43))


/*******************************************************           USART Memory Addressess        *****************************************************************************/

//#define UDR (*(volatile uint8*)(0x2C))
#define UCSRA (*(volatile uint8*)(0x2B))
#define UCSRB (*(volatile uint8*)(0x2A))
#define UBRRL (*(volatile uint8*)(0x29))
#define UBBRH (*(volatile uint8*)(0x40))
#define UCSRC (*(volatile uint8*)(0x40))
#define UDR   (*(volatile uint8*)(0x2C))




#endif /* ATMEGA32_REG_H_ */