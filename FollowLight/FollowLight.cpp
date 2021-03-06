// Do not remove the include below
#include "FollowLight.h"
#include <Arduino.h>

const int LDR_LEFT = A0;
const int LDR_RIGHT = A1;

const int LEFTMOTOR = 2;
const int LEFTMOTORPWM = 3;
const int RIGHTMOTOR = 4;
const int RIGHTMOTORPWM = 5;

const int ECHOPINGPIN = A4;
const int TRIGECHOPIN = A5;

const int LIGHT_DETECTION_LEVEL = 70;

const int CMVCONV = 59;

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(9600);
	digitalWrite(A0, HIGH);
	digitalWrite(A1, HIGH);

	pinMode(ECHOPINGPIN, OUTPUT);

	pinMode(LEFTMOTOR, OUTPUT);
	pinMode(LEFTMOTORPWM, OUTPUT);
	pinMode(RIGHTMOTOR, OUTPUT);
	pinMode(RIGHTMOTORPWM, OUTPUT);
}

// The loop function is called in an endless loop
void loop() {
	int distance = getDistance();
	if (distance > 10) {
		int leftLDRSensorVal = analogRead(LDR_LEFT);
		int rightLDRSensorVal = analogRead(LDR_RIGHT);
		delay(50);
		int delta = leftLDRSensorVal - rightLDRSensorVal;
		Serial.print(leftLDRSensorVal);
		Serial.print(" - ");
		Serial.println(rightLDRSensorVal);

		if (delta < -30) {
			digitalWrite(RIGHTMOTOR, HIGH);
			analogWrite(RIGHTMOTORPWM, 255-160 );
			digitalWrite(LEFTMOTOR, LOW);
			analogWrite(LEFTMOTORPWM, 0);
		} else if (delta > 30) {
			digitalWrite(LEFTMOTOR, LOW);
			analogWrite(LEFTMOTORPWM, 160);
			digitalWrite(RIGHTMOTOR, LOW);
			analogWrite(RIGHTMOTORPWM, 0 );
		} else {
			digitalWrite(RIGHTMOTOR, HIGH);
			analogWrite(RIGHTMOTORPWM, 255-160);
			digitalWrite(LEFTMOTOR, LOW);
			analogWrite(LEFTMOTORPWM, 160);
		}
	} else {
		digitalWrite(LEFTMOTOR, LOW);
		analogWrite(LEFTMOTORPWM, 0);
		digitalWrite(RIGHTMOTOR, LOW);
		analogWrite(RIGHTMOTORPWM, 0);
	}
}

int getDistance() {
	digitalWrite(ECHOPINGPIN, LOW);
	delayMicroseconds(2);
	digitalWrite(ECHOPINGPIN, HIGH);
	delayMicroseconds(5);
	digitalWrite(ECHOPINGPIN, LOW);

	int duration = pulseIn(TRIGECHOPIN, HIGH);
	return duration / CMVCONV;
}
