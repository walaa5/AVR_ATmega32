/*
 * main.c
 *
 *  Created on: Sep 13, 2019
 *      Author: ESC
 */

#include "LIBS\STD_TYPES.h"
#include "DIO_INT.h"
#include "DCMOTOR_INT.h"
#include "KPD_INT.h"
#include "LCD_INT.h"

#include <avr/delay.h>

int main()
{

	/*LCD_voidInit() ;
	LCD_voidSendCommand(0x0c);*/

	//DIO_SetPortDirection(DDRA ,0XFF) ;
	//DCMOTOR_voidRotateClockWise() ;

	//

	DIO_SetPortDirection(DDRD , 0xff);
	/*while(1)
	{
		DCMOTOR_voidRotateClockWise() ;
		_delay_ms(10000000) ;

		DCMOTOR_voidRotateAntiClockWise();
		_delay_ms(10000000) ;

		DCMOTOR_voidStop();
		_delay_ms(10000000) ;


	}*/

/*----------------- drive DC motor in 1 direction using opto_coupler-----------------*/

	DIO_SetPinDirection(DDRA, PIN0 , OUTPUT);

	while(1)
	{
		DIO_SetPinValue(PORTD , PIN6, HIGH);
		_delay_ms(1000000);
		DIO_SetPinValue(PORTD , PIN6, LOW);
		_delay_ms(1000000);
	}


/*-------------------project of DC_motor with KPD and LCD-------------------*/

	// set direction of KPD port
/*	DIO_SetPortDirection(DDRB , 0x0f);
	DIO_SetPortValue(KPD_PORT , 0xff);

	// set direction  of LCD port
	DIO_SetPortDirection(DDRC , 0xff);
	DIO_SetPortDirection(DDRD , 0xff);

	LCD_voidInit();
	LCD_voidSendCommand(0x0c);

	// set port direction of relay
	//DIO_SetPortDirection(DDRA , 0xff);

	LCD_Display("ENTER:1-right");
	LCD_voidGoToXY(1,0) ;
	LCD_Display("2-left  3-stop");

	u8 key ;

	while(1)
	{
		key = KPD_u8GetPressedKey();

		if(key == 0)
		{
			key = KPD_u8GetPressedKey();
		}

		else if(key == 1)
		{
			LCD_voidSendCommand(0x01);
			//_delay_ms(1000);
			LCD_Display(" now : right") ;
			//DCMOTOR_voidRotateClockWise();
			//_delay_ms(100);
		}

		else if(key == 2)
		{
			LCD_voidSendCommand(0x01);
			LCD_Display(" now : left") ;
			//_delay_ms(100);
			//DCMOTOR_voidRotateAntiClockWise();

		}

		else if(key == 3)
		{
			LCD_voidSendCommand(0x01);
			LCD_Display(" now : stop") ;
			//_delay_ms(100);
			//DCMOTOR_voidStop();
		}
		else
		{
			LCD_voidSendCommand(0x01);
			LCD_Display("ENTER:1-right");
			LCD_voidGoToXY(1,0) ;
			LCD_Display("2-left  3-stop");
			//DCMOTOR_voidStop();
		}
	}*/


	  return 0;
}
