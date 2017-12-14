#include "Lift.h"
#include "Arduino.h"
//TODO- add potentiometer..

void Lift::init(){
    liftMotor.attach(11, 1000, 2000);
}

void Lift::liftUp(){
  liftMotor.write(90-40);  
  Serial.println("Lifting UP");
}

void Lift::liftDown(){
  liftMotor.write(90+40);  
}

void Lift::stopLift(){
  liftMotor.write(90);  
}

//PRESET POSITIONS: 
void Lift::topPosition(){
  int inputValue = analogRead(7); 
  int error = (int) (desiredAngleUp-inputValue);
  armValue = constrain(Kp*error,0,180);
  liftMotor.write(armValue);
}
void Lift::middlePosition(){
   int inputValue = analogRead(7); 
  int error = (int) (desiredAngleMiddle-inputValue);
  armValue = constrain(Kp*error,0,180);
  liftMotor.write(armValue);
}
void Lift::bottomPosition(){
 int  inputValue = analogRead(7); 
  int error = (int) (desiredAngleDown-inputValue);
  armValue = constrain(Kp*error,0,180);
  liftMotor.write(armValue);
}
