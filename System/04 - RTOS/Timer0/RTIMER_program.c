/************************************/
/*	Author	  : Shady Ahmad			*/
/*	SWC		  : TIMERS				*/
/*  Layer	  : RTOS Stack			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 9, 2022         */
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "RTIMER_private.h"
#include "RTIMER_interface.h"


volatile static u8 RTIMER_u8Timer0OVFCounter = 0;
static 			u8  RTIMER_u8Timer0Preload   = 0;
static 			u16 RTIMER_u16Timer0OVFCount = 0;



void (*RTIMER_pvoidUserFunctionT0OCM)(void) = 0;


void RTIMER_voidInit(void)
{
	//Timer0 CTC Mode
	CLEAR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0,   WGM01);

	//Timer0 compare match value
	OCR0 = 125;

	//Timer0 Compare match interrupt enable
	SET_BIT(TIMSK,OCIE0);

	//Set required  64
    TCCR0 &= 0b11111000;
	TCCR0 |= RTIMER_PRESCALAR_64;
	
}


void RTIMER_voidSetCallBack(void (*ARG_pvoidfUserFunction)(void))
{
	//MTIMER_INTERRUPT_T0_OCM:
	RTIMER_pvoidUserFunctionT0OCM = ARG_pvoidfUserFunction;

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	(*RTIMER_pvoidUserFunctionT0OCM)();
}


