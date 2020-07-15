#include <stdlib.h>
#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void stateMachine(int state)
{
  switch (state) {
  case 1:
    led_dim();
    leds_on();
    state = 0;
    break;
  case 2:
    binary_count();
    leds_on();
    state = 0;
    break;
  case 3:
    led_alternate();
    leds_on();
    state = 0;
    break;
  case 4:
    play_song();
    leds_on();
    state = 0;
    break;
  default:
    break;
  }
}
