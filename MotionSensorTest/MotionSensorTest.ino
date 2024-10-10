const int MOTION_SENSOR_PIN = 5; //D5
//const int LED_PIN = 7; // D7
//const int buzzer = 7; //D7 relay thang
#define DEVICE_DISCONNECTED_C -1

int motionCurrentState = LOW; 
int motionPreviousState = LOW;


void beepBuzzer(int times){
  for(int i=0; i<times; i++){
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    delay(1000);   
  }  
}

void setup() { 
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(MOTION_SENSOR_PIN, INPUT); // Sensor is input
  pinMode(2, OUTPUT);
 // pinMode(, OUTPUT); // for buzzer

}

void loop() {
  // put your main code here, to run repeatedly:
  motionPreviousState = motionCurrentState; // Store old state thing [why? Idk]
 // OHHH so when it loops it stores the new data AS the old, and compares it
 // to the NEW NEW data.
  motionCurrentState = digitalRead(MOTION_SENSOR_PIN); //Reads and stores

 if ((motionCurrentState != DEVICE_DISCONNECTED_C)&&(motionPreviousState!= DEVICE_DISCONNECTED_C)){
 // Serial.println("lkjbeghjtg");    // Yup it works
  if (motionPreviousState == LOW && motionCurrentState==HIGH){
  Serial.println("MOTION DETECTED!!");//Why it called serial anyway
  // bcz it shows up on the Serial MONITOR, dummy
 // digitalWrite(LED_PIN, HIGH);
  beepBuzzer(3);
    
  }

  if(motionPreviousState==HIGH && motionCurrentState==LOW){
    Serial.println("MOTION STOPPED.");
  //  digitalWrite(LED_PIN, LOW);

    
 //   digitalWrite(AMBER_LED_PIN, HIGH);
  }
 }
 else{
 Serial.println("FAILED TO READ!"); //Just a check
 }
 }
 /* else {
    digitalWrite(AMBER_LED_PIN, HIGH);
    Serial.println("No motion");
    delay(5000);
  } */
 
