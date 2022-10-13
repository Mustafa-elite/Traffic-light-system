/*
 * DIO.h
 *
 * Created: 9/29/2022 4:12:10 AM
 *  Author: Dell
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../registers.h"
#include <stdio.h>

//PORTS MACROS
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D' 

//PINS DIRECTIONS
#define IN 0
#define OUT 1

//PINS VALUE
#define LOW 0
#define HIGH 1

typedef enum {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
	}EN_PINNUM_t;
	
typedef enum{
	NULLPTR,
	INVALID_ARGUMENT,
	OK
	}EN_DIOERR_t;
	


EN_DIOERR_t DIO_init(u8 portNumber,EN_PINNUM_t pinNumber,u8 direction);
EN_DIOERR_t DIO_write(u8 portNumber,EN_PINNUM_t pinNumber,u8 value);
EN_DIOERR_t DIO_read(u8 portNumber,EN_PINNUM_t pinNumber,u8 *value);
EN_DIOERR_t DIO_toggle(u8 portNumber,EN_PINNUM_t pinNumber);


#endif /* DIO_H_ */