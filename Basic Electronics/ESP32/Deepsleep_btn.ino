/*
 * File Name: esp32-deep-sleep.ino
 * Created on: 30-Jun-2020
 * Author: Noyel Seth (noyelseth@gmail.com)
 */
// create structure for push_button
struct PushBnt{
  const uint8_t pin;
  uint32_t pressCount;
  bool pressed;
};
//Create a PushButton variable
PushBnt pushBtn = {GPIO_NUM_16, 0, false};
// define Led Pin
uint8_t led_pin = GPIO_NUM_4;
// define wake up pin
uint8_t wakeUp_pin = GPIO_NUM_33;
// define taskBlinkled TaskHandle_t variable
TaskHandle_t taskBlinkled;
// define ISR function for PushButtton's Interrupt
void IRAM_ATTR isr_handle() {
  pushBtn.pressed = true;
  pushBtn.pressCount = pushBtn.pressCount + 1;
}
void setup() {
  // put your setup code here, to run once:
  // set the serial port at 115200
  Serial.begin(115200);
  delay(1000); 
  // set the pushButton pin as input with internal PullUp
  pinMode(pushBtn.pin, INPUT_PULLUP);
  // set the Interrupt handler with the pushButton pin in Falling mode
  attachInterrupt(pushBtn.pin, isr_handle, FALLING);
  // set the Led pin as ouput
  pinMode(led_pin, OUTPUT);
  //create a task that will be executed in the blinkLed() function, with priority 1 and executed on core 0
  xTaskCreate(
              blinkLed,   /* Task function. */
              "blinkLed",     /* name of task. */
              1024*2,       /* Stack size of task */
              NULL,        /* parameter of the task */
              5,           /* priority of the task */
              &taskBlinkled);      /* Task handle to keep track of created task */
  delay(500);
  //Configure Pin 33 as ext0 wake up source with LOW logic level
  esp_sleep_enable_ext0_wakeup((gpio_num_t)wakeUp_pin, 0);
}
void loop() {
  // put your main code here, to run repeatedly:
   if (pushBtn.pressed) {
      Serial.printf("PushButton(%d) Pressed \n", pushBtn.pin);
      Serial.printf("Suspend the 'blinkLed' Task \n");
      // Suspend the blinkLed Task
      vTaskSuspend( taskBlinkled );
      digitalWrite(led_pin, LOW);     
      Serial.printf("Going to sleep..... \n", pushBtn.pin);
      pushBtn.pressed = false;
      //Go to sleep now
      esp_deep_sleep_start();
  }
  esp_sleep_wakeup_cause_t wakeupReason;
  wakeupReason = esp_sleep_get_wakeup_cause();
  switch(wakeupReason)
  {
    case ESP_SLEEP_WAKEUP_EXT0  : Serial.println("using external signal ext0 for WakeUp From sleep"); break;
    case ESP_SLEEP_WAKEUP_EXT1  : Serial.println("using external signal ext1 for WakeUp From sleep"); break;
    case ESP_SLEEP_WAKEUP_TIMER  : Serial.println("using Timer signal for WakeUp From sleep"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD  : Serial.println("using TouchPad signal for WakeUp From sleep"); break;
    case ESP_SLEEP_WAKEUP_ULP  : Serial.println("using ULP signal for WakeUp From sleep"); break;
    default : break;
    Serial.printf("Resume the 'blinkLed' Task \n");
    // restart the blinkLed Task
    vTaskResume( taskBlinkled );
  }  
}
void blinkLed(void* param){  
  while(1){
    static uint32_t pin_val = 0;
    // toggle the pin value
    pin_val ^= 1;
    digitalWrite(led_pin, pin_val);
    Serial.printf("Led ----------------- %s\n" , pin_val? "On" : "Off");   
    /* Simply toggle the LED every 1000ms or 1sec */
     vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
  taskBlinkled = NULL;
  vTaskDelete( NULL );
}
