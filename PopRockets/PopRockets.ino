/*
  Record data from sensors into microSD card
*/

#include <Arduino_MKRENV.h>
#include <Arduino_MKRGPS.h>
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

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  // MKR ENV shield
  if (!ENV.begin())
  {
    Serial.println("MKR ENV shield failed to initialize!");
    while (1)
      ;
  }

  // MKR GPS Shield
  if (!GPS.begin())
  {
    Serial.println("MKR GPS Shield failed to initialize!");
    while (1)
      ;
  }

  // microSD Card
  if (!SD.begin(4))
  {
    Serial.println("microSD card failed to initialize!");
    while (1)
      ;
  }

  // One Wire Temperature Sensor
  sensors.begin();

  Serial.println("Successfully initialized sensors.");

  // Open data file
  File dataFile = SD.open(filename, FILE_WRITE);

  // Write data file if missing
  if (!SD.exists(filename) && dataFile)
  {
    Serial.print("Writing new data file...");
    dataFile.println("Timestamp (Epoch),Temperature (°C),Humidity (%),Pressure (kPa),Illuminance (lx),Liquid Temperature (°C),Latitude,Longitude,Altitude (m),Speed (km/h),Satellites");
    dataFile.close();
  }
  else if (dataFile)
  {
    Serial.println("Data file already exists, appending data.");
    dataFile.close();
  }
  else
  {
    Serial.println("Unknown error checking data file!");
  }

  Serial.println("Successfully initialized SD card.");
}

void loop()
{
  // Fetch data from sensors
  sensors.requestTemperatures();

  if (!GPS.available())
  {
    Serial.println("GPS data not available!");
  }

  float temperature = ENV.readTemperature(); // MKR ENV Shield
  float humidity = ENV.readHumidity();
  float pressure = ENV.readPressure();
  float illuminance = ENV.readIlluminance();
  float latitude = GPS.latitude(); // MKR GPS Shield
  float longitude = GPS.longitude();
  float altitude = GPS.altitude();
  float speed = GPS.speed();
  int satellites = GPS.satellites();
  unsigned long epochTime = GPS.getTime();
  float liquidTemperature = sensors.getTempCByIndex(0); // One Wire Temperature Sensor

  if (liquidTemperature == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Liquid temperature sensor disconnected!");
  }

  // Print sensor data to serial
  Serial.print("Epoch time: ");
  Serial.println(epochTime);

  Serial.print("Temperature = "); // MKR ENV Shield
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" kPa");

  Serial.print("Illuminance = ");
  Serial.print(illuminance);
  Serial.println(" lx");

  Serial.print("Liquid Temperature = ");
  Serial.println(liquidTemperature);
  Serial.print(" °C");

  Serial.print("Location = "); // MKR GPS Shield
  Serial.print(latitude, 7);
  Serial.print(", ");
  Serial.println(longitude, 7);

  Serial.print("Altitude = ");
  Serial.print(altitude);
  Serial.println("m");

  Serial.print("Ground speed = ");
  Serial.print(speed);
  Serial.println(" km/h");

  Serial.print("Number of satellites = ");
  Serial.println(satellites);

  Serial.println(); // Print empty line

  // Write sensor data to data file
  File dataFile = SD.open(filename, FILE_WRITE);

  if (dataFile)
  {
    String dataString = String(epochTime) + ",";
    dataString += String(temperature) + ",";
    dataString += String(humidity) + ",";
    dataString += String(pressure) + ",";
    dataString += String(illuminance) + ",";
    dataString += String(liquidTemperature) + ",";
    dataString += String(latitude, 7) + ",";
    dataString += String(longitude, 7) + ",";
    dataString += String(altitude) + ",";
    dataString += String(speed) + ",";
    dataString += String(satellites);

    dataFile.println(dataString);
    dataFile.close();
  }
  else
  {
    Serial.println("Error writing to data file!");
  }

  delay(1000);
}