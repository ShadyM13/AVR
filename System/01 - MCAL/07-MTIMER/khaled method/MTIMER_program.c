/************************************/
/*	Author	  :	Shady Ahmad			*/
/*	SWC		  : Timer 0				*/
/*  Layer	  : MCAL    			*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	Apr 26, 2022  		*/
/************************************/


#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MTIMER_interface.h"
#include "MTIMER_private.h"
#include "MTIMER_config.h"


//#include "MDIO_interface.h"             //is this allowed considering both MDIO and MTIMER are in the MCAL layer???

//input capture variables
u16 ov=0;
u8 flag=0;
u16 snap1;
u32 snap2;
u32 snap3;

void (*MTIMER_pvoidfUserFunction00)(void) = 0;
void (*MTIMER_pvoidfUserFunction01)(void) = 0;
void (*MTIMER_pvoidfUserFunction10)(void) = 0;
void (*MTIMER_pvoidfUserFunction20)(void) = 0;
void (*MTIMER_pvoidfUserFunction21)(void) = 0;


void MTIMER_voidTimerInit(void)
{
    #if TIMER_S == TIMER0

        #if TIMER0_M == NORMAL
            CLEAR_BIT(TCCR0,WGM00);
            CLEAR_BIT(TCCR0,WGM01);
            SET_BIT(TIMSK, TOIE0);
        
        #elif TIMER0_M == CTC
            CLEAR_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);
            OCR0 = OCR_VALUE_CTCMode;
            SET_BIT(TIMSK,OCIR0);

        // WAVE GENERATOR on PINB.3
            //Toggle OC0 on compare match
            CLEAR_BIT(TCCR0,COM01);
            SET_BIT(TCCR0,COM00);

        #elif TIMER0_M == PWM
            SET_BIT(TCCR0,WGM00);
            CLEAR_BIT(TCCR0,WGM01);

            #if PWM_M == NON_INVERTED
                SET_BIT(TCCR0, COM01);
                CLEAR_BIT(TCCR0, COM00);
            #elif PWM_M == INVERTED
                SET_BIT(TCCR0, COM01);
                SET_BIT(TCCR0, COM00);
            #endif

        #endif

        #if TIMER0_CLK == NO_CLOCK
            CLEAR_BIT(TCCR0,CS00);
            CLEAR_BIT(TCCR0,CS01);
            CLEAR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK
            SET_BIT(TCCR0,CS00);
            CLEAR_BIT(TCCR0,CS01);
            CLEAR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_8
            CLEAR_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            CLEAR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_64
            SET_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            CLEAR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_256
            CLEAR_BIT(TCCR0,CS00);
            CLEAR_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_1024
            SET_BIT(TCCR0,CS00);
            CLEAR_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == EXTERNAL_CLK_FALLING
            CLEAR_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == EXTERNAL_CLK_RISING
            SET_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        
        #endif

    #elif TIMER_S == TIMER1
        #if TIMER1_M==T1_NORMAL    
            CLEAR_BIT(TCCR1,WGM10);
            CLEAR_BIT(TCCR1,WGM11);
            CLEAR_BIT(TCCR1,WGM12);
            CLEAR_BIT(TCCR1,WGM13);
            SET_BIT(TIMSK, TOIE1);
        #elif TIMER1_M==PWM_8BIT       
            SET_BIT(TCCR1,WGM10);
            CLEAR_BIT(TCCR1,WGM11);
            CLEAR_BIT(TCCR1,WGM12);
            CLEAR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_9BIT  
            CLEAR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLEAR_BIT(TCCR1,WGM12);
            CLEAR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_10BIT   
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLEAR_BIT(TCCR1,WGM12);
            CLEAR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==T1_CTC     
            CLEAR_BIT(TCCR1,WGM10);
            CLEAR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLEAR_BIT(TCCR1,WGM13);
            OCR1A= OCR_VALUE_CTCMode;
            SET_BIT(TIMSK, OCIE1A);

            /*WE CAN USE OCR1B In Here */
        #elif TIMER1_M==FAST_PWM_8BIT  
            SET_BIT(TCCR1,WGM10);
            CLEAR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLEAR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==FAST_PWM_9BIT  
            CLEAR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLEAR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==FAST_PWM_10BIT  
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLEAR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_PHASE_FREQ_CORRECT_ICR1  
            CLEAR_BIT(TCCR1,WGM10);
            CLEAR_BIT(TCCR1,WGM11);
            CLEAR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_PHASE_FREQ_CORRECT_OCR1A 
            SET_BIT(TCCR1,WGM10);
            CLEAR_BIT(TCCR1,WGM11);
            CLEAR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_PHASE__CORRECT_ICR1      
            CLEAR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLEAR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_PHASE__CORRECT_OCR1A     
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLEAR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==CTC_ICR1       
            CLEAR_BIT(TCCR1,WGM10);
            CLEAR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==RESERVED       
            SET_BIT(TCCR1,WGM10);
            CLEAR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==FAST_PWM_ICR1    
            CLEAR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==FAST_PWM_OCR1A   
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #endif
        #if TIMER1_CLK == NO_CLOCK
            CLEAR_BIT(TCCR1,CS10);
            CLEAR_BIT(TCCR1,CS11);
            CLEAR_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK
            SET_BIT(TCCR1,CS10);
            CLEAR_BIT(TCCR1,CS11);
            CLEAR_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK_8
            CLEAR_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            CLEAR_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK_64
            SET_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            CLEAR_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK_256
            CLEAR_BIT(TCCR1,CS10);
            CLEAR_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK_1024
            SET_BIT(TCCR1,CS10);
            CLEAR_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == EXTERNAL_CLK_FALLING
            CLEAR_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == EXTERNAL_CLK_RISING
            SET_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);
        
        #endif

    #elif TIMER_S == TIMER2
        #if TIMER2_M==NORMAL
            CLEAR_BIT(TCCR2,WGM20);
            CLEAR_BIT(TCCR2,WGM21);
            SET_BIT(TIMSK, TOIE2);

        #elif TIMER2_M==CTC
            CLEAR_BIT(TCCR2,WGM20);
            SET_BIT(TCCR2,WGM21);
            OCR0= OCR_VALUE_CTCMode;
            SET_BIT(TIMSK, OCIE2);

        // WAVE GENERATOR ON PINB.3
            CLEAR_BIT(TCCR2,COM21);
            SET_BIT(TCCR2,COM20);



        #elif TIMER2_M==PWM
            SET_BIT(TCCR2,WGM20);
            CLEAR_BIT(TCCR2,WGM21);

        #elif TIMER2_M==FAST_PWM
            SET_BIT(TCCR2,WGM20);
            SET_BIT(TCCR2,WGM21);

        #endif

        #if TIMER2_CLK == NO_CLOCK
            CLEAR_BIT(TCCR2,CS20);
            CLEAR_BIT(TCCR2,CS21);
            CLEAR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK
            SET_BIT(TCCR2,CS20);
            CLEAR_BIT(TCCR2,CS21);
            CLEAR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_8
            CLEAR_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            CLEAR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_32
            SET_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            CLEAR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_64
            CLEAR_BIT(TCCR2,CS20);
            CLEAR_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_128
            SET_BIT(TCCR2,CS20);
            CLEAR_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_256
            CLEAR_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_1024
            SET_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);    

        #endif

    #else
    #endif
   
    //Enabling Global interrupt
    SET_BIT(SREG, BIT7);
    
}

void MTIMER_VoidPrealoadOverFlow(void)
{
    #if TIMER_S == TIMER0
        TCNT0 = PRELOAD_VALUE;
    #elif TIMER_S == TIMER1
        TCNT1 = PRELOAD_VALUE;      
    #elif TIMER_S == TIMER2
        TCNT2= PRELOAD_VALUE;  
    #endif
}

void MTIMER_VoidSetDuty(u16 Copy_U8Duty)
{
    #if TIMER_S == TIMER0
        OCR0= Copy_U8Duty;
    #elif TIMER_S == TIMER1
        OCR1A= Copy_U8Duty;
    #elif TIMER_S == TIMER2
        OCR2 =Copy_U8Duty;
    #endif
}

void MTIMER1_VoidInputCapture(void)
{
    //MDIO_voidSetPinDirection(MDIO_PORTD,6,MDIO_INPUT);
    /*IT can be any mode of the Timer except 8,10,12,14*/
    //SET_BIT(TIMSK,TICIE1);
    //SET_BIT(TCCR1,ICES1);   // Rising Edge
}


//Example for ISR
/*void __vector_11(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT0=PRELOAD_VALUE;
		DIO_VidTogglePin(PORTA,PIN0);
		counter=0;
	}
}
*/



// Timer/Counter0 overflow
void MTIMER_voidTimer0OverflowISR(void (*ARG_pvoidfUserFunction)(void))
{
	MTIMER_pvoidfUserFunction00 = ARG_pvoidfUserFunction;
}
void __vector_11(void) __attribute__((signal));             
void __vector_11(void)
{
    (*MTIMER_pvoidfUserFunction00)();
}

// Timer/Counter0 compare match
void MTIMER_voidTimer0CompareMatchISR(void (*ARG_pvoidfUserFunction)(void))
{
	MTIMER_pvoidfUserFunction01 = ARG_pvoidfUserFunction;
}
void __vector_10(void) __attribute__((signal));              
void __vector_10(void)
{
    (*MTIMER_pvoidfUserFunction01)();
}

// Timer/Counter1 overflow
void MTIMER_voidTimer1OverflowISR(void (*ARG_pvoidfUserFunction)(void))
{
	MTIMER_pvoidfUserFunction10 = ARG_pvoidfUserFunction;
}
void __vector_9(void)  __attribute__((signal));              
void __vector_9(void)
{
    (*MTIMER_pvoidfUserFunction10)();
}

// Timer/Counter2 overflow
void MTIMER_voidTimer2OverflowISR(void (*ARG_pvoidfUserFunction)(void))
{
	MTIMER_pvoidfUserFunction20 = ARG_pvoidfUserFunction;
}
void __vector_5(void)  __attribute__((signal));              
void __vector_5(void)
{
    (*MTIMER_pvoidfUserFunction20)();
}


// Timer/Counter2 ICU Capture event
void MTIMER_voidTimer2ICUISR(void (*ARG_pvoidfUserFunction)(void))
{
	MTIMER_pvoidfUserFunction21 = ARG_pvoidfUserFunction;
}
void __vector_6(void)  __attribute__((signal));              
void __vector_6(void)
{
    (*MTIMER_pvoidfUserFunction21)();
}

