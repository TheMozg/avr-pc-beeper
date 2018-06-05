#pragma once

#include <stdint.h>

typedef enum {
  NOTE_HALF,
  NOTE_QUARTER,
  NOTE_QUARTER_DOT,
  NOTE_EIGHTH,
  NOTE_EIGHTH_DOT,
  NOTE_SIXTEENTH
} note_value_t;

typedef struct {
  uint16_t     freq;
  note_value_t value;
} note_t;

void music_play(const note_t * notes, uint8_t note_count, uint8_t bpm, uint8_t delay_ms);