#include "proximity/HCSR04.cpp"
#include "motors/L298N.cpp"

void setup() {
  Serial.begin(9600);

  setupHCSR04();
  setupL298N();

  forward(10, 100);
}

void loop() {
  if (loopHCSR04() == 1)
  {
    stop();
  }
}