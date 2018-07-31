# IOT Status Indicator
Ever want to display the status of something with set of colored LEDs? For example: red lights mean "busy" or "do not disturb" or green lights means "ready to go". And do you want to be able to update that stutus from anywhere in the world using a WiFi or mobile connection? Well, today is your lucky day! Because the IOT status indicator is a simple library for creating a status WiFi connected status indicator using Adafruit's IO, WiFi capable devices and NeoPixels!   

## Adafruit IO  
You'll need an [Adafruit IO](LINK_IO) account. We'll use Adafruit IO to publish status updates to our indicator and subscribe to responses from the indicator, so we know our status change happened. We will use a couple of Adafruit IO feeds along with a Dashboard of buttons to make updating our status from the web super fast and easy.

Adafruit has incredible resources to help get you setup. Check out the Adafruit [Learn](LINK_IO_LEARN) page if you are new to AdafruitIO and need some help getting setup. 

## Feather Huzzah  
I am using Adafruit's Feather Huzzah with ESP8266, but you can also use Adafruit's Huzzah breakout with ESP8266 for this project as well. At the time of writing this document, the Adafruit Huzzah32 ESP32 Feather is still in development and has known issues with NeoPixels. For stability, I would recommend sticking to one of the ESP8266 boards at this time.  

The Feather Huzzah is simple to use with the Arduino IDE. Checkout the [Learn](LEARN_FEATHER_HUZZAH) page for the Feather Huzzah for all of the information you need to get started. 

Here is a diagram for wiring the Adafruit Feather Huzzah. The bends in the wires are not important, only where each wire in the diagram starts and ends.

![Adafruit Feather Huzzah Wiring Diagram](images/iot_status_indicator_wiring_diagram.png)

## Using the IOT Status Indicator Library  
Simply download the IOT Status Indicator repository as a ZIP file by clicking on `Clone or Download -> Download ZIP`. Then import it into your Arduino IDE by clicking  
`Sketch -> Include Library -> Add .ZIP Library`. 

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

## Additional Libraries  
The IOT Status Indicator library relies on other Arduino Libraries. You'll need to download these additional libraries to compile and upload the IOT Status Indicator code.  

To download the additional libraries from the Arduino IDE, go to `Sketch->Include Library->Manage Libraries...` Then, search for the library by the name listed below and install. 

Alternatively, you can also go the Github links provided below, click on the "Clone or Download" button and download the libraries as zip files and then add them to your Arduino IDE by adding by clicking `Sketch -> Include Library -> Add .ZIP Library` 

* [Adafruit NeoPixel](LIBRARY_ADAFRUIT_NEOPIXEL) by Adafruit 
* [Adafruit IO](LIBRARY_ADAFRUIT_IO) by Adafruit 
* [Adafruit MQTT](LIBRARY_ADAFRUIT_MQTT) by Adafruit
* [Arduino HTTP Client (Experimental)](LIBRARY_ARDUINO_HTTP_CLIENT) by Arduino

[LINK_IO]: https://io.adafruit.com
[LINK_IO_LEARN]: https://learn.adafruit.com/category/adafruit-io
[LINK_PRODUCT_FEATHER_HUZZAH]: https://www.adafruit.com/product/2821
[LEARN_FEATHER_HUZZAH]: https://learn.adafruit.com/adafruit-io-basics-esp8266-arduino/arduino-io-library
[LIBRARY_ADAFRUIT_NEOPIXEL]: https://github.com/adafruit/Adafruit_NeoPixel
[LIBRARY_ADAFRUIT_IO]: https://github.com/adafruit/Adafruit_IO_Arduino
[LIBRARY_ADAFRUIT_MQTT]: https://github.com/adafruit/Adafruit_MQTT_Library
[LIBRARY_ARDUINO_HTTP_CLIENT]: https://github.com/arduino-libraries/ArduinoHttpClient
