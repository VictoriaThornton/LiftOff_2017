#ifndef _DFWJOYSTICK_h
#define _DFWJOYSTICK_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#pragma once;

#include <DFW.h>
#include "MyRobot.h"

class DFWJoystick{
    
  public: 
    DFW *dfw;

    void checkForUpdates();
    void tankDrive();  
};
//extern DFWJoystick DFWJoystick;

#endif
