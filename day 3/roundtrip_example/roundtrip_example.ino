int a=0;
int b=0;
int c=0;
int d=0;

void setup(){
  Serial.begin(9600);
  
}

void loop(){
  if(Serial.available()>0){
    a=Serial.parseInt();
    b=Serial.parseInt();
    c=Serial.parseInt();
    
  }
  d=a+b+c;
  Serial.print(a);Serial.print(",");
  Serial.print(b);Serial.print(",");
  Serial.print(c);Serial.print(",");
  Serial.println(d);
  delay(100);
  
}
