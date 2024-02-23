// Right Motors
int enablePin1 = 3;
int L298N_1A = 2;
int L298N_2A = 4;
int enablePin2 = 6;
int L298N_3A = 5;
int L298N_4A = 7;

// Left Motors
int enablePin3 = 9;
int L298N_2_1A = 8;
int L298N_2_2A = 10;
int enablePin4 = 11;
int L298N_2_3A = 12;
int L298N_2_4A = 13;

void setupL298N()
{
  //Serial.begin(9600);

  // ---------------------------------------------------
  // Right Motors
  // ---------------------------------------------------

  pinMode(enablePin1, OUTPUT);
  pinMode(L298N_1A, OUTPUT);
  pinMode(L298N_2A, OUTPUT);

  pinMode(enablePin2, OUTPUT);
  pinMode(L298N_3A, OUTPUT);
  pinMode(L298N_4A, OUTPUT);

  // ---------------------------------------------------
  // Left Motors
  // ---------------------------------------------------

  pinMode(enablePin3, OUTPUT);
  pinMode(L298N_2_1A, OUTPUT);
  pinMode(L298N_2_2A, OUTPUT);

  pinMode(enablePin4, OUTPUT);
  pinMode(L298N_2_3A, OUTPUT);
  pinMode(L298N_2_4A, OUTPUT);
}

void stop()
{
  analogWrite(enablePin1, 0);
  analogWrite(enablePin2, 0);
  analogWrite(enablePin3, 0);
  analogWrite(enablePin4, 0);
}

// duration in milliseconds, speed between 0 and 255
void forward(int duration, int speed)
{
  analogWrite(enablePin1, speed);
  analogWrite(enablePin2, speed);
  analogWrite(enablePin3, speed);
  analogWrite(enablePin4, speed);

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

  delay(duration);
}

// duration in milliseconds, speed between 0 and 255
void backward(int duration, int speed)
{
  analogWrite(enablePin1, speed);
  analogWrite(enablePin2, speed);
  analogWrite(enablePin3, speed);
  analogWrite(enablePin4, speed);

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

  delay(duration);
}

// duration in milliseconds, speed between 0 and 255
void spinRight(int duration, int speed)
{
  analogWrite(enablePin1, speed);
  analogWrite(enablePin2, speed);
  analogWrite(enablePin3, speed);
  analogWrite(enablePin4, speed);

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
  digitalWrite(L298N_2_1A, HIGH);
  digitalWrite(L298N_2_2A, LOW);

  // Clockwise right motor
  digitalWrite(L298N_2_3A, LOW);
  digitalWrite(L298N_2_4A, HIGH);

  delay(duration);
}

// duration in milliseconds, speed between 0 and 255
void spinLeft(int duration, int speed)
{
  analogWrite(enablePin1, speed);
  analogWrite(enablePin2, speed);
  analogWrite(enablePin3, speed);
  analogWrite(enablePin4, speed);

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
  digitalWrite(L298N_2_1A, LOW);
  digitalWrite(L298N_2_2A, HIGH);

  // Clockwise right motor
  digitalWrite(L298N_2_3A, HIGH);
  digitalWrite(L298N_2_4A, LOW);

  delay(duration);
}

// duration in milliseconds, speeds between 0 and 255
// speed right > speed left = a left turn
// speed left > speed right = a right turn
void turn(int duration, int speedLeft, int speedRight)
{
  analogWrite(enablePin1, speedLeft);
  analogWrite(enablePin2, speedLeft);
  analogWrite(enablePin3, speedRight);
  analogWrite(enablePin4, speedRight);

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

  delay(duration);
}

extern void setupL298N();
extern void stop();
extern void forward();
extern void backward();
extern void spinRight();
extern void spinLeft();
extern void turn();
