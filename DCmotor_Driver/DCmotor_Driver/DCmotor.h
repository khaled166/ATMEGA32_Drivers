/*
 * DCmotor.h
 *
 * Created: 7/29/2020 6:27:25 PM
 *  Author: Khaledseif166
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "DIO.h"

#define   clk_wise_dir          0
#define   Anti_clkwise_dir      1

void DCmotor_init(void);

void DCmotor_Direction(uint32 dir);

void DCmotor_Move(uint8 speed);





#endif /* DCMOTOR_H_ */