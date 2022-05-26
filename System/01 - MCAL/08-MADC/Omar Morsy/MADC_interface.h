/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	March 5, 2022		*/
/************************************/

#ifndef _MADC_INTERFACE_H_
#define _MADC_INTERFACE_H_

/******* Macros Definition START ********/

// Analog Voltage Reference
#define MADC_REF_AVCC		0b00000000
#define MADC_REF_AREF		0b01000000
#define MADC_REF_2_56V		0b11000000

// ADC Prescalar
#define MADC_PRESCALAR_2	1
#define MADC_PRESCALAR_4	2
#define MADC_PRESCALAR_8	3
#define MADC_PRESCALAR_16	4
#define MADC_PRESCALAR_32	5
#define MADC_PRESCALAR_64	6
#define MADC_PRESCALAR_128	7

// Trigger Source


// ADC Channel
#define MADC_ADC0			0
#define MADC_ADC1			1
#define MADC_ADC2			2
#define MADC_ADC3			3
#define MADC_ADC4			4
#define MADC_ADC5			5
#define MADC_ADC6			6
#define MADC_ADC7			7

// ADC Enable
#define MADC_ENABLE			1
#define MADC_DISABLE		0

/******* Macros Definition END ********/

void MADC_voidInit(u8 ARG_u8Aref, u8 ARG_u8LeftAdjust, u8 ARG_u8Prescalar);

void MADC_voidEnableADC(u8 ARG_u8ADCEnable);

void MADC_voidInterruptEnable(u8 ARG_u8InterruptEnable);

void MADC_voidAutoTrigger(u8 ARG_u8TriggerSource);

void MADC_voidStartConversion(void);

u8	 MADC_u8ReadADC(u8 ARG_u8Channel);

#endif