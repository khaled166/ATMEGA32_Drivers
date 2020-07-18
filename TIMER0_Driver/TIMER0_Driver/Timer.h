 


#ifndef TIMER_H_
#define TIMER_H_

#include "DIO.h"


void Timer_Init(void);

void Timer_Start(void);

void Timer_Stop(void);

void Timer_SetDelay(uint32 Delay_Ms);






#endif /* TIMER_H_ */