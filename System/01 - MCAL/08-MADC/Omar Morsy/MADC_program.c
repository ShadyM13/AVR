/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	March 5, 2022		*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MADC_interface.h"
#include "MADC_private.h"

void MADC_voidInit(u8 ARG_u8Aref, u8 ARG_u8LeftAdjust, u8 ARG_u8Prescalar)
{
	ADMUX &= 0b00111111;
	ADMUX |= ARG_u8Aref;
	
	if(MADC_ENABLE == ARG_u8LeftAdjust)
	{
		SET_BIT(ADMUX, 5);
	}
	else if(MADC_DISABLE == ARG_u8LeftAdjust)
	{
		CLEAR_BIT(ADMUX, 5);
	}
	
	ADCSRA &= 0b11111000;
	ADCSRA |= ARG_u8Prescalar;
	
	MADC_voidEnableADC(MADC_ENABLE);
}

void MADC_voidEnableADC(u8 ARG_u8ADCEnable)
{
	if(MADC_ENABLE == ARG_u8ADCEnable)
	{
		SET_BIT(ADCSRA, 7);
	}
	else if(MADC_DISABLE == ARG_u8ADCEnable)
	{
		CLEAR_BIT(ADCSRA, 7);
	}
	else
	{
		//Report an Error
	}
}

void MADC_voidInterruptEnable(u8 ARG_u8InterruptEnable)
{
	if(MADC_ENABLE == ARG_u8InterruptEnable)
	{
		SET_BIT(ADCSRA, 3);
	}
	else if(MADC_DISABLE == ARG_u8InterruptEnable)
	{
		CLEAR_BIT(ADCSRA, 3);
	}
	else
	{
		//Report an Error
	}
}

void MADC_voidAutoTrigger(u8 ARG_u8TriggerSource)
{
	
}

void MADC_voidStartConversion(void)
{
	SET_BIT(ADCSRA, 6);
}

u8	 MADC_u8ReadADC(u8 ARG_u8Channel)
{
	// ADMUX Bits Clear Mask
	ADMUX &= 0b11100000;
	ADMUX |= ARG_u8Channel;
	MADC_voidStartConversion();
	MADC_voidFlagPolling();
	return ADCH;
}

static void MADC_voidFlagPolling(void)
{
	while(0 == GET_BIT(ADCSRA, 4));
}