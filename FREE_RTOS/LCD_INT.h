/*
 * LCD_INT.h
 *
 *  Created on: Aug 30, 2019
 *      Author: ESC
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "LIBS\STD_TYPES.h"

// ports use for lcd -- depends on connections of every user
#define LCD_DATA_PORT PORTA
#define LCD_CTRL_PORT PORTB

// control pins : depends on connection of the user so can be changed
#define LCD_RS PIN0
#define LCD_RW PIN1
#define LCD_EN PIN2

void LCD_voidSendCommand(u8 COPY_LCD_CMD) ;
void LCD_voidWriteData(u8 COPY_LCD_WRITE);
void LCD_voidInit(void);

void LCD_voidGoToXY(u8 LCD_XPOS , u8 LCD_YPOS);
void LCD_voidWriteSpecialChar(u8 *pattern , u8 block_no, u8 x, u8 y);

void LCD_Display(u8 word[]);
void LCD_voidWriteNumber(u16 Number);



#endif /* LCD_INT_H_ */
