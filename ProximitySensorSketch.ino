const int Pin=2;

void setup()
{

pinMode(Pin, INPUT);
Serial.begin(9600);

}

void loop()
{

int sensorValue = digitalRead(Pin);
if(sensorValue==LOW)
{
// This section is for no signal from sensor.
Serial.println("no Object");
delay(500);

}
else
{
// This section is for when sensor detects something.
Serial.println("Object Detected");
delay(500);

}
}
  
