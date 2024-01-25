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

  // Counter Clockwise left motor
  digitalWrite(L293D_1A, HIGH);
  digitalWrite(L293D_2A, LOW);

  // Clockwise right motor
  digitalWrite(L293D_3A, LOW);
  digitalWrite(L293D_4A, HIGH);
}

void loop() 
{
  Serial.println("Start");
  analogWrite(enablePin1, 200);
  analogWrite(enablePin2, 200);

  delay(8000);

  Serial.println("Stop");
  analogWrite(enablePin1, 0);
  analogWrite(enablePin2, 0);

  delay(8000);
}
