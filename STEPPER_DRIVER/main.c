/*
 * main.c
 *
 *  Created on: Sep 20, 2019
 *      Author: ESC
 */

#include "LIBS\STD_TYPES.h"
#include "STEPPER_INT.h"
#include "DIO_INT.h"
#include "LCD_INT.h"
#include "KPD_INT.h"
#include "SEVEN_SEGMENT_INT.h"
#include "util\delay.h"


u8 id_digit = 0;
u8 pass_digit = 0;
u16 id = 0;
u16 pass = 0;

u8 state = 0 ;
u16 id_copy ;
u16 pass_copy ;



u8 * pass_arr(u16 pass);
u8 * id_arr(u16 id);
void system(void);

int main()
{
	/*DIO_SetPortDirection(DDRD , 0XFF);

	u16 x ;
	STEPPER_voidSetAngle(90);

	_delay_ms(10000);

	for(x = 0 ; x<= 256 ; x++)
	{
		STEPPER_voidRotateAntiClockWise();
	}
	_delay_ms(10000);
	STEPPER_voidSetAngle(360);

	while(1)
	{
		STEPPER_voidRotateAntiClockWise();
		//STEPPER_voidSetAngle(d);
		//_delay_ms(10000);
	}*/


/*---------------------------------------- system code to unlock it -----------------------------------------------*/


	// LCD INATILIZE AND PORTS

	DIO_SetPortDirection(DDRD , 0xff);
	DIO_SetPortDirection(DDRC , 0xff);

	LCD_voidInit();
	LCD_voidSendCommand(0x0c);

	// KPD PORTS

	DIO_SetPortDirection(DDRA , 0X0F) ;
	DIO_SetPortValue(KPD_PORT , 0XFF) ;

	// 7 segment port

	DIO_SetPortDirection(DDRB , 0xff);

	// stepper port

	//DIO_SetPortDirection(DDRC , 0XFF);

		system() ;


	return 0 ;
}

void system(void)
{
	// some special shapes

	u8 bye[8] = {0x00 , 0x04, 0x0a , 0x15 , 0x0a , 0x04 , 0x0e ,0x11} ;
	u8 try_again[8] = {0x00 , 0x0a, 0x00 , 0x00 , 0x11 , 0x1f , 0x00 ,0x00};

	//LCD_voidWriteSpecialChar(u8 *pattern , u8 block_no, u8 x, u8 y);
	u8 count = 1 ;
	u8  *arr_id;
	u8  *arr_pass;
	u16 angle = 0;
	u8 i ;
	u8 direction ;

	// print welcome on LCD for 3 seconds

	LCD_voidGoToXY(0 , 4) ;
	LCD_Display("Welcome") ;
	_delay_ms(3 * 1000) ;

	// enter id

	LCD_voidSendCommand(0x01) ;
	LCD_voidGoToXY(0 , 1) ;
	LCD_Display("Enter ID:");

	u8 key;

	while(1)
	{
		key = NO_KEY ;
		key = KPD_u8GetPressedKey();

		if(state == 0)
		{
			 if(key != NO_KEY && (key == 0 || key == 1 || key == 2 || key == 3 || key == 4 || key == 5 || key == 6 || key == 7 || key == 8 || key == 9))
			 {
				 id = 10 * id + (u16)key ;
				 LCD_voidWriteNumber((u16)key) ;
			 }

			 else if(key != NO_KEY && key == '=')
			 {
				 state = 1 ;
				 arr_id = id_arr(id);
				 id_copy = id ;
				 while(id_copy != 0)
				 {
					id_copy /= 10 ;
					id_digit += 1 ;
				 }

				if(id_digit == 4)
				{

					_delay_ms(1000);
					LCD_voidSendCommand(0x01);
					LCD_voidGoToXY(0, 1) ;
					LCD_Display("Password:");
					SEVENSEGMENT_voidSetNumber(0 , PORTB);
				}

				else
				{
					LCD_voidGoToXY(1, 2) ;
					LCD_Display("ID Invalid!");
					_delay_ms(3* 1000);
					LCD_voidSendCommand(0x01);

					break ;
				}

			 }
		}

		// get password
		else if(state == 1)
		{
			 if(key != NO_KEY && (key == 0 || key == 1 || key == 2 || key == 3 || key == 4 || key == 5 || key == 6 || key == 7 || key == 8 || key == 9))
			 {
				 pass = 10 * pass + (u16)key ;
				 LCD_voidWriteNumber((u16)key) ;
			 }

			 else if(key != NO_KEY && key == '=')
			 {

				arr_pass = pass_arr(pass) ;

				 pass_copy = pass ;
				 while(pass_copy != 0)
				 {
					pass_copy /= 10 ;
					pass_digit += 1 ;
				 }

				 if(pass_digit == 4 && arr_id[0] == arr_pass[3] && arr_id[1] == arr_pass[2] && arr_id[2] == arr_pass[1] && arr_id[3] == arr_pass[0])
				 {
					 LCD_voidSendCommand(0x01);
					 LCD_voidGoToXY(0, 1) ;
					 LCD_Display("System Unlock");
					 LCD_voidGoToXY(1, 1) ;
					 LCD_Display("Stepper control");

					 _delay_ms(3 *1000) ;

					 state = 2 ;

					 LCD_voidSendCommand(0x01);
					 LCD_voidGoToXY(0, 1) ;
					 LCD_Display("Enter Direction") ;
					 LCD_voidGoToXY(1, 1) ;
					 LCD_Display("1:CW  2:CCW") ;

				 }
				 else
				 {
					 if(count <= 3)
					 {
						 LCD_voidSendCommand(0x01);
						 LCD_voidGoToXY(0 , 1) ;
						 LCD_Display("Try again:") ;

						 SEVENSEGMENT_voidSetNumber(count , PORTB) ;

						 LCD_voidWriteSpecialChar(try_again , 1 , 0 , 12);
						 _delay_ms(1000);

						 LCD_voidGoToXY(1, 1) ;
						 LCD_Display("Password:") ;
						 count += 1;
						 state = 1;
						 pass = 0;
						 pass_digit = 0;
						 continue ;
					 }
					 else
					 {
						 LCD_voidSendCommand(0x01);
						 LCD_voidGoToXY(0, 3) ;
						 LCD_Display("Bye Bye") ;
						 LCD_voidWriteSpecialChar(bye , 2 , 0 , 12);

						 for (i = 5 ; i > 1 ; i--)
						 {
							 SEVENSEGMENT_voidSetNumber(i-2 , PORTB);
							 _delay_ms(1000) ;
						 }

						 LCD_voidSendCommand(0x01);
						 SEVENSEGMENT_voidSetNumber(' ' , PORTB);
						 break;
					 }
				 }
			 }
		}

		// function that control motor if password is write

		else if(state == 2)
		{

			 if(key != NO_KEY && (key == 1 || key == 2 ))
			 {
				 direction = key ;
				 LCD_voidSendCommand(0x01);
				 LCD_voidGoToXY(0, 1) ;
				 LCD_Display("Enter Angle:") ;
				 LCD_voidGoToXY(1, 3);
				 state = 3 ;
			 }

		}

		else if(state == 3)
		{
			if(key != NO_KEY && (key == 0 || key == 1 || key == 2 || key == 3 || key == 4 || key == 5 || key == 6 || key == 7 || key == 8 || key == 9))
			{
				angle = angle * 10 + (u16)key ;
				LCD_voidWriteNumber((u16)key) ;
			}

			else if(key != NO_KEY && key == '=')
			{
				if(direction == 1)
				{
					STEPPER_voidSetAngleCW(angle) ;
					_delay_ms(3 * 1000);
				}
				else
				{
					STEPPER_voidSetAngleCCW(angle) ;
					_delay_ms(10 * 1000);
				}
				 state = 2 ;
				 LCD_voidSendCommand(0x01);
				 LCD_voidGoToXY(0, 1) ;
				 LCD_Display("Enter Direction") ;
				 LCD_voidGoToXY(1, 1) ;
				 LCD_Display("1:CW  2:CCW") ;
				 angle = 0;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// function will convert id number into array of each digit

u8 * id_arr(u16 ID)
{
	u8 i;
	static u8 arr[4] ;

	for(i = 5 ; i>1 ; i--)
	{
		arr[i-2] = (u8)(ID % 10) ;
		ID = ID /10 ;
	}
	return arr ;
}

// function will convert password number into array of each digit number

u8 * pass_arr(u16 password)
{
	u8 i;
	static u8 arr1[4] ;

	for(i = 5 ; i>1 ; i--)
	{
		arr1[i-2] = (u8)(password % 10) ;
		password = password /10 ;
	}
	return arr1 ;
}
