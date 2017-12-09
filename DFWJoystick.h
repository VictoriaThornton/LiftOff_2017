#pragma once

#include <DFW.h>
#include "Lift.h"
#include "Drivetrain.h"
#include "Intake.h"

class DFWJoystick {
  public:
    DFW *dfwPointer;

    void init();
    void checkForInput(); //checks for joystick input and reacts accordingly

  private:
};
