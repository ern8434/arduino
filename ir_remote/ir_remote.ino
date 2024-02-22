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
  IrReceiver.begin(sensor, 0);

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void ledSecim(int pin){
  for(int i=8;i<=11;i++){
    digitalWrite(i,(i==pin));
  }
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
      ledSecim(8);
    }
    else if (kod == buton_asagi) {
      Serial.println("*** Aşağı ***");
      ledSecim(9);
    }
    else if (kod == buton_sol) {
      Serial.println("*** Sol ***");
      ledSecim(10);
    }
    else if (kod == buton_sag) {
      Serial.println("*** Sağ ***");
      ledSecim(11);
    } 
    else {
      Serial.println(kod);
    }

    IrReceiver.resume();  // Sıradaki kodu okumaya hazırlanıyoruz
  }
  delay(200);
}