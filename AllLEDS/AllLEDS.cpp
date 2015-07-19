#include "AllLEDS.h"

int blue = 13;
int white = 6;
int rgb_red = 9;
int rgb_green = A2;
int rgb_blue = A3;

void setup() {
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(rgb_red, OUTPUT);
  pinMode(rgb_green, OUTPUT);
  pinMode(rgb_blue, OUTPUT);
}

void loop() {
  digitalWrite(blue, HIGH);
  digitalWrite(white, HIGH);
  digitalWrite(rgb_red, HIGH);
  digitalWrite(rgb_green, HIGH);
  digitalWrite(rgb_blue, HIGH);
  delay(200);
}
