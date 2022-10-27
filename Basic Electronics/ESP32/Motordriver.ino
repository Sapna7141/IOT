
//const int pin = 2
//const 

void setup() {
  
pinMode(2,OUTPUT);
pinMode(15,OUTPUT);
//pinMode(22,INPUT_PULLUP);
}

void loop() {
 
//motorAfwd();
motorArvs();

//  if(digitalRead(22)==1){
//    
//    digitalWrite(2,HIGH);
//    digitalWrite(15,LOW);
//  }
//    else{
//      digitalWrite(2,LOW);
//      digitalWrite(15,LOW);
//      }
}



void motorAfwd(){
  
  digitalWrite(2,HIGH);
  digitalWrite(15,LOW);
  
  }

 void motorArvs(){
  
  digitalWrite(2,LOW);
  digitalWrite(15,HIGH);
  
  } 

 void stopp(){
   
  digitalWrite(2,LOW);
 digitalWrite(15,LOW);
  }
