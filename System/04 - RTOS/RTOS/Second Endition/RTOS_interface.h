/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : RTOS Stack 			*/
/*  Layer	  : RTOS    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 3, 2022  		*/
/************************************/

#ifndef     RTOS_INTERFACE_H_
#define     RTOS_INTERFACE_H_

void RTOS_voidStart(void);

u8 RTOS_voidCreateTask( u8 ARG_u8Priority, u16 ARG_u16Periodicity, void (*ARG_pvTaskFunc)(void), u16 ARG_u16FirstDelay );

void RTOS_voidSuspendTask(u8 ARG_u8Priority);

void RTOS_voidResumeTask(u8 ARG_u8Priority);

void RTOS_voidDeleteTask(u8 ARG_u8Priority);


#endif
