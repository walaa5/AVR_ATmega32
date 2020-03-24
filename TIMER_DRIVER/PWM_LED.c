/*
 * PWM_LED.c
 *
 *  Created on: Oct 25, 2019
 *      Author: ESC
 */

#include"TIMER_INT.h"
#include"DIO_INT.h"
#include"AVR_TIMER_REG.h"
#include"EXTI_INT.h"
#include "DIO_REG.h"
#include "util\delay.h"
#include"NOTES.h"

void PlayMusic( const int* pMusicNotes /** Pointer to table containing music data */,
				uint8_t tempo /** paying tempo from 0 to 100. Higher value = slower playback*/ );
void main()
{
	//u16 i;
	Timer1_voidInit();
	DIO_SetPinDirection(DDRD , PIN5 , OUTPUT);
	//DIO_SetPinValue(PORTB , PIN1 , HIGH);
	u8 i;

	while(1)
	{
		/*for(i = 0 ; i<20 ;i ++)
		{
			 ICR1L =6000  ;
			 OCR1AL = 2000;
			_delay_ms(5*1000);

			 ICR1L =3000  ;
			 OCR1AL = 2000;
			_delay_ms(5 *3000);

			 ICR1L =3200  ;
			 OCR1AL = 2200;
			_delay_ms(5 * 1000);

			 ICR1L =400  ;
			 OCR1AL = 2000;
			_delay_ms(1000);

			 ICR1L =1700 ;
			 OCR1AL = 1000;
			_delay_ms(1000);
		}*/

		    PlayMusic( octave, 40 );
			_delay_ms(1000);

			PlayMusic( furelise, 20 );
			_delay_ms(1000);

			PlayMusic( starwars, 17 );
			_delay_ms(1000);

			for(i = 0 ; i< 2; i++)
		   {PlayMusic( happy, 20 );
			_delay_ms(1000);
		   }


	}

}

void PlayMusic( const int* pMusicNotes /** Pointer to table containing music data */,
				uint8_t tempo /** paying tempo from 0 to 100. Higher value = slower playback*/ )
{
	int duration;
	int note;
	int i;
	uint16_t delay = tempo * 1000;

	while( *pMusicNotes )
	{
		note = *pMusicNotes;
		pMusicNotes++;

		duration = *pMusicNotes;
		pMusicNotes++;

		if( p == note )
		{
			//pause, do not generate any sound
			OCR1AL = 0;
		}
		else
		{
			//not a pause, generate tone
			OCR1AL = 100 ;

			//set frequency
			ICR1L = note;
		}

		//wait duration
		for(i=0;i<32/duration;i++)
		{
			_delay_loop_2( delay );
			_delay_loop_2( delay );
			_delay_loop_2( delay );
			_delay_loop_2( delay );
			_delay_loop_2( delay );

		}

	}

	//turn off any sound
	OCR1AL = 0;
}

