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

void HLCD_voidSendCommand( u8 ARG_u8Command);
void HLCD_voidSendChar( u8 ARG_u8Character);
void HLCD_voidInit(void);
void HLCD_voidSendString (const char* ARG_pcStr);
void HLCD_voidClear(void);
void HLCD_voidSendString_xy (u8 ARG_u8row, u8 ARG_u8col, const char* ARG_pcStr);
void HLCD_voidSetPosition (u8 ARG_u8row, u8 ARG_u8col);
void HLCD_voidWriteStringExtended (u8 ARG_u8row, u8 ARG_u8col,const char* ARG_pcStr);
void HLCD_voidStoreCustomChar(u8* pattern,u8 CGRAM_index);
void HLCD_voidDisplayCustomChar (u8 CGRAM_index, u8 ARG_u8row, u8 ARG_u8col);
void HLCD_voidReverseString ( char ARG_charstr[], int ARG_u32length);
void HLCD_voidSendIntNumber(int ARG_u32num, char* ARG_pcstr, int ARG_u32base);


#endif   /* _HLCD_INTERFACE_H_ */
