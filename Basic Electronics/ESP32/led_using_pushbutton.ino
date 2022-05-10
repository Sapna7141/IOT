const int led = 2 ;
const int pushbutton = 23;

void setup(){
  
  pinMode(led , OUTPUT);
  pinMode(pushbutton ,INPUT);
  
  }

void loop(){
  
  if (!digitalRead(pushbutton) == 1)
  {
    digitalWrite(led,HIGH);
    }
  else 
  {
    digitalWrite(led,LOW);
    
    }
  
  
  }
