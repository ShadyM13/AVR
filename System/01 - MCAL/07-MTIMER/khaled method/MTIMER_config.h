/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : Timer 0				*/
/*  Layer	  : MCAL    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Apr 26, 2022  		*/
/************************************/



/* Timer Options:
1- TIMER0
2- TIMER1
3- TIMER2
*/

#define  TIMER_S    TIMER0

/*  TIMER 0 AND TIMER2                 */
//-----------------------------------------------------------------------------------------------------------------

/* Timer0 Mode Options:
1- NORMAL
2- CTC
3- PWM
4- FAST_PWM
*/
#define TIMER0_M    NORMAL


/* Timer0 Clock Options:
1- NO_CLOCK
2- CLK
3- CLK_8
4- CLK_64
5- CLK_256
6- CLK_1024
7- EXTERNAL_CLK_FALLING
8- EXTERNAL_CLK_RISING
*/
#define TIMER0_CLK    CLK_8


/* TIMER0 PreLoad Value*/
#define PRELOAD_VALUE         0
#define OCR_VALUE_CTCMode     220


/* Timer2 Mode Options:
1- NORMAL
2- CTC
3- PWM
4- FAST_PWM
*/
#define TIMER2_M    NORMAL

/* Timer2 Clock Options:
1- NO_CLOCK
2- CLK
3- CLK_8
4- CLK_32
5- CLK_64
6- CLK_128
7- CLK_256
8- CLK_1024
*/
#define TIMER2_CLK    CLK_8

/* PWM MODES:
1- INVERTED
2- NON_INVERTED
*/

#define PWM_M   NON_INVERTED




/*...................................................................................................................................*/

/* Timer 1 */
/* Timer1 Mode Options:

1-  T1_NORMAL
2-  PWM_8BIT
3-  PWM_9BIT
4-  PWM_10BIT
5-  T1_CTC
6-  FAST_PWM_8BIT
7-  FAST_PWM_9BIT
8-  FAST_PWM_10BIT
9-  PWM_PHASE_FREQ_CORRECT_ICR1
10- PWM_PHASE_FREQ_CORRECT_OCR1A
11- PWM_PHASE__CORRECT_ICR1
12- PWM_PHASE__CORRECT_OCR1A
13- CTC_ICR1
14- RESERVED
15- FAST_PWM_ICR1
16- FAST_PWM_OCR1A
*/
#define TIMER1_M    T1_NORMAL

/* Timer1 Clock Options:
1- NO_CLOCK
2- CLK
3- CLK_8
4- CLK_64
5- CLK_256
6- CLK_1024
7- EXTERNAL_CLK_FALLING
8- EXTERNAL_CLK_RISING
*/
#define TIMER1_CLK    CLK_8
