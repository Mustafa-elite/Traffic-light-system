/*
 * Timer.c
 *
 * Created: 10/5/2022 1:28:45 AM
 *  Author: Dell
 */ 

#include "Timer.h"

void TIMER_init()
{
	TCCR0 = 0x00;
}
EN_TIMERERR_t TIMER_start(EN_PRESCALER_t preSalerMode)
{
	EN_TIMERERR_t timerErr=TIMER_OK;
	if(preSalerMode>5)
	{
		timerErr=TIMER_NOK;
	
	}
	else
	{
		TCCR0 |=preSalerMode;
	}
	return timerErr;
}
void TIMER_stop()
{
	TCCR0 = 0x00;
}
EN_TIMERERR_t TIMER_get_state(u8 *timerState)
{
	EN_TIMERERR_t timerErr=TIMER_OK;
	if(NULL==timerState)
	{
		timerErr=TIMER_NULLPTR;
	}
	else
	{
		*timerState=(TIFR&(1<<0));
	}
	return timerErr;
}
EN_TIMERERR_t TIMER_set_value(u32 initValue)
{
	EN_TIMERERR_t timerErr=TIMER_OK;
	if(initValue>255)
	{
		timerErr=TIMER_NOK;
	}
	else
	{
		TCNT0 |= initValue;
	}
	return timerErr;
}
void TIMER_reset_TIFR()
{
	TIFR |=(1<<0);
}


