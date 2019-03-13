#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Emergency {
  /* emergency vars */
  unsigned long timestamp = 0;

  /* time in ms between light swaps */
  uint16_t timeout = 150;

  bool lightSwapIndiactor = false;

 public:
  Emergency();
  void start(Adafruit_NeoPixel * neoPixels);

 private:
  void setColors(Adafruit_NeoPixel * neoPixels);
};

#endif