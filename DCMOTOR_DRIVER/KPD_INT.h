/*
 * KPD_INT.h
 *
 *  Created on: Sep 7, 2019
 *      Author: ESC
 */

#ifndef KPD_INT_H_
#define KPD_INT_H_

#include "LIBS\STD_TYPES.h"

#define KPD_PORT PORTB
#define KPD_PIN PINB

u8 KPD_u8GetPressedKey (void);

#endif /* KPD_INT_H_ */
