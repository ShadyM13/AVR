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

void RTOS_voidCreateTask( u8 ARG_u8Priority, u16 ARG_u16Periodicity, void (*ARG_pvTaskFunc)(void) )
{
    SystemTasks[ARG_u8Priority].Periodicity = ARG_u16Periodicity;
    SystemTasks[ARG_u8Priority].TaskFunc = ARG_pvTaskFunc;
}

void voidScheduler(void)
{
    static u16 Local_u16TickCounter=0;
    u8 Local_u8TaskCounter;

    Local_u16TickCounter++;

    /*loop on all tasks to check their periodicity*/
    for(Local_u8TaskCounter=0; Local_u8TaskCounter<TASK_NUM; Local_u8TaskCounter++)
    {
        if((Local_u16TickCounter % SystemTasks[Local_u8TaskCounter].Periodicity)==0 )
        {
            /*Invoke the task function*/
            if(SystemTasks[Local_u8TaskCounter].TaskFunc != 0)
            {
                SystemTasks[Local_u8TaskCounter].TaskFunc();
            }
            else
            {
                //Do nothing
            }
        }
    }
}
