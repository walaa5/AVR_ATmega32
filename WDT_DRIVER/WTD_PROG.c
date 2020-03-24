/*
 * WTD_PROG.c
 *
 *  Created on: Oct 19, 2019
 *      Author: ESC
 */

#include "WDT_INT.h"
#include "WDT_REG.h"

#include"LIBS\MATH.h"
void WTD_voidSetTimeOut(u8 timeout)
{
	// ENABLE WDT
	set_bit(WDTCR , WDTCR_WDE) ;

	// PUT THE TIME VALUE
	WDTCR = WDTCR | timeout ;
}

void WDT_voidDisable(void)
{
	WDTCR = 0b00011000 ;
	WDTCR = 0X00 ;
}
