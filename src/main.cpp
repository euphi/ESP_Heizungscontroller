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
#include <InputController.h>

/* includes for Libraries, so platformio can find them */
#include <Wire.h>
#include <Sensors.h>


#include <OLEDStatusIndicator.h>

RelaisNode rel;
OLEDStatusIndicator status;
SSD1306Wire display(0x3c, SDA, SCL);
OLEDDisplayUi ui(&display);
InputController ictrl;

void eventHandler(HomieEvent event) {
	status.Event(event);

}
void setup() {
	Serial.begin(115200);
	Serial.println("Setup");
	Serial.flush();
	Homie.disableResetTrigger();
	Homie.setLoggingPrinter(&display);
	//Homie.setLoggingPrinter(&Serial);
	display.setLogBuffer(4,200);
	LN.setLoglevel(LoggerNode::DEBUG);

	ui.setFrameAnimation(SLIDE_LEFT);
	ui.disableAutoTransition();
	ui.disableAllIndicators();
	ui.init();

	display.flipScreenVertically();
	status.setup();
	Homie.onEvent(eventHandler);
	Homie.setup();
}

void loop() {
	status.loop();
	Homie.loop();
}
