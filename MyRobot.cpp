#include "MyRobot.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(40, 41, 42, 43, 44, 45);

/**
   Initialize the robot
*/
void MyRobot::initialize() {
  //initialize all subsystems
  lift.init();
  intake.init();
  drivetrain.init();

  //setup lcd screen
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
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
  //show the time left in auto on the lcd screen
  lcd.print("AUTO RUNNING!");
  lcd.setCursor(0, 1);

  autonomousScoreHighOrbit();
}

void MyRobot::autonomousScoreHighOrbit() {
  //move the lift to the correct height
  lift.topPosition();

  //stop at the white line
  drivetrain.stopAtLine();

  //if the line sensor sees the white line, run the intake in reverse and stop driving
  if (analogRead(9) < 800) {
    intake.intakeOut();
    drivetrain.stopDrive();
  }
}

/**
   Called by the controller between communication with the wireless controller
   during teleop mode
   @param time the amount of time remaining
   @param dfw instance of the DFW controller
*/
void MyRobot::teleop( long time) {

  //print the time left in teleop
  lcd.print("TELEOP RUNNING!");
  lcd.setCursor(0, 1);
  lcd.print(time);
  lcd.setCursor(0, 0);

  if (dfw->getCompetitionState() != powerup) {
    drivetrain.driveWithJoystick(dfw->joysticklv(), 180 - dfw->joystickrv());
  }
  if (dfw->one()) {
    lift.liftUp();
  }
  else {
    lift.stopLift();
  }
  if (dfw->two()) {
    lift.stopLift();
  }
  if (dfw->three()) {
    lift.liftDown();
  }

  if (dfw->l1()) {
    intake.intakeIn();
  }

  if (dfw->r1()) {
    intake.intakeOut();
  }

  if (dfw->l2()) {
    intake.stopIntake();
  }

  if (dfw->r2()) {
    intake.stopIntake();
  }
}
/**
   Called at the end of control to reset the objects for the next start
*/
void MyRobot::robotShutdown(void) {
  Serial.println("Here is where I shut down my robot code");
}
