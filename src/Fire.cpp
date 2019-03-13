#include "Fire.h"
#include <math.h>

Fire::Fire() {}

void Fire::start(Adafruit_NeoPixel * neoPixels) {
  /* check if timeout has expired */
  if (millis() - timestamp < timeout) {
    /* timeout hasn't expired, return */
    return;
  }

  setColors(neoPixels);

  /* update the timestamp */
  timestamp = millis();
}

void Fire::setColors(Adafruit_NeoPixel * neoPixels) {
  int min = 0;
  int max = 150;

  for (uint8_t i = 0; i < neoPixels->numPixels(); i++) {
    int randomYellowValue = min + (rand() % static_cast<int>(max - min + 1));
    neoPixels->setPixelColor(i, neoPixels->Color(255, randomYellowValue, 0));
  }

  neoPixels->show();
}
