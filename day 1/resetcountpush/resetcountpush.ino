int count=0;
const byte LED=13;//assiganamos a la variable LED el numero 13 y la ponemos como constante usamos el tipo de datos byte que acepta numeros de 0 a 255, en lugar de int que ocupa mas espacio de memoria 
const byte PINPUSH=7; //pin 7 para el push
boolean reset;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);//habilitamos el pin 13 como salida
  pinMode(PINPUSH,INPUT);//pin 7 como entrada
}

void loop() {
  // put your main code here, to run repeatedly:
  while(count <10){ //ciclo para que el led parpadee 10 veces
    digitalWrite(LED,HIGH); //prendemos el led conectado al pin 13
    delay(500);//esperamos un segundo
    digitalWrite(LED,LOW);//apagamos el led conectado al pin 13
    delay(500);//esperamos un segundo
    count=count+1;//aumentamos el contador
  }
  reset=digitalRead(PINPUSH);
  if(reset == 1){
    count=0;
  }
}
