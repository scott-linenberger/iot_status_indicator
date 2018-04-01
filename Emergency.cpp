#include "Emergency.h"
#include <math.h>

Emergency::Emergency() {}

void Emergency::start(Adafruit_NeoPixel * neoPixels) {
  /* check if timeout has expired */
  if (millis() - timestamp < timeout) {
    /* timeout hasn't expired, return */
    return;
  }

  setColors(neoPixels);

  /* update the timestamp */
  timestamp = millis();
}

void Emergency::setColors(Adafruit_NeoPixel * neoPixels) {
  /* determine a logical halfway point on pixel strip */
  uint8_t middlePixelPosition = ceil(neoPixels->numPixels() / 2);

  /* define emergency colors */
  uint32_t red = neoPixels->Color(255, 0, 0);
  uint32_t blue = neoPixels->Color(0, 0, 255);

  /* set first half of pixel colors */
  for ( uint8_t a = 0; a < middlePixelPosition; a = a + 1 ) {
    neoPixels->setPixelColor(a, (lightSwapIndiactor) ? red : blue);
  }

  /* set second half of pixel colors */
  for ( uint8_t b = middlePixelPosition; b < neoPixels->numPixels(); b = b + 1 ) {
    neoPixels->setPixelColor(b, (lightSwapIndiactor) ? blue : red);
  }

  neoPixels->show();

  /* swap lights indicator for next iteration */
  lightSwapIndiactor = !lightSwapIndiactor;
}
