// DebouncedEncoder.h
// -----
// DebounceEncoder.h - Library for using mechanical rotary encoders with debounce.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Javier Pitarch
//
// Based in the idea and work of David Johnson-Davies - www.technoblogy.com 
// Complete description can be found in his web: http://www.technoblogy.com/show?1YHJ

//CC BY 4.0
//Licensed under a Creative Commons Attribution 4.0 International license :
//http://creativecommons.org/licenses/by/4.0/
// -----


#ifndef _DEBOUNCEDENCODER_h
#define _DEBOUNCEDENCODER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif


#define OFF 2

class DebouncedEncoder
{
public:
	// ----- Constructor -----
	DebouncedEncoder(int pin1, int pin2, int max, int min, bool cycle);

	// retrieve the current position
	int  getPosition();

	// simple retrieve of the direction the knob was rotated at. 0 = No rotation, 1 = Clockwise, -1 = Counter Clockwise
	int getDirection();

	// adjust the current position
	void setPosition(int newPosition);

	// adjust the max value
	void setMaxValue(int newMaxValue);

	// adjust the min value
	void setMinValue(int newMinValue);

	// adjust the cycle mode
	void setCycleMode(bool newCycleMode);

	//Check the encoder state. Better if called from interrupt in Pin1
	void encoderCheck();

private:
	
	void changeValue(bool up);
	int _pin1, _pin2; // Pins used for the encoder. 
	volatile int direction; // 1=CW; -1=CCW
	volatile int encCount ;
	volatile int minValue;
	volatile int maxValue;
	volatile int cycleValues;

	volatile uint8_t a0 = OFF;
	volatile uint8_t c0 = OFF;


};

