// Do not remove the include below
#include "SynchronizeSlave.h"
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int RF_CE = 8;
const int RF_CSN = 7;

const int LEFTMOTOR = 2;
const int LEFTMOTORPWM = 3;
const int RIGHTMOTOR = 4;
const int RIGHTMOTORPWM = 5;

const byte READADRESS[6] = "00001";

RF24 radio(RF_CE, RF_CSN);

static FILE uartout = {0};

// create a output function
// This works because Serial.write, although of
// type virtual, already exists.
static int uart_putchar (char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

//The setup function is called once at startup of the sketch
void setup()
{
	fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);

	stdout = &uartout;
	Serial.begin(9600);
	pinMode(LEFTMOTOR, OUTPUT);
	pinMode(LEFTMOTORPWM, OUTPUT);
	pinMode(RIGHTMOTOR, OUTPUT);
	pinMode(RIGHTMOTORPWM, OUTPUT);

	radio.begin();
	radio.openReadingPipe(1, READADRESS);
	radio.startListening();
	radio.printDetails();
}

// The loop function is called in an endless loop
void loop() {
	if (radio.available()) {
		unsigned int val = 6;
		radio.read(&val, sizeof(unsigned int));
		setCommand(val);
	}
}

void setCommand(int command) {
	if (command == 0) {
		digitalWrite(RIGHTMOTOR, HIGH);
		analogWrite(RIGHTMOTORPWM, 127);
		digitalWrite(RIGHTMOTOR, LOW);
		analogWrite(RIGHTMOTORPWM, 0);
	} else if (command == 1) {
		digitalWrite(LEFTMOTOR, LOW);
		analogWrite(LEFTMOTORPWM, 0);
		digitalWrite(RIGHTMOTOR, HIGH);
		analogWrite(RIGHTMOTORPWM, 127);
	}
}
