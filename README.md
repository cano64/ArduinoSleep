Arduino Sleep
============

Arduino Sleep is a small library that will add a sleep functionality to your project.
You can use it instead of default delay() function to save power.
It works on ATMega328, ATTiny84 and ATTiny85

Just replace delay() with sdelay() that's it.

when called sdelay(), arduino will enter a power down mode for given amount of time, 
reducing power consumtion significantly

    #include "sdelay.h"
    
    #define LED_PIN 13
    #define BLINK_DELAY 1000
    
    void setup() {
      pinMode(LED_PIN, OUTPUT);
    }
    
    
    void loop() {
      digitalWrite(LED_PIN, HIGH);
      sdelay(BLINK_DELAY);
      digitalWrite(LED_PIN, LOW);
      sdelay(BLINK_DELAY);
    }
