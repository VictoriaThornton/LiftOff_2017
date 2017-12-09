#pragma once;

#include <Servo.h>

class Drivetrain{
  public: 
    void init();
    void driveStraight(int speed);
    void turn(int turn);
    void driveWithJoystick(int leftMotorSpeed, int rightMotorSpeed);
    void stopDrive();

   private: 
    unsigned lightTrackerPin;
    Servo leftDriveMotor, rightDriveMotor;
};
