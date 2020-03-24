/*
 * EXTI_PROG.h
 *
 *  Created on: Sep 28, 2019
 *      Author: ESC
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

void (* INT0_CallBack)(void) ;

void EXIT_voidInt1Init(void) ;
void EXIT_voidInt0Init(void);
void EXIT_voidInt2Init(void);

void EXIT_voidInt00Init(void);

void INT_voidEnableGlobal(void);
void INT_voidDisableGlobal(void);
void __vector_1(void);
void EXTI_INT0SetCallBack(void (* INT0_ISR)(void));


void __vector_1(void) __attribute__((signal , used)) ;
void __vector_1(void) __attribute__((signal , used)) ;
void __vector_1(void) __attribute__((signal , used)) ;
void __vector_11(void) __attribute__((signal , used)) ;


#endif /* EXTI_INT_H_ */
