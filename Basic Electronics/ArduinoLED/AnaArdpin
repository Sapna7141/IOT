int value;
const int led = 13;

void setup()
{
  pinMode(32,INPUT);
  pinMode(led , OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 
  value = analogRead(A0);
  Serial.println(value);
  delay(1000);
   
  if(value <=400){
    digitalWrite(led , HIGH);
  }
  else {
  digitalWrite(led,LOW);
  }
}
