#define DELAY_MS 500
#define PIN0 8 // 0 = off
#define PIN1 9 // 1 = on

void displayBinaryToLEDs(char *binary) {
  for (int i = 0; i < strlen(binary); i++) {
    if (binary[i] == '1') {
      digitalWrite(PIN1, HIGH);
      delay(DELAY_MS);
      digitalWrite(PIN1, LOW);
    }    

    else {
      digitalWrite(PIN0, HIGH);
      delay(DELAY_MS);
      digitalWrite(PIN0, LOW);
    }

    digitalWrite(PIN0, LOW);
    digitalWrite(PIN1, LOW);

    delay(DELAY_MS);
  }
}

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  char binary[] = "0001"; // Change this number
  
  displayBinaryToLEDs(binary);
  
  delay(DELAY_MS * 2);
}
