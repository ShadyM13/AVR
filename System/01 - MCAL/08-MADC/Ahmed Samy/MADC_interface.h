/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : ADC                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : February 28, 2022    */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _MADC_INTERFACE_H_
#define _MADC_INTERFACE_H_

//ADC Voltage Select
#define     MADC_VOLTAGE_REF_msk                 0b00111111
#define     MADC_VOLTAGE_REF_AVCC                0b01000000
#define     MADC_VOLTAGE_REF_AREF                0b00000000
#define     MADC_VOLTAGE_REF_2_56v               0b11000000

//ADC MODE Select
#define     MADC_MODE_AUTO_TRIGGER               1
#define     MADC_MODE_SINGLE_CONVERSION          0

//ADC ADJUST Select
#define     MADC_RIGHT_ADJUST                    0
#define     MADC_LEFT_ADJUST                     1

//ADC PRESCALER Select
#define     MADC_PRESCALER_clr_msk               0b11111000
#define     MADC_PRESCALER_2_msk                 0b00000001
#define     MADC_PRESCALER_4_msk                 0b00000010
#define     MADC_PRESCALER_8_msk                 0b00000011
#define     MADC_PRESCALER_16_msk                0b00000100
#define     MADC_PRESCALER_32_msk                0b00000101
#define     MADC_PRESCALER_64_msk                0b00000110
#define     MADC_PRESCALER_128_msk               0b00000111

//ADC AUTO Trigger Select
#define     MADC_AUTO_TRIG_SRC_clr_msk                      0b00011111
#define     MADC_AUTO_TRIG_SRC_FREE_RUNNING_msk             0b00000000
#define     MADC_AUTO_TRIG_SRC_ANALOG_COMP_msk              0b00100000
#define     MADC_AUTO_TRIG_SRC_EXTI0_msk                    0b01000000
#define     MADC_AUTO_TRIG_SRC_TIMER0_COMP_msk              0b01100000
#define     MADC_AUTO_TRIG_SRC_TIMER0_OVF_msk               0b10000000
#define     MADC_AUTO_TRIG_SRC_TIMER1_COMP_msk              0b10100000
#define     MADC_AUTO_TRIG_SRC_TIMER1_OVF_msk               0b11000000
#define     MADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk              0b11100000

//ADC mask to clear channel
#define     MADC_CHANNEL_SELECTOR_clr_msk       0b11100000



typedef enum {
    ADC_Channel_0,          //0  -> 0x00
    ADC_Channel_1,          //1  -> 0x01
    ADC_Channel_2,          //2  -> 0x02
    ADC_Channel_3,          //3  -> 0x03
    ADC_Channel_4,          //4  -> 0x04
    ADC_Channel_5,          //5  -> 0x05
    ADC_Channel_6,          //6  -> 0x06
    ADC_Channel_7,          //7  -> 0x07
}MADC_ChannelTypes;

void  MADC_Init(void);                                                          //ADC Initializing
void  MADC_StartConversion(MADC_ChannelTypes ARG_MCTChannel);                   //ADC Start Conversion
u16   MADC_GetResult(void);                                                     //ADC Get Readings


#endif /*_MADC_INTERFACE_H_*/