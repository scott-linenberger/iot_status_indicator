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
  uint32_t currentColor = Color::wheel(wheelValue, neoPixels);

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
