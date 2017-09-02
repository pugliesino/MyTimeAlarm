/*
  MyTimeAlarm.h 2.0 - Library for manage Time with control reset millis() after 49 day and change inteval during working.
  Created by Alessandro Colosi - August 31, 2017.
  Released into the public domain.
*/

#ifndef MyTimeAlarm_h
#define MyTimeAlarm_h

#include "Arduino.h"

class MyTimeAlarm
{
  public:
    MyTimeAlarm();
    bool on(unsigned long interval);
    bool off();
	bool change(unsigned long intervalchange, bool now);
	bool active();
  private:
    unsigned long _interval;
	unsigned long _intervalchange;
	bool _now;
	bool AlarmOn=false;
	bool ChangeOn=false;
	bool Inizialize=false;
	unsigned long previousMillis;
	unsigned long diffMillis;
	unsigned long currentMillis;
};

#endif