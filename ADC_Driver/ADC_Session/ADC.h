/*
 * ADC.h
 *
 * Created: 7/14/2020 10:59:44 AM
 *  Author: Khaledseif166
 */ 

//Flexible Analog To Digital Converter (Driver).


#ifndef ADC_H_
#define ADC_H_


#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"
#include "ADC_CONFG.h"

/*********************************************    Voltage Reference Selection For ADC.     ****************************************************************/

#define Internal_Vref_off        0             //Turn Off Internal V-ref
#define Internal_Vref_on         1             //Turn On Internal V-ref(2.56V).
#define External_AVCC            2             //Select External Voltage(MCU-5V).
#define Reserved                 3             //not Supported Feature


/*************************************************     ADC Adjust Data Result.      ***********************************************************************/       

#define Right_Adjust             0             //Clear ADLAR Bit-5 on ADMUX Register.
#define Left_Adjust              1             //Set ADLAR Bit-5 on ADMUX Register.


/******************************************   Analog Channel And Gain Selection Bits    ********************************************************************/

//Configured For Single Ended Inputs Only.

#define ADC0                     0             //By Using First 5-Bits On ADMUX Register.   
#define ADC1                     1             //By Using First 5-Bits On ADMUX Register.
#define ADC2                     2             //By Using First 5-Bits On ADMUX Register.
#define ADC3                     3             //By Using First 5-Bits On ADMUX Register.
#define ADC4                     4             //By Using First 5-Bits On ADMUX Register.
#define ADC5                     5             //By Using First 5-Bits On ADMUX Register.
#define ADC6                     6             //By Using First 5-Bits On ADMUX Register.
#define ADC7                     7             //By Using First 5-Bits On ADMUX Register.



/****************************************       ADC Control And Status Register A(ADCSRA)        ******************************************************************/

#define ADEN_DISABLE             0             //Clear ADCSRA BIT-7
#define ADEN_ENABLE              1             //Set ADCSRA BIT-7
 
 
#define AUTO_TRIGGER_DISABLE     0             //Clear ADCSRA BIT-5
#define AUTO_TRIGGER_ENABLE      1             //Set ADCSRA BIT-5

#define ADIE_DISABLE             0             //Clear ADCSRA BIT-3
#define ADIE_ENABLE              1             //Set ADCSRA BIT-3


/******************************************      ADC Pre-scaler Select Bits     ***************************************************************************/    

#define ADC_SCALE0               0             //By Using 3-bit On ADCSRA Register.
#define ADC_SCALE1               1             //By Using 3-bit On ADCSRA Register.
#define ADC_SCALE2               2             //By Using 3-bit On ADCSRA Register.
#define ADC_SCALE3               3             //By Using 3-bit On ADCSRA Register.
#define ADC_SCALE4               4             //By Using 3-bit On ADCSRA Register.
#define ADC_SCALE5               5             //By Using 3-bit On ADCSRA Register.
#define ADC_SCALE6               6             //By Using 3-bit On ADCSRA Register.





/******************************************       ADC FUNCTION PROTOTYPES      ****************************************************************************/

void ADC_INIT(void);
void ADC_READ(uint32 DATA);


 



 
#endif /* ADC_H_ */