/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : TIMERS				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	April 4, 2022		*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MTIMER_private.h"
#include "MTIMER_interface.h"

u8 MTIMER_u8Prescalar;
volatile static u8 MTIMER_u8Timer0OVFCounter = 0;
volatile static u8 MTIMER_u8Timer1OVFCounter = 0;
volatile static u8 MTIMER_u8Timer2OVFCounter = 0;
static u8  MTIMER_u8Timer0Preload  = 0;
static u16 MTIMER_u16Timer1Preload  = 0;
static u8  MTIMER_u8Timer2Preload  = 0;
static u16 MTIMER_u16Timer0OVFCount = 0;
static u16 MTIMER_u16Timer1OVFCount = 0;
static u16 MTIMER_u16Timer2OVFCount = 0;

void (*MTIMER_pvoidUserFunctionT0OVF)(void) = 0;
void (*MTIMER_pvoidUserFunctionT0OCM)(void) = 0;
void (*MTIMER_pvoidUserFunctionT1OVF)(void) = 0;
void (*MTIMER_pvoidUserFunctionT1OCMA)(void) = 0;
void (*MTIMER_pvoidUserFunctionT1OCMB)(void) = 0;
void (*MTIMER_pvoidUserFunctionT2OVF)(void) = 0;
void (*MTIMER_pvoidUserFunctionT2OCM)(void) = 0;

void MTIMER_voidInit(u8 ARG_u8TimerNo, u8 ARG_u8Mode, u8 ARG_u8Prescalar, u8 ARG_u8HWPinMode)
{
	MTIMER_u8Prescalar = ARG_u8Prescalar;
	switch(ARG_u8TimerNo)
	{
		case MTIMER_TIMER0:
			TCCR0 = 0;
			switch(ARG_u8Mode)
			{
				case MTIMER_MODE_NORMAL:
					break;
				case MTIMER_MODE_CTC:
					SET_BIT(TCCR0, WGM01);
					break;
				case MTIMER_MODE_FASTPWM:
					SET_BIT(TCCR0, WGM00);
					SET_BIT(TCCR0, WGM01);
					break;
				case MTIMER_MODE_PHASECORRECTPWM:
					SET_BIT(TCCR0, WGM00);
					break;
			}
			switch(ARG_u8HWPinMode)
			{
				case MTIMER_HWPIN_DISABLED:
					break;
				case MTIMER_HWPIN_TOGGLE:
					SET_BIT(TCCR0, COM00);
					break;
				case MTIMER_HWPIN_CLEAR:
				case MTIMER_HWPIN_NONINVERTINGPWM:
					SET_BIT(TCCR0, COM01);
					break;
				case MTIMER_HWPIN_SET:
				case MTIMER_HWPIN_INVERTINGPWM:
					SET_BIT(TCCR0, COM00);
					SET_BIT(TCCR0, COM01);
					break;
				default:
					break;
			}
			break;
		case MTIMER_TIMER1:
			break;
		case MTIMER_TIMER2:
			break;
		default:
			break;
	}
}

void MTIMER_voidInterruptEnable(u8 ARG_u8InterruptSource, u8 ARG_u8State)
{
	if(MTIMER_ENABLE == ARG_u8State)
	{
		SET_BIT(TIMSK, ARG_u8InterruptSource);
	}
	else if(MTIMER_DISABLE == ARG_u8State)
	{
		CLEAR_BIT(TIMSK, ARG_u8InterruptSource);
	}
}

void MTIMER_voidSetCallBack(u8 ARG_u8InterruptSource, void (*ARG_pvoidfUserFunction)(void))
{
	switch(ARG_u8InterruptSource)
	{
		case MTIMER_INTERRUPT_T0_OVF:
			MTIMER_pvoidUserFunctionT0OVF = ARG_pvoidfUserFunction;
			break;
		case MTIMER_INTERRUPT_T0_OCM:
			MTIMER_pvoidUserFunctionT0OCM = ARG_pvoidfUserFunction;
			break;
		case MTIMER_INTERRUPT_T1_OVF:
			MTIMER_pvoidUserFunctionT1OVF = ARG_pvoidfUserFunction;
			break;
		case MTIMER_INTERRUPT_T1_OCMA:
			MTIMER_pvoidUserFunctionT1OCMA = ARG_pvoidfUserFunction;
			break;
		case MTIMER_INTERRUPT_T1_OCMB:
			MTIMER_pvoidUserFunctionT1OCMB = ARG_pvoidfUserFunction;
			break;
		case MTIMER_INTERRUPT_T2_OVF:
			MTIMER_pvoidUserFunctionT2OVF = ARG_pvoidfUserFunction;
			break;
		case MTIMER_INTERRUPT_T2_OCM:
			MTIMER_pvoidUserFunctionT2OCM = ARG_pvoidfUserFunction;
			break;
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	MTIMER_u8Timer0OVFCounter++;
	if(MTIMER_u8Timer0OVFCount == MTIMER_u8Timer0OVFCounter)
	{
		MTIMER_u8Timer0OVFCounter = 0;
		TCCNT0 = MTIMER_u8Timer0Preload;
		(*MTIMER_pvoidUserFunctionT0OVF)();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	(*MTIMER_pvoidUserFunctionT0OCM)();
}



void MTIMER_voidTimerDelay(u8 ARG_u8TimerNo, f32 ARG_u8Delay)
{
	f32 L_f32TimerTick = (f32)MTIMER_u8Prescalar / ((f32)MTIMER_IO_CLOCK/1000);
	f32 L_f32OVFTime = L_f32TimerTick * 256;
	MTIMER_u16Timer0OVFCount = (u16)(ARG_u8Delay / L_f32OVFTime) + 1;
	MTIMER_u8Timer0Preload = (ARG_u8Delay % L_f32OVFTime);
}

void MTIMER_voidStartTimer(u8 ARG_u8TimerNo, u8 ARG_u8State)
{
	if(MTIMER_ENABLE == ARG_u8State)
	{
		switch(ARG_u8TimerNo)
		{
			case MTIMER_TIMER0:
				TCCR0 |= MTIMER_u8Prescalar;
				break;
			case MTIMER_TIMER1:
				break;
			case MTIMER_TIMER2:
				break;
			default:
				break;
		}
	}
	else
	{
		switch(ARG_u8TimerNo)
		{
			case MTIMER_TIMER0:
				TCCR0 &= ~(0b111);
				break;
			case MTIMER_TIMER1:
				break;
			case MTIMER_TIMER2:
				break;
			default:
				break;
		}
	}
}

void MTIMER_voidGeneratePWM(u8 ARG_u8TimerNo, u8 ARG_u8DutyCycle, u8 ARG_u8Frequency)
{
	
}