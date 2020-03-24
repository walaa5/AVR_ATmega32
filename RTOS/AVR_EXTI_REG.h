/*
 * AVR_EXTI_REG.h
 *
 *  Created on: Sep 28, 2019
 *      Author: ESC
 */

#ifndef AVR_EXTI_REG_H_
#define AVR_EXTI_REG_H_

#include"LIBS\STD_TYPES.h"

// interrupt sense control 1
#define MCVCR *((volatile u8 *)0x55)
#define MCVCR_ISC00 0
#define MCVCR_ISC01 1

// interrupt sense control 2
#define MCVCSR *((volatile u8 *)0x54)

// global interrupt
#define SREG *((volatile u8 *)0x5f)
#define SREG_I 7

//PIE for external DIO interrupt
#define GICR *((volatile u8 *)0x5B)
#define GICR_INT1 7
#define GICR_INT0 6
#define GICR_INT2 5

#endif /* AVR_EXTI_REG_H_ */
