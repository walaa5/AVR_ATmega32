/*
 * UART_INT.h
 *
 *  Created on: Oct 26, 2019
 *      Author: ESC
 */

#ifndef UART_INT_H_
#define UART_INT_H_

#include"LIBS/STD_TYPES.h"

void USART_voidInit(void);
void USART_voidTransmit(u8 data);
u8 USART_u8Receive(void);

void USART_voidSendAsciiNumber(u16 Number);
void USART_voidSendString(char * str);

#define no_data 200
#define LEDON 1
#define LEDOFF 2
#define MUSIC 3


#endif /* UART_INT_H_ */
