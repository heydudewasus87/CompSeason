#include "drive.h"
#include "vex.h"
#include "forklift2.h"

void initForklift2() {
  ForkLift2.setPosition(0, degrees);
}

void forklift2Up(bool waitForCompletion) {
  ForkLift2.spinTo(upSetpoint2, degrees, 100, velocityUnits::pct, waitForCompletion);
}

void forklift2Down(bool waitForCompletion) {
  ForkLift2.spinTo(downSetpoint2, degrees, 100, velocityUnits::pct, waitForCompletion);
}

void forklift2Middle(bool waitForCompletion) {
  ForkLift2.spinTo(middleSetpoint2, degrees, 75, velocityUnits::pct, waitForCompletion);
}