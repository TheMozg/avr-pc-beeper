#include "melodies.h"

#include <avr/pgmspace.h>

#include "notes.h"

static const note_t imperial_march_notes[] PROGMEM = {
  {LA3,   NOTE_QUARTER},
  {LA3,   NOTE_QUARTER},
  {LA3,   NOTE_QUARTER},
  {F3,    NOTE_EIGHTH_DOT},
  {C4,    NOTE_SIXTEENTH},

  {LA3,   NOTE_QUARTER},
  {F3,    NOTE_EIGHTH_DOT},
  {C4,    NOTE_SIXTEENTH},
  {LA3,   NOTE_HALF},

  {E4,    NOTE_QUARTER},
  {E4,    NOTE_QUARTER},
  {E4,    NOTE_QUARTER},
  {F4,    NOTE_EIGHTH_DOT},
  {C4,    NOTE_SIXTEENTH},

  {Ab3,   NOTE_QUARTER},
  {F3,    NOTE_EIGHTH_DOT},
  {C4,    NOTE_SIXTEENTH},
  {LA3,   NOTE_HALF},

  {LA4,   NOTE_QUARTER},
  {LA3,   NOTE_EIGHTH_DOT},
  {LA3,   NOTE_SIXTEENTH},
  {LA4,   NOTE_QUARTER},
  {Ab4,   NOTE_EIGHTH_DOT},
  {G4,    NOTE_SIXTEENTH},

  {Gb4,   NOTE_SIXTEENTH},
  {E4,    NOTE_SIXTEENTH},
  {F4,    NOTE_EIGHTH},
  {PAUSE, NOTE_EIGHTH},
  {Bb3,   NOTE_EIGHTH},
  {Eb4,   NOTE_QUARTER},
  {D4,    NOTE_EIGHTH_DOT},
  {Db4,   NOTE_SIXTEENTH},

  {C4,    NOTE_SIXTEENTH},
  {B3,    NOTE_SIXTEENTH},
  {C4,    NOTE_EIGHTH},
  {PAUSE, NOTE_EIGHTH},
  {F3,    NOTE_EIGHTH},
  {Ab3,   NOTE_QUARTER},
  {F3,    NOTE_EIGHTH_DOT},
  {LA3,   NOTE_SIXTEENTH},

  {C4,    NOTE_QUARTER},
  {LA3,   NOTE_EIGHTH_DOT},
  {C4,    NOTE_SIXTEENTH},
  {E4,    NOTE_HALF},

  {LA4,   NOTE_QUARTER},
  {LA3,   NOTE_EIGHTH_DOT},
  {LA3,   NOTE_SIXTEENTH},
  {LA4,   NOTE_QUARTER},
  {Ab4,   NOTE_EIGHTH_DOT},
  {G4,    NOTE_SIXTEENTH},

  {Gb4,   NOTE_SIXTEENTH},
  {E4,    NOTE_SIXTEENTH},
  {F4,    NOTE_EIGHTH},
  {PAUSE, NOTE_EIGHTH},
  {Bb3,   NOTE_EIGHTH},
  {Eb4,   NOTE_QUARTER},
  {D4,    NOTE_EIGHTH_DOT},
  {Db4,   NOTE_SIXTEENTH},

  {C4,    NOTE_SIXTEENTH},
  {B3,    NOTE_SIXTEENTH},
  {C4,    NOTE_EIGHTH},
  {PAUSE, NOTE_EIGHTH},
  {F3,    NOTE_EIGHTH},
  {Ab3,   NOTE_QUARTER},
  {F3,    NOTE_EIGHTH_DOT},
  {C4,    NOTE_SIXTEENTH},

  {LA3,   NOTE_QUARTER},
  {F3,    NOTE_EIGHTH_DOT},
  {C4,    NOTE_SIXTEENTH},
  {LA3,   NOTE_HALF}
};

const melody_t imperial_march = {
  .notes = imperial_march_notes,
  .count = 70,
  .delay = 50,
  .bpm   = 112
};
