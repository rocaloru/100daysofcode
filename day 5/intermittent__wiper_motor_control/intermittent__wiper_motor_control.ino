const byte startStopPin=2;
const byte changeSpeedPin=3;
const byte wipeRight=8;
const byte wipeLeft=9;
int wiperLatch;
int startStop;
boolean toggleSpeed;
int dwellSpeed;
int count; 
int delayChange;

void setup() {
  // put your setup code here, to run once:
  pinMode(startStopPin, INPUT_PULLUP);
  pinMode(changeSpeedPin, INPUT_PULLUP);
  pinMode(wipeRight,OUTPUT);
  pinMode(wipeLeft,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  startStop=digitalRead(startStopPin);
  delay(200);
  if(startStop==LOW){
     wiperLatch=1;
  }
  dwellSpeed=100;
  while(wiperLatch==1){
    for(count =0; count< 100; count++){
      digitalWrite(wipeLeft,HIGH);
      delay(10);
      subroutine();
    }
    digitalWrite(wipeLeft,LOW);
    for(count=0; count<dwellSpeed; count++){
      delay(10);
      subroutine();
    }
    count=0;
    if(delayChange==1 && dwellSpeed==100){
      dwellSpeed=300;
    }
    else if (delayChange == 1 && dwellSpeed==300){
      dwellSpeed=100;
    }
    delayChange=0;
  }
}

void subroutine(){
  startStop=digitalRead(startStopPin);
  if(startStop==LOW){
    wiperLatch=0;
    dwellSpeed=100;
  }
  toggleSpeed=digitalRead(changeSpeedPin);
  if(toggleSpeed==LOW){
    delayChange=1;
  }
}
