int a=1;
int b=2;
int c=3;

void setup(){
  Serial.begin(9600);
  
}

void loop(){
  if(!Serial){
    Serial.print(a);Serial.print(",");
    Serial.print(b);Serial.print(",");
    Serial.println(c);
  }
  delay(500);
  a++;
  b++;
  c++;
}
