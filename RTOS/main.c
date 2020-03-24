/*
 * main.c
 *
 *  Created on: Nov 23, 2019
 *      Author: ESC
 */

#include"DIO_INT.h"
#include"RTOS.h"
#include"TIMER_INT.h"
#include"EXTI_INT.h"

void LED1(void);
void LED2(void);
void LED3(void);

void main()
{
	DIO_SetPortDirection(DDRC , 0XFF) ;
	Timer0_voidINitCTC();
	INT_voidEnableGlobal();

	RTOS_voidCreateTask(0 , 1,LED1);
	RTOS_voidCreateTask(1 , 2,LED2);
	RTOS_voidCreateTask(2 , 3,LED3);

	while(1)
	{};

}

void LED1(void)
{
	DIO_SetPinValue(PORTC , PIN0 , HIGH);
}

void LED2(void)
{
	DIO_SetPinValue(PORTC , PIN1 , HIGH);
}

void LED3(void)
{
	DIO_SetPinValue(PORTC , PIN2 , HIGH);
}

void __vector_10(void)
{
	u16 static counter = 0;
	counter++;
	if(counter == 1000)
	{
		RTOS_voidScheduler();
		counter = 0;
	}
}
