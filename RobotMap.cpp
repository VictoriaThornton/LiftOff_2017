#pragma once;
#include <Servo.h>

Servo rightDriveMotor, leftDriveMotor, liftMotor, rightIntakeMotor, leftIntakeMotor;

void init() {
  leftDriveMotor.attach(4, 1000, 2000);
  rightDriveMotor.attach(5, 1000, 2000);

  leftIntakeMotor.attach(6, 1000, 2000);
  rightIntakeMotor.attach(7, 1000, 2000);

  liftMotor.attach(8, 1000, 2000);

  //!!! add sensors (potentiometer, gyro, ultrasonic, light, encoders, etc.)

}
