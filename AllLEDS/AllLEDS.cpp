#include "AllLEDS.h"

int blue = 13;
int white = 6;

void setup() {
	pinMode(blue, OUTPUT);
	pinMode(white, OUTPUT);
}

void loop() {
	digitalWrite(blue, HIGH);
	digitalWrite(white, HIGH);
}
