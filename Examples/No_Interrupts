/* Copyright (c) by Javier Pitarch 2019 - robellado@gmail.com
   Based in the idea and work of David Johnson-Davies - www.technoblogy.com 
   Complete description can be found in his web: http://www.technoblogy.com/show?1YHJ
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license :
   http://creativecommons.org/licenses/by/4.0/
 -----
   Bounce-Free Rotary Encoder
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license:
   http://creativecommons.org/licenses/by/4.0/
*/

int lastPosition;
int encPinA = 2;           
int encPinB = 3;          
int encMinValue = -1000;
int encMaxValue = 1000;

#include <DebouncedEncoder.h>

//Setup an encoder
DebouncedEncoder myEnc(encPinA, encPinB, encMaxValue, encMinValue, false);

void setup() {
	Serial.begin(9600);
	Serial.println("Simple debounced encoder example.");
}



void loop() {
	myEnc.encoderCheck();
	int pos = myEnc.getPosition();
	int direc = myEnc.getDirection();
	if (lastPosition != pos) {
		lastPosition = pos;
		Serial.println(pos);
		if (direc == 1) {
			Serial.println("CW");
		}
		else {
			Serial.println("CCW");
		}
	}
}
