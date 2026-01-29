// Include the library
#include "LedControl.h"

/*
 * Pin 12 is connected to the DataIn 
 * Pin 11 is connected to the CLK 
 * Pin 10 is connected to LOAD (CS)
 * We have only a single MAX7219.
 */
LedControl lc = LedControl(12, 11, 10, 1);

// A simple smiley face pattern (1 = LED on, 0 = LED off)
byte smiley[8] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
};

void setup() {
  // The MAX7219 is in power-saving mode on startup, we have to do a wakeup call
  lc.shutdown(0, false);
  
  // Set the brightness to a medium level (0 to 15)
  lc.setIntensity(0, 1);
  
  // Clear the display
  lc.clearDisplay(0);
}

void loop() {
  // Display the smiley face
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, smiley[i]);
  }
  
  delay(2000);
  
  // Bonus: Blink a single LED at (3,3)
  lc.clearDisplay(0);
  lc.setLed(0, 3, 3, true); 
  delay(500);
  lc.setLed(0, 3, 3, false);
  delay(500);
}

