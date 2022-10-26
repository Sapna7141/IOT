const int led = 13;
const int pushbutton = 2;
int buttonstate = 0;


void setup() {

 pinMode(2,INPUT);
 pinMode(13,OUTPUT);
 digitalWrite(led,LOW);

}

void loop() {
  if (digitalRead(pushbutton)==HIGH){
    buttonstate=1;
    digitalWrite(led,HIGH);
    }
else{
  buttonstate=0;
  digitalWrite(led,LOW);
  }
}
