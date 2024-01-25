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
}

void loop() 
{
  // motor 1 on left

  Serial.println("Turn in place (right)");
  // turn in place (right)
  digitalWrite(L293D_1A, LOW);
  digitalWrite(L293D_2A, HIGH);

  digitalWrite(L293D_3A, LOW);
  digitalWrite(L293D_4A, HIGH);

  analogWrite(enablePin1, 200);
  analogWrite(enablePin2, 200);

  delay(8000);

  Serial.println("Turn in place (left)");
  // turn in place (left)
  digitalWrite(L293D_1A, HIGH);
  digitalWrite(L293D_2A, LOW);

  digitalWrite(L293D_3A, HIGH);
  digitalWrite(L293D_4A, LOW);

  analogWrite(enablePin1, 200);
  analogWrite(enablePin2, 200);

  delay(8000);

  Serial.println("Moving turn (left)");
  // moving turn (left)
  digitalWrite(L293D_1A, HIGH);
  digitalWrite(L293D_2A, LOW);

  digitalWrite(L293D_3A, LOW);
  digitalWrite(L293D_4A, HIGH);

  analogWrite(enablePin1, 240);
  analogWrite(enablePin2, 160);

  Serial.println("Moving turn (right)");
  // moving turn (right)
  digitalWrite(L293D_1A, HIGH);
  digitalWrite(L293D_2A, LOW);

  digitalWrite(L293D_3A, LOW);
  digitalWrite(L293D_4A, HIGH);

  analogWrite(enablePin1, 160);
  analogWrite(enablePin2, 240);
}