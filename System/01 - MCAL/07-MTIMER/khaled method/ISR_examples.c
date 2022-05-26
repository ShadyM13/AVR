void __vector_11(void)
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

void __vector_10(void)
{
    static u16 Counter=0;
	Counter++;
	if(Counter==5000)
	{

        DIO_VidTogglePin(PORTA,PIN0);
		Counter=0;

	}

}

void __vector_5(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT2=PRELOAD_VALUE;
		DIO_VidTogglePin(PORTA,PIN0);
		counter=0;
	}

}

/*
void __vector_9(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT1=PRELOAD_VALUE;
		DIO_VidTogglePin(PORTA,PIN0);
		counter=0;
	}


}*/

void __vector_6(void)
{
	if(0==flag)
	{
		snap1=ICR1;
		ov=0;
		// falling edge
		CLR_BIT(TCCR1,ICES1);
		flag=1;
	}
	else if(1==flag)
	{
		snap2= ICR1+ (ov*65536);
		flag=2;
		// rising edge
		SET_BIT(TCCR1,ICES1);
	}
	else if (2==flag)
	{


		snap3= ICR1+ (ov*65536);

		flag=3;
	}


}

void __vector_9(void)
{
	ov++;
}
