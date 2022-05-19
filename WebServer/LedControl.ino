// LED CONTROL




#include <WiFi.h>
#include <WebServer.h>

//Put your SSID & Password

const char* ssid = "redmi";  // Enter SSID here
const char* password = "sapnasharma";  //Enter Password here

WebServer server(80);


uint8_t LEDpin = 2;
bool LEDstatus = LOW;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(LEDpin, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.on("/ledon", handle_ledon);
  server.on("/ledoff", handle_ledoff);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  
  if(LEDstatus)
  {digitalWrite(LEDpin, HIGH);}
  else
  {digitalWrite(LEDpin, LOW);}
}

void handle_OnConnect() {
  LEDstatus = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(LEDstatus)); 
}


void handle_ledon() {
  LEDstatus = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(true)); 
}

void handle_ledoff() {
  LEDstatus = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t LEDstat){
  String ptr = "<!DOCTYPE html> <html>\n";

  ptr +="<title>LED Control</title>\n";
  ptr +="</head>\n";

  ptr +="<body>\n";
  ptr +="<h1>ESP32 Web Server</h1>\n";
  ptr +="<h3>Using Station(STA) Mode</h3>\n";


  if(LEDstat)
  {ptr +="<p>LED Status: ON</p><form action=\"/ledoff\"><button type='submit'>OFF</button></form>\n";} 
  else
  {ptr +="<p>LED Status: OFF</p><form action=\"/ledon\"><button type='submit'>ON</button></form>\n";}
  ptr +="</body>\n"; 
  ptr +="</html>\n"; 
  return ptr;
  
}
