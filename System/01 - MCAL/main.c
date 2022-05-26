/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : main.c				*/
/*  Layer	  : APP					*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Mar 12, 2022		*/
/************************************/

#define F_CPU 8000000UL
#include <util/delay.h>

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_interface.h"

#define MCUCR	*((volatile u8*)0x55)
#define MCUCSR	*((volatile u8*)0x54)
#define GICR	*((volatile u8*)0x5B)
#define GIFR	*((volatile u8*)0x5A)
#define SREG	*((volatile u8*)0x5F)

int main(void)
{
	MDIO_voidSetPinDirection(MDIO_PORTA,0,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTA,1,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTA,2,MDIO_OUTPUT);
	MDIO_voidSetPinDirection(MDIO_PORTD,2,MDIO_INPUT);
	MDIO_voidSetPinDirection(MDIO_PORTD,3,MDIO_INPUT);
	MDIO_voidSetPinValue(MDIO_PORTD,2,MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTD,3,MDIO_HIGH);
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,2);
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);
	SET_BIT(SREG,7);
	while(1)
	{
		MDIO_voidSetPinValue(MDIO_PORTA,2,MDIO_HIGH);
		_delay_ms(300);
		MDIO_voidSetPinValue(MDIO_PORTA,2,MDIO_LOW);
		_delay_ms(300);
	}
	return 0;
}



void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	volatile static u8 Flag = 0;
	if(0 == Flag)
	{
		Flag = 1;
		MDIO_voidSetPinValue(MDIO_PORTA,0,MDIO_HIGH);
	}
	else
	{
		Flag = 0;
		MDIO_voidSetPinValue(MDIO_PORTA,0,MDIO_LOW);
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	MDIO_voidSetPinValue(MDIO_PORTA,1,!MDIO_u8GetPinValue(MDIO_PORTA,1));
}
