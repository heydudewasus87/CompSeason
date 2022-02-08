#include "drive.h"
#include "vex.h"
#include "forklift.h"

void initForklift() {
  ForkLiftMotorGroup.setPosition(0, degrees);
}

void forkliftUp(bool waitForCompletion) {
  ForkLiftMotorGroup.spinTo(upSetpoint, degrees, 50, velocityUnits::pct, waitForCompletion);
}

void forkliftDown(bool waitForCompletion) {
  ForkLiftMotorGroup.spinTo(downSetpoint, degrees, 100, velocityUnits::pct, waitForCompletion);
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