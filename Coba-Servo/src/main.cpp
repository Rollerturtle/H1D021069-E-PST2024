#include <Arduino.h>
#include <Servo.h>


Servo myServo;

void setup() {
  myServo.attach(D4);
}

void loop() {
  myServo.write(0);
  myServo.write(90);
  myServo.write(0);
  myServo.write(90);
}
