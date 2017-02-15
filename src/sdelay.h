/*


*/


#ifndef _SDELAY_H_
#define _SDELAY_H_



#include <Arduino.h>
#include <avr/wdt.h>
#include <avr/sleep.h>





void sleepWithWDT(uint8_t wdt_period);
void sdelay(unsigned long ms);


#endif /* _SDELAY_H_ */