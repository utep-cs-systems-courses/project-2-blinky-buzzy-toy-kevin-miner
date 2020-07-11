#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  char ledFlags = 0;
  if (switch_state_changed) {
    state = SWITCHES;
    if (state == BIT0)
      ledFlags = LED_GREEN;
    if (state == BIT1)
      ledFlags = LED_RED;
  
    //char ledFlags = 0; /* by default, no LEDs on */

    //ledFlags |= switch_state_down ? LED_GREEN : 0;
    //ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

