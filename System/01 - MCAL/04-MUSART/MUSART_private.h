/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : USART   			*/
/*  Layer	  : MUSART    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Apr 16, 2022  		*/
/************************************/

#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_


#define     UDR     *((volatile u8*)0x2C)
#define     UCSRA   *((volatile u8*)0x2B)
#define     UCSRB   *((volatile u8*)0x2A)
#define     UCSRC   *((volatile u8*)0x40)
#define     UBRRH   *((volatile u8*)0x40)       
#define     UBRRL   *((volatile u8*)0x29)


#endif