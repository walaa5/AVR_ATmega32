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

#define KPD_PORT PORTA
#define KPD_PIN PINA
#define NO_KEY 48

u8 KPD_u8GetPressedKey (void);

#endif /* KPD_INT_H_ */
