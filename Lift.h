#pragma once

#include "Servo.h"

class Lift {
  public:
    void init();
    void liftUp();
    void liftDown();
    void stopLift();

  private:
    unsigned potPin;
    Servo liftMotor;
};
