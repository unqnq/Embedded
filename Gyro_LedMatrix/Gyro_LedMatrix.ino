#include <LedControl.h>
#include <MPU6050_tockn.h>  //гіроскоп
#include <Wire.h>           //I2C

LedControl lc = LedControl(12, 10, 11, 1);  //LedControl(int dataPin, int clkPin, int csPin, int numDevices);
MPU6050 mpu6050(Wire);

byte up[] = {
  B00011000,
  B00111100,
  B01111110,
  B11111111,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

byte down[] = {
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B11111111,
  B01111110,
  B00111100,
  B00011000
};

byte left[] = {
  B0000100,
  B00001100,
  B00001110,
  B11111111,
  B11111111,
  B00001110,
  B00001100,
  B0000100
};

byte right[] = {
  B00010000,
  B00110000,
  B01110000,
  B11111111,
  B11111111,
  B01110000,
  B00110000,
  B00010000
};

void setup() {
  lc.shutdown(0, false);  // Вмикаємо модуль
  lc.setIntensity(0, 8);  //0 номер модуля, яскравість від 0-15
  lc.clearDisplay(0);

  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);  //визначає нульове положення гіроскопа
                                  // бажано не рухати гіро поки виконується ця команда
}

void loop() {
  drawArrowWithGyro();
}

void drawArrowWithGyro() {
  mpu6050.update();
  int acX = mpu6050.getAccAngleX();
  int acY = mpu6050.getAccAngleY();
  int row = map(acX, -45, 45, 0, 7);
  int col = map(acY, -170, 10, 0, 7);
  if (acY > -80) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        lc.setLed(0, i, j, bitRead(up[7 - j], 7 - i));
      }
    }
  }
  else if (acX <= -80) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        lc.setLed(0, i, j, bitRead(down[7 - j], 7 - i));
      }
    }
  }
  else if (acX > 0) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        lc.setLed(0, i, j, bitRead(left[7 - j], 7 - i));
      }
    }
  }
  else if (acX <= 0) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        lc.setLed(0, i, j, bitRead(right[7 - j], 7 - i));
      }
    }
  }
  delay(50);
}

void movePointWithGyro() {
  mpu6050.update();
  int acX = mpu6050.getAccAngleX();
  Serial.print(acX);
  int acY = mpu6050.getAccAngleY();
  Serial.print(" --- ");
  Serial.println(acY);
  int row = map(acX, -45, 45, 0, 7);
  int col = map(acY, -170, 10, 0, 7);
  lc.clearDisplay(0);
  lc.setLed(0, row, col, true);
  delay(100);
}
