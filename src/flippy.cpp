#include "drive.h"
#include "vex.h"
#include "flippy.h"

void initFlippy() {
  Flip.setPosition(0, degrees);
}

void flipDown(bool waitForCompletion) {
  Flip.spinTo(flipDownPoint, degrees, 30, velocityUnits::pct, waitForCompletion);
}

void flippyDrop(double Flipsetpoint, bool waitForCompletion) {
  Flip.spinTo(Flipsetpoint,degrees,40,velocityUnits::pct,false);
}

void flipUp(bool waitForCompletion) {
  Flip.spinTo(flipUpPoint, degrees, 40, velocityUnits::pct, waitForCompletion);
}

void flipSupport(bool waitForCompletion) {
  Flip.spinTo(flipSupportPoint, degrees, 5, velocityUnits::pct, waitForCompletion);
}
