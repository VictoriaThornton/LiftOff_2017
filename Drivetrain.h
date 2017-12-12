#pragma once;

#include <Servo.h>

class Drivetrain {
  public:
    void init();
    void driveStraight(int speed);
    void turn(int turn);
    void driveWithJoystick(int leftMotorSpeed, int rightMotorSpeed);
    void stopDrive();

    void stopAtLine();
    void readGyroValues();
    float getGyroValue();
    void resetGyro();

  private:
    //gyro stuff:
    int gyroPin = 11;
    float gyroVoltage = 5, gyroSensitivity = .0125, rotationThreshold = 2, currentAngle;
    long gyroZeroVoltage;

    unsigned lineTrackerPin;
    Servo leftDriveMotor, rightDriveMotor;
};
