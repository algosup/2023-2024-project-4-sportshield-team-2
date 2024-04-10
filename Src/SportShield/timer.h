#define TIMER_INTERRUPT_DEBUG 0
#define _TIMERINTERRUPT_LOGLEVEL_ 0
#include "NRF52_MBED_TimerInterrupt.h"
#include "NRF52_MBED_ISR_Timer.h"
#define HW_TIMER_INTERVAL_MS 1
NRF52_MBED_Timer ITimer(NRF_TIMER_3);
NRF52_MBED_ISRTimer ISR_Timer;
#define TIMER_INTERVAL_120S 120000L


//---------------------GLOBAL VARIABLE--------------

unsigned long millisPassed = millis();

//---------------------SETUP FUNCTIONS--------------

void Temps(void) {
  
  unsigned int seconds = (millisPassed / 1000) % 60;
  unsigned int minutes = (millisPassed / (1000 * 60)) % 60;
  unsigned int hours = (millisPassed / (1000 * 60 * 60)) % 24;
  Serial.print("Détecté a : ");
  Serial.print(hours);
  Serial.print("h");
  Serial.print(minutes);
  Serial.print("mn");
  Serial.print(seconds);
  Serial.println("s");
}