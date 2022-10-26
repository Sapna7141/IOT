char input;
//char s;

void setup() {
    Serial.begin(115200); 
    pinMode(2,OUTPUT);
    delay(2000);  
 
    Serial.println("Type something!");
}
 
void loop() {
  //char s,p;
    if(Serial.available()){
        input = Serial.read();
        //Serial.print("You typed: " );
        Serial.println(input);
        if(input == 's')
        {digitalWrite(2,HIGH);
        Serial.print("yess");
        }
//        if(input=p)
//        {
//          digitalWrite(2,LOW);}
    }
}
