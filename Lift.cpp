#include "Lift.h"
//TODO- add potentiometer..

void Lift::init(){
    liftMotor.attach(9, 1000, 2000);
}

void Lift::liftUp(){
  liftMotor.write(90+30);  
}

void Lift::liftDown(){
  liftMotor.write(90-30);  
}

void Lift::stopLift(){
  liftMotor.write(90);  
}
