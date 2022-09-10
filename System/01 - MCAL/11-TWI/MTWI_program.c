/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : TWI                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : June  16, 2022       */
/*       Last Edit  : N/A                  */
/*******************************************/

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MTWI_config.h"
#include "MTWI_private.h"
#include "MTWI_interface.h"

void MTWI_voidMasterInit(u8 ARG_u8Address)
{
    //Set Clock frequency to 400kbps
    //Set TWBR to 2, part of clock calculation formula 
    TWDR = 2;

    //Clear the 2 bits of TWSR, part of clock calculation formula 
    CLEAR_BIT(TWSR, TWSR_TWPS0);
    CLEAR_BIT(TWSR, TWSR_TWPS1);  

    //Set Address to Master
    if(ARG_u8Address != 0)
    {
        TWAR = (ARG_u8Address<<1);      //shift to 7 MSB
    }

    //Enable TWI
    SET_BIT(TWCR, TWCR_TWEN);

}    

void MTWI_voidSlaveInit(u8 ARG_u8Address)
{
    //Initiallize the slave address
    TWAR = (ARG_u8Address<<1);

    //Enable TWI
    SET_BIT(TWCR, TWCR_TWEN);
}

TWI_ErrStatus MTWI_SendStartCondition(void)
{
    TWI_ErrStatus Local_ErrStatus = NoError;

    //Send start condition on the bus
    SET_BIT(TWCR, TWCR_TWSTA);

    //Clear the intterupt flag to start performing the previous operation
    SET_BIT(TWCR, TWCR_TWINT);

    //wait until the intterupt flag TWINT is raised again (end of operation)
    while(1 != (GET_BIT(TWCR,TWCR_TWINT)));

    if((TWSR & 0xF8) != START_ACK)
    {
        Local_ErrStatus = StartConditionErr;
    }
    else
    {
        //Do nothing
    }

    return Local_ErrStatus;
}

TWI_ErrStatus MTWI_SendRepeatedStart(void)
{
    TWI_ErrStatus Local_ErrStatus = NoError;

    //Send start condition on the bus
    SET_BIT(TWCR, TWCR_TWSTA);

    //Clear the intterupt flag to start performing the previous operation
    SET_BIT(TWCR, TWCR_TWINT);

    //wait until the intterupt flag TWINT is raised again (end of operation)
    while(1 != (GET_BIT(TWCR,TWCR_TWINT)));

    if((TWSR & 0xF8) != REP_START_ACK)
    {
        Local_ErrStatus = RepeatedStartErr;
    }
    else
    {
        //Do nothing
    }

    return Local_ErrStatus;
}

TWI_ErrStatus MTWI_SendSlaveAddressWithWrite(u8 ARG_u8SlaveAddress)
{
    TWI_ErrStatus Local_ErrStatus = NoError;
    //Clear the start condition bit
    CLEAR_BIT(TWCR, TWCR_TWSTA);

    //Set Slave address in 7 MSB, Clear Bit 0 to Write
    TWDR = ARG_u8SlaveAddress << 1;
    CLEAR_BIT(TWDR, 0);                //Write request

    //Clear the intterupt flag to start performing the previous operation
    SET_BIT(TWCR, TWCR_TWINT);

    //wait until the intterupt flag TWINT is raised again (end of operation)
    while(1 != (GET_BIT(TWCR,TWCR_TWINT)));

    if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
    {
        Local_ErrStatus = SlaveAddressWithWriteErr;
    }
    else
    {
        //Do nothing
    }

    return Local_ErrStatus;
}

TWI_ErrStatus MTWI_SendSlaveAddressWithRead(u8 ARG_u8SlaveAddress)
{
    TWI_ErrStatus Local_ErrStatus = NoError;
    //Clear the start condition bit
    CLEAR_BIT(TWCR, TWCR_TWSTA);

    //Set Slave address in 7 MSB, Clear Bit 1 to Read
    TWDR = ARG_u8SlaveAddress << 1;
    SET_BIT(TWDR, 0);                //Read request

    //Clear the intterupt flag to start performing the previous operation
    SET_BIT(TWCR, TWCR_TWINT);

    //wait until the intterupt flag TWINT is raised again (end of operation)
    while(1 != (GET_BIT(TWCR,TWCR_TWINT)));

    if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
    {
        Local_ErrStatus = SlaveAddressWithReadErr;
    }
    else
    {
        //Do nothing
    }

    return Local_ErrStatus;
}

TWI_ErrStatus MTWI_MasterWriteDataByte(u8 ARG_u8DataByte)
{
    TWI_ErrStatus Local_ErrStatus = NoError;
    
    //Write the data byte
    TWDR = ARG_u8DataByte;

    //Clear the intterupt flag to start performing the previous operation
    SET_BIT(TWCR, TWCR_TWINT);

    //wait until the intterupt flag TWINT is raised again (end of operation)
    while(1 != (GET_BIT(TWCR,TWCR_TWINT)));

    if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
    {
        Local_ErrStatus = MasterWriteByteErr;
    }
    else
    {
        //Do nothing
    }

    return Local_ErrStatus;
}

TWI_ErrStatus MTWI_MasterReadDataByte(u8* ARG_pu8DataByte)
{
    TWI_ErrStatus Local_ErrStatus = NoError;

    //Enable Master generating ACK Bit after recieving the data
    SET_BIT(TWCR,TWCR_TWEA);
    
    //Clear the intterupt flag to start slave sending data
    SET_BIT(TWCR, TWCR_TWINT);

    //wait until the intterupt flag TWINT is raised again (end of operation)
    while(1 != (GET_BIT(TWCR,TWCR_TWINT)));

    if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
    {
        Local_ErrStatus = MasterReadByteErr;
    }
    else
    {
        //Read the recieved data
        *ARG_pu8DataByte = TWDR;
    }

    return Local_ErrStatus;
}

void MTWI_SendStopCondition(void)
{
    //Generate stop condition
    SET_BIT(TWCR, TWCR_TWSTO);

    //Clear the intterupt flag to start previous operation
    SET_BIT(TWCR, TWCR_TWINT);
}

//Write the data byte
    *ARG_pu8DataByte = TWDR;
