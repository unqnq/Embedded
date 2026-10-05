#include <IRremote.h>

int irPin = 11;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(irPin);
}

void loop() {
  testIr();
}

void testIr() {
  if(IrReceiver.decode()) {
    String code = String(IrReceiver.decodedIRData.decodedRawData, HEX).substring(0,4);
    Serial.println(code);
    IrReceiver.resume();
  }
  delay(50);
}


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
