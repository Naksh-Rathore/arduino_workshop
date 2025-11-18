const int buttonPin { 8 };
const int LEDPin { 9 };

int LEDVal { LOW };
int lastButtonState { HIGH };

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  int buttonVal = digitalRead(buttonPin);

  if (buttonVal == LOW && lastButtonState == HIGH) {
    LEDVal = (LEDVal == LOW) ? HIGH : LOW;  
    digitalWrite(LEDPin, LEDVal);
    delay(50);  
  }

  lastButtonState = buttonVal;
}
