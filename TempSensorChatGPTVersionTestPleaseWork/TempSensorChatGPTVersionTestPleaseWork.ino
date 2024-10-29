#include <DHT.h>
#include <EEPROM.h>

//#include <SPI.h>
// #include <SD.h>

#define DHTPIN 3      // Pin D3
#define DHTTYPE DHT22 // DHT 22 (AM2302)

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Gonna create structure to have both temp. and humidity be stored
struct SensorData {
  float temperature;
  float humidity;
};

const int arraySize = 5;
SensorData sensorDataArray[arraySize];
int currentCount=0;

void setup() {
  Serial.begin(9600); // Start serial communication
  dht.begin();        // Initialize the DHT sensor
}

void loop() {

  // Read temperature as Celsius
  float temperature = dht.readTemperature();
  // Read humidity
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  sensorDataArray[currentCount].temperature=temperature;
  sensorDataArray[currentCount].humidity=humidity;

EEPROM.put(currentCount*sizeof(SensorData), sensorDataArray[currentCount]);

SensorData storedValue;
EEPROM.get(currentCount*sizeof(SensorData), storedValue);

/*
if(storedValue.temperature == sensorDataArray[currentCount].temperature &&
  storedValue.humidity == sensorDataArray[currentCount].humidity){
  Serial.print("Successfully written to EEPROM address ");
  Serial.print(currentCount*sizeof(SensorData));
  Serial.print(": ");
  Serial.print("Temperature: ");
  Serial.println(storedValue.temperature);
  Serial.print(", Humidity: ");
  Serial.println(storedValue.humidity);
} else Serial.println("FAILED TO WRITE TO EEPROM ADDRESS!");
*/
//This was just debugging -- it works

  currentCount++; 
  if(currentCount >= arraySize) currentCount=0;
    
Serial.println("Sensor readings: ");
for(int counter =0; counter < arraySize; counter++){
  Serial.print("Reading #");
  Serial.print(counter+1);
  Serial.print(": ");
  Serial.print("Temperature: ");
  Serial.println(sensorDataArray[counter].temperature);
  Serial.print(", Humidity: ");
  Serial.println(sensorDataArray[counter].humidity);
  
  
}

  delay(2000); // Wait a few seconds between readings
}
