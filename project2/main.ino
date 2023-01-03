int pinRed1 = 5;
int pinRed2 = 4;
int pinGreen = 3;
int pinButton = 2;
int switchState = 0;

void setup() {
  pinMode(pinRed1, OUTPUT);
  pinMode(pinRed2, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinButton, INPUT);
}

void loop() {
  switchState = digitalRead(pinButton);
  if (switchState == LOW) {
    digitalWrite(pinRed1, LOW);
    digitalWrite(pinRed2, LOW);
    digitalWrite(pinGreen, HIGH);
  }
  else {
    digitalWrite(pinRed1, HIGH);
    digitalWrite(pinRed2, LOW);
    digitalWrite(pinGreen, LOW);
    delay(250);
    digitalWrite(pinRed1, LOW);
    digitalWrite(pinRed2, HIGH);
    delay(250);
  }
}
