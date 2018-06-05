#include "util.h"

#include <stdint.h>
#include <util/delay_basic.h>

// with F_CPU=1200000 max delay per _delay_loop_2 call is ~200 ms
// larger values will not fit into uint16_t argument

// _delay_loop_2 executes four CPU cycles per iteration
#define ITERS_PER_MS (F_CPU / 4000UL)
#define MAX_MS_PER_LOOP (65536UL / ITERS_PER_MS)

void util_delay_ms(uint16_t ms) {
  uint8_t i;
  uint8_t splits_count = ms / MAX_MS_PER_LOOP;
  uint8_t last_split = ms % MAX_MS_PER_LOOP;
  for (i = 0; i < splits_count; i++) {
    _delay_loop_2(ITERS_PER_MS * MAX_MS_PER_LOOP);
  }
  _delay_loop_2(ITERS_PER_MS * last_split);
}