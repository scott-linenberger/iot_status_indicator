#include <Adafruit_NeoPixel.h>
#include "AdafruitIO_WiFi.h"
#include "StatusIndicator.h"

/* set your WiFi and Adafruit IO information in this file */
#include "config.h"

/* init Adafruit IO */
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/* setup the feed */
AdafruitIO_Feed *status = io.feed(FEED_STATUS);
AdafruitIO_Feed *notifier = io.feed(FEED_RESPONSE);

/* setup the pixel strip */
Adafruit_NeoPixel strip =
    Adafruit_NeoPixel(NUM_PIXELS, PIN_PIXELS, NEO_GRB + NEO_KHZ800);

/* setup the status indicator */
StatusIndicator statusIndicator = StatusIndicator();

void setup() {
  /* start Serial */
  Serial.begin(9600);

  /* setup the blue LED */
  pinMode(PIN_ONBOARD_LED, OUTPUT);

  /* connect to Adafruit IO */
  connectToIO();

  /* start the indicator */
  statusIndicator.begin(strip);
}

void loop() {
  /* keep our connection up */
  if (io.status() < AIO_CONNECTED) {
    connectToIO();
  }

  /* call run on IO and the statusIndicator */
  io.run();
  statusIndicator.run();
}

void connectToIO() {
  Serial.println("Connecting to Adafruit IO...");
  io.connect();

  /* handle incoming messages */
  status->onMessage(handleMessage);

  /* set a flag for toggling the LED */
  boolean isOn = true;

  /* wait for the connection */
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    isOn = !isOn;
    digitalWrite(PIN_ONBOARD_LED, isOn);
    delay(500);
  }

  /* connected! */
  Serial.println();
  Serial.println(io.statusText());

  /* keep the blue LED on */
  digitalWrite(PIN_ONBOARD_LED, LOW);
}

void handleMessage(AdafruitIO_Data *data) {
  /* parse the response to an integer */
  String value = String(data->value());
  int intValue = value.toInt();

  /* update the desk status */
  String responseMsg = "Current Status: ";

  /* update the status indicator */
  statusIndicator.updateState(intValue);

  /* set the response message */
  switch (intValue) {
    case STATE_GREEN:
      responseMsg = responseMsg + "Available";
      break;

    case STATE_YELLOW:
      responseMsg = responseMsg + "In a Meeting";
      break;

    case STATE_BLUE:
      responseMsg = responseMsg + "Offline";
      break;

    case STATE_PURPLE:
      responseMsg = responseMsg + "Remote";
      break;

    case STATE_RED:
      responseMsg = responseMsg + "Busy";
      break;

    case STATE_GREEN_PULSING:
      responseMsg = responseMsg + "Commuting";
      break;

    case STATE_RED_PULSING:
      responseMsg = responseMsg + "Do not Disturb";
      break;

    case STATE_FIRE:
      responseMsg = responseMsg + "Fire!";
      break;

    case STATE_EMERGENCY:
      responseMsg = responseMsg + "Emergency";
      break;

    case STATE_COLORCYCLE:
      responseMsg = responseMsg + "Color Cycle";
      break;

    case STATE_PARTY_TIME:
      responseMsg = responseMsg + "Party Time!";
      break;

    default:
      /* not sure what the state is */
      responseMsg = responseMsg + "Unknown";
      break;
  }

  /* write the response to the notifier feed so we know the update happened */
  notifier->save(responseMsg);
}