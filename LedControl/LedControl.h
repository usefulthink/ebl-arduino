/*
  LedControl.h - Event-Based Library for Arduino.
  Copyright (c) 2011, Renato A. Ferreira
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
      * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LedControl_h
#define LedControl_h

#include <stdlib.h>
#include "WProgram.h"

#define MODE_NONE 0
#define MODE_BLINK_ON 1
#define MODE_BLINK_OFF 2
#define MODE_FADE_IN 3
#define MODE_FADE_OUT 4
#define MODE_FADE_WAIT 4

struct LedInformation {
  short pin;
  short mode;
  int intervalMilliseconds;
  int delayMilliseconds;
  int syncDelay;
  unsigned long lastEventMicroseconds;
  short pwmLevel;
};

class LedControlClass
{
  public:
    LedControlClass();
	void loop();
	void turnOn(short pin);
	void turnOff(short pin);
	void turnOn(short pin, int delayMilliseconds);
	void turnOff(short pin, int delayMilliseconds);
	void turnPercent(short pin, short percent);
	void blink(short pin, int times, int intervalMilliseconds);
	void blink(short pin, int times, int intervalMilliseconds, int delayMilliseconds);
	void startBlink(short pin, int intervalMilliseconds);
	void startBlink(short pin, int intervalMilliseconds, int delayMilliseconds);
	void stopBlink(short pin);
	
  private:
    short count;
	short index;
	short index2;
	int syncDelay;
	bool syncMicros;
	unsigned long lastMicros;
    LedInformation* leds;
	LedInformation* currentLed;
	void addLed(short pin);
	void setPosition(short position);
	void findPin(short pin);
};

//global instance
extern LedControlClass LedControl;

#endif