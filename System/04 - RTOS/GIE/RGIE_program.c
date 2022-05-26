/************************************/
/*	Author	  : Shady Ahmad			*/
/*	SWC		  : GIE 				*/
/*  Layer	  : RTOS Stack			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 9, 2022         */
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "RGIE_private.h"
#include "RGIE_interface.h"

void RGIE_voidEnableGI(void)
{
	SET_BIT(SREG, IBIT);
}

void RGIE_voidDisableGI(void)
{
	CLEAR_BIT(SREG, IBIT);
}