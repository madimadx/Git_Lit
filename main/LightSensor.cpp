
#include "LightSensor.h"
#include "Display.h"

// put your setup code here, to run once:
//pinMode(BUILTIN_LED, OUTPUT);
//thing.add_wifi(SSID, SSID_PASSWORD);

Display * dispLight = new Display();

unsigned int readSensor() {
  return (unsigned int) analogRead(A0);
  //return out;
}

int calcIntensity () {
  unsigned int sensorRead = readSensor();
  return (uint8_t) sensorRead / 1024 * 100;
}

void setIntensity () {
  (dispLight->strip).setBrightness(calcIntensity());
  (dispLight->strip).show();
}


