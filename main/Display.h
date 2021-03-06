#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

class Display
{
  public:
      Display();
      void setGridColor(uint32_t);
      void cycleColors(uint8_t);
      void rgbLineCycle();
      void gradient(uint32_t, uint32_t);
      void cycleRainbow(uint8_t);
      void flashColors(uint32_t, uint32_t, uint8_t);
      Adafruit_NeoPixel getStrip();
      uint32_t Wheel(byte);
      void setBrightness(int b) {brightness = b;}
      void displayCustom(String);
  private:
      Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 14, NEO_RGB + NEO_KHZ400);
      int brightness = 255;
      
      uint32_t hexTo32bitGRB(String); 
     
};
