
#include <Keypad.h>
#include <Servo.h>

Servo myservo;  

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {53, 52, 51, 50}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {49, 48, 47, 46}; //connect to the column pinouts of the keypad


Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
  
void setup() {
  
  Serial.begin(9600);

  for(int i = 6; i <= 13; i++)
  {
    pinMode(i,OUTPUT);
    }

}

void loop() {
  char customKey = customKeypad.getKey();

  if(customKey == '4')
  {
    moveForward();
  }
  else if(customKey == 'B')
  {
    moveBackward();
  }
  
  
  
} 

void moveForward()
{
  digitalWrite(13,1);
  digitalWrite(12,0);

  digitalWrite(11,1);
  digitalWrite(10,0);


  digitalWrite(9,1);
  digitalWrite(8,0);

  digitalWrite(7,1);
  digitalWrite(6,0);
}

void moveBackward()
{
  digitalWrite(13,0);
  digitalWrite(12,1);

  digitalWrite(11,0);
  digitalWrite(10,1);

  digitalWrite(9,0);
  digitalWrite(8,1);

  digitalWrite(7,0);
  digitalWrite(6,1);
}

void moveLeft()
{
  digitalWrite(13,0);
  digitalWrite(12,0);

  digitalWrite(11,0);
  digitalWrite(10,0);

  digitalWrite(9,1);
  digitalWrite(8,0);

  digitalWrite(7,1);
  digitalWrite(6,0);
}

void moveRight()
{
  digitalWrite(13,1);
  digitalWrite(12,0);

  digitalWrite(11,1);
  digitalWrite(10,0);

  digitalWrite(9,0);
  digitalWrite(8,0);

  digitalWrite(7,0);
  digitalWrite(6,0);
}

void stopCar()
{ 
  digitalWrite(13,0);
  digitalWrite(12,0);

  digitalWrite(11,0);
  digitalWrite(10,0);

  digitalWrite(9,0);
  digitalWrite(8,0);

  digitalWrite(7,0);
  digitalWrite(6,0);
  }
