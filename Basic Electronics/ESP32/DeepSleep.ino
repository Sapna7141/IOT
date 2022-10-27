int bootCount;
void setup(){
  

  pinMode(2,OUTPUT);
  pinMode(15,OUTPUT);
  delay(500);
  
  if(bootCount == 0) //Run this only the first time
  {
      digitalWrite(15,HIGH);
      bootCount = bootCount+1;
  }else
  {
      digitalWrite(2,HIGH);
  }
  
  delay(3000);

  digitalWrite(2,LOW);
  digitalWrite(15,LOW);

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}
