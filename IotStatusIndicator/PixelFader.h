#ifndef PIXELFADER_H
#define PIXELFADER_H

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

class PixelFader {
  unsigned long timestampLastFade = 0;

  /* default fade timeout to 1ms */
  uint16_t timeout = 1;

  /* default fade increment to 10 */
  uint8_t increment = 10;

  /* default fade increasing to true */
  boolean isFadeIncreasing = true;

  /* default fadeValue to 0 */
  int fadeValue = 0;

  /* fade boundaries */
  int maxFade = 255;
  int minFade = 0;

 public:
  PixelFader();
  void setIncrement(int _increment);
  void setTimeout(int _timeout);
  void fade(Adafruit_NeoPixel* _neoPixels, boolean isRed, boolean isGreen,
            boolean isBlue);

 private:
  void tickFadeValue();
};

#endif
