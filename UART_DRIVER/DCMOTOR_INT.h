/*
 * DCMOTOR_INT.h
 *
 *  Created on: Sep 13, 2019
 *      Author: ESC
 */

#ifndef DCMOTOR_INT_H_
#define DCMOTOR_INT_H_

#define MOTOR_PORT PORTA
#define MOTOR_PIN0 PIN0
#define MOTOR_PIN1 PIN1

void DCMOTOR_voidRotateClockWise(void) ;
void DCMOTOR_voidRotateAntiClockWise(void);
void DCMOTOR_voidStop(void);

#endif /* DCMOTOR_INT_H_ */
