# Slushosphere

Slushosphere is a project to make slushies in the [stratosphere](https://en.wikipedia.org/wiki/Stratosphere) via high-altitude-balloons (HAB) and record the altitude in which water becomes a slushie. When water is exposed to low pressure, it boils at a lower temperature. At the same time, it freezes because of the cold temperatures in the stratosphere. We predict because of this, water will turn into a slush in the stratosphere.

How we will achieve this is using an Arduino with an environmental shield that has ambient temperature, humidity, and pressure sensors. A GPS shield will be used to record the location and altitude of the balloon along with time. A connector carrier to connect a submersible temperature sensor to measure the temperature of the water. A microSD card on the environmental shield to record all the data and a battery connected to the Arduino to power it all.

This project is a part of [Apex Hacks 2025](https://apex.hackclub.com) from [Hack Club](https://hackclub.com). Apex has provided us with the resources to make this project a reality including funding, travel and lodging, and a team of event organizers to help us along the way.

[![Apex wordmark](https://apex.hackclub.com/_astro/wordmark.D2ClV-3K_TMzl.webp)](https://apex.hackclub.com)

## Code

You can use either [Arduino IDE 2](https://docs.arduino.cc/software/ide/#ide-v2) or [Visual Studio Code](https://code.visualstudio.com) with [arduino-cli](https://arduino.github.io/arduino-cli) to upload the code to the Arduino MKR WiFi 1010.

## Hardware

We are using the [Arduino Environmental Monitor Bundle](https://store-usa.arduino.cc/products/environmental-monitor-bundle) which includes the following parts:

- [Arduino MKR WiFi 1010](https://store-usa.arduino.cc/products/arduino-mkr-wifi-1010)
  - This is the main board that will run the code and connect to the shields and carriers.
- [Arduino MKR ENV Shield rev2](https://store-usa.arduino.cc/products/arduino-mkr-env-shield-rev2)
  - This shield has the sensors to measure ambient temperature, humidity, and pressure. It also has a microSD card slot to record the data.

In addition to the bundle, we are using the following parts:

- [Arduino MKR GPS Shield](https://store-usa.arduino.cc/products/arduino-mkr-gps-shield)
  - This shield has a GPS module to record the location and altitude of the balloon. It also has a real-time clock (RTC) which will be used to record the time of the data.
- [Arduino MKR Connector Carrier](https://store-usa.arduino.cc/collections/shields-carriers/products/arduino-mkr-connector-carrier-grove-compatible)
  - This carrier has Seeed Studio Grove connectors to connect our submersible temperature sensor from Seeed Studio.
- [One Wire Temperature Sensor DS18B20](https://www.seeedstudio.com/One-Wire-Temperature-Sensor-p-1235.html)
  - This is a submersible temperature sensor that will be used to measure the temperature of the water. It is connected to the MKR Connector Carrier.

### Collected data

The data collected by the Arduino MKR WiFi 1010 will be stored in a microSD card in the Arduino MKR ENV Shield. The data will be in CSV format with the following columns:

- `Timestamp (Epoch)`: The time the data was recorded in epoch format.
- `Temperature (°C)`: The ambient temperature in degrees Celsius measured by the MKR ENV Shield.
- `Humidity (%)`: The ambient humidity in percentage measured by the MKR ENV Shield.
- `Pressure (kPa)`: The ambient pressure in kilopascals measured by the MKR ENV Shield.
- `Illuminance (lx)`: The ambient illuminance in lux measured by the MKR ENV Shield.
- `Liquid Temperature (°C)`: The temperature of the water in degrees Celsius measured by the submersible temperature sensor.
- `Latitude`: The latitude of the balloon's location measured by the MKR GPS Shield.
- `Longitude`: The longitude of the balloon's location measured by the MKR GPS Shield.
- `Altitude (m)`: The altitude of the balloon's location in meters measured by the MKR GPS Shield.
- `Speed (km/h)`: The speed of the balloon in kilometers per hour measured by the MKR GPS Shield.
- `Satellites`: The number of satellites used to calculate the location and altitude measured by the MKR GPS Shield.

## Materials

We can see the [Bill of Materials](Bill%20of%20Materials.csv) we used to make this project. It will contain the manufacturer and Amazon links for you to buy the materials. The total cost of the materials is under 400 USD.

All materials have been checked to operate as low as -20°C. You can see the [Datasheet](Datasheet.md) for each electronic's official datasheet with operating temperatures.

### Student discounts

Discounts you can use if you are a student and doing this project.

- [Ardiuno offers 25% off the Ardiuno MKR Family and more](https://www.arduino.cc/education/github-students)
  - Helpful if you are only buying [Arduino MKR WiFi 1010](https://store.arduino.cc/products/arduino-mkr-wifi-1010). We are not using this because is cheaper to buy the [Arduino Environmental Monitor Bundle](https://store-usa.arduino.cc/products/environmental-monitor-bundle) rather than individually with the discount.
- [Adafruit offers discounts on certain Adafruit products](https://www.adafruit.com/github-students)
  - None of the discounts are for our parts so we cannot use it.
- [Amazon has Prime Student membership which is cheaper than Prime](https://www.amazon.com/joinstudent)
  - If you want faster and free delivery and exclusive Prime discounts. They were no exclusive Prime discounts for our materials at the time of the project.

## Notes

### Altitude tracking

If you're using a different GPS, make sure it works over 60,000 ft since most do not.

If you're using a barometer to get pressure and derive altitude from it, make sure records as low as 10 hPa or you may get inaccurate altitude. Most barometers don't measure that low.
