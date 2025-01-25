#include "IRremote.h"

String kod, sonkod;
int sensor = 3;  // Sensörün S pini belirtiliyor

// kumanda tanımları
String buton_yukari = "BF40FB04";
String buton_asagi = "BE41FB04";
String buton_sol = "F807FB04";
String buton_sag = "F906FB04";
String buton_ok = "BB44FB04";

int tumu_durum = 0;

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

void tum_ledler(){ // hepsini aç/kapa
  if(tumu_durum){
    tumu_durum = 0;
  } else {
    tumu_durum = 1;
  }
  for(int i=8;i<=11;i++){
    digitalWrite(i,tumu_durum);
  }
  delay(250);
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
    else if (kod == buton_ok) {
      Serial.println("*** Tümünü aç/kapa ***");
      tum_ledler();
    }
    else {
      Serial.println(kod);
    }

    IrReceiver.resume();  // Sıradaki kodu okumaya hazırlanıyoruz
  }
  delay(200);
}