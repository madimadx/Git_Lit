
#include "LightSensor.h"

// put your setup code here, to run once:
//pinMode(BUILTIN_LED, OUTPUT);
//thing.add_wifi(SSID, SSID_PASSWORD);

LightSensor::LightSensor() {
  strip = dispLight.getStrip();
}

unsigned int LightSensor::readSensor() {
  return (unsigned int) analogRead(A0);
  //return out;
}

int LightSensor::calcIntensity () {
  unsigned int sensorRead = readSensor();
  return (uint8_t) sensorRead / 1024 * 100;
}

void LightSensor::setIntensity () {
  strip.setBrightness(calcIntensity());
  strip.show();
}


