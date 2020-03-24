/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: ESC
 */

#include "DIO_INT.h"
#include "LIBS\STD_TYPES.h"

//#include <avr/delay.h>



int main()
{
//DDRA = 0x01 ;
	//PORTA = 0x01 ;
	/*u8 pin_value ;
	DIO_SetPinDirection(DDRA , PIN7, OUTPUT) ;
	DIO_SetPinDirection(DDRC_ID , PIN0, INPUT) ;

	DIO_SetPortDirection (DDRD_ID , OUTPUT) ;*/

	DIO_SetPinDirection(DDRD , PIN7, OUTPUT) ;
	DIO_SetPinValue(PORTD , PIN0, HIGH) ;

	/*while(1)
	{
		DIO_SetPinValue(PORTD , PIN0, HIGH) ;
		pin_value = DIO_GetPinValue(PINC_ID , PIN0) ;

		DIO_SetPortValue(PORTD_ID , HIGH) ;

		if(pin_value == 0)
		{
			DIO_SetPinValue(PORTA_ID , PIN7, HIGH) ;
		}
	    else
		{
			DIO_SetPinValue(PORTA_ID , PIN7, LOW) ;
		}
	}
*/

	/*DIO_SetPortDirection(PORTC , OUTPUT) ;

	while(1)
	{
		DIO_SetPinValue(PORTC , PIN1 , HIGH);
		DIO_SetPinValue(PORTC , PIN2 , HIGH);
		_delay_ms(10000) ;
		DIO_SetPinValue(PORTC , PIN1 , LOW);
		DIO_SetPinValue(PORTC , PIN2 , LOW);

		DIO_SetPinValue(PORTC , PIN0 , HIGH);
		DIO_SetPinValue(PORTC , PIN1 , HIGH);
		DIO_SetPinValue(PORTC , PIN3 , HIGH);
		DIO_SetPinValue(PORTC , PIN4 , HIGH);
		DIO_SetPinValue(PORTC , PIN6 , HIGH);
		_delay_ms(10000) ;
		DIO_SetPinValue(PORTC , PIN0 , LOW);
		DIO_SetPinValue(PORTC , PIN1 , LOW);
		DIO_SetPinValue(PORTC , PIN3 , LOW);
		DIO_SetPinValue(PORTC , PIN4 , LOW);
		DIO_SetPinValue(PORTC , PIN6 , LOW);

		DIO_SetPinValue(PORTC , PIN0 , HIGH);
		DIO_SetPinValue(PORTC , PIN1 , HIGH);
		DIO_SetPinValue(PORTC , PIN2 , HIGH);
		DIO_SetPinValue(PORTC , PIN3 , HIGH);
		DIO_SetPinValue(PORTC , PIN6 , HIGH);
		_delay_ms(10000) ;

		DIO_SetPinValue(PORTC , PIN0 , LOW);
		DIO_SetPinValue(PORTC , PIN1 , LOW);
		DIO_SetPinValue(PORTC , PIN2 , LOW);
		DIO_SetPinValue(PORTC , PIN3 , LOW);
		DIO_SetPinValue(PORTC , PIN6 , LOW);

		_delay_ms(10000) ;



	}
*/

	return 0;
}
