/*
 * KPD_PROG.c
 *
 *  Created on: Sep 7, 2019
 *      Author: ESC
 */

#include "KPD_INT.h"
#include "DIO_INT.h"
#include "LIBS\STD_TYPES.h"
#include "LCD_INT.h"

static u8 KPD_u8ARR [4][4] =
		{{1, 2, 3, '+'},
		 {4, 5, 6, '-'},
		 {7, 8, 9, 0},
		 {'c',9,'=', '/'}
		} ;

/*static u8 KPD_u8ARR [4][4] =
		{{1, 2, 3, 4},
		 {5, 6, 7, 8},
		 {9, 10, 11, 12},
		 {13, 14, 15, 16}
		} ;*/

u8 KPD_u8GetPressedKey (void)
{
	u8 local_u8ColIDX ;
	u8 local_u8RowIDX ;
	u8 local_u8PinState ;
	u8 local_u8PreassedKey = NO_KEY ;

	// loop to go for every column in he kpd
	for(local_u8ColIDX = 0; local_u8ColIDX < 4 ; local_u8ColIDX++)
	{
		// activate current column
		DIO_SetPinValue(KPD_PORT , local_u8ColIDX , LOW);

		// loop to go for every row in the kpd
		for(local_u8RowIDX = 0; local_u8RowIDX < 4 ; local_u8RowIDX++)
		{
			//get the row pin state9
			local_u8PinState = DIO_GetPinValue(KPD_PIN , (local_u8RowIDX + 4)) ;

			if(local_u8PinState == LOW)
			{
				local_u8PreassedKey = KPD_u8ARR [local_u8RowIDX][local_u8ColIDX];

				while(local_u8PinState == LOW)
				{
					// get the row pin state
					local_u8PinState = DIO_GetPinValue(KPD_PIN , (local_u8RowIDX + 4)) ;
				}
			}
		}


		// deactivate the current column
		DIO_SetPinValue(KPD_PORT , local_u8ColIDX , HIGH);
	}

	return local_u8PreassedKey;
}
