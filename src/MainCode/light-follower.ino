// Define LDR sensor pins
#define LDR_LEFT A0
#define LDR_CENTER A1
#define LDR_RIGHT A2

// Define motor driver pins
#define ENA 9  // Speed control for left motor
#define IN1 8  // Left motor forward
#define IN2 7  // Left motor backward
#define ENB 10 // Speed control for right motor
#define IN3 6  // Right motor forward
#define IN4 5  // Right motor backward

void setup() {
    pinMode(LDR_LEFT, INPUT);
    pinMode(LDR_CENTER, INPUT);
    pinMode(LDR_RIGHT, INPUT);
    
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    
    Serial.begin(9600); // For debugging
}

void loop() {
    int leftLDR = analogRead(LDR_LEFT);
    int centerLDR = analogRead(LDR_CENTER);
    int rightLDR = analogRead(LDR_RIGHT);
    
    Serial.print("L:"), Serial.print(leftLDR);
    Serial.print(" C:"), Serial.print(centerLDR);
    Serial.print(" R:"), Serial.println(rightLDR);
    
    if (centerLDR > leftLDR && centerLDR > rightLDR) {
        moveForward();
    } else if (leftLDR > rightLDR) {
        turnLeft();
    } else if (rightLDR > leftLDR) {
        turnRight();
    } else {
        stopMotors();
    }
    delay(100);
}

void moveForward() {
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnLeft() {
    analogWrite(ENA, 100);
    analogWrite(ENB, 150);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnRight() {
    analogWrite(ENA, 150);
    analogWrite(ENB, 100);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
