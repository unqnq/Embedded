#include <MPU6050_tockn.h>  //гіроскоп
#include <Wire.h>           //I2C

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);  //визначає нульове положення гіроскопа
                                  // бажано не рухати гіро поки виконується ця команда
}

void loop() {
  
}

void drawGraph() {
  mpu6050.update();
  int x = mpu6050.getAccAngleX();
  int y = mpu6050.getAccAngleY();
  Serial.print(x);
  Serial.print(" ");
  Serial.println(y);
  delay(50);
}

void checkGyro() {
  mpu6050.update();
  Serial.print("Gyro X: ");
  Serial.println(mpu6050.getGyroX());
  delay(200);
}
