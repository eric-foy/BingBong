#include "communication/raspi2arduino.cpp"

void setup() {
  Serial.begin(9600);
}

void loop() {
  helloBack();
}