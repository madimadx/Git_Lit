//#include <ESP8266WiFi.h>
//#include <ThingerESP8266.h>

#include "WifiInteraction.h"

//#define USERNAME "mmaddox"
//#define DEVICE_ID "git_lit"
//#define DEVICE_CREDENTIAL "your_device_credential"

//#define SSID "your_wifi_ssid"
//#define SSID_PASSWORD "your_wifi_ssid_password"

#define ROWS 5
#define COLS 12
#define DIFF 6

//ThingerESP8266 thing(USERNAME BaylorJ, DEVICE_ID, DEVICE_CREDENTIAL);

int diffDisplays[DIFF];
int currDisplay = 0;
uint32_t customGrid[ROWS][COLS];
uint32_t color1;
uint32_t color2;
int cycleTime = 500;
uint32_t emptyPixel;
bool isCustomEmpty = true;

WifiInteraction::WifiInteraction() {
  strip = disp.getStrip();
  color1 = strip.Color(255,0,0);
  color2 = strip.Color(0,0,255);
  emptyPixel = strip.Color(0,0,0);
}

void WifiInteraction::flipDisplay() {
  currDisplay++;
  if (currDisplay == 0) //setGridColor
    disp.setGridColor(color1);
  else if (currDisplay == 1) //cycleColors
    disp.cycleColors(cycleTime);
  else if (currDisplay == 2) //rgbLineCycle
    disp.rgbLineCycle();
  else if (currDisplay == 3) //gradient
    disp.gradient(color1, color2);
  else if (currDisplay == 4) //cycleRainbow
    disp.cycleRainbow(cycleTime);
  else {
    if (isCustomEmpty) {
      currDisplay = 0;
      disp.setGridColor(color1);
    }
    else {
      //Display::displayCustom(customGrid);
      currDisplay = 0;
    }
  }
}

void WifiInteraction::resetCustomDisplay() {
  for (int j = 0; j < ROWS; j++) {
    for (int i = 0; i < COLS; i++) {
      customGrid[j][i] = emptyPixel;
    }
  }
  isCustomEmpty = true;
}
