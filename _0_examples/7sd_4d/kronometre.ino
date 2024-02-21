#include "TM1637Display.h"  // Kütüphaneyi ekliyoruz

int CLK = 2;  // Modülün CLK pini
int DIO = 3;  // Modülün DIO pini

TM1637Display display(CLK, DIO);  // Kütüphane tanımlanıyor


void setup() {
  // put your setup code here, to run once:
  display.setBrightness(2);  // Parlaklık ayarı (0 en düşük, 7 en yüksek)
}

void loop() {
  int saniye = 0;
  int dakika = 0;

  for (int x = 1; x < 3600; x++) {
    dakika = floor(x/60);
    saniye = x%60;

    display.showNumberDecEx(100*dakika + saniye,0x40,true);
    delay(1000);
  }
}
