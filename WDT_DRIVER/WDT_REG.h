/*
 * WDT_REG.h
 *
 *  Created on: Oct 19, 2019
 *      Author: ESC
 */

#ifndef WDT_REG_H_
#define WDT_REG_H_

#include"LIBS\STD_TYPES.h"

#define WDTCR *((volatile u8 *) 0x41)

#define WDTCR_WDE 3

#endif /* WDT_REG_H_ */
