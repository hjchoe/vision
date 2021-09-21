#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision5__YELLOWCONE = signature (1, 1381, 2157, 1769, -4285, -3811, -4048, 2.5, 0);
signature Vision5__PINKDICE = signature (2, 5221, 7885, 6553, -1, 677, 338, 2.6, 0);
vision Vision5 = vision (PORT5, 50, Vision5__YELLOWCONE, Vision5__PINKDICE);
/*vex-vision-config:end*/
controller Controller1 = controller(primary);
motor rightMotor = motor(PORT11, ratio18_1, true);
motor leftMotor = motor(PORT14, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}