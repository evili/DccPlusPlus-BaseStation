#include "Railcom.h"

Railcom::Railcom() {
  // Timer 2 in normal mode disabled
  TCCR2A = 0x00;
  TCCR2B = 0x00;
  ASSR = 0x00;
  TIMSK2 = 0x00;
  TIFR2 = 0x00;
  
  sensors = sensors.first = sensors.next = NULL;
}

void Railcom::AddSensor(int sensorPin) {
  if (first == NULL) {
    sensors = new RailcomSensor(sensorPin);
    first = sensors;
  }
  else {
    RailcomSensor *last;
    for(RailcomSensor *s = first; s != NULL && s != first; s = s->next){
      last = s;
    }
    last->next = new RailcomSensor(sensorPin);
  }
}

void Railcom::RemoveSensor(int sensorPin) {
  for(RailcomSensor *s = sensors->first;
}

void Railcom::Railcom_ISR() {
  if(rState == CUTOUT_BEFORE) {
    // We should not have arrived here
    TIFR2 = 0x00;
    TIMSK2 = 0x00;
  } else if(rState == CUTOUT_ACTIVE) {
    if(rTime = )
    
  }
  else if (rState == CUTOUT_DONE) {
    rTime = 0;
    TIMSK2 = 0x00;
    TCNT2 = 0x00;
  }
}
