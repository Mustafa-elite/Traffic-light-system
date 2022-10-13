/*
 * registers.h
 *
 * Created: 9/29/2022 3:57:16 AM
 *  Author: Dell
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_


#include "../STD_TYPES.h"


/*********************************************/
/*               DIO Registers               */
/*********************************************/

//PORTA Registers
#define PORTA *((volatile u8*)0x3B)
#define DDRA *((volatile u8*)0x3A)
#define PINA *((volatile u8*)0x39)

//PORTB Registers
#define PORTB *((volatile u8*)0x38)
#define DDRB *((volatile u8*)0x37)
#define PINB *((volatile u8*)0x36)


//PORTC Registers
#define PORTC *((volatile u8*)0x35)
#define DDRC *((volatile u8*)0x34)
#define PINC *((volatile u8*)0x33)



//PORTD Registers
#define PORTD *((volatile u8*)0x32)
#define DDRD *((volatile u8*)0x31)
#define PIND *((volatile u8*)0x30)


//TIMER Registers
#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TIFR *((volatile u8*)0x58)



#endif /* REGISTERS_H_ */