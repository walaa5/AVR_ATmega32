/*
 * main.c
 *
 *  Created on: Sep 7, 2019
 *      Author: ESC
 */

#include "LIBS\STD_TYPES.h"
#include "KPD_INT.h"
#include "LCD_INT.h"
#include <util\delay.h>

void LCD_clearData();
void calculator(u8 key);
void allCalculator(u8 key);

u16 num1 = 0;
u16 num2 = 0 ;
u8 operator = ' ';
u8 first_num =1;
u16 result ;
u16 after_sign = 0 ;
//u8 key = 0;

int main()
{
	DIO_SetPortDirection(DDRA , 0xff);
	DIO_SetPortDirection(DDRC , 0xff);

	LCD_voidInit();
	LCD_voidSendCommand(0x0c);


	DIO_SetPortDirection(DDRD , 0X0F) ;
	DIO_SetPortValue(KPD_PORT , 0XFF) ;

	DIO_SetPinDirection(DDRA , PIN7 , OUTPUT) ;

/* ----------- light a led on/off using keypad --------------*/
	/*while(1)
	{
		key = KPD_u8GetPressedKey();

		//LCD_voidSendCommand(0x01) ;
		//_delay_ms(30000) ;


		while(key == 0)
		{
			key = KPD_u8GetPressedKey();

		}

		if(key == 1)
		{
			DIO_SetPinValue(PORTA , PIN7 , HIGH) ;
		}
		else if(key == 2)
		{
			DIO_SetPinValue(PORTA , PIN7 , LOW) ;
		}



	}*/

/*----------calculator program ----------------------*/

	/*while(1)
	{
		key = KPD_u8GetPressedKey();
		allCalculator(key) ;
	}*/

/*---------------- count from 1 to 16 using kpd and lcd ----------------*/

	u8 key;
	while(1)
	{
		key = 0;
		key = KPD_u8GetPressedKey();

		if(key == 0)
		{
			key = KPD_u8GetPressedKey();
		}
		else if(key!=0)
		{
			//LCD_voidWriteData('0');
			LCD_voidSendCommand(0x01);
			LCD_voidGoToXY(0,0);
			LCD_voidWriteNumber((u16)key);
		}
	}

	return 0;
}



void calculator(u8 key)
{

	if(key!= 0 && (key == '0' || key == 1 || key == 2 || key == 3 || key == 4 || key == 5 || key == 6 || key == 7 || key == 8 || key == 9))
	{
		if(first_num == 1)
		{
			if(key == '0')
			{
				num1 = key - '0' ;
				LCD_voidWriteData('0') ;
			}
			else
			{
				num1 = (u16) key ;
				LCD_voidWriteNumber(num1);
			}
		}
		else
		{
			if(key == '0' && operator == '/')
			{
				key = KPD_u8GetPressedKey();
				//num2 = key - '0' ;
				//LCD_voidWriteData(key) ;
			}
			else if(key == '0')
			{
				num2 = key - '0' ;
				LCD_voidWriteData('0') ;
			}
			else
			{
				num2 = (u16) key;
				LCD_voidWriteNumber(num2);
			}
		}
	}

	if(key != 0 && (key == '+' || key == '-' || key == '*' || key == '/'))
	{
		operator = key ;
		LCD_voidWriteData(operator) ;
		first_num = 0 ;
	}

	if(key != 0 && key == '=')
	  {
		LCD_voidWriteData(key) ;
	    //LCD_voidGoToXY(1,2) ;

	    if(operator == '+')
	    {
	      result = num1 + num2 ;
	      LCD_voidWriteNumber(result);
	    }
	    else if (operator == '-')
	    {
	    	if(num1 == num2)
	    	{
	    		LCD_voidWriteData('0');
	    	}
	    	else if(num1 > num2)
	    	{
	    		result = num1 - num2 ;
	    		LCD_voidWriteNumber(result);
	    	}
	    	else if(num1 < num2)
	    	{
	    		result = num2 - num1 ;
	    		LCD_voidWriteData('-') ;
	    		LCD_voidWriteNumber(result);
	    	}

	    }
	     else if (operator == '*')
	    {
	      result = num1 * num2 ;
	      LCD_voidWriteNumber(result);
	    }
	     else if (operator == '/')
	    {

	        result = num1 / num2 ;
	        after_sign = (100 * (num1 % num2)) / num2 ;
	        LCD_voidWriteNumber(result);
	        if(after_sign != 0)
	        {
	        	  LCD_voidWriteData('.');
	        	  LCD_voidWriteNumber(after_sign);
	       }
 	    }

	    LCD_clearData();
	  }

	if (key!= 0 && key == 'c')
	  {
	    LCD_voidSendCommand(0x01);
	    LCD_voidGoToXY(0,0) ;
	    LCD_clearData();
	  }

}
void LCD_clearData()
{
	    first_num = 1 ;
	    num1    = 0  ;
	    num2    = 0  ;
	    operator  = ' ' ;
	    result   = 0 ;
	    after_sign = 0;

}

/////////////////////////////////////////////////////////////////////////////////////////

void allCalculator(u8 key)
{
	//u8 count1 = 0;

	if(key!= 0 && (key == '0' || key == 1 || key == 2 || key == 3 || key == 4 || key == 5 || key == 6 || key == 7 || key == 8 || key == 9))
	{
		if(first_num == 1)
		{
			if(key == '0')
			{
				num1 =  (num1 * 10 ) + (u16) key -'0';
				LCD_voidWriteData('0') ;
			}
			else
			{
				num1 = (num1 * 10 ) + (u16) key ;
				LCD_voidWriteNumber((u16)key);
			}
		}
		else
		{
			if(key == '0' && operator == '/')
			{
				key = KPD_u8GetPressedKey();
				//num2 = key - '0' ;
				//LCD_voidWriteData(key) ;
			}
			else if(key == '0')
			{
				num2 = (num2 * 10 ) + (u16) key -'0' ;
				LCD_voidWriteData('0') ;
			}
			else
			{
				num2 = (num2 * 10 ) + (u16) key ;
				LCD_voidWriteNumber((u16)key);
			}
		}
	}

	if(key != 0 && (key == '+' || key == '-' || key == '*' || key == '/'))
	{
		operator = key ;
		LCD_voidWriteData(operator) ;
		first_num = 0 ;
	}

	if(key != 0 && key == '=')
	  {
		LCD_voidWriteData(key) ;
	    //LCD_voidGoToXY(1,2) ;

	    if(operator == '+')
	    {
	      result = num1 + num2 ;
	      LCD_voidWriteNumber(result);
	    }
	    else if (operator == '-')
	    {
	    	if(num1 == num2)
	    	{
	    		LCD_voidWriteData('0') ;
	    	}
	    	else if(num1 >= num2)
	    	{
	    		result = num1 - num2 ;
	    		LCD_voidWriteNumber(result);
	    	}
	    	else if(num1 < num2)
	    	{
	    		result = num2 - num1 ;
	    		LCD_voidWriteData('-') ;
	    		LCD_voidWriteNumber(result);
	    	}
	    }
	     else if (operator == '*')
	    {
	      result = num1 * num2 ;
	      LCD_voidWriteNumber(result);
	    }
	     else if (operator == '/')
	    {

	        result = num1 / num2 ;
	        after_sign = (100 * (num1 % num2)) / num2 ;
	        LCD_voidWriteNumber(result);
	        if(result == 0)
	        {
	        	LCD_voidWriteData('0') ;
	        }
	        if(after_sign != 0)
	        {
	        	  LCD_voidWriteData('.');
	        	  LCD_voidWriteNumber(after_sign);
	       }
 	    }

	    LCD_clearData();
	  }

	if (key!= 0 && key == 'c')
	  {
	    LCD_voidSendCommand(0x01);
	    LCD_voidGoToXY(0,0) ;
	    LCD_clearData();
	  }

}



