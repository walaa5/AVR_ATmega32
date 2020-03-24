/*
 * LED.c
 *
 *  Created on: Nov 23, 2019
 *      Author: ESC
 */

#include"LIBS/MATH.h"
#include"FREE_RTOS/FreeRTOS.h"
#include"FREE_RTOS/task.h"
#include"DIO_INT.h"
#include"DIO_REG.h"
#include"LCD_INT.h"

void LED1(void *PV);
void LED2(void *PV);

void lcd1(void *PV);
void lcd2(void *PV);

void main()
{
	LCD_voidInit();

	DIO_SetPortDirection(DDRA , 0XFF);
	DIO_SetPortDirection(DDRB , 0XFF);

	LCD_voidSendCommand(0X01);

	LCD_Display("Task 2");
	xTaskCreate(lcd1 , NULL ,configMINIMAL_STACK_SIZE , NULL ,1 , NULL);
	xTaskCreate(lcd2 , NULL ,configMINIMAL_STACK_SIZE , NULL ,1 , NULL);


	vTaskStartScheduler();
	while(1)
	{};
}

void LED1(void *PV)
{
	DIO_SetPinDirection(DDRC , PIN0 , OUTPUT);
	while(1)
	{
		toggle_bit(PORTC_REG , PIN0);
		vTaskDelay(200);
	}


}

void LED2(void *PV)
{
	DIO_SetPinDirection(DDRC , PIN1 , OUTPUT);
	while(1)
	{
		toggle_bit(PORTC_REG , PIN1);
		vTaskDelay(1000);
	}

}

void lcd1(void *PV)
{
	/*LCD_voidInit();
	LCD_voidSendCommand(0x0c);
	DIO_SetPortDirection(DDRA , 0XFF);
	DIO_SetPortDirection(DDRB , 0XFF);*/


	while(1)
	{
		LCD_Display("Task 1");

		vTaskDelay(500);
	}

}

void lcd2(void *PV)
{
	/*LCD_voidInit();
	LCD_voidSendCommand(0x0c);


	DIO_SetPortDirection(DDRA , 0XFF);
	DIO_SetPortDirection(DDRB , 0XFF);*/


	while(1)
	{
		LCD_Display("Task 2");

		vTaskDelay(500);
	}

}



