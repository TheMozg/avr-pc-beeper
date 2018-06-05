#include "music.h"

#include <avr/pgmspace.h>

#include "sound.h"
#include "util.h"

// convert note value with given tempo to ms
// bpm corresponds to 1/4 note
// multiplication is optimized by compiler
uint16_t note_value_to_ms(note_value_t value, uint8_t bpm) {
  switch (value) {
    case NOTE_HALF:        return 60UL * 1000UL * 4UL * 1/2 / bpm;
    case NOTE_QUARTER:     return 60UL * 1000UL * 4UL * 1/4 / bpm;
    case NOTE_QUARTER_DOT: return 60UL * 1000UL * 4UL * 3/8 / bpm;
    case NOTE_EIGHTH:      return 60UL * 1000UL * 4UL * 1/8 / bpm;
    case NOTE_EIGHTH_DOT:  return 60UL * 1000UL * 4UL * 3/16 / bpm;
    case NOTE_SIXTEENTH:   return 60UL * 1000UL * 4UL * 1/16 / bpm;
  }
  return 0;
}

void music_play(const note_t * notes, uint8_t note_count, uint8_t bpm, uint8_t delay_ms) {
  uint8_t i;
  for (i = 0; i < note_count; i++) {
    note_t note;
    memcpy_P(&note,&(notes[i]),sizeof(note_t));
    if (note.freq == 0) {
      sound_stop();
    } else {
      sound_start();
      sound_set_freq(note.freq);
    }
    util_delay_ms(note_value_to_ms(note.value, bpm));
    if (delay_ms != 0) {
      sound_stop();
      util_delay_ms(delay_ms);
    }
  }
  sound_stop();
}
