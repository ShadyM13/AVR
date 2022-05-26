/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : MSPI    			*/
/*  Layer	  : MUSART    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 3, 2022  		*/
/************************************/

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

void MSPI_voidInitMaster(void);

void MSPI_voidInitSlave(void);

u8   MSPI_u8Transceive(u8 ARG_u8Data);


#endif
