/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : TIMERS				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	April 4, 2022		*/
/************************************/

#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

#define MTIMER_TIMER0					0
#define MTIMER_TIMER1					1
#define MTIMER_TIMER2					2

#define MTIMER_MODE_NORMAL				0
#define MTIMER_MODE_CTC					1
#define MTIMER_MODE_FASTPWM				2
#define MTIMER_MODE_PHASECORRECTPWM		3

#define MTIMER_HWPIN_DISABLED			0
#define MTIMER_HWPIN_TOGGLE				1
#define MTIMER_HWPIN_CLEAR				2
#define MTIMER_HWPIN_SET				3
#define MTIMER_HWPIN_NONINVERTINGPWM	4
#define MTIMER_HWPIN_INVERTINGPWM		5

#define MTIMER_ENABLE					0
#define MTIMER_DISABLE					1

#define MTIMER_PRESCALAR_0				0
#define MTIMER_PRESCALAR_1				1
#define MTIMER_PRESCALAR_8				2
#define MTIMER_PRESCALAR_64				3
#define MTIMER_PRESCALAR_256			4
#define MTIMER_PRESCALAR_1024			5
#define MTIMER_PRESCALAR_EXT_FALLING	6
#define MTIMER_PRESCALAR_EXT_RISING		7

#define MTIMER_INTERRUPT_T0_OVF			TOIE0
#define MTIMER_INTERRUPT_T0_OCM			OCIE0
#define MTIMER_INTERRUPT_T1_OVF			TOIE1
#define MTIMER_INTERRUPT_T1_OCMA		OCIE1A
#define MTIMER_INTERRUPT_T1_OCMB		OCIE1B
#define MTIMER_INTERRUPT_T2_OVF			TOIE2
#define MTIMER_INTERRUPT_T2_OCM			OCIE2

#define MTIMER_IO_CLOCK					F_CPU

void MTIMER_voidInit(u8 ARG_u8TimerNo, u8 ARG_u8Mode, u8 ARG_u8Prescalar, u8 ARG_u8HWPinMode);
void MTIMER_voidInterruptEnable(u8 ARG_u8InterruptSource, u8 ARG_u8State);
void MTIMER_voidSetCallBack(u8 ARG_u8InterruptSource, void (*ARG_pvoidfUserFunction)(void));
void MTIMER_voidTimerDelay(u8 ARG_u8TimerNo, u8 ARG_u8Delay);
void MTIMER_voidStartTimer(u8 ARG_u8TimerNo, u8 ARG_u8State);
void MTIMER_voidGeneratePWM(u8 ARG_u8TimerNo, u8 ARG_u8DutyCycle, u8 ARG_u8Frequency);

#endif