#pragma once;

#include "DFWJoystick.h"
//#include "RobotMap.h"
#include "MyRobot.h"

#include "Drivetrain.h"
#include "Intake.h"
#include "Lift.h"
/* !!! competition states:
  enum CompetitionState {
  powerup, waitForAuto, Autonomous,waitForTeleop, Teleop
  };*/
//Drivetrain drivetrain;
//Intake intake;
//Lift lift;

extern Servo rightDriveMotor, leftDriveMotor;
extern DFW *dfw;

void tankDrive(){ 
  Serial.println("DRIVING");
  rightDriveMotor.write(180-dfw->joystickrv());
  leftDriveMotor.write(dfw->joysticklv());
}


void checkForUpdates() {
  if (dfw->getCompetitionState() != Teleop) {
//    tankDrive();

    if (dfw->one()) {
  Serial.println("ONE");
      //LIFT UP
//      lift.liftUp();
    }
    if (dfw->two()) {
      //LIFT DOWN
      Serial.println("TWO");
//      lift.liftDown();
    }
    if (dfw->three()) {
      //INTAKE IN
      Serial.println("THREE");
//      intake.intakeIn();
    }
    if (dfw->four()) {
      //INTAKE OUT
      Serial.println("FOUR");
//      intake.intakeOut();
    }
  }
}


