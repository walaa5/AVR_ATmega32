/*
 * TIMER_PROG.c
 *
 *  Created on: Oct 5, 2019
 *      Author: ESC
 */

#include"LIBS\MATH.h"
#include"AVR_TIMER_REG.h"
#include"TIMER_INT.h"
#include"DIO_INT.h"

/*-------- initialization of timer 0 over flow mode --------------*/

void Timer0_voidINit(void)
{
	// set normal mode
	clr_bit(TCCR0 , TCCR0_WGM00);
	clr_bit(TCCR0 , TCCR0_WGM01);

	//preload value setting
	TCNT0 = 123 ;

	// over flow interrupt enable
	set_bit(TIMSK , TIMSK_TOIE0);

	// set preScaler
	set_bit(TCCR0 , TCCR0_CS00);
	clr_bit(TCCR0 , TCCR0_CS01);
	set_bit(TCCR0 , TCCR0_CS02);
}

/*-------------- initialization of timer 0 external clock source on T0 -----------------*/
void Timer0_voidClockINit(void)
{
	// set normal mode
	clr_bit(TCCR0 , TCCR0_WGM00);
	clr_bit(TCCR0 , TCCR0_WGM01);

	//preload value setting
	TCNT0 = 0 ;

	// over flow interrupt enable
	set_bit(TIMSK , TIMSK_TOIE0);

	// set preScaler
	clr_bit(TCCR0 , TCCR0_CS00);
	set_bit(TCCR0 , TCCR0_CS01);
	set_bit(TCCR0 , TCCR0_CS02);
}

/*----------------- initialization of timer 0 CTC mode toggle pin oc0 ------------- */
void Timer0_voidINitCTC(void)
{
	// set normal mode
	clr_bit(TCCR0 , TCCR0_WGM00);
	set_bit(TCCR0 , TCCR0_WGM01);

	//preload value setting
	OCR0 = 125 ;

	// com0 fast mode
	clr_bit(TCCR0 , TCCR0_COM00);
	set_bit(TCCR0 , TCCR0_COM01);

	// over flow interrupt enable
	set_bit(TIMSK , TIMSK_OCIE0);

	// set preScaler
	set_bit(TCCR0 , TCCR0_CS00);
	set_bit(TCCR0 , TCCR0_CS01);
	clr_bit(TCCR0 , TCCR0_CS02);
}

/////////////////////////////////////////////


void Timer0_voidINitPWM(void)
{
	// set fast PWM mode
	set_bit(TCCR0 , TCCR0_WGM00);
	set_bit(TCCR0 , TCCR0_WGM01);

	//preload value setting
	//TCNT0 = 0 ;
	OCR0 = 32 ;

	// com0 fast mode
	clr_bit(TCCR0 , TCCR0_COM00);
	set_bit(TCCR0 , TCCR0_COM01);

	// over flow interrupt enable

	// set preScaler
	clr_bit(TCCR0 , TCCR0_CS00);
	set_bit(TCCR0 , TCCR0_CS01);
	clr_bit(TCCR0 , TCCR0_CS02);
}



void EXTI_Timer0SetCallBack(void (* TIMER0_ISR)(void))
{
	TIMER0_CallBack = TIMER0_ISR ;

}

/*void __vector_10(void)
{
	TIMER0_CallBack() ;
}*/
