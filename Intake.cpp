#pragma once;
#include "MyRobot.h"
#include "Arduino.h"
#include "RobotMap.h"
#include <Servo.h>
#include "Intake.h"
/**
 * These are the execution runtions
 */
//!!!

extern Servo rightIntakeMotor, leftIntakeMotor;
void Intake::init() {
//!!! call robotMap here
}
void Intake::intakeIn() {
//!!! call robotMap here
  leftIntakeMotor.write(90+20);
  rightIntakeMotor.write(90-20);
}
void Intake::intakeOut() {
//!!! call robotMap here
  leftIntakeMotor.write(90-20);
  rightIntakeMotor.write(90+20);
}

