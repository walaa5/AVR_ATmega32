/*
 * ADC_INT.h
 *
 *  Created on: Oct 2, 2019
 *      Author: ESC
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#include"LIBS\STD_TYPES.h"

#define ADMUX *((volatile u8 *)0x27)
#define ADCSRA *((volatile u8 *)0x26)
#define ADCH *((volatile u8 *)0x25)
#define ADCL *((volatile u8 *)0x24)

#define ADMUX_REFS1 7
#define ADMUX_REFS0 6
#define ADMUX_ADLAR 5

#define ADCSRA_ADEN 7
#define ADCSRA_ADSC 6
#define ADCSRA_ADIF 4

#define ADCSRA_ADPS0 0
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS2 2

u8 ADC_u8ChannelReading(u8 channel) ;
void ADC_voidInit(void);

#endif /* ADC_INT_H_ */
