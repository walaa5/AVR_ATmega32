/*
 * KPD_INT.h
 *
 *  Created on: Sep 7, 2019
 *      Author: ESC
 */

#ifndef KPD_INT_H_
#define KPD_INT_H_

#include "DIO_REG.h"
#include "LIBS\STD_TYPES.h"
#include "DIO_INT.h"

#define KPD_PORT PORTD
#define KPD_PIN PIND

u8 KPD_u8GetPressedKey (void);

#endif /* KPD_INT_H_ */
