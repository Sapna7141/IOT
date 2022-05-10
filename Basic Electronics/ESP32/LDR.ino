
int value;
const int led = 2;

void setup()
{
  pinMode(0,INPUT);
  pinMode(led , OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 
  value = analogRead(0);
  Serial.println(value);
  delay(1000);
   
  if(value <=400){
    digitalWrite(led , HIGH);
  }
  else {
  digitalWrite(led,LOW);
  }
}
