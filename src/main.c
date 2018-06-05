#include <avr/interrupt.h>

#include "melodies.h"
#include "music.h"
#include "sound.h"
#include "io.h"
#include "util.h"

int main() {
  // overclock to 8 MHz, F_CPU is in the Makefile
  cli();
  CLKPR = (1<<CLKPCE);
  CLKPR = 0;
  sei();

  util_delay_ms(10); // in case avr is powered before motherboard

  io_init();

  while(1) {
    uint8_t selected_option = io_selected_option();
    if (selected_option == 0) {
      if (sound_is_init()) {
        sound_deinit();
      }
      if (io_pc_is_low()) {
        io_out_set_low();
      } else {
        io_out_set_high();
      }
    } else {
      if (!sound_is_init()) {
        sound_init();
      }
      if (io_pc_is_enabled()) {
        if (io_pc_is_low()) {
          melody_play(melodies[selected_option-1]);
        }
      } else {
        util_delay_ms(1500); // bios boot estimation
        melody_play(melodies[selected_option-1]);
        while(!io_pc_is_enabled()) {
          /* wait until user changes configuration or shuts down the pc */
        }
      }
    }
  }
  return 0;
}
