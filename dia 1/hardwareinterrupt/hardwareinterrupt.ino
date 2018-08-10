volatile int count=0; //volatile usado para variables de interrupcion
const byte LED=13;//assiganamos a la variable LED el numero 13 y la ponemos como constante usamos el tipo de datos byte que acepta numeros de 0 a 255, en lugar de int que ocupa mas espacio de memoria 
const byte PINPUSH=2; //pin 2 para el push ademas en arduino uno es un pin de interrupcion con 0
boolean reset;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);//habilitamos el pin 13 como salida
  pinMode(PINPUSH,INPUT_PULLUP);//pin 2 como entrada y activamo que cuando se presione el push sea 0
  attachInterrupt(0,reset_ISR,LOW); //interrupcion 0 y ejecutaremos la funcion reset_ISR
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
}

void reset_ISR(){ //funcion que se activa cuando es presionado el push, recuerden que es PULLUP, es decir presionado es 0, ya que la interrupcion del pin 2 se activa en 0
  count=0; //
}
