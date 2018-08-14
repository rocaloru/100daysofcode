unsigned int i;
unsigned int x;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Generating powers of two");
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i =0; i<16; i++){
    x= pow(2,i);
    if(i>1){
      x=x+1;
    }
    Serial.print(x);
    delay(1000);
    Serial.print("   ");
  }
  Serial.println();
  Serial.println();
}
