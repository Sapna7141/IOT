// Wifi AP


#include "WiFi.h"
 
const char *ssid = "ESP 32 AP";
const char *password = "password";
 
void setup() {
 
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
 
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
 
}
 
void loop() {}
