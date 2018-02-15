#include "util.h"

#include <stdint.h>
#include <util/delay_basic.h>

// with F_CPU=1200000 max delay per _delay_loop_2 call is ~200 ms
// larger values will not fit into uint16_t argument
void util_delay_ms(uint16_t ms) {
  uint8_t i;
  uint8_t splits_count = ms / 200;
  uint8_t last_split = ms % 200;
  for (i = 0; i < splits_count; i++) {
    _delay_loop_2(F_CPU / 4000 * 200);
  }
  _delay_loop_2(F_CPU / 4000 * last_split);
}