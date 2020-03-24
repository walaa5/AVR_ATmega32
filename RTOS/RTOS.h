/*
 * RTOS.h
 *
 *  Created on: Nov 23, 2019
 *      Author: ESC
 */

#ifndef RTOS_H_
#define RTOS_H_

#define NO_OF_TASKS 3

typedef struct
{
	u16 periodicity ;
	void (*fptr)(void);
} Task ;

void RTOS_voidCreateTask(u8 priority , u16 task_periodicity , void (*task_ptr)(void));
void RTOS_voidScheduler(void) ;

#endif /* RTOS_H_ */
