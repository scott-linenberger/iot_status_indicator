#include "StatusIndicator.h"

StatusIndicator::StatusIndicator() {}

/* initializes NeoPixels */
void StatusIndicator::begin(Adafruit_NeoPixel &_neoPixels) {
  /* set the pixels on our indicator object */
  neoPixels = &_neoPixels;

  /* init the pixel strip */
  neoPixels->begin();
  neoPixels->clear();
  neoPixels->show();
}

void StatusIndicator::run() {
  switch (state) {
    case STATE_GREEN:
      displayColor(neoPixels->Color(0, 255, 20));
      break;

    case STATE_YELLOW:
      displayColor(neoPixels->Color(200, 200, 0));
      break;

    case STATE_BLUE:
      displayColor(neoPixels->Color(50, 50, 255));
      break;

    case STATE_PURPLE:
      displayColor(neoPixels->Color(255, 0, 255));
      break;

    case STATE_RED:
      displayColor(neoPixels->Color(255, 10, 10));
      break;

    case STATE_GREEN_PULSING:
      fader.fade(neoPixels, false, true, false);
      break;

    case STATE_RED_PULSING:
      fader.fade(neoPixels, true, false, false);
      break;

    case STATE_PARTY_TIME:
      pixelParty.party(neoPixels);
      break;

    default:
      /* unknown state, clear pixels */
      neoPixels->clear();
      neoPixels->show();
      break;
  }
}

void StatusIndicator::displayColor(uint32_t color) {
  for (uint8_t i = 0; i < neoPixels->numPixels(); i++) {
    neoPixels->setPixelColor(i, color);
  }

  /* show the changes */
  neoPixels->show();
}

void StatusIndicator::updateState(int _state) {
  /* assign the state value */
  state = _state;

  /* immediately call run to update the current status */
  run();
}
