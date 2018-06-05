#pragma once

#include "music.h"

typedef struct {
  const note_t * notes; // pointer to notes array (in progmem)
  uint8_t        count; // size of notes array
  uint8_t        delay; // delay in ms after every note
  uint8_t        bpm;   // tempo
} melody_t;

void melody_play(melody_t melody);

extern const melody_t melodies[3];
