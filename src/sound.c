#include "sound.h"

#include <avr/io.h>

static uint8_t is_init = 0;

void sound_init() {
  TCCR0A  = _BV(COM0A0) | _BV(WGM01); // CTC mode
  TCCR0B  = 0;                        // stop timer
  is_init = 1;
}

void sound_deinit() {
  TCCR0A  = 0;
  TCCR0B  = 0;
  is_init = 0;
}

uint8_t sound_is_init() {
  return is_init;
}

void sound_start() {
  TCCR0B = _BV(CS02); // start timer, 256 prescaler
}

void sound_stop() {
  TCCR0B = 0; // stop timer
}

void sound_set_freq(uint16_t freq) {
  OCR0A = (F_CPU / (2UL * 256UL) / freq) - 1; // set output compare register
}