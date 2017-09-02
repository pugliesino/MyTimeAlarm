/*
  MyTimeAlarm.cpp 2.0 - Library for manage Time with control reset millis() after 49 day and change inteval during working.
  Created by Alessandro Colosi - August 31, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "MyTimeAlarm.h"

MyTimeAlarm::MyTimeAlarm()
{

  Inizialize=true;

}

bool MyTimeAlarm::on(unsigned long interval)
{
  if (!Inizialize || AlarmOn || interval<0) return false;
	
	_interval = interval;
	previousMillis=millis();
	AlarmOn=true;
	return true;
  
}

bool MyTimeAlarm::off()
{
  if (!Inizialize || !AlarmOn) return false;
	
	previousMillis=0;
	diffMillis=0;
	currentMillis=0;
	_interval=0;
	_intervalchange=0;
	_now=false;
	AlarmOn=false;
	ChangeOn=false;
	Inizialize=false;
	return true;
	
}

bool MyTimeAlarm::change(unsigned long intervalchange, bool now)
{
  if (!Inizialize || !AlarmOn || intervalchange<0) return false;
	
	if (now) {
		_interval=intervalchange;
		previousMillis=millis();
	}else{
	_intervalchange = intervalchange;
	}
	
	_now=now;
	ChangeOn=true;
	return true;
  
}


bool MyTimeAlarm::active()
{
  if (Inizialize && AlarmOn) {
    
	currentMillis=millis();
	
	if (currentMillis<previousMillis) {
		diffMillis = 4294967295 - previousMillis + currentMillis;
		}else{
		diffMillis = currentMillis-previousMillis;
	}
     
	if (diffMillis >= _interval) {
		previousMillis = currentMillis;
		if (!_now && ChangeOn) {
			_interval=_intervalchange;
			_intervalchange=0;
			ChangeOn=false;
		}
		return true; //Alarm
	}else{
	return false;
	}
  
  
  }else{
  return false;
  }
  
}
