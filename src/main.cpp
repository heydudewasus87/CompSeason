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
#include "hook.h"
#include "Button.h"

using namespace vex;

// A global instance of competition
competition Competition;
extern int g_autonSelection;
extern int g_redOrBlue;
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
  initForklift();
  initDrive();
  initHook();
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

  if (g_autonSelection == 0) {

      forkliftDown(true);
      // vex::task::sleep(100);
      autoStraightDrive(30,false,75);
      vex::task::sleep(450);
      forkliftUp(true);
      vex::task::sleep(550);
      autoStraightDrive(-25,true,50);
      vex::task::sleep(500);
      ringLoader.spinFor(vex::directionType::fwd, 6000, msec, 100, vex::velocityUnits::pct);
      forkliftDown(true);
  }

  if (g_autonSelection == 1) {
    autoStraightDriveWithPID(-48, 1800);
    hookDown(true, 2000);    
    turnToAngle(15);

    forkliftDown(false);
    autoStraightDrive(38, true, 100);
    hookUp(true,1000);
    
    vex::task::sleep(400);
    turnToAngle(-100);
    vex::task::sleep(100);

    if (g_redOrBlue == 0)
      targetDrive(16, VisionSensor__SIG_RED, 2000);
    else
      targetDrive(16, VisionSensor__SIG_BLUE, 2000);

    autoStraightDrive(8, false, 50);
    forkliftUp(true);
    vex::task::sleep(500);
    autoStraightDrive(-15, true, 50);
    ringLoader.spinFor(vex::directionType::fwd, 4000, msec, 100, vex::velocityUnits::pct);
    forkliftDown(true);
  }

  if (g_autonSelection == 2) {

    autoStraightDriveWithPID(-48, 1300);
    hookDown(true, 1000);
    forkliftDown(false);
    turnToAngle(20);
    autoStraightDriveWithPID(40, 1000);
    hookUp(true, 2000);
    turnToAngle(-135);

    if (g_redOrBlue == 0)
      targetDrive(36, VisionSensor__SIG_RED, 3000);
    else
      targetDrive(36, VisionSensor__SIG_BLUE, 3000);

    forkliftUp(false);
    turnToAngle(110);
    vex::task::sleep(200);
    ringLoader.spinFor(vex::directionType::fwd, 3000, msec, 100, vex::velocityUnits::pct);
    vex::task::sleep(300);
    // autoStraightDrive(-10,true,50);
    // autoStraightDrive(10,true,75);
    forkliftDown(true);

  }


  if (g_autonSelection == 3) {

    autoStraightDriveWithPID(-48, 1300);
    hookDown(true, 1000);
    forkliftDown(false);
    autoStraightDriveWithPID(34, 1000);
    hookUp(true, 2000);
    autoStraightDriveWithPID(21, 500);
    turnToAngle(180);
    targetDrive(45, VisionSensor__SIG_YELLOW, 2500);
    autoStraightDrive(30,false,75);
    vex::task::sleep(450);
    forkliftUp(false);    
    vex::task::sleep(850);
    autoStraightDriveWithPID(-40, 1750);
  }

  if (g_autonSelection == 4) {
    autoStraightDriveWithPID(-76,2250);
    hookDown(true,1000);
    forkliftDown(false);
    autoStraightDriveWithPID(50,1500);
    hookUp(true);
    turnToAngle(-45);

    if (g_redOrBlue == 0)
      targetDrive(30, VisionSensor__SIG_RED, 2000);
    else
      targetDrive(30, VisionSensor__SIG_BLUE, 2000);

    forkliftUp(false);
    turnToAngle(110);
    vex::task::sleep(200);
    ringLoader.spinFor(vex::directionType::fwd, 3000, msec, 100, vex::velocityUnits::pct);
    vex::task::sleep(300);
    // autoStraightDrive(-10,true,50);
    // autoStraightDrive(10,true,75);
    forkliftDown(true);
  }
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
  LeftMotorGroup.setStopping(coast);
  RightMotorGroup.setStopping(coast);

  while (1) {
  
    tankDrive((Controller1.Axis3.value() + Controller1.Axis4.value())/2, (Controller1.Axis3.value() - Controller1.Axis4.value())/2);

    if(Controller1.ButtonR1.pressing()) {
      ForkLiftMotorGroup.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonR2.pressing()) {
      ForkLiftMotorGroup.spin(vex::directionType::rev, 127, vex::velocityUnits::pct);
    }
    else{
      ForkLiftMotorGroup.stop(vex::brakeType::brake);
    }

    // Brain.Screen.print(ForkLiftMotorGroup.position(degrees));
    // Brain.Screen.newLine();

    if(BumperH.pressing()){
    Controller1.rumble("----");
    }

    if(Controller1.Axis2.value() > 0) {
      ringLoader.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if(Controller1.Axis2.value()<0) {
      ringLoader.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else {
      ringLoader.stop(vex::brakeType::brake);
    }   

    if(Controller1.ButtonDown.pressing()) {
      ringLoader.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
    }

    if(Controller1.ButtonL1.pressing()) {
      hook.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if(Controller1.ButtonL2.pressing()) {
      hook.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    else{
      hook.stop(vex::brakeType::brake);
    }

    if(Controller1.ButtonA.pressing()) {
      RightMotorGroup.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
      LeftMotorGroup.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
    }

    if(Controller1.ButtonB.pressing()) {
      RightMotorGroup.spin(vex::directionType::fwd,-100,vex::velocityUnits::pct);
      LeftMotorGroup.spin(vex::directionType::fwd,-100,vex::velocityUnits::pct);
    }

    wait(20, msec); 
  }
}

int main() {
  printf("Initial %d\n", g_redOrBlue);

  initButtons();
  pre_auton();

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
}
