

#include <pitches.h>


//www.elegoo.com
//2016.12.08

#include "pitches.h"
 

//button set up
int buttonApin = 11;
int buttonBpin = 10;

bool modeA = false;
bool modeB = false;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C5,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C5, NOTE_G4,
  NOTE_F4, NOTE_E4, NOTE_F4, NOTE_D4};

int melody2[] = {
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_DS3, NOTE_AS3, NOTE_G3,
  NOTE_DS3, NOTE_AS3, NOTE_G3, NOTE_D3, NOTE_D3, NOTE_D3,
  NOTE_DS3, NOTE_AS3, NOTE_FS3, NOTE_DS3, NOTE_AS3, NOTE_G3};

int duration [] = {
  600, 600, 150, 150, 150, 600, 400,
  150, 150, 150, 600, 400, 150, 150, 150, 600};

int duration2 [] = {
  556, 556, 556, 417, 139, 556, 417,
  136, 1111, 556, 556, 556, 417, 139, 556, 417, 136, 556};
 
void setup() {
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}
 
void loop() {  

  if (digitalRead(buttonApin) == LOW){
    modeA = true;
    
  }
  
  if (digitalRead(buttonBpin) == LOW){
    modeB = true;
    
  }
    

  if (modeA == true){
    for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
    tone(8, melody[thisNote], duration[thisNote]);
    delay(duration[thisNote]);
    }

    modeA = false;
  }

  if (modeB == true){
    for (int thisNote = 0; thisNote < sizeof(melody2) / sizeof(melody2[0]); thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
    tone(8, melody2[thisNote], duration2[thisNote]);
    delay(duration2[thisNote]);
    }

    modeB = false;  
    delay(1000);
  }

  
  // restart after two seconds 
  delay(2000);
  }
