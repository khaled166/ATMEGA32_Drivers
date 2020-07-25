



#ifndef TIMER1_H_
#define TIMER1_H_

#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"



/**************************************************************Waveform Generation Selection Mode.************************************************************/

#define   Normal_Mode                          0
#define   PWM_phaseCorrect_8bit                1
#define   PWM_phaseCorrect_9bit                2
#define   PWM_phaseCorrect_10bit               3
#define   CTC_Mode                             4
#define   FAST_PWM_8BIT                        5
#define   FAST_PWM_9bit                        6
#define   FAST_PWM_10bit                       7
#define   PWM_phase_Freq1                      8
#define   PWM_phase_Freq2                      9
#define   PWM_phase_Correct1                   10
#define   PWM_phase_Correct2                   11
#define   CTC_Mode2                            12
#define   Reserved                             13
#define   FAST_PWM1                            14
#define   FAST_PWM2                            15

/**************************************************************Compare Match Output Mode.*********************************************************************/



//TCCR1A Register bits(7,6).
#define   Disable_OC1A           0
#define   Toggle_OC1A_ONMATCH    1
#define   Clear_OC1A_ONMATCH     2
#define   Set_OC1A_ONMATCH       3

//TCCR1A Register bits(5,4).
#define   Disable_OC1B           0
#define   Toggle_OC1B_ONMATCH    1
#define   Clear_OC1B_ONMATCH     2
#define   Set_OC1B_ONMATCH       3

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

#define DISABLE_FOC1A         0
#define ENABLE_FOC1A          1


#define DISABLE_FOC1B         0
#define ENABLE_FOC1B          1



/*********************************************************************Timer/Counter Interrupt MaskRegister-TIMSK************************************************/

#define DISABLE_TOIE1        0
#define ENABLE_TOIE1         1

#define DISABLE_OCIE1A       0
#define ENABLE_OCIE1A        1

#define DISABLE_OCIE1B       0
#define ENABLE_OCIE1B        1

#define DISABLE_TICIE1       0  
#define ENABLE_TICIE1        1

/**********************************************************************  FUNCTIONS PROTOTYPES    **************************************************************/



void TIMER1_INIT(void);
void TIMER1_STOP(void);
void TIMER1_DELAY(uint32 Freq);






/************************************************************************ TIMER1 CONFIGURATION   **************************************************************************************************/


#define    TIMER1_MODE          Normal_Mode

#define    OC1_STATUS           Disable_OC1A

#define    CLK_SELECTION        PRESACLER_1024_CLK

#define    Foc1_STATUS          DISABLE_FOC1A

#define    INTERRUPT_STATUS     ENABLE_OCIE1A


#endif /* TIMER1_H_ */