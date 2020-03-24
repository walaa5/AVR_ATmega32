/*
 * EEPROM.h
 *
 *  Created on: Nov 8, 2019
 *      Author: ESC
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#include"LIBS\STD_TYPES.h"

#define A2 0
#define EEPROM_FIXED_ADDRESS 0x50

u8 EEPROM_voidReadByte(u16 Address);
void EEPROM_voidWriteByte(u16 Address , u8 Byte);

#endif /* EEPROM_INT_H_ */
