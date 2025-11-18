void LetterToMorseCode(int delayMs, int pin) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pin, HIGH);
    delay(delayMs);
    digitalWrite(pin, LOW);
    delay(delayMs);
  }

  delay(500); // For separation between letters
}

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  int delayMs = 500;
  int pin = 8;

  // S = . . .
  LetterToMorseCode(delayMs, pin);

  // O = - - -
  LetterToMorseCode(delayMs * 3, pin);

  // S = . . .
  LetterToMorseCode(delayMs, pin);
}
