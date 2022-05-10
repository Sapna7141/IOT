
const int led2 = 23;


void setup() {
pinMode(led2,OUTPUT);
Serial.begin(9600);
}

void loop() {
  

digitalWrite(led2,HIGH);
Serial.println("led are ON");
delay(1000);

digitalWrite(led2,LOW);
Serial.println("led are OFF");
delay(1000);
}
