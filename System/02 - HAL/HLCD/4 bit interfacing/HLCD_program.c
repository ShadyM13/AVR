/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : LCD                  */
/*       Layer      : HAL                  */
/*       Version    : 1.0                  */
/*       Date       : February 14, 2022    */
/*       Last Edit  : N/A                  */
/*******************************************/

#define F_CPU 8000000UL
#include <util/delay.h>

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_interface.h"

#include "HLCD_interface.h"
#include "HLCD_config.h"

static u8 InitStepFinished = 0;

void HLCD_voidSendCommand(u8 ARG_u8Command)
{
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_LOW);		//RS = 0
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, MDIO_LOW);		//RW = 0

	MDIO_voidSetPinValue(HLCD_DATA_PORT, 4, GET_BIT(ARG_u8Command, 4));		//Databus 4
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 5, GET_BIT(ARG_u8Command, 5));		//Databus 5
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 6, GET_BIT(ARG_u8Command, 6));		//Databus 6
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 7, GET_BIT(ARG_u8Command, 7));		//Databus 7

	_delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_HIGH);			//Enable cycle
    _delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);

	if(InitStepFinished)
	{
		MDIO_voidSetPinValue(HLCD_DATA_PORT, 4, GET_BIT(ARG_u8Command, 0));		//Databus 4
		MDIO_voidSetPinValue(HLCD_DATA_PORT, 5, GET_BIT(ARG_u8Command, 1));		//Databus 5
		MDIO_voidSetPinValue(HLCD_DATA_PORT, 6, GET_BIT(ARG_u8Command, 2));		//Databus 6
		MDIO_voidSetPinValue(HLCD_DATA_PORT, 7, GET_BIT(ARG_u8Command, 3));		//Databus 7

		_delay_us(1);															
		MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);			
		MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_HIGH);			//Enable cycle
		_delay_us(1);															
		MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
	}
}


void HLCD_voidSendChar(u8 ARG_u8Character)
{
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_HIGH);		//RS = 1
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, MDIO_LOW);		//RW = 0

    MDIO_voidSetPinValue(HLCD_DATA_PORT, 4, GET_BIT(ARG_u8Character, 4));		//Databus 4
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 5, GET_BIT(ARG_u8Character, 5));		//Databus 5
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 6, GET_BIT(ARG_u8Character, 6));		//Databus 6
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 7, GET_BIT(ARG_u8Character, 7));		//Databus 7

	_delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_HIGH);			//Enable cycle
    _delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);

	MDIO_voidSetPinValue(HLCD_DATA_PORT, 4, GET_BIT(ARG_u8Character, 0));		//Databus 4
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 5, GET_BIT(ARG_u8Character, 1));		//Databus 5
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 6, GET_BIT(ARG_u8Character, 2));		//Databus 6
	MDIO_voidSetPinValue(HLCD_DATA_PORT, 7, GET_BIT(ARG_u8Character, 3));		//Databus 7

    _delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_HIGH);			//Enable cycle
    _delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
}


void HLCD_voidSendString (u8* str)
{
	u8 i;
	for(i=0; str[i]!=0 ;i++)  /* send each char of string till the NULL */
	{
		HLCD_voidSendChar (str[i]);  /* call LCD data write */
	}
}


void HLCD_voidSendString_xy (u8 row, u8 col, u8 *str)   /* Send string to LCD with xy position */
{
	HLCD_voidSetPosition (row, col);       //Set position

	HLCD_voidSendString(str);		/* Call LCD string function */
}


void HLCD_voidClear()
{
	HLCD_voidSendCommand(0x01);		/* clear display */
	HLCD_voidSendCommand (0x80);		/* cursor at home position */
}


void HLCD_voidInit(void)
{
	MDIO_voidSetPortDirection(HLCD_DATA_PORT, 0xFF);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_OUTPUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_EN_PIN,MDIO_OUTPUT);

	_delay_ms(30);

	HLCD_voidSendCommand(0x20);			//Function set  0b0010 0000
	_delay_us(40);
	HLCD_voidSendCommand(0x20);			//Function set  0b0010 0000
	_delay_us(40);
	HLCD_voidSendCommand(0xC0);			//Function set  0b1100 0000
	_delay_us(40);

	
	HLCD_voidSendCommand(0x00);					//Display ON/OFF Control 0b0000 0000
	_delay_us(40);
	HLCD_voidSendCommand(0xC0);					//Display ON/OFF Control 0b1111 0000
	_delay_us(40);


	HLCD_voidSendCommand(0x00);					//Display clear  0b0000 0000
	_delay_us(40);
	HLCD_voidSendCommand(0x10);					//Display clear  0b0000 0001
	_delay_ms(2);

	HLCD_voidSendCommand(0x00);					//Entry Mode Set  0b0000 0110
	_delay_us(40);
	HLCD_voidSendCommand(0x60);					//Entry Mode Set  0b0000 0110
	_delay_us(40);


	InitStepFinished = 1;
}


void HLCD_voidSetPosition (u8 row, u8 col)
{
	if (row == 0 && col<16)
	{
		HLCD_voidSendCommand((col & 0x0F)|0x80);	/* Command of first row and required position<16 */
	}

	else if (row == 1 && col<16)
	{
		HLCD_voidSendCommand((col & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	}
}


void HLCD_voidWriteStringExtended (u8* str, u8 row, u8 col)
{
	HLCD_voidSetPosition(row, col);
	u8 index = 0;
	u8 line0 = 0;

	while(str != 0 && ((row * 16) + (index + col)) < 32)
	{
		if( ((row * 16) + (index + col)) <16 )
		{
			HLCD_voidSendChar(str[index]);
			index++;
		}
		else if (((row * 16) + (index + col)) == 16 && 0 == line0 )
		{
			HLCD_voidSetPosition(1,0);
			line0 = 1;
		}
		else if(((row * 16) + (index + col)) < 32 && 1 == line0 )
		{
			HLCD_voidSendChar(str[index]);
			index++;
		}
	}
}


void HLCD_voidStoreCustomChar(u8* patten,u8 CGRAM_index)
{
	u8 adress;
	u8 index;
	if(CGRAM_index < 8)
	{
		adress = CGRAM_index *8;
		adress = SET_BIT(adress, 6);		
		HLCD_voidSendCommand(adress);				//SET CGRAM Adress
		for(index=0; index<=7; index++)
		{
			HLCD_voidSendChar(pattern[index]);		//write data in CGRAM
		}
		HLCD_voidSendCommand(0x02);                 //Return Home
	}
}

void HLCD_voidDisplayCustomChar (u8 CGRAM_index, u8row, u8 col)
{
	HLCD_voidSetPosition(row ,col);

	HLCD_voidSendChar(CGRAM_index);
}