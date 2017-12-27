#include "Lift.h"
#include "Arduino.h"

/**
   Initialize the Lift by attaching the lift motor and setting the potentiometer pin as an input
*/
void Lift::init() {
  liftMotor.attach(11, 1000, 2000);
  pinMode(potPin,INPUT); 
}

/**
   Make the lift go up
*/
void Lift::liftUp() {
  liftMotor.write(90 - 40);
  Serial.println("Lifting UP");
}

/**
   Make the lift go down
*/
void Lift::liftDown() {
  liftMotor.write(90 + 40);
}

/**
   Stop the lift from running
*/
void Lift::stopLift() {
  liftMotor.write(90);
}

//PRESET POSITIONS:
/**
    Move the lift to the top position: preset to score in the highest orbit
*/
void Lift::topPosition() {
  int inputValue = analogRead(potPin);
  int error = (int) (desiredAngleUp - inputValue);
  armValue = constrain(Kp * error, 0, 180);
  liftMotor.write(armValue);
}

/**
    Move the lift to the middle position: preset to score in the middle orbit
*/
void Lift::middlePosition() {
  int inputValue = analogRead(potPin);
  int error = (int) (desiredAngleMiddle - inputValue);
  armValue = constrain(Kp * error, 0, 180);
  liftMotor.write(armValue);
}

/**
    Move the lift to the bottom position: preset to score in the lowest orbit
*/
void Lift::bottomPosition() {
  int  inputValue = analogRead(potPin);
  int error = (int) (desiredAngleDown - inputValue);
  armValue = constrain(Kp * error, 0, 180);
  liftMotor.write(armValue);
}
