/*
 * TIMER_INT.h
 *
 *  Created on: Oct 5, 2019
 *      Author: ESC
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

#define LED_PORT PORTC
#define LED_PIN PIN0

#define C4   1911 	/* PWM: 261.64 Hz, note freq: 261.63 Hz, error 0.01% */
#define D4   1703 	/* PWM: 293.60 Hz, note freq: 293.66 Hz, error 0.02% */
#define E4   1517 	/* PWM: 329.60 Hz, note freq: 329.63 Hz, error 0.01% */
#define F4   1432 	/* PWM: 349.16 Hz, note freq: 349.23 Hz, error 0.02% */
#define G4   1276 	/* PWM: 391.85 Hz, note freq: 392.00 Hz, error 0.04% */
#define A4   1136 	/* PWM: 440.14 Hz, note freq: 440.00 Hz, error 0.03% */
#define B4   1012 	/* PWM: 494.07 Hz, note freq: 493.88 Hz, error 0.04% */


void (* TIMER0_CallBack)(void) ;

void EXTI_Timer0SetCallBack(void (* TIMER0_ISR)(void));

void Timer0_voidINit(void) ;
void Timer0_voidClockINit(void);
void Timer0_voidINitCTC(void);

void Timer0_voidINitPWM(void);

void Timer1_voidInit(void);
void Timer1_voidInitnormal(void);

void TIMER1_ICR_voidInit(void);

void __vector_11(void) __attribute__((signal,used));
void __vector_10(void) __attribute__((signal,used));
void __vector_6(void) __attribute__((signal,used));

#endif /* TIMER_INT_H_ */
