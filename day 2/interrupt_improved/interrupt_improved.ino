const byte LED=13;
const byte RESETPIN=2;
volatile boolean reset;
volatile byte loopCounter;
byte counter1; //contador para el led de encendido
byte counter2; //contador para el for de apagado
byte insideLoop;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(RESETPIN,INPUT);
  attachInterrupt(0,ISR_RESET, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(loopCounter<5){
    insideLoop=1;//control del momento de la interrupcion
    for(counter1=0; counter1<100; counter1++){//dividimos el tiempo en 100 para hacer mas facil
      if(reset==1){
        break; //rompemos el ciclo
      }
      digitalWrite(LED,HIGH);
      delay(10);
    }
    for(counter2=0; counter2<100; counter2++){
      if(reset==1){
        break;      //rompemos el bucled de apagado
      }
      digitalWrite(LED,LOW);
      delay(10);
    }
    loopCounter++;
    insideLoop=0;
    reset=0;
  }
}
void ISR_RESET(){
  if(insideLoop==1){
    loopCounter=-1;
    reset=1;
  }else{
    loopCounter=0;
  }
}
