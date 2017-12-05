#pragma once;
#include "MyRobot.h"
#include "Arduino.h"
#include "RobotMap.h"
#include <Servo.h>
#include "Lift.h"
/**
 * These are the execution runtions
 */
//!!!

extern Servo liftMotor;
void Lift::init() {
//!!! call robotMap here
//!!!add potentiometer here
}
void Lift::liftUp() {
//!!! call robotMap here
  liftMotor.write(90+20);
}
void Lift::liftDown() {
//!!! call robotMap here
  liftMotor.write(90-20);
}

