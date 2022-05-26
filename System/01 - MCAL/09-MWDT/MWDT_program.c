/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : MWDT    			*/
/*  Layer	  : MCAL    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Apr 24, 2022  		*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MWDT_interface.h"
#include "MWDT_private.h"

void MWDT_voidEnableWDT(u8 ARG_u8PeriodWDT)
{
    WDTCR = 0b00000000;
    
    switch(ARG_u8PeriodWDT)
    {
        case 0:
            WDTCR |= ARG_u8PeriodWDT;       //Set prescalar
            SET_BIT(WDTCR,WDE);               //Enable
            break;
        case 1:
            WDTCR |= ARG_u8PeriodWDT;       //Set prescalar
            SET_BIT(WDTCR,WDE);               //Enable
            break;
        case 2:
            WDTCR |= ARG_u8PeriodWDT;       //Set prescalar
            SET_BIT(WDTCR,WDE);               //Enable
            break;
        case 3:
            WDTCR |= ARG_u8PeriodWDT;       //Set prescalar
            SET_BIT(WDTCR,WDE);               //Enable
            break;
        case 4:
            WDTCR |= ARG_u8PeriodWDT;       //Set prescalar
            SET_BIT(WDTCR,WDE);               //Enable
            break;
        case 5:
            WDTCR |= ARG_u8PeriodWDT;       //Set prescalar
            SET_BIT(WDTCR,WDE);               //Enable
            break;
        case 6:
            WDTCR |= ARG_u8PeriodWDT;       //Set prescalar
            SET_BIT(WDTCR,WDE);               //Enable
            break;
        case 7:
            WDTCR |= ARG_u8PeriodWDT;       //Set prescalar
            SET_BIT(WDTCR,WDE);               //Enable
            break;
    }
}

/*
1. In the same operation, write a logic one to WDTOE and WDE. A logic one must be written to WDE even though it is set to one before the disable operation starts.
2. Within the next four clock cycles, write a logic 0 to WDE. This disables the Watchdog.
*/

void MWDT_voidDisableWDT(void)
{
    WDTCR |= 0b00011000;
    CLEAR_BIT(WDTCR,WDE);
}