
int IN1 = 5;
int IN2 = 4;
int IN3 = 3;
int IN4 = 2;

int ENA = 10;
int ENB = 9;

int YON = 1; 

int EN = 150; // 255 üzerinden motorlara verilen voltaj

// 1:ileri -1:geri 0:dur

void yon_sec(int y){ 
  // Eğer ters yön seçildiyse durup bir süre bekleme yap
  if(y!=0 && y!=YON){
    dur();
    delay(500);
  }
  if(y==1){
    yon_ileri();
  }
  else if(y==-1){
    yon_geri();
  }
  else {
    dur();
  }

  YON = y;// yeni yön değerini sakla
}

void dur(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  YON = 0;
}
void yon_ileri(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void yon_geri(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  //pinMode(ENA, OUTPUT);
  //pinMode(ENB, OUTPUT);
}
 
void loop() {
  analogWrite(ENA, EN);
  analogWrite(ENB, EN);

  yon_ileri(); delay(1000);
  dur(); delay(1000);

  yon_geri(); delay(1000);
  dur(); delay(1000);
  
  delay(1000);

}