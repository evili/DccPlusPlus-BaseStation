#ifndef _Railcom_h
#define _Railcom_h
#include "Arduino.h"

/* Railcom status */
static const byte CUTOUT_BEFORE = 0;
static const byte CUTOUT_ACTIVE = 1;
static const byte CUTOUT_DONE = 2;


/* times in timer count */
static const int FIRST_PACKET_START  = 1280; //  80 uS
static const int FIRST_PACKET_END    = 2832;  // 177 
static const int SECOND_PACKET_START = 3088;  // 193
static const int SECOND_PACKET_END   = 7264;  // 454
static const int CUTOUT_END          = 7680;  // 480
static const int RAILCOM_BIT_TIME    =   64;  // 250 kbits => 4 uS => 64 ticks 

struct RailcomSensor {
  byte sensePin;
  byte nBit;
  byte buffer[RAILCOM_MAX_BYTES];
  RailcomSensor *next;
}

struct Railcom {
  RailcomSensor *first;
  RailcomSensor *sensors;
  byte rState;
  unsigned int rTime;
  Railcom();
  void Railcom_ISR();
};

#endif
