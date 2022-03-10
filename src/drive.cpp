#include "drive.h"
#include "vex.h"
#include <ctime>

int centerFOV = 158;

void initDrive() {
  LeftMotorGroup.setPosition(0, degrees);
  RightMotorGroup.setPosition(0, degrees);
  LeftMotorGroup.setStopping(brake);
  RightMotorGroup.setStopping(brake);
  
  Inertial1.calibrate();
  while (Inertial1.isCalibrating()) {
    wait(20, msec);
  }
}

void autoStraightDrive(double inches, bool waitForCompletion, double straightSpeed) {
  double leftSetpoint = inches / (2 * M_PI * 2) * 360 + LeftMotorGroup.position(degrees);
  double rightSetpoint = inches / (2 * M_PI * 2) * 360 + RightMotorGroup.position(degrees);
  double leftError = leftSetpoint - LeftMotorGroup.position(deg);
  
  LeftMotorGroup.spinTo(leftSetpoint, degrees, straightSpeed, velocityUnits::pct, false);
  RightMotorGroup.spinTo(rightSetpoint, degrees, straightSpeed, velocityUnits::pct, false);

  if (waitForCompletion) {
    while ((LeftMotorGroup.isSpinning() || RightMotorGroup.isSpinning()) && leftError > 5)
      vex::task::sleep(20);
      leftError = leftSetpoint - LeftMotorGroup.position(deg);
  }
}

void autoStraightDriveWithPID(double inches, uint32_t timeLimit) {
  double leftSetpoint = inches / (2 * M_PI * 2) * 360 + LeftMotorGroup.position(degrees);
  double rightSetpoint = inches / (2 * M_PI * 2) * 360 + RightMotorGroup.position(degrees);
  
  PID leftPid, rightPid;
  PIDInit(&leftPid, 0.15, 0.0, 0.0);
  PIDInit(&rightPid, 0.15, 0.0, 0.0);
  double tolerance = 15;
  vex::timer t = timer();

  while (true) {
    if (t.time() > timeLimit) {
      break;
    }

    double leftError = leftSetpoint - LeftMotorGroup.position(degrees);
    double rightError = rightSetpoint - RightMotorGroup.position(degrees);
    
    if (leftError < tolerance && leftError > -tolerance) {
      break;
    }
    else {
      double leftVelocity = PIDCompute(&leftPid, leftError);
      LeftMotorGroup.spin(directionType::fwd, leftVelocity, velocityUnits::pct);
      printf("%f\n",leftError);
      double rightVelocity = PIDCompute(&rightPid, rightError);
      RightMotorGroup.spin(directionType::fwd, rightVelocity, velocityUnits::pct);
    }

    vex::task::sleep(20);
  }

  tankDrive(0, 0);
}

void targetDrive(double inches, vision::signature sig, uint32_t timeLimit) {
  double leftSetpoint = inches / (2 * M_PI * 2) * 360 + LeftMotorGroup.position(degrees);
  // double rightSetpoint = inches / (2 * M_PI * 2) * 360 + RightMotorGroup.position(degrees);

  PID leftPid, rightPid;
  PIDInit(&leftPid, 0.50, 0.0, 0.0);
  PIDInit(&rightPid, 0.50, 0.0, 0.0);
  double tolerance = 5;
  vex::timer t = timer();

  while (true) {
    if (t.time() > timeLimit) {
      break;
    }

    double leftError = leftSetpoint - LeftMotorGroup.position(degrees);
    // double rightError = rightSetpoint - RightMotorGroup.position(degrees);
    int angleError = 0;

    if (leftError < tolerance && leftError > -tolerance) {
      break;
    }
    else {
      VisionSensor.takeSnapshot(sig);
      if (VisionSensor.largestObject.exists) {
        angleError = 0.6*(VisionSensor.largestObject.centerX - centerFOV);
      }
      else{
        angleError = 0;
      }

      printf("%d\n", angleError);
      double leftVelocity = PIDCompute(&leftPid, 50 + angleError);
      LeftMotorGroup.spin(directionType::fwd, leftVelocity, velocityUnits::pct);
      double rightVelocity = PIDCompute(&rightPid, 50 - angleError);
      RightMotorGroup.spin(directionType::fwd, rightVelocity, velocityUnits::pct);
    }
    
    vex::task::sleep(20);
  }

  tankDrive(0, 0);
}

void turnToAngle(double setpoint) {
  float turningRatio = 2.5;
  float wheelDegrees = turningRatio * setpoint;    
  LeftMotorGroup.spinFor(
      wheelDegrees, vex::rotationUnits::deg, 
      50, vex::velocityUnits::pct, false
  );

  RightMotorGroup.spinFor(
      -wheelDegrees, vex::rotationUnits::deg,
      50, vex::velocityUnits::pct
  );
}

void turnToAbsAngle(double setpoint, bool reverse) {
  float tolerance = 0.5;
  float tolerance2 = 1.0;
  PID pid;
  PIDInit(&pid, 0.6, 0.2, 0.1);
  float prevHeading = 0;
  float heading = 0;

  while (true) {
    prevHeading = heading;
    heading = Inertial1.heading(vex::rotationUnits::deg);
    float error = setpoint - heading;
    float motion = heading - prevHeading;
    if (error < tolerance && error > -tolerance && motion < tolerance2 && motion > -tolerance2)
      break;

    float velocity = PIDCompute(&pid, error);
    // float velocity = kP * error;
    if (reverse == false) {
      tankDrive(velocity, -velocity);
    }
    else {
      tankDrive(-velocity, velocity);
    }
    vex::task::sleep(20);
  }

  tankDrive(0, 0);
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