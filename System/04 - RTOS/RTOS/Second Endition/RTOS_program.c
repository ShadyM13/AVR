/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : RTOS Stack 			*/
/*  Layer	  : RTOS    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 3, 2022  		*/
/************************************/

#include "LSTD_types.h"

#include "RTIMER_interface.h"
#include "RGIE_interface.h"

#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"

Task_type SystemTasks[TASK_NUM] = {{0,0,0}, {0,0,0}, {0,0,0}};

void RTOS_voidStart(void)
{
	RTIMER_voidSetCallBack(&voidScheduler);
    RGIE_voidEnableGI();
    RTIMER_voidInit();

}

u8 RTOS_voidCreateTask( u8 ARG_u8Priority, u16 ARG_u16Periodicity, void (*ARG_pvTaskFunc)(void), u16 ARG_u16FirstDelay )
{
    u8 Local_u8ErrorState = OK;

    /*Check if the required priority is empty or used before for another task*/
    if(SystemTasks[ARG_u8Priority].TaskFunc == 0)
    {
        SystemTasks[ARG_u8Priority].Periodicity = ARG_u16Periodicity;
        SystemTasks[ARG_u8Priority].TaskFunc = ARG_pvTaskFunc;
        SystemTasks[ARG_u8Priority].State = TASK_RESUMED;       //Initialize the task state
        SystemTasks[ARG_u8Priority].FirstDelay = ARG_u16FirstDelay;
    }
    else
    {
        /*Priority is reserved before, don't create the task*/
        u8 Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

static void voidScheduler(void)
{
    u8 Local_u8TaskCounter;

    /*loop on all tasks to check their periodicity*/
    for(Local_u8TaskCounter=0; Local_u8TaskCounter<TASK_NUM; Local_u8TaskCounter++)
    {
        /*Check if the task is suspended or not*/
        if(SystemTasks[Local_u8TaskCounter].State = TASK_RESUMED)
        {
            if(SystemTasks[Local_u8TaskCounter].FirstDelay == 0 )
            {
                /*Invoke the task function*/
                if(SystemTasks[Local_u8TaskCounter].TaskFunc != 0)
                {
                    SystemTasks[Local_u8TaskCounter].TaskFunc();
                    /* Assign the first delay parameter to the periodicity*/
                    SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity -1 ;
                }
                else
                {
                    /*Decrement the first delay*/
                    SystemTasks[Local_u8TaskCounter].FirstDelay--;
                }
            }
        }
        else
        {
            /*Task is suspended, do nothing*/
        }

    }
}

void RTOS_voidSuspendTask(u8 ARG_u8Priority)
{
    SystemTasks[ARG_u8Priority].State = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 ARG_u8Priority)
{
    SystemTasks[ARG_u8Priority].State = TASK_RESUMED;
}

void RTOS_voidDeleteTask(u8 ARG_u8Priority)
{
    SystemTasks[ARG_u8Priority].TaskFunc = 0;
}
