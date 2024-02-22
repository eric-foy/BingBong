int enablePin = 6;
int L293D_1A = 5;
int L293D_2A = 4;

void setup()
{
  Serial.begin(9600);

  pinMode(enablePin, OUTPUT);
  pinMode(L293D_1A, OUTPUT);
  pinMode(L293D_2A, OUTPUT);

  analogWrite(enablePin, 200);
}

void loop() 
{
  Serial.println("Counter Clockwise");
  digitalWrite(L293D_1A, HIGH);
  digitalWrite(L293D_2A, LOW);
  delay(2000);

  Serial.println("Clockwise");
  digitalWrite(L293D_1A, LOW);
  digitalWrite(L293D_2A, HIGH);
  delay(2000);
}
