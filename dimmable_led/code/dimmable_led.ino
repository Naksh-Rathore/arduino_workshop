const int potenPin = A0;
const int ledPin = 7;

void setup() {
  pinMode(potenPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potenVal;
  int ledVal;

  potenVal = analogRead(potenPin);
  ledVal = map(potenVal, 0, 1023, 0, 255); // Maps the potentiometer input range to the LED output range

  analogWrite(ledPin, ledVal);
}
