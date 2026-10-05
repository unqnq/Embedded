#include <Servo.h>

Servo myservo;
int servoPin = 5;
int potPin = A5;
int potValue;
int angle;

void setup() {
  myservo.attach(servoPin);
}

void loop() {
  moveWithPotentiometr();
}

void move() {
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(500);
}

void moveWithPotentiometr() {
  potValue = analogRead(potPin);
  angle = map(potValue, 0, 1023, 0, 255);
  myservo.write(angle);
  delay(15);
}