#include <Arduino.h>

int redLED = D1;
int yelLED = D2;
int greLED = D3;


void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yelLED, OUTPUT);
  pinMode(greLED, OUTPUT);
}

void loop() {
  digitalWrite(greLED, LOW);
  digitalWrite(redLED, HIGH);
  delay(1000);
  digitalWrite(redLED, LOW);
  digitalWrite(yelLED, HIGH);
  delay(1000);
  digitalWrite(yelLED, LOW);
  digitalWrite(greLED, HIGH);
  delay(1000);
}
