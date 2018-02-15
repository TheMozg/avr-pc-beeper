#include <avr/io.h> 

#include "melodies.h"
#include "music.h"
#include "sound.h"
#include "util.h"

int main() {
  util_delay_ms(10); // in case avr is powered before motherboard
  DDRB  = _BV(DDB0); // pin 0 as output
  PORTB = _BV(DDB3); // pin 3 as input with pull-up
  sound_init();      // init timer for sound
  while(1) {
    if (!(PINB & _BV(PB3))) {
      music_play(imperial_march.notes, imperial_march.count, imperial_march.bpm, imperial_march.delay);
      util_delay_ms(1000);
    }
  }
}