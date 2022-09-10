/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : TWI                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : June  16, 2022       */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef MTWI_PRIVATE_H_
#define MTWI_PRIVATE_H_


/*TWAR Register*/
#define TWAR_TWA6	7
#define TWAR_TWA5	6
#define TWAR_TWA4	5
#define TWAR_TWA3	4
#define TWAR_TWA2	3
#define TWAR_TWA1	2
#define TWAR_TWA0	1
#define TWAR_TWGCE	0

#define TWAR 		*((volatile u8*)0x22)

/*TWCR Register*/
#define TWCR_TWINT	7
#define TWCR_TWEA	6
#define TWCR_TWSTA	5
#define TWCR_TWSTO	4
#define TWCR_TWWC	3
#define TWCR_TWEN	2
#define TWCR_R2 		1
#define TWCR_TWIE	0

#define TWCR  		*((volatile u8*)0x56)

/*TWSR Register*/
#define TWSR_TWS7	7
#define TWSR_TWS6	6
#define TWSR_TWS5	5
#define TWSR_TWS4	4
#define TWSR_TWS3	3
#define TWSR_R 		2
#define TWSR_TWPS1	1
#define TWSR_TWPS0	0

#define TWSR 		*((volatile u8*)0x21)



#define TWBR 		*((volatile u8*)0x20)
#define TWDR 		*((volatile u8*)0x23)


// Status Codes for Master Transmitter Mode Definition page 183&186 in Data Sheet

#define START_ACK      	            0x08          //start has been sent
#define REP_START_ACK   	        0x10          //repeated start
#define SLAVE_ADD_AND_WR_ACK  	    0x18          //Master transimt (slave address + wrtite request) ACK    
#define SLAVE_ADD_AND_RD_ACK        0x40          //Master transimt (slave address + read request) ACK
#define MSTR_WR_BYTE_ACK  	        0x28          //Master transimit Data ACK
#define MSTR_RD_BYTE_WITH_ACK       0x50          //Master recieved data with ACK
#define MSTR_RD_BYTE_WITH_NACK      0x58          //Master recieved data with NOT ACK
#define SLAVE_ADD_RCVD_RD_REQ       0xA8          //means that slave address is recieved with read request
#define SLAVE_ADD_RCVD_WR_REQ       0x60          //means that slave address is recieved with write request
#define SLAVE_DATA_RECIEVED         0x80          //means that a byte is recieved
#define SLAVE_BYTE_TRANSMITTED      0xB8          //means that the written byte is transmitted

#define I2C_STATUS_CODE_MASK        0xF8

#define WRITE_MODE     0x00

#define READ_MODE     0x01


#define R_W             0



#endif