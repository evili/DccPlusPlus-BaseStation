#ifndef _Railcom_h
#define _Railcom_h
#include "Arduino.h"

static const byte CUTOUT_BEFORE = 0;
static const byte CUTOUT_ACTIVE = 1;
static const byte CUTOUT_DONE = 2;

static const unsigned long ARDUINO_FREQ = 16000000L;

struct Railcom {
  byte sensePin;
  Railcom();
  void Railcom_ISR();
};


#endif

