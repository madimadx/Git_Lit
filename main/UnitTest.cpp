/*#include "Display.h"
#include "UnitTest.h"
#include <Adafruit_NeoPixel.h>


UnitTest::UnitTest){
  
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
    assertEqual(countWrong, 0);
}

*/
