/*
 * LED.h
 *
 * Created: 9/29/2022 12:27:36 PM
 *  Author: Dell
 */ 



#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO Driver/DIO.h"

//CARS LEDS
#define CARS_GREENLED_PORT PORT_A
#define CARS_GREENLED_PIN  PIN0

#define CARS_YELLOWLED_PORT PORT_A
#define CARS_YELLOWLED_PIN  PIN1

#define CARS_REDLED_PORT PORT_A
#define CARS_REDLED_PIN  PIN2


//PEDSTRAIN LEDS
#define PED_GREENLED_PORT PORT_B
#define PED_GREENLED_PIN  PIN0

#define PED_YELLOWLED_PORT PORT_B
#define PED_YELLOWLED_PIN  PIN1

#define PED_REDLED_PORT PORT_B
#define PED_REDLED_PIN  PIN2




EN_DIOERR_t LED_init(u8 ledPort,u8 ledPin);
EN_DIOERR_t LED_on(u8 ledPort,u8 ledPin);
EN_DIOERR_t LED_off(u8 ledPort,u8 ledPin);
EN_DIOERR_t LED_toggle(u8 ledPort,u8 ledPin);
void LEDS_OFF();




#endif /* LED_H_ */