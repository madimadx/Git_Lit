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
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

Adafruit_NeoPixel LEDs = Adafruit_NeoPixel(60, 14, NEO_RGB + NEO_KHZ400);
Display d;
  
const char* ssid = "Connor's iPhone";
const char* password = "aaaaaaaa";

const char* host = "people.cs.clemson.edu";
const int httpsPort = 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char* fingerprint = "CF 05 98 89 CA FF 8E D8 5E 5C E0 C2 E4 F7 E6 C3 C7 50 DD 5C";

int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  int brightness = sensorValue/4;
  if(brightness)
    brightness--;
  d.setBrightness(brightness);

  d.rgbLineCycle();
  d.cycleColors(20);
  d.cycleColors(10);
  d.cycleColors(10);
  d.gradient(LEDs.Color(255*brightness/255,255*brightness/255,0), LEDs.Color(0,0,255*brightness/255));
  delay(5000);
  d.setGridColor(LEDs.Color(255*brightness/255,0,0));
  delay(5000);
  d.setGridColor(LEDs.Color(0,255*brightness/255,0));
  delay(5000);
  d.setGridColor(LEDs.Color(0,0,255*brightness/255));
  delay(5000);
  d.cycleRainbow(10);
  if(String custom = httpGet()) {
    d.displayCustom(custom);
    delay (5000);
  }
}

String httpGet(){
// Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return "";
  }

  if (client.verify(fingerprint, host)) {
    Serial.println("certificate matches");
  } else {
    Serial.println("certificate doesn't match");
  }

  String url = "/~ckinzie/embsys/customLED";
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readString();
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
  return line;
}
