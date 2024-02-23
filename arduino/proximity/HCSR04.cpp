#define TRIG_PIN 47
#define ECHO_PIN 46

void setupHCSR04() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

int loopHCSR04() {
    long duration, distance;
    
    digitalWrite(TRIG_PIN, LOW);  
    delayMicroseconds(2); 
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10); 
    digitalWrite(TRIG_PIN, LOW);
    
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration / 2) / 29.1; // Convert to distance in cm

    if (distance <= 10.16) { // 1 inch is 2.54 cm
        return 1;
    }

    delay(10);
    return 0;
}

extern void setupHCSR04();
extern int loopHCSR04();
