/*
 * Delay.c
 *
 * Created: 10/5/2022 1:59:54 PM
 *  Author: Dell
 */ 





#include "Delay.h"


void Delay_init()
{
	TIMER_init();
}
EN_TIMERERR_t Delay_ms(u32 msDelay)
{
	f32 timerTick = 0, initValueBuffer = 0;
	u32 overFlowsNum = 0, overFlowsCounter = 0, preScalerValue=1;
	u8  timerInitValue = 0;
	EN_PRESCALER_t preScalerType = PRESCALER8;
	EN_TIMERERR_t timerErr=TIMER_OK;
	if(msDelay>3)
	{
		msDelay-=3;
	}
	if (msDelay < 100000)
	{
		preScalerType =NOPRESCALER;
		preScalerValue = 1;
	}
	else if (msDelay < 1000)
	{
		preScalerType = PRESCALER64;
		preScalerValue = 64;
	}
	else if (msDelay < 10000)
	{
		preScalerType = PRESCALER256;
		preScalerValue = 256;
	}
	else
	{
		preScalerType = PRESCALER1024;
		preScalerValue = 1024;
	}
	timerTick = (f32)preScalerValue / CPU_FREQUENCY;
	overFlowsNum = (u32)(((f32)msDelay/1000) / (timerTick * 256)) + 1;
	initValueBuffer = 256 - ((((f32)msDelay / 1000) / timerTick) / (overFlowsNum));
	timerInitValue = initValueBuffer;
	initValueBuffer -= timerInitValue;
	initValueBuffer *= 100;
	if (initValueBuffer >= 50)
	{
		timerInitValue++;
	}
	else
	{
	}
	
	timerErr = TIMER_set_value(timerInitValue);
	if(timerErr != TIMER_OK)
	{
		
	}
	else
	{
		
		timerErr = TIMER_start(preScalerType);
		while(overFlowsCounter<overFlowsNum)
		{
			//TIMER_set_value(timerInitValue);
			while((TIFR&(1<<0))==0);
			
			TIMER_reset_TIFR();
			overFlowsCounter++;
		
		}
		TIMER_stop();
	}
	return timerErr;
	
}