/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : ADC                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : February 28, 2022    */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _MADC_CONFIG_H_
#define _MADC_CONFIG_H_

/*
Configure the voltage referance
Range:
MADC_VOLTAGE_REF_AVCC
MADC_VOLTAGE_REF_AREF
MADC_VOLTAGE_REF_2_56v
*/

#define     MADC_VOLTAGE_REF_SELECTOR_msk    MADC_VOLTAGEREF_AVCC
//------------------------------------------------------------------

#define     MADC_VOLTAGE_REF_mv              5000
#define     MADC_MAX_NUMBER_OF_STEPS         1024

/*
Configure the ADC Mode
Range:
MADC_MODE_AUTO_TRIGGER
MADC_MODE_SINGLE_CONVERSION
*/
#define     MADC_MODE_SELECTOR               MADC_MODE_AUTO_TRIGGER
//------------------------------------------------------------------

/*
Configure the ADC Adjustment
Range:
MADC_RIGHT_ADJUST
MADC_LEFT_ADJUST
*/
#define     MADC_ADJUSTMENT_SELECTOR        MADC_RIGHT_ADJUST
//------------------------------------------------------------------

/*
Configure the ADC PRESCALER
Range:
MADC_PRESCALER_clr_msk
MADC_PRESCALER_2_msk
MADC_PRESCALER_4_msk
MADC_PRESCALER_8_msk
MADC_PRESCALER_16_msk
MADC_PRESCALER_32_msk
MADC_PRESCALER_64_msk
MADC_PRESCALER_128_msk
*/
#define     MADC_PRESCLAER_SELECTOR         MADC_PRESCALER_128_msk
//------------------------------------------------------------------
/*
Configure the ADC Trigger source
Range:

MADC_AUTO_TRIG_SRC_clr_msk
MADC_AUTO_TRIG_SRC_FREE_RUNNING_msk
MADC_AUTO_TRIG_SRC_ANALOG_COMP_msk
MADC_AUTO_TRIG_SRC_EXTI0_msk
MADC_AUTO_TRIG_SRC_TIMER0_COMP_msk
MADC_AUTO_TRIG_SRC_TIMER0_OVF_msk
MADC_AUTO_TRIG_SRC_TIMER1_COMP_msk
MADC_AUTO_TRIG_SRC_TIMER1_OVF_msk
MADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk
*/

#define     MADC_AUTO_TRIG_SRCE_SELECTOR    MADC_AUTO_TRIG_SRC_FREE_RUNNING_msk
//------------------------------------------------------------------
#endif /*_MADC_CONFIG_H_*/