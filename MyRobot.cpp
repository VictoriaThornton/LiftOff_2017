#include "MyRobot.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

/**
   These are the execution runtions
*/
LiquidCrystal lcd(40, 41, 42, 43, 44, 45);

void MyRobot::initialize() {
  //initialize all objects here...
  //joystick.dfw = dfw;
  lift.init();
  intake.init();
  drivetrain.init();
  intake.stopIntake();

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
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
  lcd.print("AUTO RUNNING!");
  lcd.setCursor(0, 1);
  lcd.print(time);
  lcd.setCursor(0, 0);
  //note: add javadoc comments

  drivetrain.readGyroValues();

  lcd.print(drivetrain.getGyroValue());

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
  lcd.print("TELEOP RUNNING!");
  lcd.setCursor(0, 1);
  lcd.print(time);
  lcd.setCursor(0, 0);
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
  if (dfw->two()) { //MIDDLE POSITION
    lift.middlePosition();
  }
  if (dfw->three()) { //ACTUALLY DOWN
    lift.liftDown();
  }
  if (dfw->l1()) { //ACTUALLY IN
    intake.intakeIn();
  }
  
  if (dfw->r1()) { //ACTUALLY OUT
    intake.intakeOut();
  }

    if (dfw->l2()) { //ACTUALLY OUT
    intake.stopIntake();
  }

    if (dfw->r2()) { //ACTUALLY OUT
    intake.stopIntake();
  }
}
/**
   Called at the end of control to reset the objects for the next start
*/
void MyRobot::robotShutdown(void) {
  Serial.println("Here is where I shut down my robot code");

}
