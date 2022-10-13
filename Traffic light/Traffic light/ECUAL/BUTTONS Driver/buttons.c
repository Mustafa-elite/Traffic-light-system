/*
 * buttons.c
 *
 * Created: 9/30/2022 1:53:16 AM
 *  Author: Dell
 */ 

#include "buttons.h"

EN_DIOERR_t BUTTON_init(u8 portNumber,u8 pinNumber)
{
	EN_DIOERR_t dioErr=OK;
	dioErr = DIO_init(portNumber,pinNumber,IN);
	return dioErr;
}
EN_DIOERR_t BUTTON_read(u8 portNumber,u8 pinNumber,u8 *value)
{
	EN_DIOERR_t dioErr=OK;
	if(NULL==value)
	{
		dioErr=NULLPTR;
	}
	else
	{
		dioErr = DIO_read(portNumber,pinNumber,value);
	}	
	return dioErr;
}