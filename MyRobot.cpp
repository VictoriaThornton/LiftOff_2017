#pragma once;
#include "MyRobot.h"
#include "Arduino.h"
#include "DFWJoystick.h"
#include "RobotMap.h"
#include <Servo.h>
/**
   These are the execution runtions
*/
//!!!

#include "Drivetrain.h"
#include "Intake.h"
#include "Lift.h"
/* !!! competition states:
  enum CompetitionState {
  powerup, waitForAuto, Autonomous,waitForTeleop, Teleop
  };*/
Drivetrain drivetrain;
Intake intake;
Lift lift;


extern Servo rightDriveMotor, leftDriveMotor;

void MyRobot::init() {
  //!!! call robotMap here

}


/**
   Called when the start button is pressed and the robot control begins
*/
void MyRobot::robotStartup() {

}
/**
   Called by the controller between communication with the wireless controller
   during autonomous mode
   @param time the amount of time remaining
   @param dfw instance of the DFW controller
*/
void MyRobot::autonomous(long time) {
  Serial.print("\r\nAuto time remaining: ");
  Serial.print(time);
}
/**
   Called by the controller between communication with the wireless controller
   during teleop mode
   @param time the amount of time remaining
   @param dfw instance of the DFW controller
*/
void MyRobot::teleop(long time) {
  Serial.print("\r\nTeleop time remaining: ");
  Serial.print(time);
  Serial.print("\tright joystick: ");
  Serial.print(dfw->joystickrv());
  Serial.print("\tleft joystick: ");
  Serial.print(dfw->joysticklv());


  Serial.println("DRIVING");
  rightDriveMotor.write(180 - dfw->joystickrv());
  leftDriveMotor.write(dfw->joysticklv());

  if (dfw->one()) {
    Serial.println("ONE");
    //LIFT UP
    lift.liftUp();
  }
  if (dfw->two()) {
    //LIFT DOWN
    Serial.println("TWO");
    lift.liftDown();
  }
  if (dfw->three()) {
    //INTAKE IN
    Serial.println("THREE");
    intake.intakeIn();
  }
  if (dfw->four()) {
    //INTAKE OUT
    Serial.println("FOUR");
    intake.intakeOut();
  }



  //    checkForUpdates();
  //Run functions in the robot class

}
/**
   Called at the end of control to reset the o                                                             bjects for the next start
*/
void MyRobot::robotShutdown(void) {
  Serial.println("Here is where I shut down my robot code");

}
