/*
 * TIMER0.h
 *
 * Created: 7/19/2020 4:44:06 PM
 *  Author: Khaledseif166
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"

/**************************************************************Waveform Generation Selection Mode.************************************************************/

#define   Normal_Mode            0                       
#define   PWM_phase_Correct      1
#define   CTC_Mode               2
#define   PWM_fast_Mode          3 
      
/**************************************************************    Compare Match Output Mode.   *********************************************************************/

//Depends on Waveform Generation Selection Mode.
//Must Disable_OC0 in case of Normal_Mode.

#define   Disable_OC0            0
#define   Toggle_OC0_ONMATCH     1              //This case is Reserved in PWM(FAST&PHASE_CORRECT MODES).
#define   Clear_OC0_ONMATCH      2
#define   Set_OC0_ONMATCH        3



/*********************************************************************Clock Selection_Bits**********************************************************************/

#define DISABLE_CLK            0 
#define OSC_CLK                1
#define PRESACLER_8_CLK        2
#define PRESACLER_64_CLK       3
#define PRESACLER_256_CLK      4
#define PRESACLER_1024_CLK     5
#define EXTERNAL1_CLK          6
#define EXTERNAL2_CLK          7



/********************************************************************FORCE OUTPUT COMPARE********************************************************************/

#define DISABLE_FOC0          0
#define ENABLE_FOC0           1



/*********************************************************************Timer/Counter Interrupt MaskRegister-TIMSK************************************************/

#define DISABLE_TOIE0        0
#define ENABLE_TOIE0         1

#define DISABLE_OCIE0        0
#define ENABLE_OCIE0         1






/**********************************************************************  FUNCTIONS PROTOTYPES    **************************************************************/



void TIMER0_INIT(void);
void TIMER0_START(void);
void TIMER0_STOP(void);
void TIMER0_DELAY(uint32 Delay_ms);
void TIMER0_CTC_GENERATE(uint32 Delay);
void PWM0_Generate(uint16 Duty_Cycle);
void TIMER0_CALLBACK (void(*Address)(void));








/************************************************************************ TIMER0 CONFIGURATION   **************************************************************************************************/


#define    TIMER0_MODE          PWM_fast_Mode

#define    OC0_STATUS           Clear_OC0_ONMATCH

#define    CLK_SELECTION        PRESACLER_64_CLK 

#define    Foc0_STATUS          DISABLE_FOC0

#define    INTERRUPT_STATUS     ENABLE_OCIE0
 
    



#endif /* TIMER0_H_ */