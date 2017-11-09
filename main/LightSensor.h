#include <Adafruit_NeoPixel.h>

class LightSensor
{
  public:
      LightSensor();
      void setIntensity();
      unsigned int readSensor();
      int calcIntensity();
  private:
};

