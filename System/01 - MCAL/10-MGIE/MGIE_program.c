/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : GIE					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	March 12, 2022		*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MGIE_private.h"
#include "MGIE_interface.h"

void MGIE_voidEnableGI(void)
{
	SET_BIT(SREG, IBIT);
}

void MGIE_voidDisableGI(void)
{
	CLEAR_BIT(SREG, IBIT);
}