/*
 * RTOS.c
 *
 *  Created on: Nov 23, 2019
 *      Author: ESC
 */

#include"LIBS/STD_TYPES.h"
#include"RTOS.h"

Task systask[NO_OF_TASKS] ;

void RTOS_voidCreateTask(u8 priority , u16 task_periodicity , void (*task_ptr)(void))
{
	systask[priority].periodicity = task_periodicity ;
	systask[priority].fptr = task_ptr ;
}

void RTOS_voidScheduler(void)
{
	u8 taskCounter;
	u16 static counter ;
	counter++ ;

	for(taskCounter = 0; taskCounter<NO_OF_TASKS ; taskCounter++)
	{
		if(counter % (systask[taskCounter].periodicity) == 0)
		{
			systask[taskCounter].fptr();
		}
	}
}

