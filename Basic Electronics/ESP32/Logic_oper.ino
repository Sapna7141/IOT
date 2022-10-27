int a = 2;
int b = 9;
void setup() {
  Serial.begin(9600);


}

void loop() {
  
  if ((a == 2) && (b < 10)){
    Serial.println("True");
    }
    else {
      Serial.println("False");
     
      }
   if ( !(a < 1 ) || (b > 10)){
    Serial.println("True");
    }else{
      Serial.println("False");
      }
      delay(1000); 
}
