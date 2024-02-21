#include <LCD-I2C.h>


LCD_I2C lcd(0x27, 16, 2);  // Default address of most PCF8574 modules, change according

void setup() {
  Serial.begin(9600);  // joystick için

  // If you are using more I2C devices using the Wire library use lcd.begin(false)
  // this stop the library(LCD-I2C) from calling Wire.begin()
  lcd.begin();
  lcd.display();
  lcd.backlight();
}


void loop() {
  lcd.clear();
  // üst satırda kayan yazı

  lcd.setCursor(0, 0);

  int xval = analogRead(A0);
  int yval = analogRead(A1);
  int button = analogRead(A2);
  /*
    lcd.print("X:");
    lcd.print(xval);
    lcd.print(" Y:");
    lcd.print(yval);
    */

  // Yön tayini
  int yukari = 0, asagi = 0, sol = 0, sag = 0;

  // X ekseni kontrol
  if (xval < 100) {
    sol = 1;
  } else {
    sol = 0;
  }

  if (xval > 900) {
    sag = 1;
  } else {
    sag = 0;
  }

  // Y ekseni kontrol
  if (yval < 100) {
    yukari = 1;
  } else {
    yukari = 0;
  }

  if (yval > 900) {
    asagi = 1;
  } else {
    asagi = 0;
  }

  if (sol) {
    lcd.setCursor(3, 1);
    lcd.print("<=");
  }

  if (sag) {
    lcd.setCursor(8, 1);
    lcd.print("=>");
  }

  if (asagi) {
    lcd.setCursor(6, 1);
    lcd.print("|");
  }

  if (yukari) {
    lcd.setCursor(6, 0);
    lcd.print("^");
  }



  // düğmeye basılırsa lcd ışığı kapatıp aç
  if (button == 0) {
    lcd.backlightOff();
    delay(100);
    lcd.backlight();
  }

  lcd.backlight();
  //lcd.backlightOff();
  delay(200);
}
