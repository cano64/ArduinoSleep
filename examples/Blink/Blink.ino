
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

