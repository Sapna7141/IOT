int echo=7;
int trig=12;
int ledA=2;
int ledB=3;
int ledC=4;
int ledD=5;

long distance;
int duration;

void setup() {
 pinMode(echo,INPUT);
 pinMode(trig,OUTPUT);
 pinMode(ledA,OUTPUT);
 pinMode(ledB,OUTPUT);
 pinMode(ledC,OUTPUT);
 pinMode(ledD,OUTPUT);
 Serial.begin(9600);


}

void loop() {
digitalWrite(trig,LOW);
delay(2);
digitalWrite(trig,HIGH);
delay(10);
digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);
distance=duration*0.034/2;

if(distance==3){
  digitalWrite(ledA,HIGH);
  delay(500);
  Serial.println("ON");
}
if(distance==5){
  digitalWrite(ledB,HIGH);
  delay(500);
  Serial.println("ON");
}
if (distance==10){
digitalWrite(ledC,HIGH);
delay(500);
Serial.println("ON");
}    
if(distance==15){
digitalWrite(ledD,HIGH);
delay(500);
Serial.println("ON");
}

else
{
  digitalWrite(ledA,LOW);
  digitalWrite(ledB,LOW);
  digitalWrite(ledC,LOW);
  digitalWrite(ledD,LOW);
  Serial.println("OFF");   
  }
  
   }
