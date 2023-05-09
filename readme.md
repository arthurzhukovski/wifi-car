#### About
ESP8266/ESP32 firmware for a RC-car project.

https://user-images.githubusercontent.com/15804937/234292148-91fb5b22-4c60-4be7-8c9f-88938697ec7b.mp4

#### Config
Create a file "secret.h" with two variables that contain your WiFi creds:
	const char * wifiName = "SSID";
	const char * wifiPwd = "PWD";

#### Controlling the car
To control the car send via UDP an integer that represents a command:
	ncat -u 192.168.0.100 6969
List of available commands can be found in "carControls.h" file.
Board's address & port are logged on startup, check these values in the serial monitor.

#### Remote controller
The implementation is up to your imagination.
An example of keyboard controls with NodeJS:
	import { uIOhook, UiohookKey } from 'uiohook-napi';
	import * as dgram from 'dgram';
	const socket = dgram.createSocket('udp4');
	uIOhook.on('keydown', (e) => {
	    switch (e.keycode){
	        case UiohookKey.W:
	            socket.send(Buffer.from('1'), 6969, '192.168.0.100');
	            break;
	    }
	    ...
	});