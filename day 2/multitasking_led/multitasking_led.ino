const byte LED=13;
const byte LEDSHORT=12;
unsigned long oldTime;
unsigned long oldTimeShort;
unsigned long newTime;
unsigned long newTimeShort;
unsigned long timeDelay;
unsigned long timeDelayShort;
boolean ledOn;
boolean ledOnShort;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(LEDSHORT,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  newTime=millis();
  newTimeShort= millis();
  timeDelay=(newTime - oldTime);
  timeDelayShort= (newTimeShort-oldTimeShort);
  if(timeDelay >1000 && ledOn==0){
    digitalWrite(LED,HIGH);
    ledOn=1;
    oldTime=newTime;
    timeDelay=0;
  }
  if(timeDelayShort >500 && ledOnShort==0){
    digitalWrite(LEDSHORT,HIGH);
    ledOnShort=1;
    oldTimeShort= newTimeShort;
    timeDelayShort=0;
  }
  if(timeDelay >1000 && ledOn==1){
    digitalWrite(LED,LOW);
    ledOn=1;
    oldTime=newTime;
    timeDelay=0;
  }
  if(timeDelayShort >500 && ledOnShort==1){
    digitalWrite(LEDSHORT,LOW);
    ledOnShort=1;
    oldTimeShort=newTimeShort;
    timeDelayShort=0;
  }

}
