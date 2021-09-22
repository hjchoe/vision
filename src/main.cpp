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
double autonomousSpeed = 0.25;

int main()
{
  vexcodeInit();

  rightMotor.setVelocity(autonomousSpeed, velocityUnits::pct);
  leftMotor.setVelocity(autonomousSpeed, velocityUnits::pct);

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
    while (!LinedUp)
    {
      int objects = Vision5.takeSnapshot(Vision5__PINKDICE);

      /*Controller1.Screen.clearLine();
      Controller1.Screen.print(Vision5.largestObject.centerX);*/

      if (objects != 0)
      {
        if (Vision5.largestObject.centerX > CenterField+10)
        {
          // turn right
          Controller1.Screen.clearLine();
          Controller1.Screen.print("right");
          leftMotor.setVelocity(autonomousSpeed*(Vision5.largestObject.centerX-CenterField), velocityUnits::pct);
          rightMotor.setVelocity(0, velocityUnits::pct);
        }
        else if (Vision5.largestObject.centerX < CenterField-10)
        {
          // turn left
          Controller1.Screen.clearLine();
          Controller1.Screen.print("left");
          leftMotor.setVelocity(0, velocityUnits::pct);
          rightMotor.setVelocity(autonomousSpeed*(CenterField-Vision5.largestObject.centerX), velocityUnits::pct);
        }
        else
        {
          leftMotor.setVelocity(0, velocityUnits::pct);
          rightMotor.setVelocity(0, velocityUnits::pct);
          LinedUp = true;
        }
        // brief delay to keep the loop from looping too fast
        rightMotor.spin(forward);
        leftMotor.spin(forward);
      }
      else
      {
        Controller1.Screen.clearLine();
        Controller1.Screen.print("no object");
        rightMotor.setVelocity(0, velocityUnits::pct);
        leftMotor.setVelocity(0, velocityUnits::pct);
      }
      wait(50, msec);
    }
    // we're on target.  Stop the motors
    leftMotor.stop();
    rightMotor.stop();

    // we should be pointing at the object now.  Reset the variables

    LinedUp = false;
    ObjectCount = 0;
    wait(500, msec);
  }
}