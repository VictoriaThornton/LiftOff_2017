#pragma once;
#include "MyRobot.h"
#include "Arduino.h"
#include "RobotMap.h"
#include <Servo.h>
#include "Drivetrain.h"
/**
 * These are the execution runtions
 */
//!!!

extern Servo rightDriveMotor, leftDriveMotor;
void Drivetrain::init() {
//!!! call robotMap here
}
void Drivetrain::turn(int turn) {
//!!! call robotMap here
  leftDriveMotor.write(90-turn);
  rightDriveMotor.write(90-turn);
}
void Drivetrain::driveStraight(int speed) {
//!!! call robotMap here
  leftDriveMotor.write(90-speed);
  rightDriveMotor.write(90+speed);
}

