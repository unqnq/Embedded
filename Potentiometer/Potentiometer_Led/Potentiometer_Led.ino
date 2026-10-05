int ledPin = 3;
int potPin = A5;
int delayTime = 500;
int brightness = 255;
int potValue;

void setup() {
}

void loop() {
  changeBrightnessWithPot();
}

void changeBrightnessWithPot()
{
  potValue = analogRead(potPin);
  brightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
}