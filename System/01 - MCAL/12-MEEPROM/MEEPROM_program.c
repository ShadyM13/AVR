/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : EEPROM               */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : June 19, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MTWI_interface.h"
#include "MEEPROM_interface.h"
#include "MEEPROM_private.h"
#include "MEEPROM_config.h"


void MEEPROM_VoidWriteDataByte(u16 SlaveAddress , u8 Data)
{
    //Send start condition
    MTWI_SendStartCondition();

    //Send Slave Address
    MTWI_SendSlaveAddressWithWrite(1010 | EEPROM_A2_VALUE<<2 | SlaveAddress>>8);
    MTWI_MasterWriteDataByte((u8)SlaveAddress);

    //Send Data
    MTWI_MasterWriteDataByte(Data);

    //Send stop condition
    MTWI_SendStopCondition();
}

void MEEPROM_u8ReadDataByte(u16 SlaveAddress , u8* ptr)
{
    //Send start condition
    MTWI_SendStartCondition();

    //Send Slave Address
    MTWI_SendSlaveAddressWithWrite(1010 | EEPROM_A2_VALUE<<2 | SlaveAddress>>8);
    MTWI_MasterWriteDataByte((u8)SlaveAddress);

    //Send repeat start condition to read
    MTWI_SendRepeatedStart();

    //Send slave address with read
    MTWI_SendSlaveAddressWithRead(ptr);

    //Send stop condition
    MTWI_SendStopCondition();
}