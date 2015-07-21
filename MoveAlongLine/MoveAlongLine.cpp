// Do not remove the include below
#include "MoveAlongLine.h"
#include <Arduino.h>

const int RIGHTLINESENSOR = A6;
const int LEFTLINESENSOR = A7;

const int LEFTMOTOR = 2;
const int LEFTMOTORPWM = 3;
const int RIGHTMOTOR = 4;
const int RIGHTMOTORPWM = 5;

const int LINE_MAX_DETECTOR = 500;

//The setup function is called once at startup of the sketch
void setup() {
	delay(500);
	Serial.begin(9600);

	pinMode(RIGHTLINESENSOR, INPUT);
	pinMode(LEFTLINESENSOR, INPUT);

	pinMode(LEFTMOTOR, OUTPUT);
	pinMode(LEFTMOTORPWM, OUTPUT);
	pinMode(RIGHTMOTOR, OUTPUT);
	pinMode(RIGHTMOTORPWM, OUTPUT);
}

// The loop function is called in an endless loop
void loop() {
	int leftLineSensorVal = analogRead(LEFTLINESENSOR);
	int rightLineSensorVal = analogRead(RIGHTLINESENSOR);

	if (leftLineSensorVal > LINE_MAX_DETECTOR) {
		digitalWrite(RIGHTMOTOR, HIGH);
		analogWrite(RIGHTMOTORPWM, 127);
	} else {
		digitalWrite(RIGHTMOTOR, LOW);
		analogWrite(RIGHTMOTORPWM, 127);
	}
	if (rightLineSensorVal > LINE_MAX_DETECTOR) {
		digitalWrite(LEFTMOTOR, LOW);
		analogWrite(LEFTMOTORPWM, 127);
	} else {
		digitalWrite(LEFTMOTOR, HIGH);
		analogWrite(LEFTMOTORPWM, 127);
	}
	Serial.print(leftLineSensorVal);
	Serial.print(" - ");
	Serial.println(rightLineSensorVal);

}
