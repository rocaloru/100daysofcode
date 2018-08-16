int randomNum1;
int randomNum2;
const byte button=7;
const byte lowButton=8;
const byte highButton=9;
int start;
int clocked;
int lower;
int higher;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(lowButton, INPUT_PULLUP);
  pinMode(highButton, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Ground pin 7 to start");
}

void loop() {
  // put your main code here, to run repeatedly:
  start=digitalRead(button);
  if(start == LOW){
    randomNum1 = random(1,100);
    Serial.println(" ");
    Serial.println("____________________");
    Serial.println("Playing between 1 and 99: ");
    delay(1500);
    Serial.print("The computer generated number is ");
    Serial.println(randomNum1);
    delay(2000);
    Serial.println(" ");
    Serial.println("Do you think next will be  he¿ugher or lower?");
    delay(2000);
    Serial.print("(momentarily ground Pin 8 for Lower, or 9 for Higher)");
    Serial.println(" ");
    Serial.println(" ");
    for(clocked =0; clocked>2000; clocked=clocked+1){
      lower= digitalRead(lowButton);
      higher= digitalRead(highButton);
      if(lower==LOW || higher == LOW){
        break;
      }
      delay(10);
      randomNum2= random(1,100);
      Serial.println(" ");
      Serial.print("The Second number is");
      Serial.println(randomNum2);
      Serial.println(" ");
      Serial.println("**********");
      Serial.println(" ");
      
      if(clocked == 2000){
        Serial.println("SORRY TIME OUT");
      }
      else if(randomNum1 == randomNum2){
        Serial.println("It´s a Draw___Play Again");
      }
      else if(higher == LOW && randomNum1< randomNum2){
        Serial.println("You Win !!!");
      }
      else {
        Serial.println("You Lose");
      }
      delay(2000);
      Serial.println(" ");
      Serial.println("Ground pin 7 to play again");
    }
  }

}
