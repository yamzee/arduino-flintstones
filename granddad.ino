/*
 * grand dad
 * plays an amalgomation of the flintstones theme and 7 Grand Dad on 
 * digital pin 8 (arduino UNO was used)
 * yamzee 19.07.2019
 * 
 * Original code created 21.01.2010 by Tom Igoe
 * http://www.arduino.cc/en/Tutorial/Tone
 * 
 * sorry for stealing public domain code!
*/

#include "pitches.h"

//TODO: find a way to compress the array or make it easier to transfer music from sheet to this

// NOTES
int melody[] = {
  NOTE_G4, NOTE_C4, 0, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_C4, 0, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_D4, //first loop of the theme
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, //PIANO RISE
  NOTE_G4, 0, NOTE_C4, 0, //THIS SECTION SEPERATES THE FRILLS JUST FOR EASE OF MATCHING UP NOTE LENGTHS AND JUNK
  NOTE_C6, NOTE_C6, NOTE_C6, 0, //FRILLS
  NOTE_C5, 0, NOTE_A4, 0, NOTE_G4, 0, NOTE_C4, 
  NOTE_C6, NOTE_C6, NOTE_C6, 0, //FRILLS
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_C4  // END 
};

// NOTE DURATION
int noteDurations[] = {
  4, 4, 8, 4, 8, 4, 4, 8, 4, 8, 8, 8, 8, 8, 4, 4,// first loop of the theme
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, // piano rise
  8, 8, 16, 16, 
  16, 16, 16, 16,
  8, 8, 16, 16, 8, 8, 8, 
  16, 16, 16, 16,
  4, 8, 8, 8, 8, 8, 4, 4, 1  // second loop
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 61; thisNote++) {

    //TODO: calculate BPM so it isn't as rough of a guess as it is now

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1100 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.40;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
