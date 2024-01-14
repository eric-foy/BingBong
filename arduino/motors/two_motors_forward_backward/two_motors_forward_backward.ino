int enablePin1 = 6;
int L293D_1A = 5;
int L293D_2A = 4;

int enablePin2 = 10;
int L293D_3A = 9;
int L293D_4A = 8;

void setup()
{
  Serial.begin(9600);

  pinMode(enablePin1, OUTPUT);
  pinMode(L293D_1A, OUTPUT);
  pinMode(L293D_2A, OUTPUT);

  pinMode(enablePin2, OUTPUT);
  pinMode(L293D_3A, OUTPUT);
  pinMode(L293D_4A, OUTPUT);

  analogWrite(enablePin1, 200);
  analogWrite(enablePin2, 200);
}

void loop() 
{
  Serial.println("Forward");
  digitalWrite(L293D_1A, HIGH);
  digitalWrite(L293D_2A, LOW);
  digitalWrite(L293D_3A, LOW);
  digitalWrite(L293D_4A, HIGH);
  delay(10000); // 10 seconds

  Serial.println("Backward");
  digitalWrite(L293D_1A, LOW);
  digitalWrite(L293D_2A, HIGH);
  digitalWrite(L293D_3A, HIGH);
  digitalWrite(L293D_4A, LOW);
  delay(10000); // 10 seconds
}