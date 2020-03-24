/*
 * AVR_TIMER_REG.h
 *
 *  Created on: Oct 5, 2019
 *      Author: ESC
 */

#ifndef AVR_TIMER_REG_H_
#define AVR_TIMER_REG_H_

#include"LIBS\STD_TYPES.h"

#define TCCR0 *((volatile u8 *) 0x53)
#define TCNT0 *((volatile u8 *) 0x52)
#define OCR0 *((volatile u8 *) 0x5C)
#define TIMSK *((volatile u8 *) 0x59)
#define TIFR *((volatile u8 *) 0x58)
//#define TCR1L *((volatile u16 *) 0x46)


// TIMER 1 REG
#define TCCR1A *((volatile u8 *) 0x4F)
#define TCCR1B *((volatile u8 *) 0x4E)

#define TCNT1H *((volatile u8 *) 0x4D)
#define TCNT1L *((volatile u16 *) 0x4C)

#define OCR1AL *((volatile u16 *) 0x4A)
#define OCR1BL *((volatile u16*) 0x48)

#define ICR1L *((volatile u16*) 0x46)

////
#define TCCR0_WGM00 6
#define TCCR0_WGM01 3

#define TCCR0_COM00 4
#define TCCR0_COM01 5

#define TCCR0_CS00 0
#define TCCR0_CS01 1
#define TCCR0_CS02 2

#define TIMSK_TOIE0 0
#define TIMSK_OCIE0 1

#define TIFR_TOVO 0
#define TIFR_OCF0 1

//TIMER 1 REG BITS
#define TCCR1A_COM1A1 7
#define TCCR1A_COM1A0 6

#define TCCR1A_WGM11 1
#define TCCR1A_WGM10 0

#define TCCR1B_WGM12 3
#define TCCR1B_WGM13 4

#define TCCR1B_CS10 0
#define TCCR1B_CS11 1
#define TCCR1B_CS12 2

#define TIMSK_TOIE1 2

#define TCCR1B_ICNC1 7
#define TCCR1B_ICES1 6

#define TIMSK_TICIE1 5

#endif /* AVR_TIMER_REG_H_ */
