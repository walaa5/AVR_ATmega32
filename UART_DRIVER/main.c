/*
 * main.c
 *
 *  Created on: Nov 1, 2019
 *      Author: ESC
 */

#include"LIBS\STD_TYPES.h"
#include"UART_INT.h"
#include"DIO_INT.h"
#include"util\delay.h"

/*void main()
{

	// LCD INATILIZE AND PORTS

	DIO_SetPortDirection(DDRA , 0xff);
	DIO_SetPortDirection(DDRB , 0xff);

	LCD_voidInit();
	LCD_voidSendCommand(0x0c);

	// initialize UART
	USART_voidInit();

	DIO_SetPinDirection(DDRC , PIN0 , OUTPUT) ;

	//u8 x = 0;
	u8 y ;
	DIO_SetPinValue(PORTC , PIN0 , HIGH) ;
	//USART_voidSendString("walaa");
	 //USART_voidSendAsciiNumber(1256);


	while(1)
	{

		y = USART_u8Receive();
		USART_voidTransmit(y);
		LCD_voidWriteData(y);

		if(USART_u8Receive() == '1')
		{

			DIO_SetPinValue(PORTC , PIN0 , HIGH) ;

		}

		else if(USART_u8Receive() == '2')
		{
			DIO_SetPinValue(PORTC , PIN0 , LOW) ;
		}

	}


}*/
