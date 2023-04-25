struct motorPinsStruct{
  int pos;
  int neg;
};

struct motorsStruct{
  struct motorPinsStruct steeringPins;
  struct motorPinsStruct throttlePins;
};

void setupMotorPins(motorPinsStruct motorPins){
  pinMode(motorPins.pos, OUTPUT);
  pinMode(motorPins.neg, OUTPUT);
}
