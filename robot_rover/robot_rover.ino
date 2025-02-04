
int IN1 = 2;    // Sürücü kartın IN1 bağlantısı
int IN2 = 3;    // Sürücü kartın IN2 bağlantısı
int IN3 = 4;    // Sürücü kartın IN3 bağlantısı
int IN4 = 5;    // Sürücü kartın IN4 bağlantısı

int ENA = 9;
int ENB = 10;   

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  //pinMode(ENA, OUTPUT);
  //pinMode(ENB, OUTPUT);
}
 
void loop() {
  analogWrite(ENA, 130);
  
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000);
  
  digitalWrite(IN1, LOW);   // IN1 ve IN2'yi LOW yaptığımızda motor durur
  digitalWrite(IN2, LOW);
  delay(1000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2000);
  
  digitalWrite(IN1, LOW);   // IN1 ve IN2'yi LOW yaptığımızda motor durur
  digitalWrite(IN2, LOW);
  delay(1000);

}