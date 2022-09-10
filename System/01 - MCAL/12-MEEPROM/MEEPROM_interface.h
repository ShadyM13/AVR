/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : EEPROM               */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : June 19, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef     _MEEPROM_INTERFACE_H_
#define     _MEEPROM_INTERFACE_H_

void MEEPROM_VoidWriteDataByte(u8 SlaveAddress , u8 InternalReg, u8 Data);

u8 MEEPROM_u8ReadDataByte(u8 SlaveAddress , u8 InternalReg);


#endif