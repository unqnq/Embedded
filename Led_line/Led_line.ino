// Масив пінів для вибору світлодіодів (D0 - D5 лінійки підключені до D3 - D8 Arduino)
const int ledPins[] = {3, 4, 5, 6, 7, 8,9,10}; 
const int numLeds = 8; // Кількість підключених світлодіодів у межах вашої схеми

// Піни для керування кольором (мають бути з підтримкою ШІМ/PWM)
const int redPin = 11;    // R в D9
const int greenPin = 12; // G в D10
const int bluePin = 13;  // B в D11

void setup() {
  // Налаштовуємо піни світлодіодів на вихід і вимикаємо їх (HIGH = вимкнено)
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH); 
  }

  // Налаштовуємо піни кольорів на вихід і вимикаємо (255 = вимкнено для PNP/Спільного анода)
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  clearLEDs();
}

void loop() {
  // Ефект 1: Біжучий вогонь червоного кольору по лінійці
  setRGBColor(255, 0, 0); // Чистий червоний
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);  // Вмикаємо i-й світлодіод
    delay(150);
    digitalWrite(ledPins[i], HIGH); // Вимикаємо його
  }

  // Ефект 2: Біжучий вогонь зеленого кольору в зворотний бік
  setRGBColor(0, 255, 0); // Чистий зелений
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW); 
    delay(150);
    digitalWrite(ledPins[i], HIGH);
  }

  // Ефект 3: Спалах всієї лінійки синім кольором
  setRGBColor(0, 0, 255); // Чистий синій
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], LOW); // Вмикаємо всі
  delay(500);
  clearLEDs(); // Вимикаємо всі
  delay(200);
}

// Функція встановлення кольору (враховує інверсію плати Keyes v2)
void setRGBColor(int r, int g, int b) {
  analogWrite(redPin, 255 - r);
  analogWrite(greenPin, 255 - g);
  analogWrite(bluePin, 255 - b);
}

// Функція повного вимкнення лінійки
void clearLEDs() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}
