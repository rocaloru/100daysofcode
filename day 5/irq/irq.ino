int keys;
int ASCII;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    keys=Serial.read();
    Serial.println();
    Serial.print("For the letter");
    Serial.print(keys,ASCII);
    Serial.print("The code in binary is ");
    Serial.print(keys, BIN);
    Serial.print("the decimal number is ");
    Serial.println(keys, DEC);
    Serial.print ("the hexadecimal number is");
    Serial.println (keys, HEX);
  }
}
