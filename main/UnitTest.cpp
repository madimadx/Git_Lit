#include "UnitTest.h"
#include <Adafruit_NeoPixel.h>


UnitTest::UnitTest(){
  Serial.begin(9600);
}

bool UnitTest::testSetGridColor(){
    Display dispT;
    bool pass = true;
    Adafruit_NeoPixel strip = dispT.getStrip();
    uint32_t testColor = strip.Color(255, 0, 255);
    dispT.setGridColor(testColor); 
    
    for(uint16_t i=0; i< strip.numPixels(); i++) {
      if (strip.getPixelColor(i) != testColor)
        pass = false;
    }
    return pass;
}

bool UnitTest::testSetGridColorExtreme1() {
    Display dispT;
    Adafruit_NeoPixel strip = dispT.getStrip();
    uint32_t testColor = strip.Color(0, 0, 0);
    dispT.setGridColor(testColor); 
    
    bool pass = true;
    for(uint16_t i=0; i< strip.numPixels(); i++) {
      if (strip.getPixelColor(i) != testColor)
        pass = false;
    }
    return pass;
}

bool UnitTest::testSetGridColorExtreme2() {
    Display dispT;
    Adafruit_NeoPixel strip = dispT.getStrip();
    uint32_t testColor = strip.Color(255, 255, 255);
    dispT.setGridColor(testColor); 
    
    bool pass = true;
    for(uint16_t i=0; i< strip.numPixels(); i++) {
      if (strip.getPixelColor(i) != testColor)
        pass = false;
    }
    return pass;
}

bool UnitTest::rgbLineCycleFinalTest(){
    Display dispT;
    Adafruit_NeoPixel strip = dispT.getStrip();
    uint32_t testColor = strip.Color(0, 0, 255);
    dispT.rgbLineCycle();
    
    if(strip.getPixelColor(0) != testColor) {
      return false;
    }
    else return true;
}

bool UnitTest::testCycleColorsEnd() {
  uint8_t testWait = 250;
  Display dispT;
  Adafruit_NeoPixel strip = dispT.getStrip();
  dispT.cycleColors(testWait);

  bool pass = true;
  for (int i = 0; i < strip.numPixels(); i++) {
     if (strip.getPixelColor(i) != dispT.Wheel((i) & 255))
        pass = false;
  }
  return pass;
}

bool UnitTest::testGradientOffToOn() {
  Display dispT;
  Adafruit_NeoPixel strip = dispT.getStrip();
  uint32_t offColor = strip.Color(0, 0, 0);
  uint32_t onColor = strip.Color(255, 255, 255);
  dispT.gradient(offColor, onColor);

  bool pass = true;
  if (strip.getPixelColor(0) != strip.Color(0, 0, 0) || strip.getPixelColor(11) != strip.Color(255/2, 255/2, 255/2))
    pass = false;
  else if (strip.getPixelColor(48) != strip.Color(255/2, 255/2, 255/2) || strip.getPixelColor(59) != strip.Color(255, 255, 255))
    pass = false;

  return pass;
 }

 bool UnitTest::testGradientBlueToBlue() {
  Display dispT;
  Adafruit_NeoPixel strip = dispT.getStrip();
  uint32_t blueColor = strip.Color(0, 0, 255);
  dispT.gradient(blueColor, blueColor);

  bool pass = true;
  if (strip.getPixelColor(0) != strip.Color(0, 0, 255) || strip.getPixelColor(11) != strip.Color(0, 0, 255))
    pass = false;
  else if (strip.getPixelColor(48) != strip.Color(0, 0, 255) || strip.getPixelColor(59) != strip.Color(0, 0, 255))
    pass = false;

  return pass;
}

  

void UnitTest::RunAllUnitTests(){

  bool allpassing = true;
  if (!testSetGridColor()){
    Serial.println("testSetGridColor() Failed");
  }    
  if (!testSetGridColorExtreme1()) {
    Serial.println("testSetGridColorExtreme1() Failed");
    allpassing = false;
  }    
  if (!testSetGridColorExtreme2()) {
    Serial.println("testSetGridColorExtreme2() Failed");
    allpassing = false;
  }    
  if (!rgbLineCycleFinalTest()) {
    Serial.print("rgbLineCycleFinalTest() Failed");
    allpassing = false;
  }    
  if (!testCycleColorsEnd()) {
    Serial.println("testCycleColorsEnd() Failed");
    allpassing = false;
  }    
  if (!testGradientOffToOn()) {
    Serial.println("testGradientOffToOn() Failed");
    allpassing = false;
  } 
  if (!testGradientBlueToBlue()){
    Serial.println("testGradientBlueToBlue() Failed");
    allpassing = false;
  }

  if (allpassing = true)
  Serial.println("All Tests Passing");
}
   
  


