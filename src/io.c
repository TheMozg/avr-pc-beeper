#include "io.h"

void io_init() {
  PORTB = _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4) | _BV(PB5); // input
  DDRB  = _BV(DDB0); // output
}

void io_out_set_high() {
  PORTB |= 0b1;
}

void io_out_set_low() {
  PORTB &= ~0b1;
}

uint8_t io_pc_is_enabled() {
  return PINB & _BV(PB2);
}

uint8_t io_pc_is_low() {
  return !(PINB & _BV(PB1));
}

uint8_t io_selected_option() {
  uint8_t selected_l = (~(PINB >> 4)) & 0b01;
  uint8_t selected_h = (~(PINB >> 2)) & 0b10;
  return selected_h | selected_l;
}