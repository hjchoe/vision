/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jameschoe                                                 */
/*    Created:      Fri Sep 17 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision5              vision        5               
// Controller1          controller                    
// rightMotor           motor         11              
// leftMotor            motor         14              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int32_t ObjectCount = 0;
int CenterField = 158; // this is half the number of pixels of the vision sensor
bool LinedUp = false;
double autonomousSpeed = 50;

int main()
{
  vexcodeInit();

  rightMotor.setVelocity(autonomousSpeed, percent);
  leftMotor.setVelocity(autonomousSpeed, percent);

  Controller1.Screen.clearLine();

  if (Vision5.installed() == true)
  {
    Controller1.Screen.clearLine();
    Controller1.Screen.print("vrai");
  }
  else
  {
    Controller1.Screen.clearLine();
    Controller1.Screen.print("faux");
  }

  while (true)
  {
    while (!LinedUp) {
      Vision5.takeSnapshot(Vision5__YELLOWCONE);

      Controller1.Screen.clearLine();
      Controller1.Screen.print(Vision5.largestObject.centerX);

      if (Vision5.largestObject.centerX > CenterField) {
        // turn right
        rightMotor.spin(forward);
      } else if (Vision5.largestObject.centerX < CenterField) {
        // turn left
        leftMotor.spin(forward);
      } else {
        LinedUp = true;
      }
      // we're on target.  Stop the motors
      leftMotor.stop();
      rightMotor.stop();

      // brief delay to keep the loop from looping too fast
      wait(50, msec);
    }

    // we should be pointing at the object now.  Reset the variables

    LinedUp = false;
    ObjectCount = 0;
  }
}