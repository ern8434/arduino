#include "TM1637Display.h"  // Kütüphaneyi ekliyoruz

int CLK = 2;  // Modülün CLK pini
int DIO = 3;  // Modülün DIO pini

int dugme_baslat = 9;
int dugme_reset = 8;

int baslat = 0;
int reset = 0;

int zaman = 0;
int aktif = 1; // 0 ise bekleyecek


TM1637Display display(CLK, DIO);  // Kütüphane tanımlanıyor


void setup() {
  // put your setup code here, to run once:
  display.setBrightness(2);  // Parlaklık ayarı (0 en düşük, 7 en yüksek)

  pinMode(9,INPUT);
  pinMode(8,INPUT);
}

void zaman_goster(){
  int dakika = floor(zaman/60);
  int saniye = zaman%60;
  display.showNumberDecEx(100*dakika + saniye,0x40,true);
}

void loop() {
  // baslatma düğmesine basılırsa başla
  baslat = digitalRead(dugme_baslat);
  reset = digitalRead(dugme_reset);
  
  int delaytime = 1000;


  if(baslat){
    if(aktif==1){
      aktif=0;
    }
    else if(aktif==0){
      aktif=1;
    }
    delay(200);
    delaytime -= 200;
  }
  
  if(aktif){ // beklemede değilse zamanı ilerlet
    zaman++;
  }
  else if(reset){ // durmuş haldeyken reset basıldıysa sıfırla
    zaman = 0;
  }
  zaman_goster();

  delay(delaytime);
}
