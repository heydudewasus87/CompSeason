// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RightMotorGroup      motor_group   12, 14          
// LeftMotorGroup       motor_group   11, 13          
// Controller1          controller                    
// ForkLiftMotorGroup   motor_group   9, 10           
// Inertial1            inertial      1               
// LimitSwitchA         limit         A               
// HookMotor            motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RightMotorGroup      motor_group   12, 14          
// LeftMotorGroup       motor_group   11, 13          
// Controller1          controller                    
// ForkLiftMotorGroup   motor_group   9, 10           
// Inertial1            inertial      1               
// LimitSwitchA         limit         A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drive.h"
#include "forklift.h"
#include "forklift2.h"
#include "flippy.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  initForklift();
  initForklift2();
  initFlippy();
  initDrive();

  // // While going forward, put the forklift down
  // forkliftDown(false);
  // vex::task::sleep(400);
  // autoStraightDrive(45, true, 100);
  // autoStraightDrive(11,false,50);
  
  // // Lift up the goal and come back, put the forklift in middle, forkLift2 up
  // forkliftUp(true);
  // vex::task::sleep(300);
  // autoStraightDrive(-32.5,true,100);
  // vex::task::sleep(100);

  // // Turn sideways, go forward and drop the first goal
  // turnToAngle(-101);
  // // vex::task::sleep(100);
  // forkliftDown(false);
  // autoStraightDrive(20, true, 100);
  // vex::task::sleep(200);
  // flipSupport(false);

  // // Come back and aim for center goal
  // autoStraightDrive(-16,true,100);
  // vex::task::sleep(200);
  // turnToAngle(45);

  // // Go pick center goal and come back
  // autoStraightDrive(32,true,75);
  // forkliftBoost(false);
  // autoStraightDrive(13.75,true,50);
  // vex::task::sleep(400);
  // autoStraightDrive(-63,true,100);
  // forkliftDown(false);
  // turnToAngle(-60);
  // autoStraightDrive(-15,true,75);
  // forkliftDown(true);
  // flipDown(true);

  //left
  autoStraightDrive(-4,true,75);
  autoStraightDrive(-12,false,25);
  flipDown(true);
  vex::task::sleep(400);
  autoStraightDrive(10,true,75);
  forkliftDown(false);
  turnToAngle(155);
  flipSupport(false);

  // Go pick center goal and come back
  autoStraightDrive(60,true,100);
  forkliftBoost(false);
  autoStraightDrive(13.75,true,50);
  vex::task::sleep(400);
  autoStraightDrive(-50,true,100);
  turnToAngle(-65);
  autoStraightDrive(15,true,100);
  forkliftDown(true);
  
  // forkliftDown(false);
  // turnToAngle(-60);
  // autoStraightDrive(-15,true,75);
  // forkliftDown(true);
  // flipDown(true);



  // forkliftMiddle(false);
  // vex::task::sleep(100);
  // flipDown(true);
  // vex::task::sleep(200);
  // autoStraightDrive(5,true,50);
  // flipSupport(false);
  // turnToAngle(150);
  // autoStraightDrive(24,true,75);
  // forkliftDown(false);
  // autoStraightDrive(41,true,75);
  // forkliftBoost(false);
  // autoStraightDrive(5,true,50);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  initForklift();
  initForklift2();
  initFlippy();
  initDrive();

  while (1) {
  
    tankDrive((Controller1.Axis3.value() + Controller1.Axis4.value())/2, (Controller1.Axis3.value() - Controller1.Axis4.value())/2);



    if(Controller1.ButtonR1.pressing()) {
      ForkLiftMotorGroup.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonR2.pressing()) {
      ForkLiftMotorGroup.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    else{
      ForkLiftMotorGroup.stop(vex::brakeType::brake);
    }


    if(Controller1.ButtonL1.pressing()) {
      ForkLift2.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonL2.pressing()) {
      ForkLift2.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    else{
      ForkLift2.stop(vex::brakeType::brake);
    }


    if(Controller1.ButtonB.pressing()) {
      Flip.spin(vex::directionType::fwd, 5, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonA.pressing()) {
      Flip.spin(vex::directionType::rev, 5, vex::velocityUnits::pct);
    }
    else{
      Flip.stop(vex::brakeType::brake);
    }


    if(Controller1.ButtonY.pressing()) {
      RightMotorGroup.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
      LeftMotorGroup.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    }

    
    
  



    Brain.Screen.print(Flip.position(degrees));
    Brain.Screen.newLine();

    
  
  
    
  
  

  
    

    // // Inertial1.setRotation(0, degrees);
    // double rawcurrent = Inertial1.rotation(degrees);
    // // char buf[15];
    // // sprintf(buf, "%f %f %f %f", rawcurrent, current, error, output);
    

    wait(20, msec); 
  }
}


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}