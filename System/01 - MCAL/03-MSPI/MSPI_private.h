/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : MSPI    			*/
/*  Layer	  : MUSART    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	may 3, 2022  		*/
/************************************/

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_


#define     SPDR            *((volatile *u8)0x2F)      //SPI Data register


#define     SPSR            *((volatile *u8)0x2E)      //SPI Status register
#define     SPSR_SPIF       7                          //SPI interrupt flag
#define     SPSR_SPI2X      0                          ////prescalar bit 2


#define     SPCR            *((volatile *u8)0x2D)      //SPI control register
#define     SPCR_SPE        6                          //SPI enable
#define     SPCR_MSTR       4                          //Master bit
#define     SPCR_SPR1       1                          //prescalar bit 1
#define     SPCR_SPR0       0                          //prescalar bit 0


#endif
