const int LDRPin { A0 };
const int pBuzzerPin { 9 };


void setup() {
  Serial.begin(9600);

  pinMode(LDRPin, INPUT);
  pinMode(pBuzzerPin, OUTPUT);
}

void loop() {
  int LDRVal { analogRead(LDRPin) };
  int pBuzzerFreq { map(LDRVal, 0, 1023, 100, 3000) };

  tone(pBuzzerPin, pBuzzerFreq);
  delay(50);
}
