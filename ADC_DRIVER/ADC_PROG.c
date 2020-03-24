/*
 * ADC_PROG.c
 *
 *  Created on: Oct 3, 2019
 *      Author: ESC
 */

#include "LIBS\STD_TYPES.h"
#include"LIBS\MATH.h"

#include "ADC_INT.h"


void ADC_voidInit(void)
{
	// set referEnce : AVCC
	set_bit(ADMUX , ADMUX_REFS0);
	clr_bit(ADMUX , ADMUX_REFS1);

	// active left adjust mode
	set_bit(ADMUX , ADMUX_ADLAR);

	//Enable ADC
	set_bit(ADCSRA , ADCSRA_ADEN);

	// Set Pre scaler to divide by 128
	set_bit(ADCSRA , ADCSRA_ADPS0);
	set_bit(ADCSRA , ADCSRA_ADPS1);
	set_bit(ADCSRA , ADCSRA_ADPS2);
}

u8 ADC_u8ChannelReading(u8 channel)
{
	// set channel
	ADMUX &= 0b11100000 ;
	ADMUX |= channel ;

	// start conversion
	set_bit(ADCSRA , ADCSRA_ADSC);

	// polling on ADIF flag
	while(read_bit(ADCSRA , ADCSRA_ADIF)==0);

	//clear ADIF flag
	set_bit(ADCSRA , ADCSRA_ADIF);

	//return data

	return ADCH ;

}

u16 ADC_u16GetChannelReading(u16 channel)
{

}
