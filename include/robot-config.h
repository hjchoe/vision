using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature Vision5__YELLOWCONE;
extern signature Vision5__PINKDICE;
extern signature Vision5__HIGHREDGOAL;
extern signature Vision5__HIGHBLUEGOAL;
extern signature Vision5__HIGHYELLOWGOAL;
extern signature Vision5__SIG_6;
extern signature Vision5__SIG_7;
extern vision Vision5;
extern controller Controller1;
extern motor rightMotor;
extern motor leftMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );