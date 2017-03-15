/*




*/

#include "sdelay.h"

//ISR(WDT_vect) {} //uncomment this if your board keeps resetting, comment this out if your sketch or other libraries already define this ISR


void sleepWithWDT(uint8_t wdt_period) {
  wdt_enable(wdt_period);
  wdt_reset();
  #if defined(__AVR_ATtiny85__) 
    WDTCR |= _BV(WDIE); //wake up interrupt when time is up
  #else //ATTiny84, ATMega328
    WDTCSR |= _BV(WDIE); //wake up interrupt when time is up
  #endif 
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_mode();
  wdt_disable();
  #if defined(__AVR_ATtiny85__) 
    WDTCR &= ~_BV(WDIE);
  #else //ATTiny84, ATMega328
    WDTCSR &= ~_BV(WDIE);
  #endif 
}


void sdelay(unsigned long ms) {
  //watchdog timer at 128kHz
  //one tick every 0.0078125ms
  //2048 cycles = 16ms
  //at 5V at room temperature, actual results may vary
  //it takes 65ms to wake up at the slowest setting
  #define WAKING_UP_TIME 65
  
  while (ms >= 8192 + WAKING_UP_TIME) { sleepWithWDT(WDTO_8S);   ms -= 8192 + WAKING_UP_TIME; }
  if (ms >= 4096 + WAKING_UP_TIME)    { sleepWithWDT(WDTO_4S);   ms -= 4096 + WAKING_UP_TIME; }
  if (ms >= 2048 + WAKING_UP_TIME)    { sleepWithWDT(WDTO_2S);   ms -= 2048 + WAKING_UP_TIME; }
  if (ms >= 1024 + WAKING_UP_TIME)    { sleepWithWDT(WDTO_1S);   ms -= 1024 + WAKING_UP_TIME; }
  if (ms >= 512 + WAKING_UP_TIME)     { sleepWithWDT(WDTO_500MS); ms -= 512 + WAKING_UP_TIME; }
  if (ms >= 256 + WAKING_UP_TIME)     { sleepWithWDT(WDTO_250MS); ms -= 256 + WAKING_UP_TIME; }
  if (ms >= 128 + WAKING_UP_TIME)     { sleepWithWDT(WDTO_120MS); ms -= 128 + WAKING_UP_TIME; }
  if (ms >= 64 + WAKING_UP_TIME)      { sleepWithWDT(WDTO_60MS); ms -= 64 + WAKING_UP_TIME; }
  if (ms >= 32 + WAKING_UP_TIME)      { sleepWithWDT(WDTO_30MS); ms -= 32 + WAKING_UP_TIME; }
  if (ms >= 16 + WAKING_UP_TIME)      { sleepWithWDT(WDTO_15MS); ms -= 16 + WAKING_UP_TIME; }  
  if (ms > 0) delay(ms);
}

