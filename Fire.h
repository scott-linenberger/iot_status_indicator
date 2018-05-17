#ifndef FIRE_H
#define FIRE_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Fire {
  /* emergency vars */
  unsigned long timestamp = 0;

  /* time in ms between light swaps */
  uint16_t timeout = 100;

 public:
  Fire();
  void start(Adafruit_NeoPixel * neoPixels);

 private:
  void setColors(Adafruit_NeoPixel * neoPixels);
};

#endif