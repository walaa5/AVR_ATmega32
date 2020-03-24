/*
 * STEPPER_PROG.c
 *
 *  Created on: Sep 20, 2019
 *      Author: ESC
 */

#include"LIBS/STD_TYPES.h"
#include"DIO_INT.h"
#include"STEPPER_INT.h"
#include"LCD_INT.h"

#include <util\delay.h>

void STEPPER_voidRotateClockWise(void)
{
	// first excitation : set blue wire low
	DIO_SetPinValue(STEPPER_PORT, COIL0 , LOW);

	//set pink , yellow , orange : HIGH
	DIO_SetPinValue(STEPPER_PORT, COIL1 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL2 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL3 , HIGH);

	_delay_ms(10);


	// second excitation : set PINK wire low
	DIO_SetPinValue(STEPPER_PORT, COIL1 , LOW);

	//set pink , yellow , orange : HIGH
	DIO_SetPinValue(STEPPER_PORT, COIL0 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL2 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL3 , HIGH);

	_delay_ms(10);


	// third excitation : set yellow wire low
	DIO_SetPinValue(STEPPER_PORT, COIL2 , LOW);

	//set pink , yellow , orange : HIGH
	DIO_SetPinValue(STEPPER_PORT, COIL0 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL1 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL3 , HIGH);

	_delay_ms(10);



	// first excitation : set orange wire low
	DIO_SetPinValue(STEPPER_PORT, COIL3 , LOW);

	//set pink , yellow , orange : HIGH
	DIO_SetPinValue(STEPPER_PORT, COIL1 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL2 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL0 , HIGH);

	_delay_ms(10);

}

void STEPPER_voidRotateAntiClockWise(void)
{

	// first excitation : set orange wire low
	DIO_SetPinValue(STEPPER_PORT, COIL3 , LOW);

	//set pink , yellow , blue : HIGH
	DIO_SetPinValue(STEPPER_PORT, COIL1 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL2 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL0 , HIGH);

	_delay_ms(10);


	// second excitation : set yellow wire low
	DIO_SetPinValue(STEPPER_PORT, COIL2 , LOW);

	//set pink , blue , orange : HIGH
	DIO_SetPinValue(STEPPER_PORT, COIL0 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL1 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL3 , HIGH);

	_delay_ms(10);


	// third excitation : set PINK wire low
	DIO_SetPinValue(STEPPER_PORT, COIL1 , LOW);

	//set blue , yellow , orange : HIGH
	DIO_SetPinValue(STEPPER_PORT, COIL0 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL2 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL3 , HIGH);

	_delay_ms(10);


	// forth excitation : set blue wire low
	DIO_SetPinValue(STEPPER_PORT, COIL0 , LOW);

	//set pink , yellow , orange : HIGH
	DIO_SetPinValue(STEPPER_PORT, COIL1 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL2 , HIGH);
	DIO_SetPinValue(STEPPER_PORT, COIL3 , HIGH);

	_delay_ms(10);

}


void STEPPER_voidSetAngleCW(u16 copy_u8Angle)
{
	u16 x = 0;
	u16 steps =(( 512 * copy_u8Angle)/ 360) ;


	while(x <= steps)
	{
		STEPPER_voidRotateClockWise();
		x = x + 1;
	}


}

void STEPPER_voidSetAngleCCW(u16 copy_u8Angle)
{
	u32 x = 0;
	u32 steps;
	u32 y = 512 * (u32)copy_u8Angle;
	steps =  y / 360 ;

	//LCD_voidWriteNumber(copy_u8Angle);
	//LCD_voidWriteNumber((u16)steps);

	while(x <= steps)
	{
		x = x + 1;
		STEPPER_voidRotateAntiClockWise();

	}
	//LCD_voidWriteNumber((u16)x);


}


