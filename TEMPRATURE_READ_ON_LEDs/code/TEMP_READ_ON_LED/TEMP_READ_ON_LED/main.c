/*
 * main.c
 *
 * Created: 1/11/2024 4:31:15 AM
 *  Author: Eslam
 */ 

#include <xc.h>
#include <util/delay.h>

void ADC_init()
{
	ADMUX|=(1<<REFS0);
	ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	
}

uint16_t ADC_read(uint8_t channel)
{
	uint16_t ain,ainlow;
	
	ADMUX|=(ADMUX & 0xf0)|(channel & 0x0f);
	
	ADCSRA|=(1<<ADSC);
	
	while(ADCSRA&(1<<ADSC));
	
	ainlow =(uint16_t)ADCL;
	
	ain=(uint16_t)ADCH*256;
	
	ain=ain+ainlow;
	
	return ain;
}


int main(void)
{
	ADC_init();
	
	DDRC|=(1<<PC0)|(1<<PC1)|(1<<PC2);
	
    while(1)
    {
         uint16_t ADC_value= ADC_read(0);
		 
		 float temp =ADC_value;
		 
		 if(temp>=0 && temp<10)
		 {
			 PORTC|=0b00000001;
			 PORTC&=0b00000001;
			 
		 }
		 
		 else if(temp>=10 && temp < 20)
		 {
			 PORTC|=0b00000010;
			 PORTC&=0b00000010;
		 }
		 
		 else if (temp>=20)
		 {
			  PORTC|=0b00000100;
			  PORTC&=0b00000100;
		 }
		 
		 _delay_ms(500);
    }
}