int sensorPin = A7;
double sensorValue;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL1V1);
  pinMode(sensorPin, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Temp: ");
  Serial.println(sensorValue/9.31);

  delay(100);
}

