/*
 * main.c
 *
 *  Created on: Oct 5, 2019
 *      Author: ESC
 */
#include"TIMER_INT.h"
#include"DIO_INT.h"
#include"AVR_TIMER_REG.h"
#include"EXTI_INT.h"
#include "DIO_REG.h"
#include "LCD_INT.h"
#include"LIBS\MATH.h"
#include "EXTI_INT.h"
#include "SEVEN_SEGMENT_INT.h"
#include"util\delay.h"

void CTC(void);
//void ISR(void);
void ledBlink_CTCMode(void);
void ledBlink_normalMode(void);
void __vector_11(void);
void __vector_6(void);

u16 periodTime = 0;
u16 offTime = 0;

u16 ICR = 0 ;
u16 ICR_periodTime = 0;
u16 ICR_offTime = 0;
/*void main()
{

	/* project of generate and read PWM signal */

	/*	Timer1_voidInitnormal();
	EXIT_voidInt0Init();
	Timer0_voidINitPWM();
	INT_voidEnableGlobal();

	// OCR0
	DIO_SetPinDirection(DDRB , PIN3 , OUTPUT);

	//set int 0 as input
	DIO_SetPinDirection(DDRD , PIN2 , INPUT);

	DIO_SetPortDirection(DDRC , 0xFF);
	//DIO_SetPortDirection(DDRD , 0xFF);
	DIO_SetPinDirection(DDRA , PIN5 , OUTPUT);
	DIO_SetPinDirection(DDRA , PIN6 , OUTPUT);
	DIO_SetPinDirection(DDRA, PIN7 , OUTPUT);

	// LCDinit
	LCD_voidInit();
	LCD_voidSendCommand(0x0c);*/

	//LCD_voidGoToXY(0 , 1);
	//LCD_Display("CLOC");
	//EXTI_INT0SetCallBack(ISR);

	////////////////////////////////////////////////
	//DIO_SetPortDirection(DDRC , 0XFF);

	//DIO_SetPortDirection(DDRD , 0xFF);
	//DIO_SetPortDirection(DDRC , 0xff);

	//DIO_SetPinDirection(DDRD , PIN5 , OUTPUT);

	//DIO_SetPinDirection(DDRB , PIN3 , OUTPUT);

	/*--------- project of blink led with normal mode T0 pin ---------------*/
	/*LCD_voidInit();
	LCD_voidSendCommand(0x0c);
	TCNT0 = 0 ;
	LCD_voidGoToXY(0 , 1);
	 //LCD_voidWriteNumber((u16)TCNT0) ;
	 LCD_Display("CLOCK = ");
	_delay_ms(10000) ;*/

	/*--------- project of two 7 segment --------------*/

	/*	Timer0_voidINit() ;
	INT_voidEnableGlobal();

	DIO_SetPortDirection(DDRA , 0XFF);
	DIO_SetPinDirection (DDRB , PIN7 , OUTPUT);
	DIO_SetPinDirection (DDRB , PIN6 , OUTPUT);*/

	//EXTI_Timer0SetCallBack(sevenSegment2_normalMode);
	/* --------- PROJECT OF ICR PIN ----------------*/

	/*TIMER1_ICR_voidInit();
	Timer1_voidInitnormal();
	Timer0_voidINitPWM();
	INT_voidEnableGlobal();

	DIO_SetPinDirection(DDRB, PIN3 , OUTPUT);
	DIO_SetPinDirection(DDRD, PIN6 , INPUT);

	DIO_SetPortDirection(DDRC , 0xFF);
	DIO_SetPinDirection(DDRA , PIN5 , OUTPUT);
	DIO_SetPinDirection(DDRA , PIN6 , OUTPUT);
	DIO_SetPinDirection(DDRA, PIN7 , OUTPUT);



	LCD_voidInit();
	LCD_voidSendCommand(0x0c);
	LCD_voidGoToXY(0 , 1);
	//LCD_Display("CLOCK");

	while(1)
	{
		//LCD_voidGoToXY(0 , 9);
		//LCD_voidWriteNumber((u16)TCNT0) ;

		//_delay_ms(1000) ;

		//DIO_SetPinValue(PORTA , PIN0 ,HIGH);

		// SERVO CODE
		//DIO_SetPinValue(PORTB , PIN0 , HIGH);

		//for(ICR1L = 3000 ; TCR1 <6000 ;)

		while((ICR_periodTime ==0) && (ICR_offTime == 0));
		INT_voidDisableGlobal();

		LCD_voidGoToXY(0 , 1);
		LCD_voidWriteNumber(ICR_periodTime) ;
		LCD_voidGoToXY(1 , 1);
		LCD_voidWriteNumber(ICR_offTime) ;


	}

}*/

void ledBlink_normalMode(void)
{
	static volatile u8 counter = 0;
	counter++ ;
	static u8 flag = 0;

	if(counter == 31)
	{
		TCNT0 = 123 ;
		// BLINK
		if(flag == 0)
		{
			DIO_SetPinValue(LED_PORT,LED_PIN ,HIGH);
			flag = 1;
		}

		else if(flag == 1)
		{
			DIO_SetPinValue(LED_PORT,LED_PIN ,LOW);
			flag = 0;
		}

		counter = 0;
	}
}

void CTC(void)
{
	static volatile u8 counter = 0;
	counter ++ ;
	if(counter == 4)
	{
		DIO_SetPinValue(PORTA , PIN0 ,LOW);
	}

	else if(counter == 80)
	{
		DIO_SetPinValue(PORTA , PIN0 ,HIGH);
		counter = 0 ;
	}
}

void ledBlink_CTCMode(void)
{
	static volatile u8 counter1 = 0;
	counter1++ ;
	static u8 flag1 = 0;

	if(counter1 == 4000)
	{
		// BLINK
		if(flag1 == 0)
		{
			DIO_SetPinValue(LED_PORT,LED_PIN ,HIGH);
			flag1 = 1;
		}

		else if(flag1 == 1)
		{
			DIO_SetPinValue(LED_PORT,LED_PIN ,LOW);
			flag1 = 0;
		}

		counter1 = 0;
	}
}

void __vector_11(void)
{
	static volatile u8 counter_7 = 0;
	counter_7++ ;
	static u8 flag_71 = 0;
	static u8 flag_72 = 0;

	static u8 flag = 0;


	if(flag == 0)
	{
		DIO_SetPinValue(PORTB,PIN6 ,HIGH);
		DIO_SetPinValue(PORTB,PIN7 ,LOW);

		SEVENSEGMENT_voidSetNumber(flag_71 , PORTA);
		flag = 1;
	}

	else if(flag == 1)
	{
		DIO_SetPinValue(PORTB,PIN7 ,HIGH);
		DIO_SetPinValue(PORTB,PIN6 ,LOW);

		SEVENSEGMENT_voidSetNumber(flag_72 , PORTA);
		flag = 0;
	}

	if(counter_7 == 31)
	{
		TCNT0 = 123 ;
		//
		flag_71 += 1;

		if(flag_71 == 10 )
		{
			flag_72 += 1;
			flag_71 = 0;
		}
		if(flag_72 == 10 )
		{
			flag_72 =0 ;
		}

		counter_7 = 0;
	}
}

void __vector_1(void)
{
	static u8 counter = 0;
	u8 Temp ;
	counter++;
	if(counter == 2)
	{
		TCNT1L = 0;
	}

	else if(counter == 3)
	{
		periodTime = TCNT1L ;
		EXIT_voidInt00Init();
	}

	else if (counter ==4)
	{
		offTime = TCNT1L - periodTime ;
	}
}

void __vector_6(void)
{
	static u8 counter4 = 0 ;
	counter4 ++;
	u16 Temp;
	if(counter4 == 5)
	{
		ICR = ICR1L ;
	}
	else if(counter4 == 6)
	{
		Temp=ICR1L;
		ICR_periodTime = Temp - ICR ;  //PERIOD TIME
		set_bit(TCCR1B  , TCCR1B_ICES1 );
	}

	else if(counter4 == 7)
	{
		ICR_offTime = ICR1L  ;

	}

}
