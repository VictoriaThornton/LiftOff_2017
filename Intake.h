#pragma once

#include "Servo.h"

class Intake {
  public:
    void init();
    void intakeOut();
    void intakeIn();
    void stopIntake();

  private:
    Servo leftIntakeMotor, rightIntakeMotor;
};
