#include "TM1637Display.h"  // Kütüphaneyi ekliyoruz

int CLK = 2;  // Modülün CLK pini
int DIO = 3;  // Modülün DIO pini

TM1637Display display(CLK, DIO);  // Kütüphane tanımlanıyor


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  display.setBrightness(7);  // Parlaklık ayarı (0 en düşük, 7 en yüksek)

  display.showNumberDec(0, false);  // Ekranda ___0 yazacak
  delay(1000);
  display.showNumberDec(1, true);  // Ekranda 0001 yazacak
  delay(1000);
  display.clear();                         // Yeni bilgi göndermeden önce ekranı temizle
  display.showNumberDec(19, false, 2, 1);  // Ekranda _19_ yazacak
  delay(1000);
  display.clear();
  display.showNumberDec(4, true, 2, 0);  // Ekranda 04__ yazacak
  delay(1000);
  display.clear();
  display.showNumberDec(-1, false, 3, 1);  // Ekranda __-1 yazacak
  delay(1000);
  display.clear();
  display.showNumberDec(-2, false, 3, 0);  // Ekranda _-2_ yazacak
  delay(1000);
  display.clear();
  display.showNumberHexEx(0xABCD);  // Ekranda ABCD yazacak
  delay(1000);
  display.clear();
  display.showNumberHexEx(0xEF);  // Ekranda __EF yazacak
  delay(1000);

  for (int x = 0; x < 7; x++) {  // Parlaklık ayarını değiştirelim
    display.setBrightness(x);
    display.showNumberDec(1919, false);  // Yazılan değişince parlaklık değişir
    delay(500);
  }

  display.setBrightness(7, false);     // Burada false yapıp veri değişince-
  display.showNumberDec(1919, false);  // - ekran kapanır. 1919 hiç görünmeyecek
  delay(1000);
  display.setBrightness(7, true);      // Ekran açıldı, hala veri görünmüyor
  display.showNumberDec(1923, false);  // Bu veri ekranı açar, 1923 görünür
  delay(1000);
}
