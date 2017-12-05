#ifndef _DRIVETRAIN_h
#define _DRIVETRAIN_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#pragma once

#include "Servo.h"
#include "RobotMap.h"

class Drivetrain{
  
  public: 
   void init();
   void driveStraight(int speed);
   void turn(int turn);
  private: 
   
  
};

//extern MyRobot MyRobot;
#endif
