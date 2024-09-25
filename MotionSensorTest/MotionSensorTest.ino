const int MOTION_SENSOR_PIN = 4; //D4
const int LED_PIN = 2; // D2
int motionCurrentState = LOW; 
int motionPreviousState = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MOTION_SENSOR_PIN, INPUT); // Sensor is input
  pinMode(LED_PIN, OUTPUT); // LED is output

}

void loop() {
  // put your main code here, to run repeatedly:
  motionPreviousState = motionCurrentState; // Store old state thing [why? Idk]
 // OHHH so when it loops it stores the new data AS the old, and compares it
 // to the NEW NEW data.
  motionCurrentState = digitalRead(MOTION_SENSOR_PIN); //Reads and stores

  if (motionPreviousState == LOW && motionCurrentState==HIGH){
  Serial.println("MOTION DETECTED!!");//Why it called serial anyway
  digitalWrite(LED_PIN, HIGH);
  }

  if(motionPreviousState==HIGH && motionCurrentState==LOW){
    Serial.println("MOTION STOPPED.");
    digitalWrite(LED_PIN, LOW);
  }
}
