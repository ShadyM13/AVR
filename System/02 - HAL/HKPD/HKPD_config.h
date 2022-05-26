/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        :                      */
/*       Layer      :                      */
/*       Version    : 1.0                  */
/*       Date       :                      */
/*       Last Edit  : N/A                  */
/*******************************************/
#ifndef HKPD_CONFIG_H_
#define HKPD_CONFIG_H_

#define HKPD_KEYPAD_PORT	MDIO_PORTC

#define HKPD_VALUE_ADJUST(Val)   	do													\
										switch(Val)										\
										{	case 0b1110: Val = 0;	break;				\
											case 0b1101: Val = 1;	break;				\
											case 0b1011: Val = 2;	break;				\
											case 0b0111: Val = 3;	break;				\
											default:	 Val = 4;	break;				\
										}												\
										}while(0);

u8 HKPD_u8AdjustValue(u8 ARG_u8Value);

#endif /* HKPD_CONFIG_H_ */
