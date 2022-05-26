/************************************/
/*	Author	  : Shady Ahmad			*/
/*	SWC		  : TIMERS				*/
/*  Layer	  : RTOS Stack			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 9, 2022         */
/************************************/

#ifndef RTIMER_INTERFACE_H_
#define RTIMER_INTERFACE_H_


#define RTIMER_PRESCALAR_0				0
#define RTIMER_PRESCALAR_1				1
#define RTIMER_PRESCALAR_8				2
#define RTIMER_PRESCALAR_64				3
#define RTIMER_PRESCALAR_256			4
#define RTIMER_PRESCALAR_1024			5
#define RTIMER_PRESCALAR_EXT_FALLING	6
#define RTIMER_PRESCALAR_EXT_RISING		7

#define RTIMER_INTERRUPT_T0_OCM			OCIE0

void RTIMER_voidInit(void);
void RTIMER_voidSetCallBack(void (*ARG_pvoidfUserFunction)(void));


#endif