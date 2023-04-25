#include "carControls.h";

void setup() {
  Serial.begin(115200);
  initCarControls();
  delay(500);
  Serial.println("Board set up.");
}

void loop() {
  performTestSpins();
}

void performTestSpins(){
  controls(TURN_LEFT);
  delay(1000);
  
  controls(TURN_RIGHT);
  delay(1000);
  
  controls(TURN_CENTER);
  delay(1000);

  controls(THROTTLE_FORWARD);
  delay(1000);
  
  controls(THROTTLE_BACKWARDS);
  delay(1000);
  
  controls(THROTTLE_STOP);
  delay(1000);
}
