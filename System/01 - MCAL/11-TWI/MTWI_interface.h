/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : TWI                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : June  16, 2022       */
/*       Last Edit  : N/A                  */
/*******************************************/


#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_

typedef enum
{
    NoError,
    StartConditionErr,
    RepeatedStartErr,
    SlaveAddressWithWriteErr,
    SlaveAddressWithReadErr,
    MasterWriteByteErr,
    MasterReadByteErr

}TWI_ErrStatus;

void MTWI_voidMasterInit(u8 ARG_u8Address);  //pass 0 if Master will not be adressed
void MTWI_voidSlaveInit(u8 ARG_u8Address);

TWI_ErrStatus MTWI_SendStartCondition(void);
TWI_ErrStatus MTWI_SendRepeatedStart(void);

TWI_ErrStatus MTWI_SendSlaveAddressWithWrite(u8 ARG_u8SlaveAddress);
TWI_ErrStatus MTWI_SendSlaveAddressWithRead(u8 ARG_u8SlaveAddress);

TWI_ErrStatus MTWI_MasterWriteDataByte(u8 ARG_u8DataByte);
TWI_ErrStatus MTWI_MasterReadDataByte(u8* ARG_pu8DataByte);

void MTWI_SendStopCondition(void);




#endif