#include "DFWJoystick.h"
#include "Arduino.h"
  Lift lift;
  Drivetrain drivetrain;
  Intake intake;
void DFWJoystick::init() {
  Serial.begin(9600);
  lift.init();
  drivetrain.init();
  intake.init();
}

void DFWJoystick::checkForInput() {
  if (dfwPointer->getCompetitionState() != powerup) {
    //DFW.joystick will return 0-180 as an int into rightmotor.write
    drivetrain.driveWithJoystick(dfwPointer->joysticklv(), 180 - dfwPointer->joystickrv());
  }
  if (dfwPointer->one()) {
    Serial.println("LIFTINGUP!!!!!!!!!!!!!!!!!!!!!");
    lift.liftUp();
  } else {
    lift.stopLift();
  }
  if (dfwPointer->two()) {
    lift.liftDown();
  }
  if (dfwPointer->three()) { //out
    intake.intakeOut();
  }
  if (dfwPointer->four()) { //in
    intake.intakeIn();
  }
}
