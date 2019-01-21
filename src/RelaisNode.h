/*
 * RelaisNode.h
 *
 *  Created on: 14.08.2016
 *      Author: ian
 */

#ifndef SRC_RELAISNODE_H_
#define SRC_RELAISNODE_H_

#include <HomieNode.hpp>

#ifdef PCF8575
#include <PCF8575.h>
#else
#include "Adafruit_MCP23017.h"
#endif

class RelaisNode : public HomieNode {

public:
	RelaisNode(uint16_t defaults = 0x0000, uint16_t invert = 0x0000, uint16_t inputmask = 0x0000);

protected:
  virtual void setup() override;
  virtual void loop() override;

  virtual void onReadyToOperate() override;

  virtual bool handleInput(const HomieRange& range, const String  &property, const String &value) override;

private:
  void updateRelais(uint16_t updateMask=0xFFFF);
  void readInputs();

  uint16_t relais_bitset; // stores actual value
  uint16_t invert_bitset; // If bit is set, value written to PCF8575 will be inverted
  uint16_t input_mask;  // If bit is set, related pin will be configured as (quasi-)input
  uint16_t input_data;

  uint16_t updateMaskLoop;

#ifdef PCF8575
  PCF8575 io;
#else
  Adafruit_MCP23017 io;
#endif


};

#endif /* SRC_RELAISNODE_H_ */
