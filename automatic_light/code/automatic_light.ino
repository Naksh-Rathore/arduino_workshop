#include <Servo.h>

const int servoPin { 9 };
Servo servo{};

const int pirPin { 8 };
int lastPirPos { LOW };

bool isOn { true };

void setLight(int pirVal);

void setup() {
  Serial.begin(9600);

  servo.attach(servoPin);
  servo.write(90);

  pinMode(pirPin, INPUT);
}

void loop() {
  int pirVal { digitalRead(pirPin) };

  Serial.println(pirVal);

  if (pirVal == HIGH)
    setLight(pirVal);

  lastPirPos = pirVal;
  delay(50);
}

void setLight(int pirVal) {
  Serial.println("In setLight() function");

  if (lastPirPos == pirVal)
    return;

  if (isOn) 
    servo.write(45); 
  
  else
    servo.write(135);

  isOn = !isOn;
  delay(2000);
  servo.write(90);
}
