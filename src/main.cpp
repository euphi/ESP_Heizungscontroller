/*
 * main.cpp
 *
 *  Created on: 14.08.2016
 *      Author: ian
 */

#include <Homie.hpp>

#include <Homie.h>
#include <RelaisNode.h>

/* includes for Libraries, so platformio can find them */
#include <Wire.h>
#include <Sensors.h>
#include <OLEDStatusIndicator.h>

RelaisNode rel;
OLEDStatusIndicator status;


void eventHandler(HomieEvent event) {
	status.Event(event);

}
void setup() {
	Serial.begin(115200);
	Serial.println("Up!");
	Serial.flush();

	status.setup();
	Homie.disableResetTrigger();
	Homie.onEvent(eventHandler);
	Homie.setup();
}

void loop() {
	status.loop();
	Homie.loop();
}
