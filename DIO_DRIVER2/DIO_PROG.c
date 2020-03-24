/*
 * DIO_PROG.c
 *
 *  Created on: Aug 23, 2019
 *      Author: ESC
 */

#include "LIBS\MATH.h"
#include "DIO_REG.h"
#include "DIO_INT.h"

void DIO_SetPinValue (u8 DIO_PORTID , u8 DIO_PINID , u8 DIO_PinValue)
{
	if (DIO_PinValue == HIGH)
	{
		switch(DIO_PORTID)
		{
		case PORTA:
			set_bit(PORTA_REG , DIO_PINID);
		break;

		case PORTB:
			set_bit(PORTB_REG , DIO_PINID) ;
		break;

		case PORTC:
			set_bit(PORTC_REG , DIO_PINID) ;
		break;

		case PORTD:
			set_bit(PORTD_REG , DIO_PINID) ;
		break;

		}

	}

	else if (DIO_PinValue == LOW)
	{
		switch(DIO_PORTID)
		{
		case PORTA:
			clr_bit(PORTA_REG , DIO_PINID) ;
		break;

		case PORTB:
			clr_bit(PORTB_REG , DIO_PINID) ;
		break;

		case PORTC:
			clr_bit(PORTC_REG , DIO_PINID) ;
		break;

		case PORTD:
			clr_bit(PORTD_REG , DIO_PINID) ;
		break;

			}

		}
}

void DIO_SetPinDirection (u8 DIO_DDRID , u8 DIO_PINID, u8 DIO_PINIO)
{
	if (DIO_PINIO == OUTPUT)
	{
		switch(DIO_DDRID)
		{
		case DDRA:
			set_bit(DDRA_REG , DIO_PINID);
		break;

		case DDRB:
			set_bit(DDRB_REG , DIO_PINID);
		break;

		case DDRC:
			set_bit(DDRC_REG , DIO_PINID);
		break;

		case DDRD:
			set_bit(DDRD_REG , DIO_PINID);
		break;

		}

	}

	if (DIO_PINIO == INPUT)
	{
		switch(DIO_DDRID)
		{
			case DDRA:
				clr_bit(DDRA_REG , DIO_PINID);
			break;

			case DDRB:
				clr_bit(DDRB_REG , DIO_PINID);
			break;

			case DDRC:
				clr_bit(DDRC_REG , DIO_PINID);
			break;

			case DDRD:
				clr_bit(DDRD_REG , DIO_PINID);
			break;

		}

	}
}

u8 DIO_GetPinValue (u8 DIO_PIN , u8 DIO_PINID)
{
	u8 value_read ;

	switch(DIO_PIN)
	{

	case PINA :
	value_read = read_bit(PINA_REG , DIO_PINID);
	break;

	case PINB :
	value_read = read_bit(PINB_REG , DIO_PINID);

	break;

	case PINC:
	value_read = read_bit(PINC_REG , DIO_PINID);
	break;

	case PIND:
	value_read = read_bit(PIND_REG ,DIO_PINID);
	break;

	}

	return value_read;
}

void DIO_SetPortDirection(u8 DIO_DDRID , u8 DIO_PortValue)
{

	switch(DIO_DDRID)
	{
		case DDRA:
			DDRA_REG = DIO_PortValue ;
		break ;

		case DDRB:
			DDRB_REG = DIO_PortValue ;
		break ;

		case DDRC:
			DDRC_REG = DIO_PortValue ;
		break ;

		case DDRD:
			DDRD_REG = DIO_PortValue ;
		break ;

	}

}

void DIO_SetPortValue(u8 DIO_PORTID , u8 DIO_PortValue)
{

	switch(DIO_PORTID)
	{

		case PORTA:
			PORTA_REG = DIO_PortValue ;
		break ;

		case PORTB:
			PORTB_REG = DIO_PortValue ;
		break ;

		case PORTC:
			PORTC_REG = DIO_PortValue ;
		break ;

		case PORTD:
			PORTD_REG = DIO_PortValue ;
		break ;

	}

}

u8 DIO_GetPortValue(u8 DIO_PIN)
{
	u8 value_read ;

	switch(DIO_PIN)
	{

		case PINA:
			value_read = PINA_REG ;
		break ;

		case PINB:
			value_read = PINB_REG ;
		break ;

		case PINC:
			value_read = PINC_REG ;
		break ;

		case PIND:
			value_read = PIND_REG ;
		break ;

	}

	return value_read;

}

