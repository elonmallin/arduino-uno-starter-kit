#include <Servo.h>

Servo myServo;
int const potPin = A0;
int const servoPin = 9;
int const ledPinR = 3;
int const ledPinG = 5;
int potVal;
int angle, oldAngle;

unsigned long currentTime, oldTime, deltaTime, angleUnchangedTime;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);

  currentTime = millis();
}

void loop() {
  oldTime = currentTime;
  currentTime = millis();
  deltaTime = currentTime - oldTime;

  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  oldAngle = angle;
  angle = map(potVal, 0, 1023, 0, 179);
  if (angle == oldAngle) {
    angleUnchangedTime += deltaTime;
  }
  else {
    angleUnchangedTime = 0;
  }
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);

  digitalWrite(ledPinG, LOW);
  if (angle < 60) {
    if (currentTime % 500 < 250) {
      digitalWrite(ledPinR, LOW);
    }
    else {
      digitalWrite(ledPinR, HIGH);
    }
  }
  else if (angle > 120) {
    if (currentTime % 2000 < 1000) {
      digitalWrite(ledPinR, LOW);
    }
    else {
      digitalWrite(ledPinR, HIGH);
    }
  }
  else {
    if (angleUnchangedTime > 5000) {
      if (currentTime % 500 < 250) {
        digitalWrite(ledPinR, LOW);
        digitalWrite(ledPinG, HIGH);
      }
      else {
        digitalWrite(ledPinR, HIGH);
        digitalWrite(ledPinG, LOW);
      }
    }
    else if (angleUnchangedTime > 3000) {
      digitalWrite(ledPinR, LOW);
      digitalWrite(ledPinG, HIGH);
    }
    else {
      digitalWrite(ledPinR, HIGH);
    }
  }

  delay(15);
}
