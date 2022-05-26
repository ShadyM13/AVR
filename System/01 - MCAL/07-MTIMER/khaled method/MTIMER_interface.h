/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : Timer 0				*/
/*  Layer	  : MCAL    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Apr 26, 2022  		*/
/************************************/

#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

#define 

#define TIMER0  0
#define TIMER1  1
#define TIMER2  2

#define NO_CLOCK                0
#define CLK                     1
#define CLK_8                   2
#define CLK_64                  3
#define CLK_256                 4
#define CLK_1024                5
#define EXTERNAL_CLK_FALLING    6
#define EXTERNAL_CLK_RISING     7
#define CLK_128                 8
#define CLK_32                  9

#define T1_NORMAL                           0
#define PWM_8BIT                            2
#define PWM_9BIT                            3
#define PWM_10BIT                           4
#define T1_CTC                              5
#define FAST_PWM_8BIT                       6
#define FAST_PWM_9BIT                       7
#define FAST_PWM_10BIT                      8
#define PWM_PHASE_FREQ_CORRECT_ICR1         9
#define PWM_PHASE_FREQ_CORRECT_OCR1A        10
#define PWM_PHASE__CORRECT_ICR1             11
#define PWM_PHASE__CORRECT_OCR1A            12
#define CTC_ICR1                            13
#define RESERVED                            14
#define FAST_PWM_ICR1                       15
#define FAST_PWM_OCR1A                      16


#define INVERTED                            0
#define NON_INVERTED                        1



void MTIMER_voidTimerInit(void);
void MTIMER_VoidPrealoadOverFlow(void);
void MTIMER_VoidSetDuty(u16 Copy_U8Duty);
void MTIMER1_VoidInputCapture(void);

void MTIMER_voidTimer0OverflowISR(void (*ARG_pvoidfUserFunction)(void));
void MTIMER_voidTimer0CompareMatchISR(void (*ARG_pvoidfUserFunction)(void));
void MTIMER_voidTimer1OverflowISR(void (*ARG_pvoidfUserFunction)(void));
void MTIMER_voidTimer2OverflowISR(void (*ARG_pvoidfUserFunction)(void));
void MTIMER_voidTimer2ICUISR(void (*ARG_pvoidfUserFunction)(void));

/*
void MTIMER_voidInit( u8 ARG_u8TimerNo, u8 ARG_u8Mode, u8 ARG_u8Prescalar, u8 ARG_u8HWPinMode);
void MTIMER_voidInterruptEnalbe( u8 ARG_u8TimerNo, u8 ARG_u8State);
void MTIMER_voidSetCallBack(u8 ARG_u8TimerNo, boid (*ARG_PvoidUserFunction)(void));
void MTIMER_voidTimerDelay(u8 ARG_u8TimerNo, u8 ARG_u8Delay);
void MTIMER_voidStartTimer(u8 ARG_u8TimerNo, u8 ARG_u8State);
void MTIMER_voidGeneratePWM(u8 ARG_u8DutyCycle, u8 ARG_u8Frequency);
*/

#endif