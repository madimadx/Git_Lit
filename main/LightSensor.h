#include <Adafruit_NeoPixel.h>
#include "Display.h"

class LightSensor
{
  public:
      LightSensor();
      void setIntensity();
      unsigned int readSensor();
      int calcIntensity();
  private:
      Display dispLight;
      Adafruit_NeoPixel strip;
};

