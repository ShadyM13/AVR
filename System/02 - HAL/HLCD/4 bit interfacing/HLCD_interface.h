/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : LCD                  */
/*       Layer      : HAL                  */
/*       Version    : 1.0                  */
/*       Date       : February 14, 2022    */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _HLCD_INTERFACE_H_
#define _HLCD_INTERFACE_H_

#define     HLCD_DATA_PORT      MDIO_PORTA
#define     HLCD_CTRL_PORT      MDIO_PORTB
#define     HLCD_RS_PIN         0
#define     HLCD_EN_PIN         1
#define     HLCD_RW_PIN         2


void HLCD_voidSendCommand(u8 ARG_u8Command);
void HLCD_voidSendChar(u8 ARG_u8Character);
void HLCD_voidInit(void);
void HLCD_voidSendString (u8 *str);
void HLCD_voidClear(void);
void HLCD_voidSendString_xy (u8 row, u8 col, u8 *str);
void HLCD_voidSetPosition (u8 row, u8 col);
void HLCD_voidWriteStringExtended (u8* str, u8 row, u8 col);
void HLCD_voidStoreCustomChar(u8* patten,u8 CGRAM_index);
void HLCD_voidDisplayCustomChar (u8 CGRAM_index, u8row, u8 col);




#endif   /* _HLCD_INTERFACE_H_ */
