#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX

int sensorPin = A0;
int sensorValue = 0;

/* Change these values based on your calibration values */
#define soilWet 500   // Define max value we consider soil 'wet'
#define soilDry 750   // Define min value we consider soil 'dry'

// Sensor pins
#define sensorPower 7
#define sensorPin A0

void setup() {
  pinMode(sensorPower, OUTPUT);
  // Initially keep the sensor OFF
  digitalWrite(sensorPower, LOW);
  Serial.begin(9600);
}

void loop() {
  char input;
  Serial.println("If you want to get info about soil moisture type 'Y': ");
  while (!Serial.available()) {
    // Wait for input
  }
  input = Serial.read();
  
  if (input == 'Y' || input == 'y') {
    int moisture = readSensor();

    Serial.print("Soil moisture: ");
      Serial.println(moisture);
  
    // Determine status of our soil
    if (moisture < soilWet) {

      Serial.println("Status: Soil is too wet");
    } else if (moisture >= soilWet && moisture < soilDry) {
      
      Serial.println("Status: Soil moisture is perfect");
    } else {
      Serial.println("Status: Soil is too dry - time to water!");
    }
  }
  delay(2000);
}

int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);              // Allow power to settle
  int val = analogRead(sensorPin);  // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;             // Return analog moisture value
}
