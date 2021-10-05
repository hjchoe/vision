#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision5__YELLOWCONE = signature (1, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision5__PINKDICE = signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision5__HIGHREDGOAL = signature (3, 6729, 9593, 8161, -1795, -885, -1340, 4.4, 0);
signature Vision5__HIGHBLUEGOAL = signature (4, -3145, -1333, -2239, 5461, 11189, 8325, 2.2, 0);
signature Vision5__HIGHYELLOWGOAL = signature (5, 149, 2571, 1360, -4359, -3459, -3909, 2.4, 0);
vision Vision5 = vision (PORT5, 50, Vision5__YELLOWCONE, Vision5__PINKDICE, Vision5__HIGHREDGOAL, Vision5__HIGHBLUEGOAL, Vision5__HIGHYELLOWGOAL);
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