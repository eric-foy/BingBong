// Using enable jumper right now so no need for enable pins. Max speed at 5V with jumper


// Right Motors
//int enablePin1 = 3;
int L298N_1A = 2;
int L298N_2A = 4;
//int enablePin2 = 6;
int L298N_3A = 5;
int L298N_4A = 7;

// Left Motors
//int enablePin1 = 9;
int L298N_2_1A = 8;
int L298N_2_2A = 10;
//int enablePin2 = 11;
int L298N_2_3A = 12;
int L298N_2_4A = 13;

void setup()
{
  //Serial.begin(9600);

  // ---------------------------------------------------
  // Right Motors
  // ---------------------------------------------------

  //pinMode(enablePin1, OUTPUT);
  pinMode(L298N_1A, OUTPUT);
  pinMode(L298N_2A, OUTPUT);

  //pinMode(enablePin2, OUTPUT);
  pinMode(L298N_3A, OUTPUT);
  pinMode(L298N_4A, OUTPUT);

  // ---------------------------------------------------
  // Left Motors
  // ---------------------------------------------------

  pinMode(L298N_2_1A, OUTPUT);
  pinMode(L298N_2_2A, OUTPUT);

  //pinMode(enablePin2, OUTPUT);
  pinMode(L298N_2_3A, OUTPUT);
  pinMode(L298N_2_4A, OUTPUT);
}

void forward(int delayMilli)
{
  // ---------------------------------------------------
  // Right Motors
  // ---------------------------------------------------

  // Counter Clockwise left motor
  digitalWrite(L298N_1A, HIGH);
  digitalWrite(L298N_2A, LOW);

  // Clockwise right motor
  digitalWrite(L298N_3A, LOW);
  digitalWrite(L298N_4A, HIGH);

  // ---------------------------------------------------
  // Left Motors
  // ---------------------------------------------------

  // Counter Clockwise left motor
  digitalWrite(L298N_2_1A, LOW);
  digitalWrite(L298N_2_2A, HIGH);

  // Clockwise right motor
  digitalWrite(L298N_2_3A, HIGH);
  digitalWrite(L298N_2_4A, LOW);

  delay(delayMilli);
}

void backward(int delayMilli)
{
  // ---------------------------------------------------
  // Right Motors
  // ---------------------------------------------------

  // Counter Clockwise left motor
  digitalWrite(L298N_1A, LOW);
  digitalWrite(L298N_2A, HIGH);

  // Clockwise right motor
  digitalWrite(L298N_3A, HIGH);
  digitalWrite(L298N_4A, LOW);

  // ---------------------------------------------------
  // Left Motors
  // ---------------------------------------------------

  // Counter Clockwise left motor
  digitalWrite(L298N_2_1A, HIGH);
  digitalWrite(L298N_2_2A, LOW);

  // Clockwise right motor
  digitalWrite(L298N_2_3A, LOW);
  digitalWrite(L298N_2_4A, HIGH);

  delay(delayMilli);
}

void loop() 
{
  forward(2000);
  backward(2000);
}
