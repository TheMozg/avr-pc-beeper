#pragma once

#include <stdint.h>

void sound_init();
void sound_set_freq(uint16_t freq);
void sound_start();
void sound_stop();
