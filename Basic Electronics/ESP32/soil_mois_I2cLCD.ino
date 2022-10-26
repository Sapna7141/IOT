#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

const int analogInPin = A0;
int sensorValue = 0;

void setup(){
  lcd.init();                 
  lcd.backlight();
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture:");
  sensorValue=analogRead(A5);
  lcd.setCursor(0,1);
  lcd.print(sensorValue);
  delay(300);
}
