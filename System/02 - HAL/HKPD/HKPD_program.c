/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : KPD                  */
/*       Layer      : HAL                  */
/*       Version    : 1.0                  */
/*       Date       : February 18, 2022    */
/*       Last Edit  : N/A                  */
/*******************************************/


#define F_CPU 8000000UL
#include <util/delay.h>

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_interface.h"

#include "HLCD_interface.h"
#include "HLCD_config.h"

#include "HKPD_interface.h"
#include "HKPD_config.h"

u8 ARG_u8Col, ARG_u8Row;
u8 ARG_u8PressedKey;

u8 HKPD_u8KeypadButtons [4][4] = {	{'7','8','9','+'},
									{'4','5','6','-'},
									{'1','2','3','*'},
									{'F','0','=','/'}};          // F -> Clear Function



u8 HKPD_u8GetPressedKey (void)
{
	u8 L_u8Cols;
	u8 L_u8Rows;

	MDIO_voidSetPortDirection(HKPD_KEYPAD_PORT, 0xF0);          //Columns: B7 - B4,   Rows: B3 - B0
	MDIO_voidSetPortValue(HKPD_KEYPAD_PORT, 0x0F);				//Columns = 0b0000 ,   Rows: Pullup

	do
	{
		L_u8Rows = MDIO_u8GetPortValue(HKPD_KEYPAD_PORT);
	}while(0x0F == L_u8Rows);

	MDIO_voidSetPortDirection(HKPD_KEYPAD_PORT, 0x0F);			//Columns: B3 - B0,   Rows: B7 - B4
	MDIO_voidSetPortValue(HKPD_KEYPAD_PORT, 0xF0);				//Columns: Pullup ,   Rows = 0b0000


	L_u8Cols = MDIO_u8GetPortValue(MDIO_PORTC);
	L_u8Cols >>= 4;												//Shifting the 4 bits to the proper position

	L_u8Rows = HKPD_u8AdjustValue(L_u8Rows);
	L_u8Cols = HKPD_u8AdjustValue(L_u8Cols);


	return HKPD_u8KeypadButtons[L_u8Rows][L_u8Cols];
}


inline u8 HKPD_u8AdjustValue(u8 ARG_u8Value)
{
	switch(ARG_u8Value)
		{	case 0b1110: ARG_u8Value = 0;	break;
			case 0b1101: ARG_u8Value = 1;	break;
			case 0b1011: ARG_u8Value = 2;	break;
			case 0b0111: ARG_u8Value = 3;	break;
			default:	 ARG_u8Value = 4;	break;
		}
	return ARG_u8Value;
}
