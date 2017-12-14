/* This is the RBE 1001 Template as of
 *
 * 3/28/17
 *
 * This Template
 * is designed to run the autonomous and teleop sections of the final
 * competition. Write and test your autonomous and teleop code on your
 * own and place the code in auto.cpp or teleop.cpp respectively.
 * The functions will be called by the competition framework based on the
 * time and start button. DO NOT change this file, your code will be called
 * by the framework. The framework will pass your code a reference to the DFW
 * object as well as the amount of MS remaining.0112
 */
#include <DFW.h>
#include "MyRobot.h"
//#include <LiquidCrystal.h>

MyRobot myRobot;
DFW dfw(&myRobot); // Instantiates the DFW object and setting the debug pin. The debug pin will be set high if no communication is seen after 2 seconds

//LiquidCrystal lcd(40, 41, 42, 43, 44, 45);

void setup() {
  Serial.begin(9600); // Serial output begin. On  ly needed for debug
  dfw.begin(); // Serial1 output begin for DFW library. Buad and port #."Serial1 only"
  myRobot.initialize();  //attach ports
  myRobot.dfw=&dfw;

//  lcd.begin(16, 2);
//  lcd.clear();
//  lcd.setCursor(0, 0);
}
void loop() {
  dfw.run();
  
// lcd.print("                    ");
//   lcd.setCursor(0, 0);
//lcd.print(analogRead(9));
//  lcd.setCursor(0, 0);
//  Serial.println(analogRead(9));
//  Serial.println(analogRead(8));

  //Serial.println(analogRead(7)); //read potentiometer value...
 // Serial.println(analogRead(9),DEC);
  //make gyro 6? 
  //make line trackers 8&9? 
}
