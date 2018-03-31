#include "ColorCycle.h"

ColorCycle::ColorCycle() {}

void ColorCycle::start(Adafruit_NeoPixel * neoPixels) {
  /* check if timeout has expired */
  if (millis() - timestamp < timeout) {
    /* timeout hasn't expired, return */
    return;
  }

  /* tick the pixel position and color wheel values */
  tickValues(neoPixels);

  /* get the current color */
  uint32_t currentColor = colorWheel(wheelValue, neoPixels);

  /* update the pixels */
  for (uint8_t i = 0; i < neoPixels->numPixels(); i++) {
    neoPixels->setPixelColor(i, currentColor);
  }

  neoPixels->show();

  /* update the timestamp */
  timestamp = millis();
}

void ColorCycle::tickValues(Adafruit_NeoPixel * neoPixels) {
  /* increment the color on the color wheel */
  wheelValue += increment;

  /* reset the value if needed */
  wheelValue > 255 ? 0 : wheelValue;
}

uint32_t ColorCycle::colorWheel(byte wheelPosition, Adafruit_NeoPixel * neoPixels) {
  wheelPosition = 255 - wheelPosition;
  if (wheelPosition < 85) {
    return neoPixels->Color(255 - wheelPosition * 3, 0, wheelPosition * 3);
  }
  if (wheelPosition < 170) {
    wheelPosition -= 85;
    return neoPixels->Color(0, wheelPosition * 3, 255 - wheelPosition * 3);
  }
  wheelPosition -= 170;
  return neoPixels->Color(wheelPosition * 3, 255 - wheelPosition * 3, 0);
}