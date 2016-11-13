# Relais node for controllig a underfloor heating

## How to compile
The sources here are very simple, because almost all logic is in the `RelaisǸode` of my [HomieNodeCollection](https://github.com/euphi/HomieNodeCollection). To compile, HomieNodeCollection must be available as lib. The simplest way to do this is to copy or symlink the sources of HomieNodeCollection into the `lib` directory.

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
* DIN Rail adapters
* Wires
* Several WAGO Clamps

### Details
In my case the magnetic valves for the undefloor heating were all already installed in the apartments junction box. They were connected to a simple thermostat in every room that just switches the valve on or off.

In a first step, I connected the Relais Boards in parallel to the thermostat, so you can still switch the heating by the Thermostat. (Heating is on, if Thermostat OR Relais is on).

**_WARNING_: In my case the valves (and thus the existing thermostats and thus the relais) use 230V AC. Rules and local laws for electrical safety must be applied. Never access electrical installations unless you are empowered to do so. Please keep in mind that also the low voltage DC supply (12V / 5V / 3.3V) can be dangerous, because they can start a fire if not well protected against too high currents. **

### Notes
* The relais needs 5V to switch. Ensure that the power supply for 5V is powerful enough to switch on the last relais while all other are already on.


### Controll the thermostat with OpenHAB

```
Number heizung_signal	"WiFi Signal" (wifi_qual, rrd_graph)		{mqtt="<[local:devices/hzgctrl/$stats/signal:state:default]"}

Group Heizung

Switch heizung_1    "1: Living Room"	(Heizung)		{mqtt="<[local:devices/hzgctrl/Relais/in_1:state:default],
													   >[local:devices/hzgctrl/Relais/in_1/set:command:*:default]", autoupdate="false"}

Switch heizung_2    "2: Sleeping Room"	(Heizung)		{mqtt="<[local:devices/hzgctrl/Relais/in_2:state:default],
													   >[local:devices/hzgctrl/Relais/in_2/set:command:*:default]", autoupdate="false"}

Switch heizung_3    "3: Bathroom"	(Heizung)		{mqtt="<[local:devices/hzgctrl/Relais/in_3:state:default],
													   >[local:devices/hzgctrl/Relais/in_3/set:command:*:default]", autoupdate="false"}

Switch heizung_4    "4: Kitchen"	(Heizung)		{mqtt="<[local:devices/hzgctrl/Relais/in_4:state:default],
													   >[local:devices/hzgctrl/Relais/in_4/set:command:*:default]", autoupdate="false"}
```
