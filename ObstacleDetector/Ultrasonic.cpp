// Do not remove the include below
#include "Ultrasonic.h"
#include <Arduino.h>

const int ECHOPINGPIN = A4;
const int TRIGECHOPIN = A5;
const int LEFTMOTOR = 2;
const int LEFTMOTORPWM = 3;
const int RIGHTMOTOR = 4;
const int RIGHTMOTORPWM = 5;

const int CMVCONV = 59;

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(9600);
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
		digitalWrite(LEFTMOTOR, LOW);
		digitalWrite(LEFTMOTORPWM, HIGH);
		digitalWrite(RIGHTMOTOR, HIGH);
		digitalWrite(RIGHTMOTORPWM, LOW);

	} else {
		digitalWrite(LEFTMOTOR, LOW);
		digitalWrite(LEFTMOTORPWM, LOW);
		digitalWrite(RIGHTMOTOR, LOW);
		digitalWrite(RIGHTMOTORPWM, LOW);
	}
	delay(100);
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
