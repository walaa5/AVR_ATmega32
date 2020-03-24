/*
 * SPI_PROG.h
 *
 *  Created on: Nov 1, 2019
 *      Author: ESC
 */

void SPI_voidInit(u8 Role)
{
	// SPI ENABLE
	set_bit(SPCR , SPCR_SPE) ;

	//check on master or slave
	if(Role == SPI_MASTER)
	{
		set_bit(SPCR , SPCR_MSTR);

		//SET FREQUENCY DIVIDE BY 16
		set_bit(SPCR , SPCR_SPRO);

	}
	else if(Role == SPI_SLAVE)
	{
		clr_bit(SPCR , PCR_MSTR);
	}

}

u8 SPI_u8Rectrans
