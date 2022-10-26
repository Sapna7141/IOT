
#include <Servo.h>
Servo myservo;
int pos = 0;
void setup()
{     myservo.attach(9);
      pinMode(3, OUTPUT);
      pinMode(2, OUTPUT);
      pinMode(8, OUTPUT); 
      pinMode(6, OUTPUT); 
        
}

void loop()
{
for (pos = 0; pos <= 90; pos += 1) 
{                                    
                                    
    myservo.write(pos);             
    delay(15);                      
  }
    digitalWrite(3, HIGH);
  delay(8000);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
 
  delay(2000);
  digitalWrite(2, LOW);
 
  digitalWrite(6, HIGH);
 for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(15);                      
  }
  delay(8000);
  digitalWrite(6, LOW);
  digitalWrite(2, HIGH);
  
  delay(2000);
  digitalWrite(2, LOW);
  
}
