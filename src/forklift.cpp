#include "drive.h"
#include "vex.h"
#include "forklift.h"

void initForklift() {
  ForkLiftMotorGroup.setPosition(0, degrees);
}

void forkliftUp(bool waitForCompletion) {
  initForklift();
  ForkLiftMotorGroup.spinTo(500, degrees, 100, velocityUnits::pct, waitForCompletion);
}

int forkliftDownTask() {
  while (true) {
    if (BumperA.pressing()) {
      break;
    }
    else {
      ForkLiftMotorGroup.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }

    vex::task::sleep(20);
  }

  ForkLiftMotorGroup.stop(vex::brakeType::brake);
  return 0;
}

void forkliftDown(bool waitForCompletion) {
  if (waitForCompletion) {
    forkliftDownTask();
  }
  else {
    vex::task t(forkliftDownTask);
  }
}

void forkliftMiddle(bool waitForCompletion) {
  ForkLiftMotorGroup.spinTo(middleSetpoint, degrees, 75, velocityUnits::pct, waitForCompletion);
}

void forkliftBoost(bool waitForCompletion) {
  ForkLiftMotorGroup.spinTo(upSetpoint, degrees, 75, velocityUnits::pct, waitForCompletion);
}

void forkliftSlowDown(bool waitForCompletion) {
  ForkLiftMotorGroup.spinTo(downSetpoint, degrees, 40, velocityUnits::pct, waitForCompletion);
}