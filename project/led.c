#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachine.h"

unsigned char red_on = 0, green_on = 0;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  leds_on();
}

void leds_on() 
 { 
   P1OUT = LEDS;  
 } 

void led_dim()
{
  for (int i = 0; i < 1000; i++) {
    
    P1OUT = LED_RED;
    if (i % 20 == 0)
      __delay_cycles(100000);
    P1OUT = !LED_RED;
    if (i % 20 == 0)
      __delay_cycles(100000);
    
    P1OUT = LED_GREEN;
    if (i % 20 == 0)
       __delay_cycles(100000);
    P1OUT = !LED_GREEN;
    if (i % 20 == 0)
      __delay_cycles(100000);
  }
}

void binary_count()
{
  P1OUT = !LEDS;
  __delay_cycles(10000000);
  
  P1OUT = LED_RED;
  __delay_cycles(10000000);
  
  P1OUT = LED_GREEN;
  __delay_cycles(10000000);
  
  P1OUT = !LED_RED;
  __delay_cycles(10000000);
  
  P1OUT = LEDS;
  __delay_cycles(5000000);
}

void led_alternate()
{
  for (int i = 0; i < 20; i++) {
    P1OUT = LED_GREEN;
    __delay_cycles(500000);
    P1OUT = !LED_RED;
    __delay_cycles(500000);
    P1OUT = !LED_GREEN;
    __delay_cycles(500000);
    P1OUT = LED_RED;
    __delay_cycles(500000);
  }
}
