#include "Intake.h"

void Intake::init() {
  leftIntakeMotor.attach(10, 1000, 2000);
  rightIntakeMotor.attach(7, 1000, 2000);

  rightIntakeMotor.write(90);
  leftIntakeMotor.write(90);
}

//check directions....
void Intake::intakeOut() {
  leftIntakeMotor.write(90 + 20);
  rightIntakeMotor.write(90 - 20);
}

void Intake::intakeIn() {
  leftIntakeMotor.write(90 - 20);
  rightIntakeMotor.write(90 + 20);
}

void Intake::stopIntake() {
  leftIntakeMotor.write(90);
  rightIntakeMotor.write(90);
}
