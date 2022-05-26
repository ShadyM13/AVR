/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : MWDT    			*/
/*  Layer	  : MCAL    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Apr 24, 2022  		*/
/************************************/

#ifndef MWDT_INTERFACE_H_
#define MWDT_INTERFACE_H_

#define     MWDT_PERIOD_16K         0
#define     MWDT_PERIOD_32K         1
#define     MWDT_PERIOD_64K         2
#define     MWDT_PERIOD_128K        3
#define     MWDT_PERIOD_256K        4
#define     MWDT_PERIOD_512K        5
#define     MWDT_PERIOD_1024K       6
#define     MWDT_PERIOD_2048K       7

#define     WDE                     3
#define     WDTOE                   4



void MWDT_voidEnableWDT(u8 ARG_u8PeriodWDT);

void MWDT_voidDisableWDT(void);

#endif