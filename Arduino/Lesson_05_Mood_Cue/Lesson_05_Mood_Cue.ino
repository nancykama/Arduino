#include <Servo.h>
Servo myServo;
int const potPin = A0;
int potVal;
int angle;

void setup() {
  myServo.attach(9);

  Serial.begin(9700); 
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1022, 0, 180);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
