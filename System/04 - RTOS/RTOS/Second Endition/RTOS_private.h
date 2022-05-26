/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : RTOS Stack 			*/
/*  Layer	  : RTOS    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 3, 2022  		*/
/************************************/

#ifndef     RTOS_PRIVATE_H_
#define     RTOS_PRIVATE_H_

#define TASK_RESUMED    0
#define TASK_SUSPENDED  1

typedef struct
{
    u16 Periodicity;
    void (*TaskFunc) (void);
    u8 State;
    u16 FirstDelay;
}Task_type;

static void voidScheduler(void);

#endif
