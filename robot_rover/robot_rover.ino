
int IN1 = 5;
int IN2 = 4;
int IN3 = 3;
int IN4 = 2;

int ENA = 10;
int ENB = 9;

int yon = 1; 

// 1:ileri -1:geri 0:dur

void yon_sec(int y){ 
  // Eğer ters yön seçildiyse durup bir süre bekleme yap
  if(y!=0 && y!=yon){
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

  yon = y;// yeni yön değerini sakla
}

void dur(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
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
  int EN = 150;
  
  analogWrite(ENA, EN);
  analogWrite(ENB, EN);
  
  
  yon_ileri(); delay(1000);
  dur();

  yon_geri(); delay(1000);
  dur();

  delay(2000);

}