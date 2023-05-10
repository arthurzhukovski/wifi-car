#### About
ESP8266/ESP32 firmware for a RC-car project.

https://user-images.githubusercontent.com/15804937/237058177-b94ba5e2-374e-4a6b-845f-d2f5cbb7bf26.MOV

#### Config
Create a file "secret.h" with two variables that contain your WiFi creds:
```
const char * wifiName = "SSID";
const char * wifiPwd = "PWD";
```
Current version is written for ESP32 microcontroller. In order to make it work on other models you have to include other WiFi & UDP libraries and rewrite some parts yourself.
For instance, in case of ESP8266 include "ESP8266WiFi.h" instead of "WiFi.h" and "WiFiUdp.h" instead of "AsyncUDP.h". Note that the interface for the UPD library differs quite a lot.
#### Controlling the car
To control the car send via UDP an integer that represents a command:

```
> ncat -u 192.168.0.100 6969
> 1
> 0
```

List of available commands can be found in "carControls.h" file.

Board's address & port are logged on startup, check these values in the serial monitor.

#### Remote controller
The implementation is up to your imagination.

An example of keyboard controls with NodeJS:
```
import { uIOhook, UiohookKey } from 'uiohook-napi';
import * as dgram from 'dgram';
const socket = dgram.createSocket('udp4');
uIOhook.on('keydown', (e) => {
    switch (e.keycode){
	case UiohookKey.W:
	    socket.send(Buffer.from('1'), 6969, '192.168.0.100');
	    break;
	...
    }
});
uIOhook.on('keyup', (e) => {
    switch (e.keycode){
        case UiohookKey.W:
            socket.send(Buffer.from('0'), 6969, '192.168.0.100');
            break;
	...
    }
});
uIOhook.start();
``` 
