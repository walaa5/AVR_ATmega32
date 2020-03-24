/*
 * DIO_INT.h
 *
 *  Created on: Aug 23, 2019
 *      Author: ESC
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "LIBS\STD_TYPES.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define HIGH 1
#define LOW 0

#define DDRA 4
#define DDRB 5
#define DDRC 6
#define DDRD 7

#define OUTPUT 1
#define INPUT  0

#define PINA 0
#define PINB 1
#define PINC 2
#define PIND 3




void DIO_SetPinValue(u8 DIO_PORTID , u8 DIO_PINID , u8 DIO_PinValue);
void DIO_SetPinDirection(u8 DIO_DDRID , u8 DIO_PINID, u8 DIO_PINIO) ;

u8 DIO_GetPinValue (u8 DIO_PIN , u8 DIO_PINID) ;

void DIO_SetPortDirection(u8 DIO_DDRID , u8 PortValue) ;
void DIO_SetPortValue(u8 DIO_PORTID , u8 DIO_PortValue) ;



#endif /* DIO_INT_H_ */
