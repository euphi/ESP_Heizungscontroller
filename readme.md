# Relais node for controllig a underfloor heating

## Basic concept

This homie node switches the heating valves using relays. Beside the handling of MQTT messages, it is completety dumb. It just follows the commands received via MQTT.
The command are send by an Openhab server. All the logic goes into there.


## Hardware

* ESP8266 Module
* I2C IO-Extender PFC8575 (16 GPIOs)
* 8xRelais Board
* 4xRelais Board
* DIN Rail
* 12V Power Supply
* Two adjustable DCDC Converter (set to 12V -> 3,3V and to 12V -> 5V)
* DIN Rail
* DIN Rail adapters
* Wires
* Several WAGO Clamps

### Details
In my case the magnetic valves for the undefloor heating were all already installed in the apartments junction box. They are conect to a simple thermostat in every room that just switches the valve on or off.


**_WARNING_: In my case the valves (and thus the thermostats and thus the relais) use 230V AC. Rules for electrical safety must be applied. Never access electrical installations unless you are empowered to do so.**

### Notes
* The relais needs 5V to switch. Ensure that the power supply for 5V is powerful enough to switch on the last relais while all other are already on.
