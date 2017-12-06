int leftMotorF=13;
int leftMotorB=12;
int rightMotorF=11;
int rightMotorB=10;

int bleftMotorF=9;
int bleftMotorB=8;
int brightMotorF=7;
int brightMotorB=6;

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {53, 52, 51, 50}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {49, 48, 47, 46};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void setup() {
  pinMode(leftMotorF,OUTPUT);
  pinMode(leftMotorB,OUTPUT);
  pinMode(rightMotorF,OUTPUT);
  pinMode(rightMotorB,OUTPUT);
  pinMode(bleftMotorF,OUTPUT);
  pinMode(bleftMotorB,OUTPUT);
  pinMode(brightMotorF,OUTPUT);
  pinMode(brightMotorB,OUTPUT);
}

void loop() {

  char customKey = customKeypad.getKey();
  if(customKey=='1')
 { goForward();
  delay(3000);
  stopCar();}
  
  
  
  if(customKey=='9')
  {goBackward();
  delay(3000);
  stopCar();
  }
  
   if(customKey=='4')
  {goRight();
  delay(3000);
  stopCar();}
   if(customKey=='6')
  {goLeft();
  delay(3000);
  stopCar();}
}

void goForward()
{
  digitalWrite(leftMotorF,HIGH);
  digitalWrite(leftMotorB,LOW);
  digitalWrite(bleftMotorF,HIGH);
  digitalWrite(bleftMotorB,LOW);
  digitalWrite(rightMotorF,HIGH);
  digitalWrite(rightMotorB,LOW);
  digitalWrite(brightMotorF,HIGH);
  digitalWrite(brightMotorB,LOW);
}
void goBackward()
{
  digitalWrite(leftMotorF,LOW);
  digitalWrite(leftMotorB,HIGH);
  digitalWrite(bleftMotorF,LOW);
  digitalWrite(bleftMotorB,HIGH);
  digitalWrite(rightMotorF,LOW);
  digitalWrite(rightMotorB,HIGH);
  digitalWrite(brightMotorF,LOW);
  digitalWrite(brightMotorB,HIGH);
}
void stopCar()
{
    digitalWrite(leftMotorF,LOW);
  digitalWrite(leftMotorB,LOW);
  digitalWrite(rightMotorF,LOW);
  digitalWrite(rightMotorB,LOW);
   digitalWrite(bleftMotorF,LOW);
  digitalWrite(bleftMotorB,LOW);
  digitalWrite(brightMotorF,LOW);
  digitalWrite(brightMotorB,LOW);
}
void goLeft()
{
  digitalWrite(leftMotorF,LOW);
  digitalWrite(leftMotorB,HIGH);
  digitalWrite(bleftMotorF,LOW);
  digitalWrite(bleftMotorB,HIGH);
  digitalWrite(rightMotorF,LOW);
  digitalWrite(rightMotorB,LOW);
  digitalWrite(brightMotorF,LOW);
  digitalWrite(brightMotorB,LOW);
}
void goRight()
{
  digitalWrite(leftMotorF,LOW);
  digitalWrite(leftMotorB,LOW);
  digitalWrite(bleftMotorF,LOW);
  digitalWrite(bleftMotorB,LOW);
  digitalWrite(rightMotorF,HIGH);
  digitalWrite(rightMotorB,LOW);
  digitalWrite(brightMotorF,HIGH);
  digitalWrite(brightMotorB,LOW);
}



