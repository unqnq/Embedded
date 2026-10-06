#include <LedControl.h>

LedControl lc = LedControl(12, 10, 11, 1);  //LedControl(int dataPin, int clkPin, int csPin, int numDevices);

void setup() {
  lc.shutdown(0, false);  // Вмикаємо модуль
  lc.setIntensity(0, 8);  //0 номер модуля, яскравість від 0-15
  lc.clearDisplay(0);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      lc.setLed(0, i, j, 1);  // (модуль матриць, рядок, стовбчик, стан світлодіода)
      delay(100);
    }
  }
}
