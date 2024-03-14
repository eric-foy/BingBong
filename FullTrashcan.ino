#include "HX711.h"


const int trigPin = 2;
const int echoPin = 3;
long duration;
int distance;

HX711 scale;
const int LOADCELL_DOUT_PIN = 5;
const int LOADCELL_SCK_PIN = 6;
int x = 0;
long reading = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  digitalWrite(trigPin, LOW); // This is for the proximity sensor. Might need to change to make ordered sensor work.
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if (scale.is_ready()) { // Output for the HX711 or the scale.
    reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }
 

  if (distance <= '50') { // This should count how long the sensor is triggered at close range.
    ++x;
  } else {
    x = 0;
  }

  if (x == 10 || reading == 100) { // Probably need to adjust values.
    // Take trash out.
  }

  delay(1000);
}
