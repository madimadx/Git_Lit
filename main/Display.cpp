
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "Display.h"

#define PIN 14
#define ROWS 5
#define COLS 12

Display::Display() {
  Serial.begin(9600);
  strip.begin();
  //make sure the pixels are set to off
  strip.show();
}

// Fill the entire grid with one color
void Display::setGridColor(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
}

void Display::cycleColors(uint8_t wait) {

  
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void Display::rgbLineCycle() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255,0,0));
    strip.show();
    delay(100);
    Serial.println("red");
  }
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0,255,0));
    strip.show();
    delay(100);
    Serial.println("green");
  }
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0,0,255));
    strip.show();
    delay(100);
    Serial.println("blue");
  }
}
/*
void Display::displayCustom(uint32_t custom[ROWS][COLS]) {
  for (int j = 0; j < ROWS; j++) {
    for (int i = 0; i < COLS; i++) {
      strip.setPixelColor (i+(j*COLS), custom[j][i]);
    }
  }
  grid.show();
}*/

void Display::gradient(uint32_t c1, uint32_t c2) {
  uint16_t i, j, k;
  uint8_t r1, r2, r3, g1, g2, g3, b1, b2, b3;

  r1 = c1 >> 16;
  g1 = (c1 << 8) >> 16;
  b1 = (c1 << 16) >> 16;
  r2 = c2 >> 16;
  g2 = (c2 << 8) >> 16;
  b2 = (c2 << 16) >> 16;
  

  for(j=0; j< ROWS; j++) {
    for(i=0; i< COLS; i++) {
      r3 = (r1 - r1/(2*(COLS-1))*i - r1/(2*(ROWS-1))*j) + (r2/(2*(COLS-1))*i + r2/(2*(ROWS-1))*j);
      g3 = (g1 - g1/(2*(COLS-1))*i - g1/(2*(ROWS-1))*j) + (g2/(2*(COLS-1))*i + g2/(2*(ROWS-1))*j);
      b3 = (b1 - b1/(2*(COLS-1))*i - b1/(2*(ROWS-1))*j) + (b2/(2*(COLS-1))*i + b2/(2*(ROWS-1))*j);
      strip.setPixelColor(i+(j*COLS), strip.Color(r3,g3,b3));
      Serial.print(strip.Color(r3,g3,b3));
      Serial.print(" ");
    }
    Serial.println(" ");
   strip.show();
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void Display::cycleRainbow(uint8_t wait) {
  uint16_t i, j, k;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< ROWS; i++) {
      for(k=0; k< COLS; k++) {
        strip.setPixelColor(k+(i*COLS), Wheel(((k * 256 / COLS) + j) & 255));
        //Serial.print(Wheel(((k * 256 / COLS) + j) & 255));
        //Serial.print(" ");
      }
      //Serial.println(" ");

    }
   strip.show();
   delay(wait);
  }
}
/********************************************* Sketchy **************************************************/
void Display::flashColors(uint32_t c1, uint32_t c2, uint8_t wait) {
  for (int j=0; j<50; j++) { 
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c1);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c2);        //turn every third pixel off
      }
    }
  }
}

Adafruit_NeoPixel Display::getStrip() {
  return strip;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Display::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
