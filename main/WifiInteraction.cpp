/*//#include <ESP8266WiFi.h>
//#include <ThingerESP8266.h>

#include "WifiInteraction.h"
#include "Display.h"

//#define USERNAME "mmaddox"
//#define DEVICE_ID "git_lit"
//#define DEVICE_CREDENTIAL "your_device_credential"

//#define SSID "your_wifi_ssid"
//#define SSID_PASSWORD "your_wifi_ssid_password"

#define ROWS 5
#define COLS 12
#define DIFF 6

//ThingerESP8266 thing(USERNAME BaylorJ, DEVICE_ID, DEVICE_CREDENTIAL);

//Display * disp = new Display();
Display dist;
int diffDisplays[DIFF];
int currDisplay = 0;
uint32_t customGrid[ROWS][COLS];
uint32_t color1 = (disp.strip).Color(255,0,0);;
uint32_t color2 = (disp.strip).Color(0,0,255);;
int cycleTime = 500;
uint32_t emptyPixel = (disp.strip).Color(0,0,0);
bool isCustomEmpty = true;

void flipDisplay() {
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

void resetCustomDisplay() {
  for (int j = 0; j < ROWS; j++) {
    for (int i = 0; i < COLS; i++) {
      customGrid[j][i] = emptyPixel;
    }
  }
  isCustomEmpty = true;
}

/*
can we add this to the display class?????
void displayCustom(uint32_t custom[ROWS][COLS]) {
  for (int j = 0; j < ROWS; j++) {
    for (int i = 0; i < COLS; i++) {
      strip.setPixelColor (i+(j*COLS), custom[j][i]);
    }
  }
  grid.show();
}
*/

