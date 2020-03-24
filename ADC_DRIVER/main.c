/*
 * main.c
 *
 *  Created on: Oct 4, 2019
 *      Author: ESC
 */
#include "ADC_INT.h"
#include "DIO_INT.h"
#include "LCD_INT.h"
#include "util\delay.h"
void main()
{

	DIO_SetPortDirection(DDRA , 0X00) ;
	DIO_SetPortValue(PORTA , 0xff) ;
	DIO_SetPortDirection(DDRB , 0XFF) ;

	//lcd ports
	DIO_SetPortDirection(DDRD , 0XFF);
	DIO_SetPortDirection(DDRC , 0XFF);

	LCD_voidInit();
	LCD_voidSendCommand(0X0C) ;

	 ADC_voidInit() ;
	 u8 value ;


	/* while(1)
	 {
		 value = ADC_u8ChannelReading(PIN0) ;
		 DIO_SetPortValue(PORTD , value) ;
	 }*/

/*--------------------- display ADC value on LCD -------------------------------*/

	 while(1)
	 {
		 value = ADC_u8ChannelReading(PIN0) ;
		 LCD_voidSendCommand(0X01);
		 DIO_SetPortValue(PORTB , value) ;
		 LCD_voidWriteNumber((u16)value);
		 _delay_ms(1000);



	 }
/*-------------------------- transducar -----------------------------*/
	/* u8 TEMP ;
	 while(1)
	 {
		 value = ADC_u8ChannelReading(PIN0) ;
		 LCD_voidSendCommand(0X01);
		// _delay_ms(10);
		 TEMP = (value * 500) / 256 ;
		 LCD_voidWriteNumber((u16) TEMP);
		 _delay_ms(1000);

	 }*/

}
