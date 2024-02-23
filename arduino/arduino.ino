#include "proximity/HCSR04.cpp"

void setup() {
  Serial.begin(9600);

  setupHCSR04();
}

void loop() {
  loopHCSR04();
}