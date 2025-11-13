#include <Servo.h>

Servo servo{};

const int servoPin { 8 };

const int button1Pin { 9 };
const int button2Pin { 10 };

const int LEDPin { 11 };

const int checkWin();
void rotateServo(const int winnerButtonPin, Servo& servo);

void setup() {
  Serial.begin(9600);

  randomSeed(analogRead(A7));

  servo.attach(servoPin);
  servo.write(90);

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  pinMode(LEDPin, OUTPUT);
}

void loop() {
  int randomTime { random(1000, 11000) };
  
  Serial.print("[DEBUG]: Random delay is ");
  Serial.println(randomTime);

  delay(randomTime);
  digitalWrite(LEDPin, HIGH);

  int winnerButtonPin { checkWin() };

  Serial.print("[DEBUG]: Winner button's pin is ");
  Serial.println(winnerButtonPin);

  rotateServo(winnerButtonPin, servo);

  servo.write(90);
  digitalWrite(LEDPin, LOW);
}

const int checkWin() {
  while (true) {
    int button1Val { digitalRead(button1Pin) };
    int button2Val { digitalRead(button2Pin) };

    if (button1Val == LOW)
      return button1Pin;

    else if (button2Val == LOW)
      return button2Pin;
  }
}

void rotateServo(const int winnerButtonPin, Servo& servo) {
  if (winnerButtonPin == button1Pin)  
    servo.write(135);

  else 
    servo.write(45);
    
  delay(2000);
}
