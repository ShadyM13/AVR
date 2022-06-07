 /************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : USART   			*/
/*  Layer	  : MUSART    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  : May 7, 2022  		*/
/************************************/


#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MUSART_interface.h"
#include "MUSART_private.h"

void MUSART_voidInit(u8 ARG_u8BaudRate, u8 ARG_u8ModeSel, u8 ARG_u8Parity, u8 ARG_u8StopBits, u8 ARG_u8DataBits)
{
	//Baud rate selection
	UBRRL = 51; //Baud Rate: 9600

	//Mode select (ASYNC, SYNC)  ,  Parity selection,  Stop bits selection,   Data bits selection (MUST ALL BE ASSIGNED AT THE SAME TIME)
	UCSRC = (1 << 7) | (ARG_u8ModeSel << 6) | (ARG_u8Parity << 4) | (ARG_u8StopBits << 3) | ((ARG_u8DataBits & 0b11) << 1);

	//if 9 bits required
	if(ARG_u8DataBits == MUSART_DATA_BITS_9)
	{
		SET_BIT(UCSRB, 2);
	}
	else
	{
		CLEAR_BIT(UCSRB, 2);
	}
}

void MUSART_voidEnableTx(u8 ARG_u8Enable)
{
	if(ARG_u8Enable == MUSART_ENABLE)
	{
		SET_BIT(UCSRB, 3);
	}
	else
	{
		CLEAR_BIT(UCSRB, 3);
	}
}

void MUSART_voidEnableRx(u8 ARG_u8Enable)
{
	if(ARG_u8Enable == MUSART_ENABLE)
		{
			SET_BIT(UCSRB, 4);
		}
		else
		{
			CLEAR_BIT(UCSRB, 4);
		}
}

void MUSART_voidSendChar(char Data)
{
	while(1 != GET_BIT(UCSRA, 5));
	UDR = Data;
	while(1 != GET_BIT(UCSRA, 6));
	SET_BIT(UCSRA, 6);
}

char MUSART_charReceiveChar(void)
{
	while(1 != GET_BIT(UCSRA, 7));
	return UDR;
}

void MUSART_voidSendString(const char* ARG_ccharString)
{
	u8 L_u8Counter = 0;
	do{
		MUSART_voidSendChar(ARG_ccharString[L_u8Counter++]);
	}while(ARG_ccharString[L_u8Counter] != '\0');
}

void MUSART_ReceiveStringUntil(char* ARG_charpString, u8 ARG_u8TerminatingChar)
{
	u8 L_u8Counter = 0;
	do{
		ARG_charpString[L_u8Counter++] = MUSART_charReceiveChar();
	}while(ARG_charpString[L_u8Counter] != ARG_u8TerminatingChar);
}
