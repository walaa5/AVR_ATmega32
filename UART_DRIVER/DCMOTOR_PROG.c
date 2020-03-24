/*
 * DCMOTOR_PROG.c
 *
 *  Created on: Sep 13, 2019
 *      Author: ESC
 */

#include "LIBS\STD_TYPES.h"
#include "DCMOTOR_INT.h"
#include "DIO_INT.h"


void DCMOTOR_voidRotateClockWise(void)
{
	DIO_SetPinValue(MOTOR_PORT , MOTOR_PIN0 , LOW);
	DIO_SetPinValue(MOTOR_PORT , MOTOR_PIN1 , HIGH);
}

void DCMOTOR_voidRotateAntiClockWise(void)
{
	DIO_SetPinValue(MOTOR_PORT , MOTOR_PIN1 , LOW);
	DIO_SetPinValue(MOTOR_PORT , MOTOR_PIN0 , HIGH);
}
void DCMOTOR_voidStop(void)
{
	DIO_SetPinValue(MOTOR_PORT , MOTOR_PIN1 , LOW);
	DIO_SetPinValue(MOTOR_PORT , MOTOR_PIN0 , LOW);
}

/*void DCMOTOR_voidOptoCoupler(void)
{
	DIO_SetPinValue(MOTOR_PORT , MOTOR_PIN , L);
}*/
