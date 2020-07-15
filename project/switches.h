#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch1 is p1.3 */
#define SW2 BIT1		/* switch1 is p1.3 */
#define SW3 BIT2		/* switch1 is p1.3 */
#define SW4 BIT3		/* switch1 is p1.3 */
#define SWITCHES (SW1 | SW2 | SW3 | SW4)		/* only 1 switch on this board */

//static char switch_update_interrupt_sense();
void switch_init();
void switch_interrupt_handler();

extern char state, switch_state_down, switch_state_changed; /* effectively boolean */
extern char sw_one, sw_two, sw_thr, sw_fou, CURRENT_STATE;

#endif // included
