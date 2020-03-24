/*
 * EEPROM_PROG.c
 *
 *  Created on: Nov 8, 2019
 *      Author: ESC
 */

#include"I2C.h"
#include"EEPROM_INT.h"

void EEPROM_voidWriteByte(u16 Address , u8 Byte)
{
	// send start condition
	I2C_u8Start();

	// send slave address
	 I2C_u8SendSlaveAddressWithWrite(EEPROM_FIXED_ADDRESS | A2 << 2 |((Address >> 8)&3));

	 // send the 8 lsb location address
	 I2C_u8WriteDataByte((u8)Address);

	 // send the data
	 I2C_u8WriteDataByte(Byte) ;

	 //reload the bus
	 I2C_voidStop();

}

u8 EEPROM_voidReadByte(u16 Address)
{
	u8 Data ;
	// send start condition
	I2C_u8Start();

	// send slave with write
	I2C_u8SendSlaveAddressWithWrite(EEPROM_FIXED_ADDRESS | A2 << 2 |((Address >> 8)&3));

	// send slave Address 8 lsb
	I2C_u8WriteDataByte((u8)Address);

	// repeated start to change operation to reading
	I2C_u8SendRepeatedStart();

	// send read operation
	I2C_u8SendSlaveAddressWithRead(EEPROM_FIXED_ADDRESS | A2 << 2 |((Address >> 8)&3));

	//read the data
	I2C_u8ReadDataByte(&Data) ;

	// stop the bus
	I2C_voidStop();

	// return the data
	return Data ;

}
