/*
  MyTimeAlarm.cpp 2.0 - Library for manage Time with control reset millis() after 49 day and change inteval during working.
  Created by Alessandro Colosi - August 31, 2017.
  Released into the public domain.
*/

#include <MyTimeAlarm.h>

MyTimeAlarm Timer1;

MyTimeAlarm Timer2;

int i=0;

void setup() {

Serial.begin(9600);

if (Timer1.on(5000)) Serial.println("Timer 1 ON"); else Serial.println("Error Timer1");
if (Timer2.on(1000)) Serial.println("Timer 2 ON"); else Serial.println("Error Timer1");

}

void loop() {

 if (Timer1.active()) {
    Serial.println("Alarm Timer1");
    i++;
    if (i==3) {
		Timer1.off(); //off Timer1 after 3 repeat alarm
		Timer2.change(3000,true); //change Timer2 immediately (now=true) to 2 sec. (in example ... after Timer1 off)
	}
	
 }


 if (Timer2.active()) Serial.println("Alarm Timer2"); //Timer2 always active
 
 
}
