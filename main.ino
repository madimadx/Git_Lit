/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <Adafruit_NeoPixel.h>
#include "Display.h"


Adafruit_NeoPixel LEDs = Adafruit_NeoPixel(60, 14, NEO_RGB + NEO_KHZ400);
Display d;

void setup() {

}

void loop() {
  d.rgbLineCycle();
  d.cycleRainbow(99999999);
  d.gradient(LEDs.Color(89,184,235), LEDs.Color(246,25,155));
}
