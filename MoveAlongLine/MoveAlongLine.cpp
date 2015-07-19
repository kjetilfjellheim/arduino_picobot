// Do not remove the include below
#include "MoveAlongLine.h"
#include <Arduino.h>

const int RIGHTLINESENSOR = A6;
const int LEFTLINESENSOR = A7;

//The setup function is called once at startup of the sketch
void setup() {
	delay(500);
	Serial.begin(9600);
	pinMode(RIGHTLINESENSOR, INPUT);
	pinMode(LEFTLINESENSOR, INPUT);
	pinMode(A2, OUTPUT);
	pinMode(A3, OUTPUT);
}

// The loop function is called in an endless loop
void loop() {
	int leftLineSensorVal = analogRead(LEFTLINESENSOR);
	int rightLineSensorVal = analogRead(RIGHTLINESENSOR);
	Serial.print(leftLineSensorVal);
	Serial.print(" - ");
	Serial.println(rightLineSensorVal);
	delay(500);
}
