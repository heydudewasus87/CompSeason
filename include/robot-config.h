using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor_group RightMotorGroup;
extern controller Controller1;
extern motor_group ForkLiftMotorGroup;
extern motor_group LeftMotorGroup;
extern motor Flip;
extern motor ForkLift2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );