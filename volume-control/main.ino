int const potPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potVal = analogRead(potPin);
  int volume = map(potVal, 0, 1023, 0, 100);
  Serial.write(volume);
}
