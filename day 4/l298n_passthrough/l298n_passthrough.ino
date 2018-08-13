const byte enA=9;
const byte in1=8;
const byte in2=7;
const byte in3=5;
const byte in4=4;
const byte enB=3;

int enAVal, in1Val, in2Val, in3Val, in4Val, enBVal;

void setup(){
  Serial.begin(9600);
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enB,OUTPUT);
}

void loop(){
  while(Serial.available()>0){
    enAVal=Serial.parseInt();
    in1Val=Serial.parseInt();
    in2Val=Serial.parseInt();
    //solo leemos los siguientes valores si hay datos
    
    if(Serial.available()>0){
      in3Val=Serial.parseInt();
      in4Val=Serial.parseInt();
      enBVal=Serial.parseInt();
    }
    
    //escribimos los valores que recibimos
    analogWrite(enA,enAVal);
    digitalWrite(in1,in1Val);
    digitalWrite(in2,in2Val);
    digitalWrite(in3,in3Val);
    digitalWrite(in4,in4Val);
    analogWrite(enB, enBVal);
    
    //purgamos los demas valores
    while(Serial.available() >0){
      char x=Serial.read();
    }
    
  }

}
