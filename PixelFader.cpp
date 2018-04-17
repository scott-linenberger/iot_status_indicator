#include "PixelFader.h"

PixelFader::PixelFader() {}

void PixelFader::fade(Adafruit_NeoPixel* neoPixels, boolean isRed,
                      boolean isGreen, boolean isBlue) {
  /* check if the fade timeout has passed */
  if (millis() - timestampLastFade < timeout) {
    /*timeout hasn't passed, do nothing */
    return;
  }

  /* timeout has passed, do fade */
  tickFadeValue();

  /* update the pixels */
  for (uint8_t i = 0; i < neoPixels->numPixels(); i++) {
    uint8_t valueRed = isRed ? fadeValue : 0;
    uint8_t valueGreen = isGreen ? fadeValue : 0;
    uint8_t valueBlue = isBlue ? fadeValue : 0;
    neoPixels->setPixelColor(i, valueRed, valueGreen, valueBlue);
  }

  /* show the update */
  neoPixels->show();

  /* update the timestamp */
  timestampLastFade = millis();
}

void PixelFader::tickFadeValue() {
  /* tick the value up or down */
  if (isFadeIncreasing) {
    fadeValue += increment;
  } else {
    fadeValue -= increment;
  }

  /* check if the fade value has maxed out */
  if (fadeValue >= maxFade) {
    /* set it to the max and start fading down */
    fadeValue = maxFade;
    isFadeIncreasing = false;
  }

  /* check if the fade has bottomed out */
  if (fadeValue <= minFade) {
    /* set the fade to the min and start fading up */
    fadeValue = minFade;
    isFadeIncreasing = true;
  }
}

/* set the fade increment (how much the fade changes per fade change) */
void PixelFader::setIncrement(int _increment) { increment = _increment; }

/* sets the fade timeout (how fast the fade goes: less is faster, more is
 * slower) */
void PixelFader::setTimeout(int _timeout) { timeout = _timeout; }