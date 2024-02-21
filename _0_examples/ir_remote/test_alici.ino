#include "IRremote.h"

String kod, sonkod;
int sensor = 3;  // Sensörün S pini belirtiliyor

// kumanda tanımları
String buton_yukari = "FF00FD02";
String buton_asagi = "FE01FD02";
String buton_sol = "FC03FD02";
String buton_sag = "FD02FD02";


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(sensor, 0);  // Kütüphane başlatılıyor
}

void loop() {
  if (IrReceiver.decode()) {                                     // Bir kod alındı
    kod = String(IrReceiver.decodedIRData.decodedRawData, HEX);  // Kodu değişkene aktarıyoruz
    if (kod != "0") {
      sonkod = kod;
    } else {
      kod = sonkod;
    }                   // 0 dönüyorsa tuş basılı tutuluyordur
    kod.toUpperCase();  // Kod büyük harfe dönüştürülüyor


    if (kod == buton_yukari) {
      Serial.println("*** Yukarı ***");
    }
    else if (kod == buton_asagi) {
      Serial.println("*** Aşağı ***");
    }
    else if (kod == buton_sol) {
      Serial.println("*** Sol ***");
    }
    else if (kod == buton_sag) {
      Serial.println("*** Sağ ***");
    } 
    else {
      Serial.println(kod);
    }

    IrReceiver.resume();  // Sıradaki kodu okumaya hazırlanıyoruz
  }
  delay(200);
}