#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RightMotorGroupMotorA = motor(PORT4, ratio18_1, true);
motor RightMotorGroupMotorB = motor(PORT2, ratio18_1, true);
motor_group RightMotorGroup = motor_group(RightMotorGroupMotorA, RightMotorGroupMotorB);
controller Controller1 = controller(primary);
motor LeftMotorGroupMotorA = motor(PORT3, ratio18_1, false);
motor LeftMotorGroupMotorB = motor(PORT1, ratio18_1, false);
motor_group LeftMotorGroup = motor_group(LeftMotorGroupMotorA, LeftMotorGroupMotorB);
inertial Inertial1 = inertial(PORT20);
motor ringLoader = motor(PORT7, ratio36_1, false);
motor hook = motor(PORT6, ratio36_1, false);
motor ForkLiftMotorGroup = motor(PORT5, ratio36_1, false);
/*vex-vision-config:begin*/
signature VisionSensor__SIG_BLUE = signature (1, -3693, -2791, -3242, 9633, 12887, 11260, 3, 0);
signature VisionSensor__SIG_RED = signature (2, 6953, 9657, 8305, -1221, 1, -610, 2.5, 0);
signature VisionSensor__SIG_YELLOW = signature (3, -45, 955, 455, -3181, -883, -2032, 1.2, 0);
signature VisionSensor__SIG_YELLOW2 = signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
signature VisionSensor__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.1, 0);
vision VisionSensor = vision (PORT8, 50, VisionSensor__SIG_BLUE, VisionSensor__SIG_RED, VisionSensor__SIG_YELLOW, VisionSensor__SIG_YELLOW2, VisionSensor__SIG_5);
/*vex-vision-config:end*/
bumper BumperA = bumper(Brain.ThreeWirePort.A);
bumper BumperH = bumper(Brain.ThreeWirePort.H);

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