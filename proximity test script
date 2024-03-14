#define TRIG_PIN 9
#define ECHO_PIN 10

int beepCounter = 0; // Initialize the counter

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    long duration, distance;
    
    digitalWrite(TRIG_PIN, LOW);  
    delayMicroseconds(2); 
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10); 
    digitalWrite(TRIG_PIN, LOW);
    
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration / 2) / 29.1; // Convert to distance in cm

    if (distance <= 2.54) { // 1 inch is 2.54 cm
        beepCounter++;
        Serial.print("Beep ");
        Serial.println(beepCounter);
    }

    delay(10);
}
