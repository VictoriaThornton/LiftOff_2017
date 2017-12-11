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
    unsigned potPin = 7;
    Servo liftMotor;
    const double desiredAngleUp = 328 + 120, desiredAngleDown = 240+100,desiredAngleMiddle = ((240 + 100)-(328+120)); //in degrees
    const double Kp = 1, Ki = 0, Kd = 0;
    int error;
    double armValue = 0, setpoint, inputValue, outputValue;
};
