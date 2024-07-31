#ifndef __SHSHAKEITL298N_H__
#define __SHSHAKEITL298N_H__

#include <Arduino.h>
#include "SHShakeitBase.h"

const int LEDPIN = 2;

class SHShakeitL298N : public SHShakeitBase {
private:
	byte	pinL98N_enA = 0;
	byte	pinL98N_enB = 0;
	byte	pinL98N_in1 = 0;
	byte	pinL98N_in2 = 0;
	byte	pinL98N_in3 = 0;
	byte	pinL98N_in4 = 0;
public:
	uint8_t motorCount() {
		return 2;
	}

	String providerName() {
		return "L298N";
	}

	void begin(byte	pL98N_enA, byte	pL98N_enB, byte	pL98N_in1, byte	pL98N_in2, byte	pL98N_in3, byte	pL98N_in4) {

		pinL98N_enA = pL98N_enA;
		pinL98N_enB = pL98N_enB;
		pinL98N_in1 = pL98N_in1;
		pinL98N_in2 = pL98N_in2;
		pinL98N_in3 = pL98N_in3;
		pinL98N_in4 = pL98N_in4;

		pinMode(pinL98N_enA, OUTPUT);
		pinMode(pinL98N_enB, OUTPUT);
		pinMode(pinL98N_in1, OUTPUT);
		pinMode(pinL98N_in2, OUTPUT);
		pinMode(pinL98N_in3, OUTPUT);
		pinMode(pinL98N_in4, OUTPUT);
		pinMode(LEDPIN, OUTPUT);

		digitalWrite(pinL98N_enA, LOW);
		digitalWrite(pinL98N_enB, LOW);

		digitalWrite(pinL98N_in1, LOW);
		digitalWrite(pinL98N_in2, HIGH);

		digitalWrite(pinL98N_in3, LOW);
		digitalWrite(pinL98N_in4, HIGH);

		analogWriteFrequency(30000); // for Darkrock PC fans
	}

protected:
	void setMotorOutput(uint8_t motorIdx, uint8_t value) {
		int mappedValue = 0;
		if (value != 0) {
			mappedValue = int(map(value, 0, 255, 163, 255));
		}

		if (mappedValue >= 163) {
			digitalWrite(LEDPIN, HIGH);
		} else {
			digitalWrite(LEDPIN, LOW);
		}

		if (motorIdx == 0) {
			analogWrite(pinL98N_enA, mappedValue);
		}
		else {
			analogWrite(pinL98N_enB, mappedValue);
			}
		}
	};

#endif