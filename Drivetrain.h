#pragma once;

#include <Servo.h>

class Drivetrain{
  public: 
    void init();
    void driveStraight(int speed);
    void turn(int turn);
    void driveWithJoystick(int leftMotorSpeed, int rightMotorSpeed);
    void stopDrive();
    void stopAtLine();

   private: 
    unsigned leftLineTrackerPin = 8, rightLineTrackerPin = 9;
    Servo leftDriveMotor, rightDriveMotor;
};
