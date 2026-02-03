#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define the hardware type. 
// Use FC16_HW for the common 4-in-1 modules. Use GENERIC_HW for single modules.
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 1 // Change this if you have more modules

#define DATA_PIN  12
#define CS_PIN    10
#define CLK_PIN   11

// Setup for Software SPI (using your existing pins)
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  myDisplay.begin();
  myDisplay.setIntensity(3); // Set brightness (0-15)
  myDisplay.displayClear();

  // Parameters: Text, Alignment, Speed, Pause Time, Effect In, Effect Out
  myDisplay.displayText("SELAM MiLLET", PA_CENTER, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void loop() {
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset(); // Loop the animation
  }
}