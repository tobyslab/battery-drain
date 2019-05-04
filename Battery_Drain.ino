#include <SoftSerial.h>

SoftSerial mySerial(5, 0);

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  mySerial.println("Battery drain v0.1");
}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.println("Loop");
  delay(1000);
}
