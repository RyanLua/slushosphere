# Project Datasheet

Datasheet for weight of non-electronics used in the project.

| Item                                       | Weight (g) | Manufacturer Link                               |
| ------------------------------------------ | ---------- | ----------------------------------------------- |
| Polar Tech Thermo Chill 207/T16C 8 x 6 x 7 | 31         | https://www.polar-tech.com/shop/item/207%2Ft16c |

# Electronics Datasheet

Datasheet for the electronics used in the project. Some Fritzing links are not official and may not be up to date. If you find an official Fritzing link, please let us know so we can update it.

| Item                                              | Temperature range (°C) | Weight (g) | Datasheet Link                                                                                                          | Fritzing Link                                                                                              |
| ------------------------------------------------- | ---------------------- | ---------- | ----------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| Arduino MKR WiFi 1010                             | -20 to +80             | 32         | https://docs.arduino.cc/resources/datasheets/ABX00023-datasheet.pdf                                                     | https://content.arduino.cc/assets/Arduino%20MKR%20WIFI%201010.fzpz                                         |
| Arduino MKR ENV Shield rev2                       | -40 to +120            | 32         | https://www.st.com/resource/en/datasheet/hts221.pdf                                                                     | https://content.arduino.cc/assets/Arduino%20MKR%20ENV%20Shield.fzpz                                        |
| Arduino MKR GPS Shield                            | -40 to +85             | 14         | https://content.arduino.cc/assets/Arduino-MKR-GPS-Shield_u-blox8-SAM-M8Q_DataSheet_UBX-16012619.pdf                     | https://forum.fritzing.org/uploads/short-url/vtJmwPP0qo7ksIrhe34RObGyFl4.fzpz                              |
| Arduino MKR Connector Carrier                     |                        | 32         | https://store-usa.arduino.cc/collections/shields-carriers/products/arduino-mkr-connector-carrier-grove-compatible       | https://forum.fritzing.org/uploads/short-url/aA5wYZ3b2lv6sQEg6W6jkxjTFgw.fzpz                              |
| Adafruit Lithium Ion Polymer Battery 3.7v 1200mAh | -20 to +60[^1]         | 23         | https://cdn-shop.adafruit.com/product-files/258/C101-_Li-Polymer_503562_1200mAh_3.7V_with_PCM_APPROVED_8.18.pdf         | https://github.com/adafruit/Fritzing-Library/raw/refs/heads/master/parts/LiPoly%20Battery%20(1300mAh).fzpz |
| One Wire Temperature Sensor DS18B20               | -10 to +85[^2]         | 54         | https://files.seeedstudio.com/wiki/One-Wire-Temperature/res/DS18B20-Datasheet.pdf                                       | https://forum.fritzing.org/uploads/short-url/1y9gVcpzoVgtYc0VBdMwWpETT2A.fzpz                              |
| SanDisk MAX ENDURANCE microSD Card 32GB           | -40 to +85             | 5          | https://shop.sandisk.com/products/memory-cards/microsd-cards/sandisk-max-endurance-uhs-i-microsd?sku=SDSQQVR-032G-GN6IA |                                                                                                            |

[^1]: Discharge temperature range. Does not include charging temperature range.
[^2]: We only measure when it freezes (0°C), so it's fine it can't measure as low as -20°C.
