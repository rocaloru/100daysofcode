int counter;
const byte led=13;
const byte inputPin=7;
int in;
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  in= digitalRead(inputPin);
  if (in ==LOW){
    delay(200);
    counter= counter+1;
    value=value+1;
    Serial.println(value);
  }
  if((value%2 ==0) && (counter==1)){
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  counter=0;
}
