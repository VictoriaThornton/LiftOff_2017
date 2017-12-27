#include "Intake.h"

/**
 * Initialize the intake by attaching the motors
 */
void Intake::init() {
  leftIntakeMotor.attach(6, 1000, 2000);
  rightIntakeMotor.attach(7, 1000, 2000);

  rightIntakeMotor.write(90);
  leftIntakeMotor.write(90);
} 

/**
 * Make the intake run in reverse
 */
void Intake::intakeOut() {
  leftIntakeMotor.write(90 + 40);
  rightIntakeMotor.write(90 - 40);
}

/**
 * Make the intake run forwards
 */
void Intake::intakeIn() {
  leftIntakeMotor.write(90 - 40);
  rightIntakeMotor.write(90 + 40);
}

/**
 * Make the intake stop running
 */
void Intake::stopIntake() {
  leftIntakeMotor.write(90);
  rightIntakeMotor.write(90);
}
