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
    state = 0;
    break;
  case 2:
    binary_count();
    state = 0;
    break;
  case 3:
    led_alternate();
    state = 0;
    break;
  case 4:
    play_song();
    state = 0;
    break;
  default:
    break;
  }
}
