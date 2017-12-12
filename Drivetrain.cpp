#include "Arduino.h"
#include "Drivetrain.h"



//TODO-add encoders? gyro? line tracker
void Drivetrain::init() {
  leftDriveMotor.attach(4, 1000, 2000);
  rightDriveMotor.attach(5, 1000, 2000);
  pinMode(leftLineTrackerPin, INPUT);
  pinMode(rightLineTrackerPin, INPUT);
  resetGyro();
}

void Drivetrain::driveWithJoystick(int leftMotorSpeed, int rightMotorSpeed) {
  leftDriveMotor.write(leftMotorSpeed);
  rightDriveMotor.write(rightMotorSpeed);
}

void Drivetrain::turn(int turn) {
  leftDriveMotor.write(90 - turn);
  rightDriveMotor.write(90 - turn);
}
void Drivetrain::driveStraight(int speed) {
  leftDriveMotor.write(90 + speed);
  rightDriveMotor.write(90 - speed);
}

void Drivetrain::stopDrive() {
  leftDriveMotor.write(90);
  rightDriveMotor.write(90);
}

void Drivetrain::resetGyro() {
  for (int i = 0; i < 500; i++) {
    gyroZeroVoltage += analogRead(gyroPin);
    delay(5);
  }
  gyroZeroVoltage /= 500;
}
void Drivetrain::readGyroValues() {
      //This line converts the 0-1023 signal to 0-5V and finds the voltage offset from sitting still
     float gyroRate = ((analogRead(gyroPin)- gyroZeroVoltage) * gyroVoltage) / 1023;
  
      //This line divides the voltage we found by the gyro's sensitivity
    gyroRate /= gyroSensitivity;
  
      //Ignore the gyro if our angular velocity does not meet our threshold
    if (gyroRate >= rotationThreshold || gyroRate <= -rotationThreshold) {
      //This line divides the value by 100 since we are running in a 10ms loop (1000ms/10ms)
      gyroRate /= 100;
      currentAngle += gyroRate;
    }
  
      //Keep our angle between 0-359 degrees
    if (currentAngle < 0)
      currentAngle += 360;
    else if (currentAngle > 359)
      currentAngle -= 360;
  
    //DEBUG
    Serial.println(currentAngle);
  
    delay(10);
}

//working...
float Drivetrain::getGyroValue() {
  return currentAngle;
}

void Drivetrain::stopAtLine(){
  if(analogRead(leftLineTrackerPin) < 950 || analogRead(rightLineTrackerPin) < 950){
    stopDrive();
    delay(10);
  }
  if (analogRead(leftLineTrackerPin) > 1000 || analogRead(rightLineTrackerPin) > 1000){
    driveStraight(30);  
  } 
}
