int ldrPin = A7;
double ldrValue;

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  Serial.print("LDR: ");
  Serial.println(ldrValue);

  delay(100);
}

