#include "WiFi.h"
#include "AsyncUDP.h"
#include "carControls.h"
#include "udpControls.h"
#include "secret.h"

void setup() {
  Serial.begin(115200);
  initCarControls();
 
  WiFi.begin(wifiName, wifiPwd);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  delay(500);

  initUdpControls();
}

void loop() {
  
}
