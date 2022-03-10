#include "drive.h"
#include "vex.h"
#include "hook.h"

void initHook() {
  hook.setBrake(brake);
  hook.setPosition(0, degrees);
}


void hookDown(bool waitForCompletion, uint32_t timeLimit) {
  if (waitForCompletion and timeLimit > 0) {
    vex::timer t = timer();
    
    while (true) {
      if (t.time() > timeLimit)
        break;

      if (hook.position(deg) < hookDownSetpoint)
        break;
      
      hook.spin(reverse, 100, pct);
      task::sleep(20);
    }

    hook.stop(brake);
  }
  else if (waitForCompletion and timeLimit <= 0) {
    hook.spinTo(hookDownSetpoint, degrees, 100, velocityUnits::pct, true);
  }
  else if (!waitForCompletion) {
    hook.spinTo(hookDownSetpoint, degrees, 100, velocityUnits::pct, false);
  }
}   

void hookUp(bool waitForCompletion, uint32_t timeLimit) {
  if (waitForCompletion and timeLimit > 0) {
    vex::timer t = timer();
    
    while (true) {
      if (t.time() > timeLimit)
        break;

      if (hook.position(deg) > hookUpSetpoint)
        break;
      
      hook.spin(fwd, 100, pct);
      task::sleep(20);
    }

    hook.stop(brake);
  }
  else if (waitForCompletion and timeLimit <= 0) {
    hook.spinTo(hookUpSetpoint, degrees, 100, velocityUnits::pct, true);
  }
  else if (!waitForCompletion) {
    hook.spinTo(hookUpSetpoint, degrees, 100, velocityUnits::pct, false);
  }
}

