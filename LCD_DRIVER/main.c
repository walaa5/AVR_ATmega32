/*
 * main.c
 *
 *  Created on: Aug 30, 2019
 *      Author: ESC
 */

#include "LIBS\STD_TYPES.h"
#include "LCD_INT.h"
#include "DIO_INT.h"
#include <avr\delay.h>


int main()
{
	DIO_SetPortDirection(DDRA , 0xff);
	DIO_SetPortDirection(DDRC , 0xff);

	LCD_voidInit();
	LCD_voidSendCommand(0x0c);

	/*LCD_voidWriteCommand('h');
	LCD_voidWriteCommand('e');
	LCD_voidWriteCommand('l');
	LCD_voidWriteCommand('l');
	LCD_voidWriteCommand('o');*/

	//LCD_voidGoToXY(0,0) ;
	//LCD_Display("_gg") ;

	//LCD_voidWriteData('1');
	/*u8 x = 0;
	u8 y = 0;

	while(1)
	{
		x = 0;
		y = 0;
		while(y < 16-5)
		{
			x = 0;
			while(x < 2)
			{
				LCD_voidGoToXY(x,y);
				LCD_Display("walaa");
				_delay_ms(10000);
				y += 2;
				x += 1;
				LCD_voidSendCommand (0x01);
				_delay_ms(2);
			}
			y += 2;
	}}*/

	//u8 pattern[8] = {0x00 , 0x12 , 0x12 , 0x12 , 0x1E , 0x04 , 0x00, 0x00} ;

/* ---------- program that write my name in arabic as sin wave ----------*/

	u8 pattern1[8] = {0x00 , 0x06 , 0x06 , 0x02 , 0x1E , 0x00 , 0x00, 0x00} ;
	u8 pattern2[8] = {0x00 , 0x0b , 0x0b , 0x0b , 0x1f , 0x1f , 0x00, 0x00} ;
	u8 pattern3[8] = {0x00 , 0x07 , 0x04 , 0x14 , 0x1f , 0x00 , 0x00, 0x00} ;

	u8 x = 0;
	u8 y = 0;

	while(1)
	{
		x = 0;
		y = 15;
		while(y > 3)
		{
			x = 0;
			while(x < 2)
			{
				LCD_voidWriteSpecialChar(pattern1 , 0 , x , y) ;
				LCD_voidWriteSpecialChar(pattern2 , 1 , x , y-1) ;
				LCD_voidWriteSpecialChar(pattern3 , 2 , x , y-2) ;

				_delay_ms(10000);
				y -= 1;
				x += 1;
				LCD_voidSendCommand (0x01);
				_delay_ms(2);
			}
			//y += 2;
		}
	}

////////////////////////////////////////////////////////////////////////////////////


/*------------- project that write u16 number on the lcd ----------*/
	//u16 x = 1234;
	//LCD_voidWriteNumber(65500);


/*------------------- project of the gun and dead men ------------*/

	/*u8 x ;

	u8 gun[8]      ={0x00 , 0x1e , 0x1c , 0x18 , 0x18 , 0x10 , 0x10 ,0x00};
	u8 man[8]      ={0x0e , 0x0e , 0x04 , 0x0e , 0x15 , 0x04 , 0x0a ,0x11};
	u8 bullet[8]   ={0x00 , 0x00 , 0x0c , 0x0e , 0x0c , 0x00 , 0x00 ,0x00};
	u8 dead_man[8] ={0x00 , 0x00 , 0x15 , 0x0f , 0x15 , 0x00 , 0x00 ,0x00};
	u8 clear [8]   ={0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,0x00};
	u8 sad[8]      ={0x00 , 0x00 , 0x0a , 0x00 , 0x00 , 0x04 , 0x0a ,0x00};
	while(1)
	{

		LCD_voidWriteSpecialChar(gun , 0 , 0 , 1);
		LCD_voidWriteSpecialChar(man , 1 , 0 , 14);
		//LCD_voidWriteSpecialChar(man , 2 , 0 , 13);

		for(x = 2 ; x < 14 ; x++)
		{
			LCD_voidWriteSpecialChar(bullet , 3 , 0 , x);
			_delay_ms(10000);
			/*{
				//LCD_voidWriteSpecialChar(clear , 4 , 0 , x);
				LCD_voidWriteSpecialChar(dead_man , 5 , 1 , x);
				_delay_ms(10000);
			}

			LCD_voidWriteSpecialChar(clear , 4 , 0 , x);
		}
		LCD_voidWriteSpecialChar(clear , 4 , 0 , 14);
		LCD_voidWriteSpecialChar(dead_man , 5 , 1 , 14);
		_delay_ms(100000);

		LCD_voidGoToXY(1,0) ;
		LCD_Display("Ohh!!sorry");
		LCD_voidWriteSpecialChar(sad , 6 , 1 , 11);
		_delay_ms(600000);
		LCD_voidSendCommand(0x01);
		_delay_ms(10000);
	}*/
////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}

/*void LCD_Display(u8 word[])
{
	u8 i ;

	for(i = 0; word[i]!=0 ;i++)
	{
		LCD_voidWriteData(word[i]);
	}
}*/


