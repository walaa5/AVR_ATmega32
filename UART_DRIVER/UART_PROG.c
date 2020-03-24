/*
 * UART_PROG.c
 *
 *  Created on: Oct 26, 2019
 *      Author: ESC
 */
#include "UART_REG.h"
#include "LIBS/MATH.h"
#include "UART_INT.h"

void USART_voidInit(void)
{
	u8 UCSRC_VALUE = 0 ;
	// UART ENABLE
	set_bit(UCSRB , UCSRB_RXEN) ;
	set_bit(UCSRB , UCSRB_TXEN) ;

	// access USCRC register
	set_bit(UCSRC_VALUE , UCSRC_URSEL) ;

	//characterized : 8bits
	set_bit(UCSRC_VALUE , UCSRC_UCSZ1) ;
	set_bit(UCSRC_VALUE , UCSRC_UCSZ0) ;

	// send the value to the transmitter
	UCSRC = UCSRC_VALUE ;

	// 9600 bps baudrate
	UBRRL=51;
}

void USART_voidTransmit(u8 data)
{
	// polling with blocking on UDRE
	while((read_bit(UCSRA , UCSRA_UDRE))== 0);

	// send the data
	UDR = data ;

	// check for transmitter complete
	//while((read_bit(UCSRA , UCSRA_TXC)) == 0);
	//set_bit(UCSRA , UCSRA_TXC);
}

u8 USART_u8Receive(void)
{
	// poling with blocking on receive complete
	while((read_bit(UCSRA , UCSRA_RXC)) == 0) ;

	// get the data
	return UDR ;
}

void USART_voidSendString(char * str)
{
	u8 i ;

	for(i = 0; str[i]!=0 ;i++)
	{
		USART_voidTransmit(str[i]);
	}
}

void USART_voidSendAsciiNumber(u16 Number)
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
		USART_voidTransmit(arr[i]) ;
	}
}

