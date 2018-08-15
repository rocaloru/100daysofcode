int keyboardByte;
int oldKeyboardByte;
int counter;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(counter==0){
    Serial.println("");
    Serial.println("I can respond to the word -hello typed and entered above.");
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    counter=1;
  }
  if(Serial.available() >0){
    keyboardByte = Serial.read();
    oldKeyboardByte = oldKeyboardByte + keyboardByte;
    if((oldKeyboardByte== 532) || (oldKeyboardByte==500)){
      Serial.println("Hello there!");
      Serial.println(" ");
      Serial.println("Are any of the colors red, green, or blue your favorite color? (yes/no)");
      Serial.println(" ");
      oldKeyboardByte=0;
    }
    if(oldKeyboardByte==337){
      Serial.println(" ");
      Serial.println("Which of them is your favorite?");
      Serial.println(" ");
      oldKeyboardByte=0;
    }
    if((oldKeyboardByte==432)|| (oldKeyboardByte == 749)){
      Serial.println(" ");
      Serial.println("Sorry, I have to go");
      Serial.println(" ");
      oldKeyboardByte=0;  
    }
    if(oldKeyboardByte==221){
      Serial.println(" ");
      Serial.println("Oh ok, well have a nice day");
      Serial.println(" ");
      Serial.println(" I only know  the three colors");
      Serial.println(" ");
      oldKeyboardByte=0;
    }
    switch (oldKeyboardByte){
      case 315: //red
        Serial.println(" ");
        Serial.println("Red is nice, but I like Green");
        Serial.println(" ");
        Serial.println("Nice talking to you, goodbye");
        Serial.println(" ");
        oldKeyboardByte=0;
        break;
     case 529: //green
       Serial.println(" ");
       Serial.println("Green is my favorite color too.");
       Serial.println(" ");
       Serial.println("Nice talking to you, goodbye");
       Serial.println(" ");
       oldKeyboardByte=0;
       break;
    
    case 424: //blue
      Serial.println(" ");
      Serial.println(" Blue is my second favorite color, but I like Green better");
      Serial.println(" ");
      Serial.println("Nice talking to you, goodbye");
      Serial.println(" ");
      oldKeyboardByte=0;
      break;
    }
  }
}
