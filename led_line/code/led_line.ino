void cycleLight(int pin) {
  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
}

void setup() {
  // put your setup code here, to run once:

  for (int i = 8; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 8; i <= 10; i++) {
    cycleLight(i);
  }
}
