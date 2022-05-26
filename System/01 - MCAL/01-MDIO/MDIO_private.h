/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : DIO                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : February 4, 2022     */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_

typedef struct
{
    u8 PIN;
    u8 DDR;
    u8 PORT;

} GPIO_Type;


#define GPIOA ((volatile GPIO_Type*)0x39)
#define GPIOB ((volatile GPIO_Type*)0x36)
#define GPIOC ((volatile GPIO_Type*)0x33)
#define GPIOD ((volatile GPIO_Type*)0x30)



#endif