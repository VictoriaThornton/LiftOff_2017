#pragma once;

#include <Servo.h>

class Drivetrain {
  public:
    void init();
    void drive(int speed);
    void turn(int turn);
    void driveWithJoystick(int leftMotorSpeed, int rightMotorSpeed);
    void stopDrive();

    void stopAtLine();
    void readGyroValues();
    float getGyroValue();
    void resetGyro();

  private:
    int gyroPin = 11;
    float gyroVoltage = 5, gyroSensitivity = .0125, rotationThreshold = 2, currentAngle;
    long gyroZeroVoltage;

    unsigned leftLineTrackerPin = 8, rightLineTrackerPin = 9;
    Servo leftDriveMotor, rightDriveMotor;
};
