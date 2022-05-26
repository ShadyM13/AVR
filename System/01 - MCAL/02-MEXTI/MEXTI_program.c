/************************************/
/*	Author	  :	Omar Morsy			*/
/*	SWC		  : EXTI				*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	March 12, 2022		*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MEXTI_private.h"
#include "MEXTI_interface.h"

void (*MEXTI_pvoidUserFunctionINT0)(void) = 0;
void (*MEXTI_pvoidUserFunctionINT1)(void) = 0;
void (*MEXTI_pvoidUserFunctionINT2)(void) = 0;

void MEXTI_voidInit(u8 ARG_u8InterruptNumber, u8 ARG_u8Mode)
{
    switch(ARG_u8InterruptNumber)
    {
        case MEXTI_INT0:
            switch(ARG_u8Mode)
            {
                case MEXTI_MODE_LOW:
                    CLEAR_BIT(MCUCR,ISC00);
                    CLEAR_BIT(MCUCR,ISC01);
                    break;
                case MEXTI_MODE_IOC:
                    SET_BIT(MCUCR,ISC00);
                    CLEAR_BIT(MCUCR,ISC01);
                    break;
                case MEXTI_MODE_FALLING:
                    CLEAR_BIT(MCUCR,ISC00);
                    SET_BIT(MCUCR,ISC01);
                    break;
                case MEXTI_MODE_RISING:
                    SET_BIT(MCUCR,ISC00);
                    SET_BIT(MCUCR,ISC01);
                    break;
                default:
                    break;
            }
            break;

        case MEXTI_INT1:
            switch(ARG_u8Mode)
            {
                case MEXTI_MODE_LOW:
                    CLEAR_BIT(MCUCR,ISC10);
                    CLEAR_BIT(MCUCR,ISC11);
                    break;
                case MEXTI_MODE_IOC:
                    SET_BIT(MCUCR,ISC10);
                    CLEAR_BIT(MCUCR,ISC11);
                    break;
                case MEXTI_MODE_FALLING:
                    CLEAR_BIT(MCUCR,ISC10);
                    SET_BIT(MCUCR,ISC11);
                    break;
                case MEXTI_MODE_RISING:
                    SET_BIT(MCUCR,ISC10);
                    SET_BIT(MCUCR,ISC11);
                    break;
                default:
                    break;
            }

            break;

        case MEXTI_INT2:
            switch(ARG_u8Mode)
            {
                case MEXTI_MODE_FALLING:
                    CLEAR_BIT(MCUCSR,ISC2);
                    break;
                case MEXTI_MODE_RISING:
                    SET_BIT(MCUCSR,ISC2);
                    break;
                default:
                    break;
            }

            break;

        default:
            break;
    }
}

void MEXTI_voidEnableInterrupt(u8 ARG_u8InterruptNumber)
{
	SET_BIT(GICR, ARG_u8InterruptNumber);
}

void MEXTI_voidDisableInterrupt(u8 ARG_u8InterruptNumber)
{
	CLEAR_BIT(GICR, ARG_u8InterruptNumber);
}



//____________________________________________________________________________________
void MEXTI_voidSetCallBackINT0(void (*ARG_pvoidfUserFunctionINT0)(void))
{
	MEXTI_pvoidUserFunctionINT0 = ARG_pvoidfUserFunctionINT0;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	(*MEXTI_pvoidUserFunctionINT0)();
}
//____________________________________________________________________________________




//____________________________________________________________________________________
void MEXTI_voidSetCallBackINT1(void (*ARG_pvoidfUserFunctionINT1)(void))
{
	MEXTI_pvoidUserFunctionINT1 = ARG_pvoidfUserFunctionINT1;
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	(*MEXTI_pvoidUserFunctionINT1)();
}
//____________________________________________________________________________________




//____________________________________________________________________________________
void MEXTI_voidSetCallBackINT2(void (*ARG_pvoidfUserFunctionINT2)(void))
{
	MEXTI_pvoidUserFunctionINT2 = ARG_pvoidfUserFunctionINT2;
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	(*MEXTI_pvoidUserFunctionINT2)();
}
//____________________________________________________________________________________