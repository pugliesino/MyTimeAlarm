# MyTimeAlarm
Library for manage Time with the control of reset millis() after 49 day and interval change during working


The library is used to handle pauses or temporal repetitions without using the delay () that blocks the execution of the code.

The library also handles multiple instances, the millis() function reset after about 49 days (with exact time calculation after the reset) and the ability to change the interval during execution.
When changing the range, you can indicate whether the change will occur immediately or wait for the alarm to start.


Use Libray:

include library

#include <MyTimeAlarm.h>

Inizialize instances Timer1 -> MyTimeAlarm XXXXXXX;

MyTimeAlarm Timer1;

set Timer1 ON with the indication of the interval in milliseconds - return true or false
Timer1.on(5000) 

set Timer1 OFF - return true or false
Timer1.off()

to know if the alarm was triggered - return true or false
Timer1.active()

for example (in loop...):
if (Timer1.active()) Serial.println("Alarm Timer1");

change Timer2 immediately (Interval, true) - return true or false
Timer2.change(3000,true);

change Timer2 NOT immediately  - wait for the alarm to start (Interval, false)
Timer2.change(3000,false);
