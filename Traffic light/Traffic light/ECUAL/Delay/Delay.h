/*
 * Delay.h
 *
 * Created: 10/5/2022 2:00:15 PM
 *  Author: Dell
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include "../../MCAL/Timer/Timer.h"

void Delay_init();
EN_TIMERERR_t Delay_ms(u32 msDelay);




#endif /* DELAY_H_ */