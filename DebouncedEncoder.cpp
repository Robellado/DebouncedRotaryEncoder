
#include "Arduino.h"
#include "DebouncedEncoder.h"


DebouncedEncoder::DebouncedEncoder(int pin1, int pin2, int max, int min, bool cycle)
{
	//Definitions
	_pin1 = pin1;
	_pin2= pin2;
	minValue = min;
	maxValue = max;
	cycleValues = cycle;
	
	pinMode(pin1, INPUT_PULLUP);
	pinMode(pin2, INPUT_PULLUP);
}

int DebouncedEncoder::getPosition()
{
	return encCount;
}

int DebouncedEncoder::getDirection()
{
	return direction;
}

void DebouncedEncoder::setPosition(int newPosition)
{
	encCount = newPosition;
}

void DebouncedEncoder::setMaxValue(int newMaxValue)
{
	maxValue = newMaxValue;
}

void DebouncedEncoder::setMinValue(int newMinValue)
{
	minValue = newMinValue;
}


void DebouncedEncoder::setCycleMode(bool newCycleMode)
{
	cycleValues = newCycleMode;

}


void DebouncedEncoder::encoderCheck()
//Check the encoder state. Better if called from interrupt
{
	int a = digitalRead(_pin1);
	int b = digitalRead(_pin2);
	if (a != a0) { // A changed
		a0 = a;
		if (c0 == OFF) {
			c0 = b;
			return;
		}
		if (b != c0) {
			changeValue(a == b);
			c0 = OFF; 
		}
	}
}

void DebouncedEncoder::changeValue(bool Up)
{
	int prevencCount = encCount;
	bool cycled = false;

	if (Up == 1) encCount++;
	else encCount--;

	if (encCount > prevencCount) direction = 1;
	else direction = -1;

	if (cycleValues == true) {
		if (encCount == minValue - 1) {
			encCount = maxValue;
			cycled = true;
		}
		if (encCount == maxValue + 1 && cycled == false) {
			encCount = minValue;
		}
	}
	else {
		if (encCount > maxValue) encCount = maxValue;
		if (encCount < minValue) encCount = minValue;
	}

}
