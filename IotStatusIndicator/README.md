# iot_status_indicator
A simple library for creating an IOT status indicator using Adafruit IO and Adafruit's WiFi Feather boards.

You'll need an IO account with [AdafruitIO](https://io.adafruit.com). Adafruit has incredible resources to 
help get you setup. Check out their [Learn](https://learn.adafruit.com/category/adafruit-io) page if you 
are new to AdafruitIO and need some help getting setup. 

**Important**: You WILL need the Adafruit libraries. [This](https://learn.adafruit.com/adafruit-io-basics-esp8266-arduino/arduino-io-library) is a fantastic resource for getting 
your Arduino IDE ready for using WiFi Feather boards. 

Simply download [this](https://github.com/scott-linenberger/iot_status_indicator/tree/1.0.0) repository as a ZIP file. Then import it into your Arduino IDE using  
`Sketch -> Include Library -> Add .ZIP Library` 

Once you've added the library, you can open the usage example by using  
`File -> Examples -> iot_status_indicator-<version> -> basicUsage`  

In the example, set the values for the following variables  
```
#define IO_USERNAME ""
#define IO_KEY ""
#define WIFI_SSID ""
#define WIFI_PASS ""
```
`IO_USERNAME` and `IO_KEY` need to come from your AdafruitIO account and `WIFI_SSID` and `WIFI_PASS` are your WiFi credentials. 
