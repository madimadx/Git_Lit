#include "UnitTest.h"
#include <Adafruit_NeoPixel.h>


UnitTest::UnitTest(){
  Serial.begin(9600);
}

void UnitTest::testSetGridColor(){
    Display dispT;
    Adafruit_NeoPixel strip = dispT.getStrip();
    uint32_t testColor = strip.Color(255, 0, 255);
    dispT.setGridColor(testColor); 
    
    int countWrong = 0;
    for(uint16_t i=0; i< strip.numPixels(); i++) {
      if (strip.getPixelColor(i) != testColor)
        countWrong++;
    }
    if(countWrong == 0)
      Serial.print("All tests passed");
    else
      Serial.print("Failed");
}
