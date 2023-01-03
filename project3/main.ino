int pinRed1 = 5;
int pinRed2 = 4;
int pinRed3 = 3;
const int leds[] = { pinRed1, pinRed2, pinRed3 };
const int pinSensor = A0;
const float baselineTemp = 23.0;
const float tempStep = 0.6;

void setup() {
  Serial.begin(9600);

  for (int led : leds) {
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(pinSensor);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = (voltage - .5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  if (temperature < baselineTemp) {
    for (int led : leds) {
      digitalWrite(led, LOW);
    }
  }
  else if (temperature < baselineTemp + tempStep) {
    digitalWrite(pinRed1, LOW);
    digitalWrite(pinRed2, LOW);
    digitalWrite(pinRed3, HIGH);
  }
  else if (temperature < baselineTemp + tempStep * 2) {
    digitalWrite(pinRed1, LOW);
    digitalWrite(pinRed2, HIGH);
    digitalWrite(pinRed3, HIGH);
  }
  else if (temperature < baselineTemp + tempStep * 3) {
    digitalWrite(pinRed1, HIGH);
    digitalWrite(pinRed2, HIGH);
    digitalWrite(pinRed3, HIGH);
  }
}
