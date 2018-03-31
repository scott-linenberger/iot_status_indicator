#ifndef STATUS_INDICATOR_H
#define STATUS_INDICATOR_H

#include <Adafruit_NeoPixel.h>
#include "PixelFader.h"
#include "PixelParty.h"
#include "Emergency.h"
#include "ColorCycle.h"

/* declare states */
#define STATE_GREEN 1
#define STATE_YELLOW 2
#define STATE_BLUE 3
#define STATE_PURPLE 4
#define STATE_RED 5
#define STATE_GREEN_PULSING 6
#define STATE_RED_PULSING 7
#define STATE_EMERGENCY 97
#define STATE_COLORCYCLE 98
#define STATE_PARTY_TIME 99

class StatusIndicator {
  Adafruit_NeoPixel *neoPixels;
  PixelFader fader = PixelFader();
  PixelParty pixelParty = PixelParty();
  Emergency emergency = Emergency();
  ColorCycle colorCycle = ColorCycle();

  /* default state is OFFLINE */
  int state = 0;

 public:
  StatusIndicator();
  void begin(Adafruit_NeoPixel &_neoPixels);
  void run();
  void updateState(int _state);

 private:
  void displayColor(uint32_t color);
};

#endif