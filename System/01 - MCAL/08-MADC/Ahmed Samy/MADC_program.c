/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : ADC                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : March 1, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MADC_interface.h"
#include "MADC_private.h"
#include "MADC_config.h"

//ADC Initializing
void  MADC_Init(void)
{
/**********Selecting voltage referance**********/
    ADMUX_Reg &= MADC_VOLTAGE_REF_msk;
    ADMUX_Reg |= MADC_VOLTAGE_REF_SELECTOR_msk;

/**************Selecting ADC Mode***************/
    #if      MADC_MODE_SELECTOR == MADC_MODE_AUTO_TRIGGER
                SET_BIT(ADCSRA_Reg,5);
                SFIOR_Reg &= MADC_AUTO_TRIG_SRC_clr_msk;
                SFIOR_Reg |= MADC_AUTO_TRIG_SRCE_SELECTOR;

    #elif    MADC_MODE_SELECTOR == MADC_MODE_SINGLE_CONVERSION
                CLEAR_BIT(ADCSRA_Reg,5);
    #endif


/*************Selecting Adjustment**************/
    #if     MADC_ADJUSTMENT_SELECTOR == MADC_RIGHT_ADJUST
                CLEAR_BIT(ADMUX_Reg,5);
        
    #elif   MADC_ADJUSTMENT_SELECTOR == MADC_LEFT_ADJUST
                SET_BIT(ADMUX_Reg,5);
    #endif


/************Clearing interrupt flag************/
    SET_BIT(ADCSRA_Reg,4);


/******************Enable ADC*******************/
    SET_BIT(ADCSRA_Reg,7);

}



//ADC Start Conversion
void  MADC_StartConversion(MADC_ChannelTypes ARG_MCTChannel)
{
    /*************Selecting ADC Channel**************/
    ADMUX_Reg &= MADC_CHANNEL_SELECTOR_clr_msk;
    ADMUX_Reg =| ARG_MCTChannel;

    /*************Selecting ADC Channel**************/
    SET_BIT(ADCSRA_Reg,6); 
}



u16   MADC_GetResult(void)
{
    while(GET_BIT(ADCSRA_Reg,6));
 
    return ADCLH_Reg;
}