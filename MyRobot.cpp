#include "MyRobot.h"
#include "Arduino.h"

/**
   These are the execution runtions
*/
void MyRobot::initialize() {
  //initialize all objects here...
  //joystick.dfw = dfw;
  lift.init();
  intake.init();
  drivetrain.init();
  intake.stopIntake();
}

void MyRobot::moveTo(unsigned position) {
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
void MyRobot::autonomous( long time) {
  Serial.print("\r\nAuto time remaining: ");
  Serial.print(time);
}
/**
   Called by the controller between communication with the wireless controller
   during teleop mode
   @param time the amount of time remaining
   @param dfw instance of the DFW controller
*/
void MyRobot::teleop( long time) {
  Serial.print("\r\nTeleop time remaining: ");
  Serial.print(time);
  Serial.print("\tright joystick: ");
  Serial.print(dfw->joystickrv());
  Serial.print("\tleft joystick: ");
  Serial.print(dfw->joysticklv());
  //Run functions in the robot class
  //moveTo(35);

  //  joystick.checkForInput();

  if (dfw->getCompetitionState() != powerup) {
    //DFW.joystick will return 0-180 as an int into rightmotor.write
    drivetrain.driveWithJoystick(dfw->joysticklv(), 180 - dfw->joystickrv());
  }
  if (dfw->one()) {//ACTUALLY UP
    lift.liftUp();
  } else {
    lift.stopLift();
  }
  if (dfw->two()) { //ACTUALLY DOWN
    lift.liftDown();
  }
  if (dfw->three()) { //ACTUALLY IN
    intake.intakeOut();
  }else{
    intake.stopIntake();
    }
  if (dfw->four()) { //ACTUALLY OUT
    intake.intakeIn();
  }

}
/**
   Called at the end of control to reset the objects for the next start
*/
void MyRobot::robotShutdown(void) {
  Serial.println("Here is where I shut down my robot code");

}
