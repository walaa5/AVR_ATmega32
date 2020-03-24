/*
 * TIMER1_PROG.C
 *
 *  Created on: Oct 18, 2019
 *      Author: ESC
 */

#include"LIBS\MATH.h"
#include"AVR_TIMER_REG.h"
#include"TIMER_INT.h"
#include"DIO_INT.h"


void Timer1_voidInit(void)
{
	// set on top clear on compare
	set_bit(TCCR1A , TCCR1A_COM1A1);
	clr_bit(TCCR1A , TCCR1A_COM1A0);

	// set wave form to 14: fast PWM
	set_bit(TCCR1A , TCCR1A_WGM11);
	clr_bit(TCCR1A , TCCR1A_WGM10);

	set_bit(TCCR1B  , TCCR1B_WGM12);
	set_bit(TCCR1B  , TCCR1B_WGM13);

	// preload  period time = 20ms
	ICR1L = 1000;

	//ON TIME = 750US
	OCR1AL = 750;

	// PRESCALER divided by 8
	clr_bit(TCCR1B  , TCCR1B_CS10);
	set_bit(TCCR1B  , TCCR1B_CS11);
	clr_bit(TCCR1B  , TCCR1B_CS12);
}

void Timer1_voidInitnormal(void)
{
	// set NORMAL MODE
	clr_bit(TCCR1A , TCCR1A_WGM11);
	clr_bit(TCCR1A , TCCR1A_WGM10);
	clr_bit(TCCR1B , TCCR1B_WGM12);
	clr_bit(TCCR1B , TCCR1B_WGM13);

	//preload value setting
	TCNT1L = 0;

	set_bit(TIMSK , TIMSK_TOIE1);

	// PRESCALER divided by 8
	clr_bit(TCCR1B  , TCCR1B_CS10);
	clr_bit(TCCR1B  , TCCR1B_CS11);
	set_bit(TCCR1B  , TCCR1B_CS12);
}

void TIMER1_ICR_voidInit(void)
{
	// SET EDGE SELECTION ON falling edge
	clr_bit(TCCR1B  , TCCR1B_ICES1);

	// enable ICU interrupt
	set_bit(TIMSK  , TIMSK_TICIE1);
}
