// Define pin numbers
const int motionSensorPin = 5; // PIR motion sensor output pin
const int ledPin = 13;          // LED pin

void setup() {
  Serial.begin(9600);           // Start serial communication
  pinMode(motionSensorPin, INPUT); // Set motion sensor pin as input
  pinMode(ledPin, OUTPUT);      // Set LED pin as output
}

void loop() {
  int motionState = digitalRead(motionSensorPin); // Read motion sensor

  if (motionState == HIGH) {
    // Motion detected
    Serial.println("Motion detected!");
    digitalWrite(ledPin, HIGH); // Turn on LED
  } else {
    // No motion
    Serial.println("No motion.");
    digitalWrite(ledPin, LOW); // Turn off LED
  }

  delay(500); // Short delay for stability
}
