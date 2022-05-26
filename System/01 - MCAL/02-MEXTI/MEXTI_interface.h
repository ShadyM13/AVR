/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : EXTI				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	March 12, 2022		*/
/************************************/

#ifndef _MEXTI_INTERFACE_H_
#define _MEXTI_INTERFACE_H_

#define MEXTI_INT0			INT0
#define MEXTI_INT1			INT1
#define MEXTI_INT2			INT2

#define MEXTI_MODE_LOW		0
#define MEXTI_MODE_IOC		1
#define MEXTI_MODE_RISING	2
#define MEXTI_MODE_FALLING	3

void MEXTI_voidInit(u8 ARG_u8InterruptNumber, u8 ARG_u8Mode);

void MEXTI_voidEnableInterrupt(u8 ARG_u8InterruptNumber);

void MEXTI_voidDisableInterrupt(u8 ARG_u8InterruptNumber);

void MEXTI_voidSetCallBackINT0(void (*ARG_pvoidfUserFunctionINT0)(void));

void MEXTI_voidSetCallBackINT1(void (*ARG_pvoidfUserFunctionINT1)(void));

void MEXTI_voidSetCallBackINT2(void (*ARG_pvoidfUserFunctionINT2)(void));

#endif