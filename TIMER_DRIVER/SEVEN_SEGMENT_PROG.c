
#include"LIBS\STD_TYPES.h"
#include"SEVEN_SEGMENT_INT.h"
#include"DIO_INT.h"

void SEVENSEGMENT_voidSetNumber(u8 copy_u8Number , u8 copy_u8SevenSegPort)
{
	switch(copy_u8Number)
	{
		case 0:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b00111111);

		break;

		case 1:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b00000110);

		break;

		case 2:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b01011011);

		break;

		case 3:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b01001111);

		break;

		case 4:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b01100110);

		break;

		case 5:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b01101101);

		break;

		case 6:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b01111101);

		break;

		case 7:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b00000111);

		break;

		case 8:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b01111111);

		break;

		case 9:

			DIO_SetPortValue(copy_u8SevenSegPort , 0b01101111);

		break;
	}
}
