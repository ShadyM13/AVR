/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : MSPI    			*/
/*  Layer	  : MUSART    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 3, 2022  		*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"


#include "MSPI_config.h"
#include "MSPI_interface.h"
#include "MSPI_private.h"


void MSPI_voidInitMaster(void)
{
    //Prescalar select
    SET_BIT(SPCR,SPCR_SPR0);
    CLEAR_BIT(SPCR,SPCR_SPR1);
    CLEAR_BIT(SPSR,SPSR_SPI2X);

    //SPI MASTER SELECT
    SET_BIT(SPCR,SPCR_MSTR);

    //SPI ENABLE
    SET_BIT(SPCR,SPCR_SPE);
    
}

void MSPI_voidInitSlave(void)
{
    //SPI SLAVE  SELECT
    CLEAR_BIT(SPCR,SPCR_MSTR);
    //SPI ENABLE
    SET_BIT(SPCR,SPE);
}

u8   MSPI_u8Transceive(u8 ARG_u8Data)
{
    //Sending data by just writing in the SPDR data register
    SPDR = ARG_u8Data;
    
    //wait until transfare is complete by polling the SPIF flag
    while(GET_BIT(SPSR,SPSR_SPIF) == 0);

    //return data
    return SPDR; 
}