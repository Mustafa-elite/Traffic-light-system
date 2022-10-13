/*
 * Application.h
 *
 * Created: 9/30/2022 1:18:23 AM
 *  Author: Dell
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


#include "../ECUAL/LED Driver/LED.h"
#include "../ECUAL/BUTTONS Driver/buttons.h"
#include "../ECUAL/Delay/Delay.h"


typedef enum{
	NORMAL_SEQUENCE,
	PED_SEQUENCE
	}EN_APPFLOW_t;
	
void app_init();
u8 appStart();
void yellowsBlink();
void carsYelllowGreenCase();
void pedToNormalMode();
EN_APPFLOW_t greenForCar();
EN_APPFLOW_t yelllowForCar();
EN_APPFLOW_t redForCar();

#endif /* APPLICATION_H_ */