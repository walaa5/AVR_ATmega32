#include "I2c.h"
#include <avr/io.h>

void I2C_voidInitMaster(void)
{
	TWBR = 0x02; 							// bit rate = 400.000 kbps, F_CPU = 8M   SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
	TWSR &= ~((1<<TWPS1) | (1<<TWPS0));     //baud rate
	TWCR = (1<<TWEN);                       //enable I2C
}

void I2C_voidInitSlave(unsigned char Address)
{
	TWAR = (Address<<1);    // Set address
	TWCR = (1<<TWEN); 		//enable I2C
}

unsigned char I2C_u8Start(void)
{
	unsigned char Local_u8ErrorStatus=0;
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);     // Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	while(!(TWCR & (1<<TWINT)));                    // Wait till start condition is transmitted
	if((TWSR & 0xF8) != START_ACK)					// Check for the Status
	{
		Local_u8ErrorStatus=1;
	}
	return Local_u8ErrorStatus;

}

unsigned char I2C_u8SendRepeatedStart(void)
{
	unsigned char Local_u8ErrorStatus=0;
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);         // Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	while(!(TWCR & (1<<TWINT)));                        // wait till restart condition is transmitted
	if((TWSR & 0xF8) != REP_START_ACK)					// Check for the Status
	{
		Local_u8ErrorStatus=1;
	}
	return Local_u8ErrorStatus;
}

unsigned char I2C_u8SendSlaveAddressWithWrite(unsigned char SlaveAddress)
{
	unsigned char Local_u8ErrorStatus=0;
	TWDR = (SlaveAddress<<1);                     //Address and write instruction
	TWCR = (1<<TWINT) | (1<<TWEN);                 // Clear TWI interrupt flag, Enable TWI
	while (!(TWCR & (1<<TWINT)));                  // Wait till complete TWDR byte transmitted
	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)		// Check for the Status
	{
		Local_u8ErrorStatus=1;
	}
	return Local_u8ErrorStatus;
}

unsigned char I2C_u8SendSlaveAddressWithRead(unsigned char SlaveAddress)
{
	unsigned char Local_u8ErrorStatus=0;
	TWDR = (SlaveAddress<<1);                     	//Address
	TWDR |= (1<<0);                                 // read instruction
	TWCR = (1<<TWINT) | (1<<TWEN);                  // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT)));                   // Wait till complete TWDR byte received
	if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)		// Check for the Status
	{
		Local_u8ErrorStatus=1;
	}
	return Local_u8ErrorStatus;
}

unsigned char I2C_u8WriteDataByte(unsigned char DataByte)
{
	unsigned char Local_u8ErrorStatus=0;
	TWDR = DataByte;                    	// put data in TWDR
	TWCR = (1<<TWINT) | (1<<TWEN);       	// Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT)));        	// Wait till complete TWDR byte transmitted
	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)	// Check for the Status
	{
		Local_u8ErrorStatus=1;
	}
	return Local_u8ErrorStatus;
}

unsigned char I2C_u8ReadDataByte(unsigned char *DataByte)
{
	unsigned char Local_u8ErrorStatus=0;
	TWCR = (1<<TWINT) | (1<<TWEN);             // Clear TWI interrupt flag,Enable TWI
	while(!(TWCR & (1<<TWINT)));               // Wait till complete TWDR byte transmitted
	if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_NACK)// Check for the Status
	{
		Local_u8ErrorStatus=1;
	}
	*DataByte=TWDR;
	return Local_u8ErrorStatus;
}

void I2C_voidStop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO); // Clear TWI interrupt flag, Put stop condition on SDA,Enable TWI
}

