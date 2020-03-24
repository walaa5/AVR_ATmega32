/*
 * STEPPER_INT.h
 *
 *  Created on: Sep 20, 2019
 *      Author: ESC
 */

#ifndef STEPPER_INT_H_
#define STEPPER_INT_H_

#include"LIBS/STD_TYPES.h"

#define STEPPER_PORT PORTC
#define COIL0 PIN7
#define COIL1 PIN6
#define COIL2 PIN5
#define COIL3 PIN4

void STEPPER_voidRotateClockWise(void);
void STEPPER_voidRotateAntiClockWise(void);
void STEPPER_voidSetAngleCW(u16 copy_u8Angle);
void STEPPER_voidSetAngleCCW(u16 copy_u8Angle);
#endif /* STEPPER_INT_H_ */
