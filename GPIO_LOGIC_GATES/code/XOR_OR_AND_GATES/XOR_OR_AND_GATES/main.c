/*
 * main.c
 *
 * Created: 1/7/2024 5:04:25 AM
 *  Author: Eslam Walid
 */ 

#include <xc.h>
#include "c:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\2.0.401\xc8\avr\include\avr\iom32.h"



int main(void)
{
	//using port D as input for switches (pull up res.)
	DDRD &= 0x00;
	PORTD |= 0xff;
	
	// port A,B,C as output for LEDs 
	DDRA|=0xff;
	DDRB|=0x01;
	DDRC|=0x01;
	
	
	
    while(1)
    {
        //for port A OR gate
		if((PIND&(1<<PD0)) == 0 && (PIND&(1<<PD1)) !=0)
		{
			
			if((PIND&(1<<PD6)) == 0 || (PIND&(1<<PD7)) == 0)
			{
				PORTB&=0x00;
				PORTC&=0x00;
				PORTA |= 0x01;
			}
			else{
				PORTB&=0x00;
				PORTC&=0x00;
				PORTA&=0x00;
				
			}
			
			
		}
		
		//for port B AND gate
		else if((PIND&(1<<PD0)) == 0 && (PIND&(1<<PD1)) ==0)
		{
			if((PIND&(1<<PD6)) == 0 && (PIND&(1<<PD7)) == 0)
			{
				PORTC&=0x00;
				PORTA&=0x00;
				PORTB|=0x01;
			}
			else{
				PORTB&=0x00;
				PORTC&=0x00;
				PORTA&=0x00;
				
			}
			
			
		}
		
		//for port C XOR gate
		else if((PIND&(1<<PD0)) == 1 && (PIND&(1<<PD1)) == 0)
		{
			
			if(((PIND&(1<<PD6))==0) != ((PIND&(1<<PD7))==0) )
			{
				
				
				PORTA&=0x00;
				PORTB&=0x00;
				PORTC|=0x01;
		    }
			
			else{
				
				PORTB&=0x00;
				PORTC&=0x00;
				PORTA&=0x00;
				
				
			}
			
			
		}
		
		else{
			PORTB&=0x00;
			PORTC&=0x00;
			PORTA&=0x00;
		}
		
    }
}