/************************************/
/*	Author	  :	Shady Ahmad  		*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	March 5, 2022		*/
/************************************/

#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_

#define ADCL	*((volatile u8*)0x24)
#define ADCH	*((volatile u8*)0x25)
#define ADCSRA	*((volatile u8*)0x26)
#define ADMUX	*((volatile u8*)0x27)
#define SFIOR	*((volatile u8*)0x50)

void MADC_voidFlagPolling(void);

#endif