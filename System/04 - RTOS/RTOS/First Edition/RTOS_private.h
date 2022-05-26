/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : RTOS Stack 			*/
/*  Layer	  : RTOS    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 3, 2022  		*/
/************************************/

#ifndef     RTOS_PRIVATE_H_
#define     RTOS_PRIVATE_H_



typedef struct
{
    u16 Periodicity;
    void (*TaskFunc) (void);
}Task_type;

static void voidScheduler(void);

#endif
