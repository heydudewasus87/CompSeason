#include "drive.h"
#include "vex.h"

void initDrive() {
  LeftMotorGroup.setPosition(0, degrees);
  RightMotorGroup.setPosition(0, degrees);
  
}

void autoStraightDrive(double inches, bool waitForCompletion, double straightSpeed) {
  double leftSetpoint = inches / (2 * M_PI * 2) * 360 + LeftMotorGroup.position(degrees);
  double rightSetpoint = inches / (2 * M_PI * 2) * 360 + RightMotorGroup.position(degrees);
  
  LeftMotorGroup.spinTo(leftSetpoint, degrees, straightSpeed, velocityUnits::pct, false);
  RightMotorGroup.spinTo(rightSetpoint, degrees, straightSpeed, velocityUnits::pct, false);

  if (waitForCompletion) {
    while (LeftMotorGroup.isSpinning() || RightMotorGroup.isSpinning())
      vex::task::sleep(20);
  }
}

void turnToAngle(double setpoint) {
  // Note: +90 degrees is a right turn
  float turningRatio = 2.5;
  float wheelDegrees = turningRatio * setpoint;    
  // Divide by two because each wheel provides half the rotation
  LeftMotorGroup.spinFor(
      wheelDegrees, vex::rotationUnits::deg, 
      50, vex::velocityUnits::pct, false
  );

  RightMotorGroup.spinFor(
      -wheelDegrees, vex::rotationUnits::deg,
      50, vex::velocityUnits::pct
  );
}

void tankDrive(double leftVelocity, double rightVelocity) {
  if (leftVelocity < -100) {
    leftVelocity = -100;
  }
  else if (leftVelocity > 100) {
    leftVelocity = 100;
  }

  if (rightVelocity < -100) {
    rightVelocity = -100;
  }
  else if (rightVelocity > 100) {
    rightVelocity = 100;
  }

  LeftMotorGroup.spin(vex::directionType::fwd, leftVelocity, vex::velocityUnits::pct);
  RightMotorGroup.spin(vex::directionType::fwd, rightVelocity, vex::velocityUnits::pct);
}