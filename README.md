#ESP32 I2C ADXL345 Accelerometer Lib

##Introduction
This is a i2c adxl345 lib designed for [esp-idf][1]. Currently there is no i2c lib in esp-idf repository, so I modified a lib from ESP8266 rtos sdk.

##Usage
Please refer to esp32_i2c_adxl345_main.c.

##Notice
I only tested GPIO4 and GPIO5. In theory other pins should also work with the same configurations.

##Credits
- The I2C lib is based on [esp-open-rtos][2]
- The adxl345 lib is based on [Geeetech wiki][3] example code


[1]:https://github.com/espressif/esp-idf
[2]:https://github.com/SuperHouse/esp-open-rtos
[3]:http://www.geeetech.com/wiki/index.php/ADXL345_Triple_Axis_Accelerometer_Breakout