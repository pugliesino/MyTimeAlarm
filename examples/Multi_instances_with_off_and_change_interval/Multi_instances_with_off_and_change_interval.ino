/*
  MyTimeAlarm.cpp 2.0 - Library for manage Time with control reset millis() after 49 day and change inteval during working.
  Created by Alessandro Colosi - August 31, 2017.
  Released into the public domain.
*/

#include <MyTimeAlarm.h>

MyTimeAlarm Timer1; //Inizialize instances Timer1

MyTimeAlarm Timer2; //Inizialize instances Timer2

int i=0;

void setup() {

Serial.begin(9600);

if (Timer1.on(5000)) Serial.println("Timer 1 ON"); else Serial.println("Error Timer1"); //Turn on Timer1 with intervals in milliseconds
if (Timer2.on(1000)) Serial.println("Timer 2 ON"); else Serial.println("Error Timer1"); //Turn on Timer2 with intervals in milliseconds

}

void loop() {

 if (Timer1.active()) { //check if Timer1 is active (interval reached)
    Serial.println("Alarm Timer1");
    i++;
    if (i==3) { //event after 3 repeat
		Timer1.off(); //Timer1 off after 3 repeat alarm
		Timer2.change(3000,true); //change Timer2 immediately (now=true) to 3 sec. (in example ... after Timer1 off)
		// Timer2.change(3000,false); //change Timer2 NOT immediately (now=false) to 3 sec. (in this case the change occurs after the alarm)
		
	}
	
 }


 if (Timer2.active()) Serial.println("Alarm Timer2"); //check if Timer1 is active (interval reached) - Timer2 is never switched off (in this example)
 
 
}