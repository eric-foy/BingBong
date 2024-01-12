int enablePin = 6;
int L293D_1A = 5;
int L293D_2A = 4;

void setup()
{
  Serial.begin(9600);

  pinMode(enablePin, OUTPUT);
  pinMode(L293D_1A, OUTPUT);
  pinMode(L293D_2A, OUTPUT);

  digitalWrite(L293D_1A, HIGH);
  digitalWrite(L293D_2A, LOW);
}

void loop() 
{
  for (int i = 255; i > 100; i -= 10)
  {
    Serial.print("PWM duty cycle: ");
    Serial.println(i/255.0f);
    analogWrite(enablePin, i);
    delay(2000);
  }

  for (int i = 100; i < 256; i += 10)
  {
    Serial.print("PWM duty cycle: ");
    Serial.println(i/255.0f);
    analogWrite(enablePin, i);
    delay(2000);
  }
}
