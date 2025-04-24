/*
  Record data from sensors into microSD card
*/

#include <Arduino_MKRENV.h>
#include <SPI.h>
#include <SD.h>
#include <OneWire.h>
#include <string>
#include <DallasTemperature.h>

// TODO: Change this when we have a physical prototype
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
String filename = "data.csv";

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // MKR ENV shield
  if (!ENV.begin()) {
    Serial.println("MKR ENV shield failed to initialize!");
    while (1);
  }

  // microSD Card
  if (!SD.begin(10)) { // TODO: Change this to proper microSD card pin
    Serial.println("microSD card failed, or not present!");
    while (1);
  }

  // One Wire Temperature Sensor
  sensors.begin();
  
  Serial.println("Successfully initialized sensors.");

  // Open data file
  File dataFile = SD.open(filename, FILE_WRITE);

  // Write data file if missing
  if (!SD.exists(filename) && dataFile) {
    Serial.print("Writing new data file...");
    dataFile.println("Timestamp,Temperature,Humidity,Pressure,Illuminance,Liquid Temperature");
    dataFile.close();
  } else if (dataFile) {
    Serial.println("Data file already exists, appending data.");
    dataFile.close();
  } else {
    Serial.println("Unknown error checking data file!");
  }

  Serial.println("Successfully initialized SD card.");
}

void loop() {
  sensors.requestTemperatures();
  
  float temperature       = ENV.readTemperature(); // MKR ENV Shield
  float humidity          = ENV.readHumidity();
  float pressure          = ENV.readPressure();
  float illuminance       = ENV.readIlluminance();
  float liquidTemperature = sensors.getTempCByIndex(0); // One Wire Temperature Sensor

  if(liquidTemperature == DEVICE_DISCONNECTED_C) 
  {
    Serial.println("Error: Liquid temperature sensor disconnected!");
  }
  
  // Print sensor data to serial
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure    = ");
  Serial.print(pressure);
  Serial.println(" kPa");

  Serial.print("Illuminance = ");
  Serial.print(illuminance);
  Serial.println(" lx");

  Serial.print("Liquid Temperature = ");
  Serial.println(liquidTemperature);
  Serial.println(" °C");

  Serial.println(); // Print empty line

  // Write sensor data to data file
  File dataFile = SD.open(filename, FILE_WRITE);

  if (dataFile) {
    String dataString = "void,";
    dataString += String(temperature) + ",";
    dataString += String(humidity) + ",";
    dataString += String(pressure) + ",";
    dataString += String(illuminance) + ",";
    dataString += String(liquidTemperature);
  
    dataFile.println(dataString);
    dataFile.close();
  } else {
    Serial.println("Error writing to data file!");
  }
  
  delay(1000);
}