#include "TM1637Display.h"  // Kütüphaneyi ekliyoruz

int CLK = 2;  // Modülün CLK pini
int DIO = 3;  // Modülün DIO pini

TM1637Display display(CLK, DIO);  // Kütüphane tanımlanıyor


void setup() {
  // put your setup code here, to run once:
  display.setBrightness(4);  // Parlaklık ayarı (0 en düşük, 7 en yüksek)
}

void loop() {
  for (int x = 999; x >= 0; x--) {  // Geri sayım
    display.showNumberDec(x,false);
    delay(1000);
  }
}
