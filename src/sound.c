#include "sound.h"

#include <avr/io.h>

void sound_init() {
  TCCR0A = _BV(COM0A0) | _BV(WGM01); // CTC mode
  TCCR0B = 0;                        // stop timer
}

void sound_start() {
  TCCR0B = _BV(CS01) | _BV(CS00);    // start timer, 64 prescaler
}

void sound_stop() {
  TCCR0B = 0;                        // stop timer
}

void sound_set_freq(uint16_t freq) {
  OCR0A = (F_CPU / (2UL * 64UL) / freq) - 1; // set output compare register
}