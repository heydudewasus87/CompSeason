#ifndef __DRIVE_H
#define __DRIVE_H

#include "PIDController.h"
#include "vex.h"

extern inertial Inertial1;

void initDrive();
void autoStraightDrive(double setpoint, bool waitForCompletion, double straightSpeed);
void turnToAngle(double setpoint);
void tankDrive(double leftVelocity, double rightVelocity);


#endif