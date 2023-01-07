const int pinPhotosensorRed = A0;
const int pinPhotosensorGreen = A1;
const int pinPhotosensorBlue = A2;
const int pinLedR = 11;
const int pinLedG = 9;
const int pinLedB = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedG, OUTPUT);
  pinMode(pinLedB, OUTPUT);
}

void loop() {
  int sensorR = analogRead(pinPhotosensorRed)/4;
  delay(2);
  int sensorG = analogRead(pinPhotosensorGreen)/4;
  delay(2);
  int sensorB = analogRead(pinPhotosensorBlue)/4;
  delay(2);

  Serial.print("Raw sensor values \t Red: ");
  Serial.print(sensorR);
  Serial.print("\t Green: ");
  Serial.print(sensorG);
  Serial.print("\t Blue: ");
  Serial.println(sensorB);

  if (sensorR > sensorG && sensorR > sensorB) {
    sensorR = 200;
    sensorG = 0;
    sensorB = 0;
  }
  else if (sensorB > sensorR && sensorB - 3 > sensorG) {
    sensorR = 0;
    sensorG = 0;
    sensorB = 200;
  }
  else {
    sensorR = 0;
    sensorG = 200;
    sensorB = 0;
  }

  analogWrite(pinLedR, sensorR);
  analogWrite(pinLedG, sensorG);
  analogWrite(pinLedB, sensorB);

  delay(400);
}
