
#include <Adafruit_BMP280.h>
#define BMP_SDA 21
#define BMP_SCL 22
Adafruit_BMP280 bmp280;
#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t broadcastAddress[] = {0x58, 0xBF, 0x25, 0x38, 0x24, 0x9C};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  char a[32];
  int b;
  float c;
  bool d;
} struct_message;

// Create a struct_message called myData
struct_message myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
  Serial.println("Initializing BMP280");
  boolean status = bmp280.begin(0x76);
  if (!status) {
    Serial.println("Not connected");
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}}
 
void loop() {
  // Set values to send
  strcpy(myData.a, "THIS IS A CHAR");
  myData.b = bmp280.readTemperature();
  myData.c =  bmp280.readPressure();
  myData.d = false;
  Serial.println("Temperature:");
  Serial.println(myData.b);
  Serial.println("Pressure:");
  Serial.println(myData.c);
//  display.print("Temperature:");
//  display.println(myData.b);
//  display.print("Pressure:");
//  display.println(myData.c);
//  display.display();
  //delay(3000);
  
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(2000);
}
