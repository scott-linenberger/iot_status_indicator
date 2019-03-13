#ifndef COLORCYCLE_H 
#define COLORCYCLE_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Color.h"

class ColorCycle {
  /* party vars */
  unsigned long timestamp = 0;

  /* time in ms between party ticks */
  uint16_t timeout = 1;

  /* amount to increment party colors on the color wheel */
  uint8_t increment = 5;

  /* current position on the color wheel */
  int wheelValue = 0;

 public:
  ColorCycle();
  void start(Adafruit_NeoPixel * neoPixels);

 private:
  void tickValues(Adafruit_NeoPixel * neoPixels);
};

#endif