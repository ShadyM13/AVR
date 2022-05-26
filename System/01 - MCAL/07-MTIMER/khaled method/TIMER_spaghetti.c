/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : Timer 0				*/
/*  Layer	  : APP					*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Mar 19, 2022		*/
/************************************/

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_interface.h"
#include "MGIE_interface.h"

#define TCCR0	*((volatile u8*)0x53)
#define TCNT0	*((volatile u8*)0x52)
#define OCR0	*((volatile u8*)0x5C)
#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)

volatile u8 NourVariableOVF = 0;
volatile u8 LED_state = 0;

int main(void)
{
	MDIO_voidSetPinDirection(MDIO_PORTC, 0, MDIO_OUTPUT);
	MGIE_voidEnableGI();
	TIMSK = 0x01;
	TCNT0 = 128;
	TCCR0 = 0b00000101;
	while(1);
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	NourVariableOVF++;
	if(31 == NourVariableOVF)
	{
		NourVariableOVF = 0;
		TCNT0 = 128;
		LED_state = !LED_state;
		MDIO_voidSetPinValue(MDIO_PORTC, 0, LED_state);
	}
}