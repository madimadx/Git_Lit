#include <Adafruit_NeoPixel.h>
#include "Display.h"

#define ROWS 5
#define COLS 12
#define DIFF 6

class WifiInteraction
{
  public:
      WifiInteraction();
      void resetCustomDisplay();
      void flipDisplay();
      uint32_t customGrid[ROWS][COLS];
  private:
      int diffDisplays[DIFF];
      int currDisplay;
      Display disp;
      uint32_t color1, color2;
      int cycleTime;
      uint32_t emptyPixel;
      bool isCustomEmpty;  
      Adafruit_NeoPixel strip;
};

