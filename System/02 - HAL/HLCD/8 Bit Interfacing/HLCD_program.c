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


void HLCD_voidSendCommand(u8 ARG_u8Command)
{
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_LOW);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, MDIO_LOW);		//RW = 0

    MDIO_voidSetPortValue(HLCD_DATA_PORT, ARG_u8Command);
    _delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_HIGH);
    _delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
}


void HLCD_voidSendChar(u8 ARG_u8Character)
{
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_HIGH);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, MDIO_LOW);		//RW = 0
    MDIO_voidSetPortValue(HLCD_DATA_PORT, ARG_u8Character);
    _delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_HIGH);
    _delay_us(1);
    MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, MDIO_LOW);
}


void HLCD_voidInit(void)
{
    MDIO_voidSetPortDirection(HLCD_DATA_PORT, 0xFF);
    MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_RS_PIN, MDIO_OUTPUT);
    MDIO_voidSetPinDirection(HLCD_CTRL_PORT, HLCD_EN_PIN,MDIO_OUTPUT);
    _delay_ms(30);
    HLCD_voidSendCommand(0x3C);			//Function set  0b0011 1100
    _delay_us(40);
    HLCD_voidSendCommand(0x0C);			//Display ON/OFF Control 0b0000 1100
    _delay_us(40);
    HLCD_voidSendCommand(0x01);			//Display clear  0b0000 0001
    _delay_ms(2);
    HLCD_voidSendCommand(0x06);			//Entry Mode Set  0b0000 0110
    _delay_us(40);
}


void HLCD_voidSendString (const char* ARG_pcStr)
{
	u8 i;
	for(i=0;ARG_pcStr[i]!='\0';i++)  /* send each char of string till the NULL */
	{
		HLCD_voidSendChar (ARG_pcStr[i]);  /* call LCD data write */
	}
}


void HLCD_voidSendString_xy (u8 ARG_u8row, u8 ARG_u8col, const char* ARG_pcStr)   /* Send string to LCD with xy position */
{
	HLCD_voidSetPosition (ARG_u8row, ARG_u8col);       	//Set position
	HLCD_voidSendString(ARG_pcStr);		/* Call LCD string function */
}


void HLCD_voidClear()
{
	HLCD_voidSendCommand(0x01);		    /* clear display */
	HLCD_voidSendCommand (0x80);		/* cursor at home position */
}


void HLCD_voidSetPosition (u8 ARG_u8row, u8 ARG_u8col)
{
	if (ARG_u8row == 0 && ARG_u8col<16)
	{
		HLCD_voidSendCommand((ARG_u8col & 0x0F)|0x80);	/* Command of first row and required position<16 */
	}

	else if (ARG_u8row == 1 && ARG_u8col<16)
	{
		HLCD_voidSendCommand((ARG_u8col & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	}
}


void HLCD_voidWriteStringExtended (u8 ARG_u8row, u8 ARG_u8col, const char* ARG_pcStr)
{
	HLCD_voidSetPosition(ARG_u8row, ARG_u8col);
	u8 index = 0;
	u8 line0 = 0;

	while(ARG_pcStr[index] != '\0' && ((ARG_u8row * 16) + (index + ARG_u8col)) < 32)
	{
		if( ((ARG_u8row * 16) + (index + ARG_u8col)) <16 )
		{
			HLCD_voidSendChar(ARG_pcStr[index]);
			index++;
		}
		else if (((ARG_u8row * 16) + (index + ARG_u8col)) == 16 && line0 == 0)
		{
			HLCD_voidSetPosition(1,0);
			line0++;
		}
		else if(((ARG_u8row * 16) + (index + ARG_u8col)) < 32 && line0 == 1 )
		{
			HLCD_voidSendChar(ARG_pcStr[index]);
			index++;
		}
	}
}


void HLCD_voidStoreCustomChar(u8* pattern,u8 CGRAM_index)
{
	u8 adress;
	u8 index;
	if(CGRAM_index < 8)
	{
		adress = CGRAM_index * 8;
		adress = SET_BIT(adress, 6);		
		HLCD_voidSendCommand(adress);				//SET CGRAM Adress
		for(index=0; index < 8; index++)
		{
			HLCD_voidSendChar(pattern[index]);		//write data in CGRAM
		}
		HLCD_voidSendCommand(0x02);                 //Return Home
	}
}


void HLCD_voidDisplayCustomChar (u8 CGRAM_index, u8 ARG_u8row, u8 ARG_u8col)
{
	HLCD_voidSetPosition(ARG_u8row ,ARG_u8col);

	HLCD_voidSendChar(CGRAM_index);
}


void HLCD_voidReverseString ( char ARG_charstr[], int ARG_u32length)
{
	int start = 0;
	int end = ARG_u32length -1;
	int temp;
	while(start < end)
	{
		temp = *(ARG_charstr+start);
		*(ARG_charstr+start) = *(ARG_charstr+end) ;
		*(ARG_charstr+end) = temp;
		start++;
		end--;
	}
}


void HLCD_voidSendIntNumber(int ARG_u32num, char* ARG_pcstr, int ARG_u32base)
{
	//implementation of itoa();
	int i = 0;
	u8 isNegative = 0;

	// Handle 0 explicitly, otherwise empty string is printed for 0
	if(0 == ARG_u32num)
	{
		ARG_pcstr[i++] = '0';
		ARG_pcstr[i] = '\0';
		HLCD_voidSendString(ARG_pcstr);
	}

	// In standard itoa(), negative numbers are handled only with
	// base 10. Otherwise numbers are considered unsigned.

	if( 0 > ARG_u32num && 10 == ARG_u32base)
	{
		isNegative = 1;
		ARG_u32num = -ARG_u32num;
	}
	// Process individual digits
	while (ARG_u32num != 0)
	{
		int rem = ARG_u32num % ARG_u32base;
		ARG_pcstr[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		ARG_u32num = ARG_u32num/ARG_u32base;
	}
	// If number is negative, append '-'
	if(isNegative)
	{
		ARG_pcstr = '-';
	}
	ARG_pcstr[i] = '\0'; // Append string terminator

	// Reverse the string
	HLCD_voidReverseString(ARG_pcstr,i);

	HLCD_voidSendString(ARG_pcstr);


}
