# include <OneWire.h>
# include <DallasTemperature.h>

const int SENSOR_PIN = 7; // D7 pin

OneWire oneWire(SENSOR_PIN); //Connects wire to pin?
DallasTemperature tempSensor(&oneWire); // library to read and convert
// .. data from d1u6i7834uks wire thing

float tempCelsius;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // It's like the baud or something. 
  tempSensor.begin();

  if(tempSensor.getDeviceCount()==0){
    Serial.println("NO TEMPERATURE SENSORS!");
  } 
  else {
    Serial.print(tempSensor.getDeviceCount());
    Serial.println(" TEMPERATURE SENSORS FOUND.");
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:
  tempSensor.requestTemperatures(); //Self-explanatory
  tempCelsius = tempSensor.getTempCByIndex(3); // read temp.
  Serial.print(tempSensor.getTempCByIndex(3));

  if (tempCelsius != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature: ");
  
  Serial.print(tempCelsius);
  Serial.print(" degrees Celsius");
  Serial.println();
  } 

else Serial.println("FAILED TO READ!");
  
/*  if (tempCelsius > 0) Serial.println("HIGHER THAN ZERO"); 
  else Serial.println("LOWER THAN ZERO -- FREEZING!");
  delay(500);
*/
}
