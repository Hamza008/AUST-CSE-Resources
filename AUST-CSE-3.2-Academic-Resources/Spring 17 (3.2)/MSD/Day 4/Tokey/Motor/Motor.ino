int leftMotorF = 13;
int leftMotorB = 12;
int rightMotorF = 11;
int rightMotorB = 10;

int bleftMotorF = 9;
int bleftMotorB = 8;
int brightMotorF = 7;
int brightMotorB = 6;

void setup() {
  Serial.begin(9600);
  pinMode(leftMotorF, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
  pinMode(rightMotorF, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  pinMode(bleftMotorF, OUTPUT);
  pinMode(bleftMotorB, OUTPUT);
  pinMode(brightMotorF, OUTPUT);
  pinMode(brightMotorB, OUTPUT);
}




const int LeftSonarIn = 41;
const int LeftSonarOut = 40;
const int RightSonarIn = 45;
const int RightSonarOut= 44;
const int ForwardSonarIn = 43;
const int ForwardSonarOut = 42;

void loop() {

  long durationL,durationR,durationF, inchesL,inchesR,inchesF, cm;


  pinMode(LeftSonarOut, OUTPUT);
  digitalWrite(LeftSonarOut, LOW);
  delayMicroseconds(5);
  digitalWrite(LeftSonarOut, HIGH);
  delayMicroseconds(30);
  digitalWrite(LeftSonarOut, LOW);


  pinMode(LeftSonarIn, INPUT);
  durationL = pulseIn(LeftSonarIn, HIGH);

   pinMode(RightSonarOut, OUTPUT);
  digitalWrite(RightSonarOut, LOW);
  delayMicroseconds(2);
  digitalWrite(RightSonarOut, HIGH);
  delayMicroseconds(30);
  digitalWrite(RightSonarOut, LOW);
  pinMode(RightSonarIn, INPUT);
  durationR = pulseIn(RightSonarIn, HIGH); 

  
  pinMode(ForwardSonarOut, OUTPUT);

  
  digitalWrite(ForwardSonarOut, LOW);
  delayMicroseconds(2);
  digitalWrite(ForwardSonarOut, HIGH);
  delayMicroseconds(30);
  digitalWrite(ForwardSonarOut, LOW);


  pinMode(ForwardSonarIn, INPUT);
  durationF = pulseIn(ForwardSonarIn, HIGH);

  // convert the time into a distance
  inchesL = microsecondsToCentimeters(durationL);
  inchesR = microsecondsToCentimeters(durationR);
  inchesF = microsecondsToCentimeters(durationF);
//  cm = microsecondsToCentimeters(duration);

  Serial.println(inchesL);
   Serial.println(inchesR);
    Serial.println(inchesF);
    /*
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  */
  delay(100);

if(inchesR>10 && inchesF>10 &&inchesL>10)
{
  stopCar();
  Serial.println("STOP");
  }
 else if(inchesR<=10 && inchesF<=10 &&inchesL<=10)
  {
    go360();
    Serial.println("360");
  }
   else if(inchesR<=10 && inchesF<=10)
  {
    goLeft(); 
    Serial.println("LEFT");
    //delay(1000); 
  }
  else if(inchesR<=10&&inchesF>10)
  {
    goForward();
    Serial.println("FORWARD");
    //delay(1000);
  }
  else if(inchesR>10)
  {
    goRight(); 
    Serial.println("RIGHT");
    //delay(1000); 
  }
  
   

  
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}



void goForward()
{
  digitalWrite(leftMotorF, HIGH);
  digitalWrite(leftMotorB, LOW);
  digitalWrite(bleftMotorF, HIGH);
  digitalWrite(bleftMotorB, LOW);
  digitalWrite(rightMotorF, HIGH);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(brightMotorF, HIGH);
  digitalWrite(brightMotorB, LOW);
}
void goBackward()
{
  digitalWrite(leftMotorF, LOW);
  digitalWrite(leftMotorB, HIGH);
  digitalWrite(bleftMotorF, LOW);
  digitalWrite(bleftMotorB, HIGH);
  digitalWrite(rightMotorF, LOW);
  digitalWrite(rightMotorB, HIGH);
  digitalWrite(brightMotorF, LOW);
  digitalWrite(brightMotorB, HIGH);
}
void stopCar()
{
  digitalWrite(leftMotorF, LOW);
  digitalWrite(leftMotorB, LOW);
  digitalWrite(rightMotorF, LOW);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(bleftMotorF, LOW);
  digitalWrite(bleftMotorB, LOW);
  digitalWrite(brightMotorF, LOW);
  digitalWrite(brightMotorB, LOW);
}
void goRight()
{
  digitalWrite(leftMotorF, HIGH);
  digitalWrite(leftMotorB, LOW);
  digitalWrite(bleftMotorF, HIGH);
  digitalWrite(bleftMotorB, LOW);
  digitalWrite(rightMotorF, LOW);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(brightMotorF, LOW);
  digitalWrite(brightMotorB, LOW);
}
void goLeft()
{
  digitalWrite(leftMotorF, LOW);
  digitalWrite(leftMotorB, LOW);
  digitalWrite(bleftMotorF, LOW);
  digitalWrite(bleftMotorB, LOW);
  digitalWrite(rightMotorF, HIGH);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(brightMotorF, HIGH);
  digitalWrite(brightMotorB, LOW);
}

void go360()
{
  goLeft();
  delay(500);
 }



