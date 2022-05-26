/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : USART   			*/
/*  Layer	  : MUSART    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	May 7, 2022  		*/
/************************************/

#ifndef _MUSART_INTERFACE_H_
#define _MUSART_INTERFACE_H_

#define MUSART_DISABLE		0
#define MUSART_ENABLE		1

#define MUSART_ASYNC		0
#define MUSART_SYNC			1

#define MUSART_PARITY_OFF	0
#define MUSART_PARITY_EVEN	2
#define MUSART_PARITY_ODD	3

#define MUSART_STOP_BITS_1	0
#define MUSART_STOP_BITS_2	1

#define MUSART_DATA_BITS_5	0
#define MUSART_DATA_BITS_6	1
#define MUSART_DATA_BITS_7	2
#define MUSART_DATA_BITS_8	3
#define MUSART_DATA_BITS_9	7

void MUSART_voidInit(u8 ARG_u8BaudRate, u8 ARG_u8ModeSel, u8 ARG_u8Parity, u8 ARG_u8StopBits, u8 ARG_u8DataBits);

void MUSART_voidEnableTx(u8 Enable);

void MUSART_voidEnableRx(u8 Enable);

void MUSART_voidSendChar(char Data);

char MUSART_charReceiveChar(void);

void MUSART_voidSendString(const char* ARG_ccharString);

void MUSART_ReceiveStringUntil(char* ARG_charpString, u8 ARG_u8TerminatingChar);

#endif
