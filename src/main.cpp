/*
 * main.cpp
 *
 *  Created on: 14.08.2016
 *      Author: ian
 */

#include <Homie.hpp>

#include <Homie.h>
#include <RelaisNode.h>
#include <LoggerNode.h>

/* includes for Libraries, so platformio can find them */
#include <SensorNode.h> // TODO: Quirk to make pio find sensor.h when compiling HomieNodeCollection

RelaisNode rel;

void setup() {
	Serial.begin(115200);
	Serial.println("Starting Heizungscontroller");
	Serial.flush();

	Homie.disableResetTrigger();
	LN.setLoglevel(LoggerNode::INFO);
	Homie_setFirmware("HzngCtrl", "0.9");
	Homie.setBroadcastHandler([](String level, String value) {LN.logf(__PRETTY_FUNCTION__,LoggerNode::INFO, "Broadcast: %s: %s", level.c_str(), value.c_str());return true;});
	Homie.setup();
	Serial.begin(115200);
	Serial.println("Finished Setup");
	Serial.flush();
}

void loop() {
	Homie.loop();
}
