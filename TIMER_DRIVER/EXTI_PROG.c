/*
 * EXTI_PROG.c
 *
 *  Created on: Sep 28, 2019
 *      Author: ESC
 */
#include "LIBS\STD_TYPES.h"
#include "LIBS\MATH.h"
#include "AVR_EXTI_REG.h"
#include"EXTI_INT.h"


void EXIT_voidInt1Init(void)
{
	// set sense control
	set_bit(MCVCR , MCVCR_ISC01) ;
	clr_bit(MCVCR , MCVCR_ISC00) ;

	// PIE
	set_bit(GICR , GICR_INT1) ;
}

void EXIT_voidInt0Init(void)
{
	// set sense control falling edge
	set_bit(MCVCR , MCVCR_ISC01) ;
	clr_bit(MCVCR , MCVCR_ISC00) ;

	// PIE
	set_bit(GICR , GICR_INT0) ;
}

void EXIT_voidInt00Init(void)
{
	// set sense control falling edge
	set_bit(MCVCR , MCVCR_ISC01) ;
	set_bit(MCVCR , MCVCR_ISC00) ;

	// PIE
	set_bit(GICR , GICR_INT0) ;
}

void EXIT_voidInt2Init(void)
{
	// set sense control
	set_bit(MCVCR , MCVCR_ISC01) ;
	clr_bit(MCVCR , MCVCR_ISC00) ;

	// PIE
	set_bit(GICR , GICR_INT2) ;
}

void INT_voidEnableGlobal(void)
{
	// global interrupt enable
	set_bit(SREG , SREG_I) ;

}

void INT_voidDisableGlobal(void)
{
	// global interrupt enable
	clr_bit(SREG , SREG_I) ;

}



void EXTI_INT0SetCallBack(void (* INT0_ISR)(void))
{
	INT0_CallBack = INT0_ISR ;

}

/*void __vector_1(void)
{
	INT0_CallBack() ;
}*/
