/*
 * main.c
 *
 * Created: 1/9/2024 10:27:07 PM
 *  Author: Owner
 */ 

#include <xc.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 1000000UL


void init_intrrupt(){
	MCUCR|=(1<<ISC01);
	MCUCR&=~(1<<ISC00);
	GICR|=(1<<INT0);
	sei();
	
}

void Set_pins(){
	
	DDRD|=0b00000001;
	PORTD|=0b00000100;
}
ISR(INT0_vect){
	
		PORTD|=(1<<PD0);
		
		_delay_ms(1000);
		
		PORTD&=~(1<<PD0);
		
	}
	
	


int main(void)
{
	init_intrrupt();
	Set_pins();
    while(1)
    {
		
		
    }
}