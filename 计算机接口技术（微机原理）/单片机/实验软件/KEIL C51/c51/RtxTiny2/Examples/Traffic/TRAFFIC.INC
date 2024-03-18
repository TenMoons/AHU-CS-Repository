
PORT1 &= ~0x20;            /* set P1.5 to zero: Key Input */

/* define a debug function for the pedestrian push button */
signal void push_key (void)  {
  PORT1 |=  0x20;          /* set P3.0       */
  twatch (`Clock*0.05);    /* wait 50 msec   */
  PORT1 &= ~0x20;          /* reset P3.0     */
}

/* define a toolbar button to call push_key */
define button "Push for Walk", "push_key ()"

RADIX=10 // decimal output in watch window
