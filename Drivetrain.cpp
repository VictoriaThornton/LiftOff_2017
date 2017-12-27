#include "Arduino.h"
#include "Drivetrain.h"

/**
   Initialize the drivetrain by attaching the drive motors,
   setting the setting the line trackers as inputs, and resetting the gyro
*/
void Drivetrain::init() {
  leftDriveMotor.attach(4, 1000, 2000);
  rightDriveMotor.attach(5, 1000, 2000);
  pinMode(leftLineTrackerPin, INPUT);
  pinMode(rightLineTrackerPin, INPUT);
  resetGyro();
}

/**
   Drive the robot using speed from the joysticks
   @param left joystick speed
   @param right joystick speed
*/
void Drivetrain::driveWithJoystick(int leftMotorSpeed, int rightMotorSpeed) {
  leftDriveMotor.write(leftMotorSpeed);
  rightDriveMotor.write(rightMotorSpeed);
}

/**
   Use proportional control with the gyro as an input and the drive motors as an output to turn to a specific angle
   @param angle to turn
*/
void Drivetrain::turn(int turn) {
  int Kp = 2;
  int inputValue = getGyroValue();
  int error = (int)(turn - inputValue);
  error = (int) (turn - inputValue);
  int turnValue = constrain(Kp * error, 0, 180);

  leftDriveMotor.write(turnValue);
  rightDriveMotor.write(turnValue);
}

/**
   Have the robot drive at a set speed
   @param the power to write to the motors
*/
void Drivetrain::drive(int speed) {
  leftDriveMotor.write(90 + speed);
  rightDriveMotor.write(90 - speed);
}

/**
   Make the robot stop driving
*/
void Drivetrain::stopDrive() {
  leftDriveMotor.write(90);
  rightDriveMotor.write(90);
}

/**
   Zero the gyro
*/
void Drivetrain::resetGyro() {
  for (int i = 0; i < 500; i++) {
    gyroZeroVoltage += analogRead(gyroPin);
    delay(5);
  }
  gyroZeroVoltage /= 500;
}

/**
   Begin reading the gyro values
*/
void Drivetrain::readGyroValues() {
  //This line converts the 0-1023 signal to 0-5V and finds the voltage offset from sitting still
  float gyroRate = ((analogRead(gyroPin) - gyroZeroVoltage) * gyroVoltage) / 1023;

  //This line divides the voltage we found by the gyro's sensitivity
  gyroRate /= gyroSensitivity;

  //Ignore the gyro if the angular velocity does not meet the threshold
  if (gyroRate >= rotationThreshold || gyroRate <= -rotationThreshold) {
    //This line divides the value by 100 since we are running in a 10ms loop (1000ms/10ms)
    gyroRate /= 100;
    currentAngle += gyroRate;
  }

  //Keep the angle between 0-359 degrees
  if (currentAngle < 0)
    currentAngle += 360;
  else if (currentAngle > 359)
    currentAngle -= 360;

  delay(10);
}

/**
   Get the current gyro angle
   @return the current gyro angle in degrees
*/
float Drivetrain::getGyroValue() {
  return currentAngle;
}

/**
   Use the value of the line trackers to stop at the white line in front of the orbit
*/
void Drivetrain::stopAtLine() {
  int value = analogRead(rightLineTrackerPin);
  if (value < 800) {
    value = 200;
    stopDrive();
    delay(100);
  }
  else {
    drive(30);
  }
}
