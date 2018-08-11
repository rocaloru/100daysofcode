const byte LED=13;
unsigned long oldTime=0; 
unsigned long newTime=0;
unsigned int timeDelay;
boolean ledOn;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  newTime= millis();//iniciamos el temporizador
  timeDelay=(newTime-oldTime);//calculamos el tiempo transcurrido
  if(timeDelay > 1000 && ledOn==0){//durante un segundo encendemos un led si el estado esta apagado ledOn=0
    digitalWrite(LED,HIGH);
    ledOn=1;//cambiamos el estado del led a encendido
    oldTime=newTime; //intercambiamos los valores de los tiempos
    timeDelay=0;//reiniciamos el contador del tiempo
  }
  if(timeDelay >1000 && ledOn==1){
    digitalWrite(LED,LOW);
    ledOn=0;
    oldTime=newTime;
    timeDelay=0;
  }
}
