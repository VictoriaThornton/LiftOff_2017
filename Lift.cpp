#include "Lift.h"
#include "Arduino.h"
//TODO- add potentiometer..

void Lift::init(){
    liftMotor.attach(9, 1000, 2000);
}

void Lift::liftUp(){
  liftMotor.write(90-30);  
}

void Lift::liftDown(){
  liftMotor.write(90+30);  
}

void Lift::stopLift(){
  liftMotor.write(90);  
}

//PRESET POSITIONS: 
void Lift::topPosition(){
  inputValue = analogRead(7);
  error = (int) (desiredAngleUp-inputValue);
  armValue = constrain(Kp*error,0,180);
  liftMotor.write(armValue);
}
void Lift::middlePosition(){
  inputValue = analogRead(7);
  error = (int) (desiredAngleMiddle-inputValue);
  armValue = constrain(Kp*error,0,180);
  liftMotor.write(armValue);
}
void Lift::bottomPosition(){
  inputValue = analogRead(7);
  error = (int) (desiredAngleDown-inputValue);
  armValue = constrain(Kp*error,0,180);
  liftMotor.write(armValue);
}
