#pragma once;

#include "DFWJoystick.h"
//#include "RobotMap.h"
#include "MyRobot.h"
/* !!! competition states:
  enum CompetitionState {
  powerup, waitForAuto, Autonomous,waitForTeleop, Teleop
  };*/
extern Servo rightDriveMotor, leftDriveMotor;
extern DFW *dfw;

void tankDrive(){ 
  rightDriveMotor.write(180-dfw->joystickrv());
  leftDriveMotor.write(dfw->joysticklv());
}


void checkForUpdates() {
  if (dfw->getCompetitionState() != Teleop) {
    tankDrive();

    if (dfw->one()) {
      //LIFT UP

    }
    if (dfw->two()) {
      //LIFT DOWN

    }
    if (dfw->three()) {
      //INTAKE IN

    }
    if (dfw->four()) {
      //INTAKE OUT
    }
  }
}


