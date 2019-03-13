#include "Color.h"

uint32_t Color::wheel(byte position, Adafruit_NeoPixel * neoPixels) {
   position = 255 - position;
  if (position < 85) {
    return neoPixels->Color(255 - position * 3, 0, position * 3);
  }
  if (position < 170) {
    position -= 85;
    return neoPixels->Color(0, position * 3, 255 - position * 3);
  }
  position -= 170;
  return neoPixels->Color(position * 3, 255 - position * 3, 0);
}