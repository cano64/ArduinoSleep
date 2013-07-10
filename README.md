Arduino Sleep
============

Arduino Sleep is a small library that will add a sleep function to your project.
You can use it instead of default delay() function to save power.
It works on ATMega328, ATTiny84 and ATTiny85

Just replace delay() with sdelay() that's it.

when called sdelay(), arduino will enter a power down mode for given amount of time, 
reducing power consumtion significantly
