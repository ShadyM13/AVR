/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : ADC                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : February 28, 2022    */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_

#define     ((volatile u8*)0x27)
#define ADCSRA_Reg  ((volatile u8*)0x26)
#define SFIOR_Reg   ((volatile u8*)0x50)
#define ADCL_Reg    ((volatile u8*)0x24)
#define ADCH_Reg    ((volatile u8*)0x25)

#define ADCLH_Reg   ((volatile u16*)0x24)       // u16 will read the value of the two registers 0x24 and 0x25   only incase ADLAR = 0

#endif /*_MADC_PRIVATE_H_*/