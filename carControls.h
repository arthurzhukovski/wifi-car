#include "motorPins.h";
const int THROTTLE_STOP = 0;
const int THROTTLE_FORWARD = 1;
const int THROTTLE_BACKWARDS = 2;

const int TURN_CENTER = 3;
const int TURN_LEFT = 4;
const int TURN_RIGHT = 5;

struct motorsStruct motors = {{14, 12}, {15, 13}};

void initCarControls(){
  setupMotorPins(motors.steeringPins);
  setupMotorPins(motors.throttlePins);
}

void startSpinning(motorPinsStruct motorPins, bool spinInReverse){
  digitalWrite(motorPins.pos, spinInReverse ? LOW : HIGH);
  digitalWrite(motorPins.neg, spinInReverse ? HIGH : LOW);
}

void stopSpinning(motorPinsStruct motorPins){
  digitalWrite(motorPins.pos, LOW);
  digitalWrite(motorPins.neg, LOW);
}

void controls(int action){
  switch(action){
    case THROTTLE_STOP:
      Serial.println("THROTTLE_STOP");
      stopSpinning(motors.throttlePins);
    break;
    case THROTTLE_FORWARD:
      Serial.println("THROTTLE_FORWARD");
      startSpinning(motors.throttlePins, false);
    break;
    case THROTTLE_BACKWARDS:
      Serial.println("THROTTLE_BACKWARDS");
      startSpinning(motors.throttlePins, true);
    break;
    case TURN_CENTER:
        Serial.println("TURN_CENTER");
        stopSpinning(motors.steeringPins);
    break;
    case TURN_LEFT:
      Serial.println("TURN_LEFT");
      startSpinning(motors.steeringPins, true);
    break;
    case TURN_RIGHT:
      Serial.println("TURN_RIGHT");
      startSpinning(motors.steeringPins, false);
    break;
   }
}
