#include <Servo.h>

// Define pins for Ultrasonic Sensor
const int pingTrigPin = 12;
const int pingEchoPin = 13;

// Servo motor instance
Servo myservo;
int pos = 0;

// Setup function: runs once
void setup() {
  // Flame sensor inputs
  pinMode(1, INPUT);  // Center flame sensor
  pinMode(2, INPUT);  // Right flame sensor
  pinMode(3, INPUT);  // Left flame sensor

  // Motor control outputs
  pinMode(6, OUTPUT); // Motor1 IN1
  pinMode(7, OUTPUT); // Motor1 IN2
  pinMode(8, OUTPUT); // Motor2 IN1
  pinMode(9, OUTPUT); // Motor2 IN2

  // Water pump control
  pinMode(10, OUTPUT);

  // Attach servo motor
  myservo.attach(11);
  myservo.write(90);  // Initialize to center position
}

// Function to spray water and extinguish fire
void put_off_fire() {
  digitalWrite(10, HIGH); // Turn pump on
  delay(500);

  // Sweep servo right to left
  for (pos = 1; pos <= 90; pos++) {
    myservo.write(pos);
    delay(10);
  }

  // Sweep servo back
  for (pos = 90; pos >= 2; pos--) {
    myservo.write(pos);
    delay(10);
  }

  digitalWrite(10, LOW); // Turn pump off
  myservo.write(90);     // Reset to center
}

// Convert microseconds to centimeters
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

// Loop function: runs repeatedly
void loop() {
  long duration, cm;

  // Trigger Ultrasonic
  pinMode(pingTrigPin, OUTPUT);
  digitalWrite(pingTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTrigPin, LOW);

  // Read Echo
  pinMode(pingEchoPin, INPUT);
  duration = pulseIn(pingEchoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  // If obstacle detected between 20cm and 50cm
  if (cm >= 20 && cm < 50) {
    // Move Forward
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);

    // Turn slightly
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }

  // Center Flame Detected
  if (digitalRead(1) == HIGH) {
    // Stop
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    put_off_fire(); // Extinguish fire
  }

  // Right Flame Detected
  if (digitalRead(2) == HIGH) {
    // Turn Right
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    // Stop
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  // Left Flame Detected
  if (digitalRead(3) == HIGH) {
    // Turn Left
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    // Stop
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
}
