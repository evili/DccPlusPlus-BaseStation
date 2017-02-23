# RailCom for DCC++ BaseStation

This repo is a trial to use th DCC++ BaseStation as a RailCom Booster
and/or Detector.

## RailCom
[RailCom]() is the [NMRA Standard](http://www.nmra.org/sites/default/files/s-9.3.2_2012_12_10.pdf)
for bidirectonial communication between locomotives and the DCC central.

## Rationale
Since the Arduino + Motor Shield  IS the Booster and the central, we can easily
get the cutout.

Using the Motor Shield, we notice that the BRAKE and DIR pins ar NOT-XORED to provide the IN2 signal to the LM298.

To signal a cutout we need to put both outputs to ground level, so we
need to put DIRA to LOW, BRAKEA to HIGH, and ENA to HIGH:

Once we have the cutout we just need to sense if there's any RailCom
data arriving from the track.

For this we will need some circuitry to
sense the 2.2V/36mA/250kHz from the decoder (TODO).

## Circuitry

Use an analog comparator (like LM339) with voltage (12 V, 15 V), from
track so that it can get inputs directly. Since the output is an open
drain, pull up to Vcc = 5V (or 3.3) and connect to an Arduino
Interrupt-On-Change Pin (with an opto-coupler?).

Then it's "just" a matter to read a timer value to seize railcom data. 





