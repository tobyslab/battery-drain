#include <SoftSerial.h>

SoftSerial mySerial(0, 1);  // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  mySerial.println("Battery drain v0.1");
  pinMode(2, OUTPUT);
  mySerial.println("Hai.");
  mySerial.print("Voltage> ");
  //delay(1000);
}

void loop() {
  int vccValue;
  float voltage;
  mySerial.print("Voltage: ");
  vccValue = readVcc();
  voltage = (float) vccValue / 1000;
  if(voltage > 4) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
  mySerial.print(voltage);
  mySerial.println("V");
  delay(1000);
}

uint16_t readVcc(void) 
{
  uint16_t result;
  // Read 1.1V reference against Vcc
  ADMUX = (0<<REFS0) | (12<<MUX0);
  delay(2); // Wait for Vref to settle
  ADCSRA |= (1<<ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCW;
  return 1125300L / result; // Back-calculate AVcc in mV
}
