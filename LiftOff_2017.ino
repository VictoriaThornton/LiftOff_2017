#include <DFW.h>
#include "MyRobot.h"

MyRobot myRobot;
DFW dfw(&myRobot); // Instantiates the DFW object and setting the debug pin. The debug pin will be set high if no communication is seen after 2 seconds

void setup() {
  Serial.begin(9600);
  dfw.begin(); 
  myRobot.initialize();  //attach ports
  myRobot.dfw=&dfw;
}
void loop() {
  dfw.run();
}
