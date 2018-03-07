#ifndef PIXELPARTY_H
#define PIXELPARTY_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class PixelParty {
  /* party vars */
  unsigned long timestamp = 0;

  /* time in ms between party ticks */
  uint16_t timeout = 10;

  /* amount to increment party colors on the color wheel */
  uint8_t increment = 20;

  /* which pixel to update */
  uint8_t pixelPosition = 0;

  /* current position on the color wheel */
  int wheelValue = 0;

 public:
  PixelParty();
  void party(Adafruit_NeoPixel * neoPixels);

 private:
 void tickValues(Adafruit_NeoPixel * neoPixels);
  uint32_t colorWheel(byte wheelPosition, Adafruit_NeoPixel * neoPixels);
};

#endif