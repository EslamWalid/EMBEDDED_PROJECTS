/*
 * main.c
 *
 * Created: 1/15/2024 1:30:34 AM
 *  Author: Eslam Walid
 */ 

#include <xc.h>
#include <avr/interrupt.h>


#define F_CPU 8000000UL

volatile uint8_t OV_time=0;


void timer_init(void)
{
	TCCR0=0;
	TIMSK=0;
	TCCR0|=(1<<CS00)|(1<<CS02);
	TIMSK|=(1<<TOIE0);
	TCNT0=182;
	sei();
}


ISR(TIMER0_OVF_vect)
{
	if(OV_time == 3){
		OV_time=0;
		TCNT0=182;
		PORTC^=(1<<PC0);
	}
	else{
	OV_time++;
	}
	
	
	
}





int main(void)
{
	timer_init();
	
	DDRC=0x01;
	
    while(1)
    {
        
    }
}