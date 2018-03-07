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
  /* setup the state string */
  String stateString = "Current status is: ";

  switch (state) {
    case STATE_AVAILABLE:
      displayColor(neoPixels->Color(0, 255, 20));
      currentStatus = stateString + "Available";
      break;

    case STATE_MEETING:
      displayColor(neoPixels->Color(200, 200, 0));
      currentStatus = stateString + "In a meeting";
      break;

    case STATE_OFFLINE:
      displayColor(neoPixels->Color(50, 50, 255));
      currentStatus = stateString + "Offline";
      break;

    case STATE_REMOTE:
      displayColor(neoPixels->Color(255, 0, 255));
      currentStatus = stateString + "Working remote";
      break;

    case STATE_DO_NOT_DISTURB:
      displayColor(neoPixels->Color(255, 10, 10));
      currentStatus = stateString + "Do not disturb";
      break;

    case STATE_COMMUTING:
      currentStatus = stateString + "Commuting";
      fader.fade(neoPixels, false, true, false);
      break;

    case STATE_ON_A_CALL:
      currentStatus = stateString + "On a call";
      fader.fade(neoPixels, true, false, false);
      break;

    case STATE_PARTY_TIME:
      pixelParty.party(neoPixels);
      currentStatus = stateString + "Party Time";
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

String StatusIndicator::updateState(int _state) {
  /* assign the state value */
  state = _state;

  /* immediately call run to update the current status */
  run();

  /* return the status string */
  return currentStatus;
}
