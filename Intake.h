#ifndef _INTAKE_h
#define _INTAKE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#pragma once

#include "Servo.h"
#include "RobotMap.h"

class Intake{
  
  public: 
   void init();
   void intakeIn();
   void intakeOut();
  private: 
   
  
};

//extern MyRobot MyRobot;
#endif
