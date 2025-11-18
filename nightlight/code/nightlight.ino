const int ldrPin = A0;
const int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  // Option 1
  int ldrVal = analogRead(ldrPin);

  if (ldrVal < 150) {
    digitalWrite(ledPin, HIGH);
  }

  else {
    digitalWrite(ledPin, LOW);
  }

  // Option 2
  /*
  float ldrVal = analogRead(ldrPin) * (5.0 / 1023.0);

  if (ldrVal < 1.0) {
    digitalWrite(ledPin, HIGH);
  }

  else {
    digitalWrite(ledPin, LOW);
  }
  */
}
