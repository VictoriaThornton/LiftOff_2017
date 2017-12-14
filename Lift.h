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
    const double desiredAngleUp = 420, desiredAngleDown = 870, desiredAngleMiddle = 740; //in degrees
    const double Kp = 1, Ki = 0, Kd = 0;
    double armValue = 0, setpoint, outputValue; //inputValue, outputValue;
};
