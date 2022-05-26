/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : DIO                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : February 8, 2022     */
/*       Last Edit  : N/A                  */
/*******************************************/

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_private.h"
#include "MDIO_interface.h"




//Functions Implementations for controlling the whole PORTS

void MDIO_voidSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction)


{
    switch(ARG_u8Port)
    {
        case MDIO_PORTA:
            GPIOA -> DDR = ARG_u8Direction;
            break;

        case MDIO_PORTB:
            GPIOB -> DDR = ARG_u8Direction;
            break;

        case MDIO_PORTC:
            GPIOC -> DDR = ARG_u8Direction;
            break;

        case MDIO_PORTD:
            GPIOD -> DDR = ARG_u8Direction;
            break;
    
        default:
            //report an Error
            break;
    }
}

void MDIO_voidSetPortValue(u8 ARG_u8Port, u8 ARG_u8Value)
{
    switch (ARG_u8Port)
    {
        case MDIO_PORTA:
            GPIOA -> PORT = ARG_u8Value;
            break;

        case MDIO_PORTB:
            GPIOB -> PORT = ARG_u8Value;
            break;

        case MDIO_PORTC:
            GPIOC -> PORT = ARG_u8Value;
            break;

        case MDIO_PORTD:
            GPIOD -> PORT = ARG_u8Value;
            break;
    
        default:
            //report an Error
            break;
    }
}

u8   MDIO_u8GetPortValue(u8 ARG_u8Port)
{
	u8 L_u8ReturnValue;
    switch (ARG_u8Port)
    {


        case MDIO_PORTA:
            L_u8ReturnValue = GPIOA -> PIN; 
            break;

        case MDIO_PORTB:
            L_u8ReturnValue = GPIOB -> PIN; 
            break;

        case MDIO_PORTC:
            L_u8ReturnValue = GPIOC -> PIN; 
            break;

        case MDIO_PORTD:
            L_u8ReturnValue = GPIOD -> PIN; 
            break;
    
        default:
            //Report an Error
            L_u8ReturnValue = 0;
            break;
    }
    return L_u8ReturnValue;
}


/////////////////////Functions Implementations for controlling a Specific PIN////////////////////


void MDIO_voidSetPinDirection(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Direction)
{
    if (ARG_u8Pin >=0 && ARG_u8Pin <=7)
    {
        switch(ARG_u8Port)
        {
            case MDIO_PORTA:
                if(ARG_u8Direction == MDIO_OUTPUT)
                {
                    SET_BIT(GPIOA -> DDR, ARG_u8Pin);
                }
                if(ARG_u8Direction == MDIO_INPUT)
                {
                    CLEAR_BIT(GPIOA -> DDR, ARG_u8Pin);
                }
                else
                {
                    //report error
                }
                break;

            case MDIO_PORTB:
                if(ARG_u8Direction == MDIO_OUTPUT)
                {
                    SET_BIT(GPIOB -> DDR, ARG_u8Pin);
                }
                if(ARG_u8Direction == MDIO_INPUT)
                {
                    CLEAR_BIT(GPIOB -> DDR, ARG_u8Pin);
                }
                else
                {
                    //report error
                }
                break;

            case MDIO_PORTC:
                if(ARG_u8Direction == MDIO_OUTPUT)
                {
                    SET_BIT(GPIOC -> DDR, ARG_u8Pin);
                }
                if(ARG_u8Direction == MDIO_INPUT)
                {
                    CLEAR_BIT(GPIOC -> DDR, ARG_u8Pin);
                }
                else
                {
                    //report error
                }
                break;

            case MDIO_PORTD:
                if(ARG_u8Direction == MDIO_OUTPUT)
                {
                    SET_BIT(GPIOD -> DDR, ARG_u8Pin);
                }
                if(ARG_u8Direction == MDIO_INPUT)
                {
                    CLEAR_BIT(GPIOD -> DDR, ARG_u8Pin);
                }
                else
                {
                    //report error
                }
                break;

            default:
                //report an Error
                break;
        }
    }
    else
    {
        //report error
    }
}

void MDIO_voidSetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Value)
{
    if (ARG_u8Pin >=0 && ARG_u8Pin <=7)
    {
        switch(ARG_u8Port)
        {
            case MDIO_PORTA:
                if(ARG_u8Value == MDIO_HIGH)
                {
                    SET_BIT(GPIOA -> PORT, ARG_u8Pin);
                }
                if(ARG_u8Value == MDIO_LOW)
                {
                    CLEAR_BIT(GPIOA -> PORT, ARG_u8Pin);
                }
                else
                {
                    //report error
                }
                break;

            case MDIO_PORTB:
                if(ARG_u8Value == MDIO_HIGH)
                {
                    SET_BIT(GPIOB -> PORT, ARG_u8Pin);
                }
                if(ARG_u8Value == MDIO_LOW)
                {
                    CLEAR_BIT(GPIOB -> PORT, ARG_u8Pin);
                }
                else
                {
                    //report error
                }
                break;

            case MDIO_PORTC:
                if(ARG_u8Value == MDIO_HIGH)
                {
                    SET_BIT(GPIOC -> PORT, ARG_u8Pin);
                }
                if(ARG_u8Value == MDIO_LOW)
                {
                    CLEAR_BIT(GPIOC -> PORT, ARG_u8Pin);
                }
                else
                {
                    //report error
                }
                break;

            case MDIO_PORTD:
                if(ARG_u8Value == MDIO_HIGH)
                {
                    SET_BIT(GPIOD -> PORT, ARG_u8Pin);
                }
                if(ARG_u8Value == MDIO_LOW)
                {
                    CLEAR_BIT(GPIOD -> PORT, ARG_u8Pin);
                }
                else
                {
                    //report error
                }
                break;

            default:
                //report an Error
                break;
        }
    }
    else
    {
        //report error
    }
}

u8 MDIO_u8GetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin)
{
    u8 L_u8ReturnValue;
    if(ARG_u8Pin >=0 && ARG_u8Pin <=7)
    {
        switch (ARG_u8Port)

        {
            case MDIO_PORTA:
                L_u8ReturnValue = GET_BIT(GPIOA -> PIN, ARG_u8Pin);
                break;

            case MDIO_PORTB:
                L_u8ReturnValue = GET_BIT(GPIOB -> PIN, ARG_u8Pin);
                break;

            case MDIO_PORTC:
                L_u8ReturnValue = GET_BIT(GPIOC -> PIN, ARG_u8Pin);
                break;

            case MDIO_PORTD:
                L_u8ReturnValue = GET_BIT(GPIOD -> PIN, ARG_u8Pin);
                break;
        
            default:
                //Report an Error
                L_u8ReturnValue = 0;
                break;
        }
    }
    return L_u8ReturnValue;
}
