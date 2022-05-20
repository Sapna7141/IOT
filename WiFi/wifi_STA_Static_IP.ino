// Wifi STA Static IP


#include <WiFi.h>
 
const char* ssid = "redmi";
const char* password =  "sapnasharma";
 
IPAddress staticIP(192, 168, 1, 166);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 1, 254);
    
void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
 
  if (WiFi.config(staticIP, gateway, subnet,dns) == false) {
    Serial.println("Configuration failed.");
  }
    
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting...\n\n");
  }
  
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS 1: ");
  Serial.println(WiFi.dnsIP(0));   
}
    
void loop(){}
