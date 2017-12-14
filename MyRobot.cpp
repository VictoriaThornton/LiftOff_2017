#include "MyRobot.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

/**
   These are the execution runtions
*/
LiquidCrystal lcd(40, 41, 42, 43, 44, 45);

void MyRobot::initialize() {
  //initialize all objects here...
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
//50 degrees corresponds to about 90 degrees?

/**
   Called by the controller between communication with the wireless controller
   during autonomous mode
   @param time the amount of time remaining
   @param dfw instance of the DFW controller
*/
void MyRobot::autonomous( long time) {
  //    Serial.print("\r\nAuto time remaining: ");
  //    Serial.print(time);
  lcd.print("AUTO RUNNING!");
  lcd.setCursor(0, 1);
  lcd.print(time);
  lcd.setCursor(0, 0);
  //note: add javadoc comments

  lcd.print(analogRead(9));

  lift.topPosition();
  drivetrain.stopAtLine();

  if (analogRead(9) < 850) {
    Serial.println("Intake out");
    intake.intakeOut();
    drivetrain.stopDrive();
  }
}

void MyRobot::autonomousScoreHighOrbit() {
  lift.topPosition();

  lcd.print(analogRead(8));
  Serial.println(analogRead(7));
  if (analogRead(7) > 450) {
    Serial.println("About 420");
    drivetrain.stopAtLine();
  }

  if (analogRead(8) > 830 || analogRead(8) < 850  && analogRead(9) > 830 || analogRead(9) < 850) {
    //intake.intakeOut();
  }
}

//void autonomousOneOrbit() {
//  drivetrain.stopAtLine();
//
//  if (analogRead(8) < 600 || analogRead(9) < 600) {
//    intake.intakeOut();
//  }
//}

//void autonomousTwoOrbits() {
//  lift.topPosition();
//
//  drivetrain.readGyroValues();
//
//  lcd.print(drivetrain.getGyroValue());
//
//  drivetrain.stopAtLine();
//
//  drivetrain.turn(90);
//  while (millis() < currentTime + millis()) {
//    drivetrain.driveStraight(60);
//  }
//
//  drivetrain.turn(90);
//
//  drivetrain.stopAtLine();
//
//  autonomousOneOrbit();
//}

/**
   Called by the controller between communication with the wireless controller
   during teleop mode
   @param time the amount of time remaining
   @param dfw instance of the DFW controller
*/
void MyRobot::teleop( long time) {
  //  Serial.print("\r\nTeleop time remaining: ");
  //  Serial.print(time);

  //Run functions in the robot class
  //  lcd.print("TELEOP RUNNING!");
  //  lcd.setCursor(0, 1);
  //  lcd.print(time);
  //  lcd.setCursor(0, 0);

  if (dfw->getCompetitionState() != powerup) {
    //DFW.joystick will return 0-180 as an int into rightmotor.write
    drivetrain.driveWithJoystick(dfw->joysticklv(), 180 - dfw->joystickrv());
  }
  if (dfw->one()) {
    lift.liftUp();
  } else {
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
  //  intake.stopIntake();
  //    lift.stopLift();
  //lift.bottomPosition();
}
