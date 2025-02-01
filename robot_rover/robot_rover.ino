/*
  L298N Motor Sürücü Kartı Arduino ile Nasıl Kullanılır? (2 Motor)
 
  L298N çift motor sürücü modülünün detaylı açıklaması ve örnek projelerini
  web sitemizde bulabilirsiniz.
 
  Mete Hoca
  https://www.metehoca.com/
*/

int IN1 = 2;    // Sürücü kartın IN1 bağlantısı
int IN2 = 3;    // Sürücü kartın IN2 bağlantısı
int IN3 = 4;    // Sürücü kartın IN3 bağlantısı
int IN4 = 5;    // Sürücü kartın IN4 bağlantısı

int ENA = 9;   // 1. motorun (A) çalışma ve hız kontrol pini
int ENB = 10;    // 2. motorun (B) çalışma ve hız kontrol pini
                // IN1 ve IN2 pinleri 1. motorun bağlı olduğu OUT1 ve OUT2
                // çıkışlarını, ENA pini ise motor hızını kontrol ediyor
                // ENA = ENABLE MOTOR A demek, yani sola takılan motor
                // IN3 ve IN4 pinleri 2. motorun bağlı olduğu OUT3 ve OUT4
                // çıkışlarını, ENB pini ise motor hızını kontrol ediyor
                // ENB = ENABLE MOTOR B demek, yani sağa takılan motor
                // Bu pinler PWM (~) destekli bir header'a bağlanmalı

void setup() {
  pinMode(IN1, OUTPUT);     // Pinler çıkış olarak ayarlanıyor
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 100);    // 1. motora hız ayarı yapılıyor (0-255)
  analogWrite(ENB, 100);    // 2. motora hız ayarı yapılıyor (0-255)
}

void loop() {
  digitalWrite(IN1, HIGH);  // 1. motor kısa bir süre döndürülüyor
  digitalWrite(IN2, LOW);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);  // 2. motor kısa bir süre döndürülüyor
  digitalWrite(IN4, LOW);
  delay(1000);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(IN1, LOW);   // 1. motor TERS YÖNE kısa bir süre döndürülüyor
  digitalWrite(IN2, HIGH);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);   // 2. motor TERS YÖNE kısa bir süre döndürülüyor
  digitalWrite(IN4, HIGH);
  delay(1000);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}