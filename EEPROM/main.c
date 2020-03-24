/*
 * main.c
 *
 *  Created on: Nov 9, 2019
 *      Author: ESC
 */

#include"I2C.h"
#include"EEPROM_INT.h"
#include"DIO_INT.h"
#include"util/delay.h"

void main()
{
	I2C_voidInitMaster();
	DIO_SetPortDirection(DDRD , 0XFF);
	//DIO_SetPortDirection(DDRC , 0XFF);

	EEPROM_voidWriteByte(0 ,0x55);
	_delay_ms(10);
	u8 x = EEPROM_voidReadByte(0);
	DIO_SetPortValue(PORTD ,x);


}
