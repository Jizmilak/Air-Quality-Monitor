
//
// Mobile Air Quality Monitor
// Hamid Ebrahimi Kahaki
// Version 0.8
//

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay_basic.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "n3310_lcd.h"
#include "DHT22.h"

void adc_init(void){
	
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));    //16Mhz/128 = 125Khz the ADC reference clock
	ADMUX |= (1<<REFS0);                //Voltage reference from Avcc (5v)
	ADCSRA |= (1<<ADEN);                //Turn on ADC
	ADCSRA |= (1<<ADSC);                //Do an initial conversion because this one is the slowest and to ensure that everything is up and running
}

uint16_t read_adc(uint8_t channel){
	ADMUX &= 0xF0;                    //Clear the older channel that was read
	ADMUX |= channel;                //Defines the new ADC channel to be read
	ADCSRA |= (1<<ADSC);                //Starts a new conversion
	while(ADCSRA & (1<<ADSC));            //Wait until the conversion is done
	return ADCW;                    //Returns the ADC value of the chosen channel
}


int main( void )
{
  unsigned char e='X';
  DHT22_DATA_t sensor_values;
  DHT22_ERROR_t error;
  uint16_t aq;
  uint16_t ppm;
  uint16_t percent;
  char text[4];
  
  text[3]=0;
  
  adc_init();
   
  _delay_loop_2(10000); // Delay for working with LCD
  
  LCD_init();
  LCD_write_string( 0, 0, " Air Quality:", MENU_NORMAL );
  LCD_write_string( 0, 3, "       % Fresh", MENU_NORMAL );
  
  // Super loop
  while (1)
  {
	    for(int i=0;i<50;i++)
	        _delay_loop_2(0xffff);
		
	    aq=read_adc(0); //reading Air quality sensor
		ppm=((1024*27)/aq-27);
		percent=(ppm-15)*100 / 75;
		if(percent>100) percent=100;
		if(percent<0) percent=0;
		
		text[0]=(percent==100)?'1':' ';
		text[1]=(char)(percent /10%10+'0');
		text[2]=(char)(percent %10+'0');
		
		LCD_write_string_big(0,1,text,MENU_NORMAL);
			  
  }
}

