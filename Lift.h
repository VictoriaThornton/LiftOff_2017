#pragma once

#include "Servo.h"

class Lift {
  public:
    void init();
    void liftUp();
    void liftDown();
    void stopLift();
    void topPosition();
    void middlePosition();
    void bottomPosition();

  private:
    unsigned potPin;
    Servo liftMotor;
};
