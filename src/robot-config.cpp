#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RightMotorGroupMotorA = motor(PORT10, ratio18_1, true);
motor RightMotorGroupMotorB = motor(PORT16, ratio18_1, true);
motor_group RightMotorGroup = motor_group(RightMotorGroupMotorA, RightMotorGroupMotorB);
controller Controller1 = controller(primary);
motor ForkLiftMotorGroupMotorA = motor(PORT15, ratio36_1, false);
motor ForkLiftMotorGroupMotorB = motor(PORT6, ratio36_1, true);
motor_group ForkLiftMotorGroup = motor_group(ForkLiftMotorGroupMotorA, ForkLiftMotorGroupMotorB);
motor LeftMotorGroupMotorA = motor(PORT1, ratio18_1, false);
motor LeftMotorGroupMotorB = motor(PORT11, ratio18_1, false);
motor_group LeftMotorGroup = motor_group(LeftMotorGroupMotorA, LeftMotorGroupMotorB);
motor Flip = motor(PORT20, ratio36_1, false);
motor ForkLift2 = motor(PORT17, ratio36_1, true);

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