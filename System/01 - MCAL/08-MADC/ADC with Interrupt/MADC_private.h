/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : ADC					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	March 18, 2022		*/
/************************************/

#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_

#define ADCL	*((volatile u8*)0x24)
#define ADCH	*((volatile u8*)0x25)
#define ADCSRA	*((volatile u8*)0x26)
#define ADMUX	*((volatile u8*)0x27)
#define SFIOR	*((volatile u8*)0x50)

#endif
