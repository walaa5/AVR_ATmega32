
#include"LIBS\STD_TYPES.h"
#include"UART_INT.h"
#include"DIO_INT.h"
#include"util\delay.h"
#include"LCD_INT.h"
#include"NOTES.h"
#include"TIMER_INT.h"
#include"AVR_TIMER_REG.h"


void PlayMusic( const int* pMusicNotes /** Pointer to table containing music data */,
				uint8_t tempo /** paying tempo from 0 to 100. Higher value = slower playback*/ );

u8 id_digit = 0;
u8 pass_digit = 0;
u16 id = 0;
u16 pass = 0;

u8 state = 0 ;
u16 id_copy ;
u16 pass_copy ;

u8 * pass_arr(u16 pass);
u8 * id_arr(u16 id);
void system(void);

void main()
 {
	// LCD INATILIZE AND PORTS

	DIO_SetPortDirection(DDRA , 0xff);
	DIO_SetPortDirection(DDRB , 0xff);

	LCD_voidInit();
	LCD_voidSendCommand(0x0c);

	// initialize UART
	USART_voidInit();

	// TIMER

	DIO_SetPinDirection(DDRD , PIN5 , OUTPUT);
	DIO_SetPinDirection(DDRD , PIN7 , OUTPUT);
	DIO_SetPinDirection(DDRD , PIN6 , OUTPUT);

	system() ;

}

// fun to

void system(void)
{

	u8 count = 1 ;
	u8  *arr_id;
	u8  *arr_pass;

	// print welcome on LCD for 3 seconds

	LCD_voidGoToXY(0 , 4) ;
	LCD_Display("WELCOME") ;
	USART_voidSendString("Welcome TO Your system \r");
	_delay_ms(3 * 1000) ;

	// enter id

	LCD_voidSendCommand(0x01) ;
	LCD_voidGoToXY(0 , 1) ;
	LCD_Display("Enter ID:");
	USART_voidSendString("please enter your ID \r");

	u8 R_num ;

	while(1)
	{
		R_num = no_data;
		R_num = USART_u8Receive();
		//USART_voidTransmit(R_num);

		if(state == 0)
		{

			if(R_num != no_data && (R_num == '0' || R_num == '1' || R_num == '2' || R_num == '3' || R_num == '4' || R_num == '5' || R_num == '6' || R_num == '7' || R_num == '8' || R_num == '9'))
			{
				id = 10 * id + (u16)(R_num - '0') ;
				LCD_voidWriteData(R_num);
				USART_voidTransmit(R_num);
			}

			else if(R_num != no_data && R_num == '=')
			{
				 state = 1 ;
				 arr_id = id_arr(id);
				 id_copy = id ;
				 while(id_copy != 0)
				 {
					id_copy /= 10 ;
					id_digit += 1 ;
				 }

				if(id_digit == 4)
				{

					_delay_ms(1000);
					LCD_voidSendCommand(0x01);
					LCD_voidGoToXY(0, 1) ;
					LCD_Display("Password:");
					USART_voidSendString("\rThanks, Now Enter Your Password \r");
					//SEVENSEGMENT_voidSetNumber(0 , PORTB);
				}

				else
				{
					LCD_voidGoToXY(1, 2) ;
					LCD_Display("ID Invalid!\r");
					USART_voidSendString("\ryour ID is Invalid Sorry we have to close the system\r");
					_delay_ms(3* 1000);
					LCD_voidSendCommand(0x01);

					break ;
				}

			 }
		}

		// GET password
		else if(state == 1)
		{
			if(R_num != no_data && (R_num == '0' || R_num == '1' || R_num == '2' || R_num == '3' || R_num == '4' || R_num == '5' || R_num == '6' || R_num == '7' || R_num == '8' || R_num == '9'))
			{
				pass = 10 * pass + (u16)(R_num - '0') ;
				LCD_voidWriteData(R_num);
				USART_voidTransmit(R_num);
			}
			else if(R_num != no_data && R_num == '=')
			{

				arr_pass = pass_arr(pass) ;

				 pass_copy = pass ;
				 while(pass_copy != 0)
				 {
					pass_copy /= 10 ;
					pass_digit += 1 ;
				 }

				 if(pass_digit == 4 && arr_id[0] == arr_pass[3] && arr_id[1] == arr_pass[2] && arr_id[2] == arr_pass[1] && arr_id[3] == arr_pass[0])
				 {
					 LCD_voidSendCommand(0x01);
					 LCD_voidGoToXY(0, 1) ;
					 LCD_Display("System Unlock");
					 USART_voidSendString("\rHello Walaa how can I help you? please choose.\r");
					 USART_voidSendString("0 - close the system \r");
					 USART_voidSendString("1 - turn led on \r");
					 USART_voidSendString("2 - turn led off \r");
					 USART_voidSendString("3 - play music \r");
					 USART_voidSendString("4 - turn motor on \r");
					 USART_voidSendString("5 - turn motor off \r");


					 _delay_ms(3 *1000) ;

					 state = 2 ;
				 }

				 else
				 {
					 if(count <= 3)
					 {
						 LCD_voidSendCommand(0x01);
						 LCD_voidGoToXY(0 , 1) ;
						 LCD_Display("\rTry again:\r") ;


						 _delay_ms(1000);

						 LCD_voidGoToXY(1, 1) ;
						 LCD_Display("Password:") ;
						 USART_voidSendString("\ryou entered A wrong password pleaase Try Again\r");
						 count += 1;
						 state = 1;
						 pass = 0;
						 pass_digit = 0;
						 continue ;
					 }
					 else
					 {
						 LCD_voidSendCommand(0x01);
						 LCD_voidGoToXY(0, 3) ;
						 LCD_Display("you have entered wrong password 3 times , Bye Bye") ;
						 USART_voidSendString("\ryou have entered wrong password 3 times , Bye Bye\r");
						 _delay_ms(3 *1000) ;
						 LCD_voidSendCommand(0x01);
						 break;
					 }
				 }
			}
		}

		// function that control motor if password is write

		else if(state == 2)
		{

			 if(R_num != no_data && (R_num == '0' ||R_num == '1' || R_num == '2' || R_num == '3' || R_num == '4' || R_num == '5'))
			 {
				 if(R_num == '1')
				 {
					 LCD_voidSendCommand(0x01);
					 LCD_voidGoToXY(0, 1) ;
					 LCD_Display("LED_ON") ;
					 USART_voidSendString("Led On\r");
					 DIO_SetPinValue(PORTD ,PIN7, HIGH);
				 }
				 else if(R_num == '2')
				 {
						 LCD_voidSendCommand(0x01);
						 LCD_voidGoToXY(0, 1) ;
						 LCD_Display("LED_OFF") ;
						 USART_voidSendString("Led Off\r");
						 DIO_SetPinValue(PORTD ,PIN7, LOW);
				 }

				else if (R_num == '3')
				{
					Timer1_voidInit();
					 LCD_voidSendCommand(0x01);
					 LCD_voidGoToXY(0, 1) ;
					 LCD_Display("Play Music");
					 USART_voidSendString("Play Music\r");

				    PlayMusic( octave, 40 );
					_delay_ms(1000);

					PlayMusic( furelise, 20 );
					_delay_ms(1000);

					PlayMusic( starwars, 17 );
					_delay_ms(1000);


				}
				else if(R_num == '4')
				{
					DIO_SetPinValue(PORTD , PIN6, HIGH);
					 LCD_voidSendCommand(0x01);
					 LCD_voidGoToXY(0, 1) ;
					 LCD_Display("Motor On");
					 USART_voidSendString("Motor On\r");
					_delay_ms(10000);
				}
				else if(R_num == '5')
				{
					DIO_SetPinValue(PORTD , PIN6, LOW);
					 LCD_voidSendCommand(0x01);
					 LCD_voidGoToXY(0, 1) ;
					 LCD_Display("Motor Off");
					 USART_voidSendString("Motor Off\r");
					_delay_ms(10000);
				}

				else if(R_num == '0')
				{
					 USART_voidSendString("good bye, walaa");
					 _delay_ms(3000);
					 LCD_voidSendCommand(0x01);
					 break ;
				}


			 }

		}

	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// function will convert id number into array of each digit

u8 * id_arr(u16 ID)
{
	u8 i;
	static u8 arr[4] ;

	for(i = 5 ; i>1 ; i--)
	{
		arr[i-2] = (u8)(ID % 10) ;
		ID = ID /10 ;
	}
	return arr ;
}

// function will convert password number into array of each digit number

u8 * pass_arr(u16 password)
{
	u8 i;
	static u8 arr1[4] ;

	for(i = 5 ; i>1 ; i--)
	{
		arr1[i-2] = (u8)(password % 10) ;
		password = password /10 ;
	}
	return arr1 ;
}

///////////////////////////////////////////////////////////////////////

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
