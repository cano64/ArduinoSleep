/*

  This sketch will blink LED13 few times upon start using original delay function
  Then it will blink once a second using sleep delay
  
  This library is intended for standalone ATmega and ATtiny chips, 
  there is little or no benefit using sleep on the Arduino board


*/


#include <sdelay.h> //use this if your sketch or other libraries define their own ISR(WDT_vect)

ISR(WDT_vect) {} //uncomment this if your board keeps resetting, comment this out if your sketch or other libraries already define this ISR


#define LED_PIN 13
#define BLINK_DELAY 500
#define BLINK_FAST_DELAY 50
#define BLINK_FAST_COUNT 20



void setup() {
  pinMode(LED_PIN, OUTPUT);
  //fast blink few times with old delay to indicate start of the sketch
  for(byte i = 0; i < BLINK_FAST_COUNT; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(BLINK_FAST_DELAY);
    digitalWrite(LED_PIN, LOW);
    delay(BLINK_FAST_DELAY);
  }
}


void loop() {
  digitalWrite(LED_PIN, HIGH);
  sdelay(BLINK_DELAY);
  digitalWrite(LED_PIN, LOW);
  sdelay(BLINK_DELAY);
}