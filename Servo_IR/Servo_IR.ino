#include <Servo.h>
#include <IRremote.h>

Servo myservo;
int servoPin = 5;
int irPin = 11;
int angle = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  IrReceiver.begin(irPin);
  myservo.write(angle);
}

void loop() {
  moveWithIR();
}

void moveWithIR() {
  if (IrReceiver.decode()) {
    String code = String(IrReceiver.decodedIRData.decodedRawData, HEX).substring(0, 4);
    uint16_t irCode = (uint16_t)strtoul(code.c_str(), nullptr, 16);
    IrReceiver.resume();
    switch (irCode) {
      case 0xE619:  //0
        angle = 0;
        break;
      case 0xBA45:  //1
        angle = 29;
        break;
      case 0xB946:  //2
        angle = 58;
        break;
      case 0xB847:  //3
        angle = 87;
        break;
      case 0xBB44:  //4
        angle = 116;
        break;
      case 0xBF40:  //5
        angle = 145;
        break;
      case 0xBC43:  //6
        angle = 174;
        break;
      case 0xF807:  //7
        angle = 203;
        break;
      case 0xEA15:  //8
        angle = 232;
        break;
      case 0xF609:  //9
        angle = 255;
        break;

      case 0xE718:  //up arrow
        angle += 20;
        if(angle >255) angle = 255;
        break;
      case 0xAD52:  //down arrow
        angle -= 20;
        if(angle < 0) angle = 0;
        break;
    }
    myservo.write(angle);
  }
  delay(20);
}

// IR:
// 1 - ba45
// 2 - b946
// 3 - b847
// 4 - bb44
// 5 - bf40
// 6 - bc43
// 7 - f807
// 8 - ea15
// 9 - f609
// * - e916
// 0 - e619
// # - f20d
// up arrow - e718
// left arrow - f708
// ok - e31c
// right arrow - a55a
// down arrow - ad52