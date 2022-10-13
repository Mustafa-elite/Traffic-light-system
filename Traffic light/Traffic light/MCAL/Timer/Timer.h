/*
 * Timer.h
 *
 * Created: 10/5/2022 1:29:25 AM
 *  Author: Dell
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../registers.h"
#include <stdio.h>

#define CPU_FREQUENCY 1000000

typedef enum {
	STOP_TIMER,
	NOPRESCALER,
	PRESCALER8,
	PRESCALER64,
	PRESCALER256,
	PRESCALER1024
	}EN_PRESCALER_t;

typedef enum{
	TIMER_NULLPTR,
	TIMER_OK,
	TIMER_NOK
	}EN_TIMERERR_t;



void TIMER_init();
EN_TIMERERR_t TIMER_start(EN_PRESCALER_t preSalerMode);
EN_TIMERERR_t TIMER_get_state(u8* timerState);
EN_TIMERERR_t TIMER_set_value(u32 initValue);
void TIMER_reset_TIFR();
void TIMER_stop();

#endif /* TIMER_H_ */