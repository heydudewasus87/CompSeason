using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor_group RightMotorGroup;
extern controller Controller1;
extern motor_group LeftMotorGroup;
extern inertial Inertial1;
extern motor ringLoader;
extern motor hook;
extern motor ForkLiftMotorGroup;
extern signature VisionSensor__SIG_BLUE;
extern signature VisionSensor__SIG_RED;
extern signature VisionSensor__SIG_YELLOW;
extern signature VisionSensor__SIG_YELLOW2;
extern signature VisionSensor__SIG_5;
extern signature VisionSensor__SIG_6;
extern signature VisionSensor__SIG_7;
extern vision VisionSensor;
extern bumper BumperA;
extern bumper BumperH;
extern motor Motor9;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );