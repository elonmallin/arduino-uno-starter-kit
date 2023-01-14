int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int potPin = A1;
const int photosensPin = A0;
const int ledPin = 13;
const int tonePin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(photosensPin);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  float potScale = (float)analogRead(potPin) / 1023.0;
  Serial.print("potScale: ");
  Serial.print(potScale);

  sensorValue = analogRead(photosensPin);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  Serial.print(", pitch: ");
  Serial.print(pitch);

  int scaledPitch = (int)((float)pitch * potScale);
  tone(tonePin, scaledPitch, 20);
  Serial.print(", scaledPitch: ");
  Serial.println(scaledPitch);
  
  delay(250);
}



