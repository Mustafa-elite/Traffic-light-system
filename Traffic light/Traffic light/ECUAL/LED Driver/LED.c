/*
 * LED.c
 *
 * Created: 9/29/2022 12:27:21 PM
 *  Author: Dell
 */ 

#include "LED.h"

EN_DIOERR_t LED_init(u8 ledPort,u8 ledPin)
{
	EN_DIOERR_t dioErr=OK;
	dioErr = DIO_init(ledPort,ledPort,OUT);
	return dioErr;
}
EN_DIOERR_t LED_on(u8 ledPort,u8 ledPin)
{
	EN_DIOERR_t dioErr=OK;
	dioErr =DIO_write(ledPort,ledPin,HIGH);
	return dioErr;
}
EN_DIOERR_t LED_off(u8 ledPort,u8 ledPin)
{
	EN_DIOERR_t dioErr=OK;
	dioErr = DIO_write(ledPort,ledPin,LOW);
	return dioErr;
}
EN_DIOERR_t LED_toggle(u8 ledPort,u8 ledPin)
{
	EN_DIOERR_t dioErr=OK;
	dioErr = DIO_toggle(ledPort,ledPin);
	return dioErr;
}
void LEDS_OFF()
{
	LED_off(CARS_REDLED_PORT,CARS_REDLED_PIN);
	LED_off(CARS_YELLOWLED_PORT,CARS_YELLOWLED_PIN);
	LED_off(CARS_GREENLED_PORT,CARS_GREENLED_PIN);
	
	LED_off(PED_REDLED_PORT,PED_REDLED_PIN);
	LED_off(PED_YELLOWLED_PORT,PED_YELLOWLED_PIN);
	LED_off(PED_GREENLED_PORT,PED_GREENLED_PIN);
}