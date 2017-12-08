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
#include <SensorNode.h> // TODO: make pio find sensor.h when compiling HomieNodeCollection
#include <Automaton.h>

RelaisNode rel(0x0000, 0x0FFF, 0xF000);

void setup() {
	delay(200);
	Serial.begin(74880);
	Serial.println("Starting Heizungscontroller");
	Homie.setLedPin(16, false);
	Homie.disableResetTrigger();
	LN.setLoglevel(LoggerNode::INFO);
	Homie_setFirmware("HzngCtrl", "1.1.5");
	//Homie.setBroadcastHandler([](String level, String value) {LN.logf(__PRETTY_FUNCTION__,LoggerNode::INFO, "Broadcast: %s: %s", level.c_str(), value.c_str());return true;});
	Homie.setup();
}

void loop() {
	Homie.loop();
}
