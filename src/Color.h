#ifndef COLOR_H
#define COLOR_H

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

class Color {
 public:
  static uint32_t wheel(byte position, Adafruit_NeoPixel* neoPixels);
};

#endif