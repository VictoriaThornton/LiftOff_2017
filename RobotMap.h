#ifndef _ROBOTMAP_h
#define _ROBOTMAP_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#pragma once;
#include <Servo.h>

class RobotMap{
  
  public: 
    void init(); 
    Servo rightDriveMotor, leftDriveMotor, liftMotor, rightIntakeMotor, leftIntakeMotor;

  private: 
  
};

extern RobotMap RobotMap;
#endif
