# Pop Rockets

Pop Rockets is a project to make popsicles in the [stratosphere](https://en.wikipedia.org/wiki/Stratosphere) and record the altitiude in which popsicles freeze via high-altitude-balloons (HAB).

This project is a part of [Apex Hacks 2025](https://apex.hackclub.com) from [Hack Club](https://hackclub.com). Apex has provided us with the resources to make this project a reality including funding, travel and lodging, and a team of event organizers to help us along the way.

[![Apex wordmark](https://apex.hackclub.com/_astro/wordmark.D2ClV-3K_TMzl.webp)](https://apex.hackclub.com)

## Materials

We can see the [Bill of Materials](Bill%20of%20Materials.csv) we used to make this project. All materials have been checked to operate as low as -20°C.

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

We don't have a way to measure altitude because the way Apex projects a launched, they already record the altitude for us. You use something like the [Arduino MKR GPS Shield](https://store.arduino.cc/products/arduino-mkr-gps-shield) to measure altitude.

If you're using a different GPS, make sure it works over 60,000 ft since most do not.

If you're using a barometer to get pressure and derive altitude from it, make sure records as low as 10 hPa or you may get inaccurate altitude. Most barometers don't measure that low.
