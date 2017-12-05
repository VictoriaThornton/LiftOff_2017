#ifndef _LIFT_h
#define _LIFT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#pragma once

#include "Servo.h"
#include "RobotMap.h"

class Lift{
  
  public: 
   void init();
   void liftUp();
   void liftDown();
  private: 
   
  
};

//extern MyRobot MyRobot;
#endif
