/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : DIO                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : February 8, 2022     */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#define MDIO_PORTA 0
#define MDIO_PORTB 1
#define MDIO_PORTC 2
#define MDIO_PORTD 3

#define MDIO_LOW    0
#define MDIO_HIGH   1

#define MDIO_OUTPUT 1
#define MDIO_INPUT  0

//Functions prototype for controlling the whole PORTS

void MDIO_voidSetPortDirection(u8 ARG_u8Port, u8 ARG_u8Direction);
void MDIO_voidSetPortValue(u8 ARG_u8Port, u8 ARG_u8Value);
u8   MDIO_u8GetPortValue(u8 ARG_u8Port);

//Functions prototype for controlling a Specific PIN

void MDIO_voidSetPinDirection(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Direction);
void MDIO_voidSetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin, u8 ARG_u8Value);
u8 MDIO_u8GetPinValue(u8 ARG_u8Port, u8 ARG_u8Pin);


#endif _MDIO_INTERFACE_H_