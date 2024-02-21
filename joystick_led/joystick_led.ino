void setup() {
  Serial.begin(9600);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}


void loop() {

  int xval = analogRead(A0);
  int yval = analogRead(A1);
  int button = analogRead(A2);

  // Serial Monitor
  Serial.print(xval);
  Serial.print(",");
  Serial.print(yval);
  Serial.println();

  // X ekseni kontrol
  if (xval < 100) {
    digitalWrite(6, 1);
  } else {
    digitalWrite(6, 0);
  }

  if (xval > 900) {
    digitalWrite(7, 1);
  } else {
    digitalWrite(7, 0);
  }

  // Y ekseni kontrol
  if (yval < 100) {
    digitalWrite(8, 1);
  } else {
    digitalWrite(8, 0);
  }

  if (yval > 900) {
    digitalWrite(9, 1);
  } else {
    digitalWrite(9, 0);
  }

  // düğme anahtarı kontrol
  if (button == 0) {
    digitalWrite(10, 1);
  } else {
    digitalWrite(10, 0);
  }

  delay(100);  // delay in between reads for stability
}
