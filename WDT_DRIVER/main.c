/*
 * main.c
 *
 *  Created on: Oct 19, 2019
 *      Author: ESC
 */

#include "DIO_INT.h"
#include "WDT_INT.h"
#include "util\delay.h"

void main()
{
	DIO_SetPinDirection(DDRA, PIN0 , OUTPUT);
	DIO_SetPinValue(PORTA , PIN0 , HIGH);

	_delay_ms(1000) ;
	DIO_SetPinValue(PORTA , PIN0 , LOW);

	WTD_voidSetTimeOut(6);
	while(1);

}
