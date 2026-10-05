int ledPin = 3;
int photoRezPin = A4;
int delayTime = 500;
int brightness = 255;
int photoRezValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  photoRezValue = analogRead(photoRezPin);  // 0 - light, 1023 - dark
  // Serial.println(photoRezValue);
  brightness = map(photoRezValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
}