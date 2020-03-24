/*
 * UART_REG.h
 *
 *  Created on: Oct 26, 2019
 *      Author: ESC
 */

#ifndef UART_REG_H_
#define UART_REG_H_

#include"LIBS/STD_TYPES.h"

#define UDR *((volatile u8 *)0X2C)
#define UCSRA *((volatile u8 *)0X2B)
#define UCSRB *((volatile u8 *)0X2A)
#define UCSRC *((volatile u8 *)0X40)
#define UBRRL *((volatile u8 *)0X29)

#define UCSRC_URSEL 7
#define UCSRC_UMSEL 6
#define UCSRC_UPM1 5
#define UCSRC_UPM0 4
#define UCSRC_USBS 3

#define UCSRC_UCSZ1 2
#define UCSRC_UCSZ0 1
#define UCSRC_UCPOL 0

#define UCSRB_RXEN 4
#define UCSRB_TXEN 3
#define UCSRB_UCSZ2 2

#define UCSRA_UDRE 5
#define UCSRA_TXC 6
#define UCSRA_RXC 7

#endif /* UART_REG_H_ */
