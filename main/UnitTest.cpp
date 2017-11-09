#include "Display.h"
#include "UnitTest.h"



void testSetGridColor(){
    Display dispT;
    uint32_t testColor = (dispT.strip).Color(255, 0, 255);
    (dispT)->setGridColor(testColor); 
    
    int countWrong = 0;
    for(uint16_t i=0; i< (dispT.strip).numPixels(); i++) {
      if ((dispT.strip).getPixelColor(i) != testColor)
        countWrong++;
    }
    assertEqual(countWrong, 0);
}


