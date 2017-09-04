# MyTimeAlarm
Library for manage Time with the control of reset millis() after 49 day and interval change during working


The library is used to handle pauses or temporal repetitions without using the delay () that blocks the execution of the code.

The library also handles multiple instances, the millis() function reset after about 49 days (with exact time calculation after the reset) and the ability to change the interval during execution.
When changing the range, you can indicate whether the change will occur immediately or wait for the alarm to start.


Use Libray:


#include <MyTimeAlarm.h> //include library

MyTimeAlarm Timer1; //Inizialize instances Timer1 -> MyTimeAlarm XXXXXXX;

Timer1.on(5000) //set Timer1 ON with the indication of the interval in milliseconds - return true or false

Timer1.off() //set Timer1 OFF - return true or false

Timer1.active() //to know if the alarm was triggered - return true or false

if (Timer1.active()) Serial.println("Alarm Timer1"); //for example (in loop...)

Timer1.change(3000,true); //change Timer1 immediately (Interval, true) - return true or false

Timer1.change(3000,false); //change Timer1 NOT immediately  - wait for the alarm to start (Interval, false)
