const int ledStartPin = 8;
const int ledEndPin = 11;

const int buzzerPin = 7;

int delayMs;

// To pass to int *result, use & but to pass to int &result just use result
void getUserInput(char *msg, int *result) {
  Serial.print(msg);

  while (Serial.available() > 0) Serial.read(); 
  while (Serial.available() == 0) {}

  *result = Serial.parseInt();
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  for (int i = ledStartPin; i <= ledEndPin; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(buzzerPin, OUTPUT);

  getUserInput("Enter the amount of seconds you want to wait: ", &delayMs);
  delay(delayMs * 1000);
}

void loop() {
  digitalWrite(buzzerPin, HIGH);

  for (int i = ledStartPin; i <= ledEndPin; i++) {
    digitalWrite(i, HIGH);
  }
}
