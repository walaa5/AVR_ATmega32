/*
 * LCD_PROG.c
 *
 *  Created on: Aug 30, 2019
 *      Author: ESC
 */

#include "LCD_INT.h"
#include "DIO_INT.h"
#include <avr\delay.h>


// initialization function : use it in the beginning of any lcd program
void LCD_voidInit(void)
{
	// wait for more than 30 ms
	_delay_ms(40);

	// function set command (8bit mode -- 2 lines -- 5*7)
	LCD_voidSendCommand (0b00111000);

	//wait for more than 39 us
	_delay_ms(1);

	//display on/off control command (cursor on/off -- cursor blink/not blink)
	LCD_voidSendCommand (0x0c);

	// wait for more than 39 us
	_delay_ms(1);

	//lcd clear : to clear any data on the lcd
	LCD_voidSendCommand (0x01);

	// delay for more than 1.53 ms
	_delay_ms(2);

	// entry mode set
	LCD_voidSendCommand(0x0A);

	//delay for more than 1 ms
	_delay_ms(1);

}


void LCD_voidSendCommand (u8 COPY_LCD_CMD)
{
	// disable Enable bin
	DIO_SetPinValue (LCD_CTRL_PORT,LCD_EN,LOW);

	//RS COMMAND : LOW
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_RS , LOW) ;
	//_delay_ms(1) ;

	//RW COMMAND : LOW
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_RW , LOW) ;
	//_delay_ms(1) ;

	// SEND THE COMMAND
	DIO_SetPortValue (LCD_DATA_PORT ,COPY_LCD_CMD) ;
	_delay_ms(1) ;

	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN , HIGH) ;
	_delay_ms(1) ;
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN , LOW) ;

}
void LCD_voidWriteData (u8  COPY_LCD_WRITE)
{

	// disable Enable bin
	DIO_SetPinValue (LCD_CTRL_PORT,LCD_EN,LOW);

	//RS COMMAND : HIGH
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_RS , HIGH) ;
	//_delay_ms(1) ;

	//RW COMMAND : LOW
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_RW , LOW) ;
	//_delay_ms(1) ;

	// SEND THE COMMAND
	DIO_SetPortValue (LCD_DATA_PORT ,COPY_LCD_WRITE) ;
	_delay_ms(1) ;

	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN , HIGH) ;
	_delay_ms(1) ;
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN , LOW) ;

}

void LCD_voidGoToXY(u8 LCD_XPOS , u8 LCD_YPOS)
{
	// SET DD RAM ADRESS
	LCD_voidSendCommand((LCD_XPOS * 0x40 + LCD_YPOS) | 0b10000000);

}

void LCD_voidWriteSpecialChar(u8 *pattern , u8 block_no, u8 x, u8 y)
{
	// variable for loop
	u8 i;

	// every block is 8 bytes so calculate address by multiply it with 8
	u8 address = 8 * block_no ;

	// set CG RAM address from data sheet (00 01 A5-A0)
	LCD_voidSendCommand(address | 0b01000000);

	// LOOP to write data from CGRAM to DDRAM (array of 8 bytes)
	for(i = 0 ; i< 8; i++)
	{
		LCD_voidWriteData(pattern[i]);
	}
	// set DDRAM to write on LCD by using GO TO XY
	LCD_voidGoToXY(x , y);

	//display block number from CGRAM
	LCD_voidWriteData(block_no);
}
void LCD_voidWriteNumber(u16 Number)
{
	u8 num_digit = 0 ;
	u8 i;
	u16 copy_number = Number;

	while(copy_number != 0)
	{
		copy_number /= 10 ;
		num_digit += 1;
	}

	u8 arr[num_digit] ;

	for(i = num_digit ; i> 0 ; i--)
	{
		arr[i-1] = (u8)((Number % 10) +'0') ;
		Number = Number /10 ;
	}


	for(i = 0 ; i<num_digit ; i++)
	{
		LCD_voidWriteData(arr[i]) ;
	}

}

void LCD_Display(u8 word[])
{
	u8 i ;

	for(i = 0; word[i]!=0 ;i++)
	{
		LCD_voidWriteData(word[i]);
	}
}


