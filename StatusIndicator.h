#ifndef STATUS_INDICATOR_H
#define STATUS_INDICATOR_H

#include <Adafruit_NeoPixel.h>
#include "PixelFader.h"
#include "PixelParty.h"

/* declare states */
#define STATE_AVAILABLE 1
#define STATE_MEETING 2
#define STATE_OFFLINE 3
#define STATE_REMOTE 4
#define STATE_DO_NOT_DISTURB 5
#define STATE_COMMUTING 6
#define STATE_ON_A_CALL 7
#define STATE_PARTY_TIME 99

class StatusIndicator {
  Adafruit_NeoPixel *neoPixels;
  PixelFader fader = PixelFader();
  PixelParty pixelParty = PixelParty();

  /* default state is OFFLINE */
  int state = 0;
  String currentStatus = "Current status: Unknown";

 public:
  StatusIndicator();
  void begin(Adafruit_NeoPixel &_neoPixels);
  void run();
  String updateState(int _state);

 private:
  void displayColor(uint32_t color);
};

#endif