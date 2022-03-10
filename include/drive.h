#ifndef __DRIVE_H
#define __DRIVE_H

#include "PIDController.h"
#include "vex.h"

void initDrive();
void autoStraightDrive(double setpoint, bool waitForCompletion, double straightSpeed);
void autoStraightDriveWithPID(double inches, uint32_t timeLimit);
void targetDrive(double setpoint, vision::signature sig, uint32_t timeLimit);
void turnToAngle(double setpoint);
void turnToAbsAngle(double setpoint, bool reverse = false);
void tankDrive(double leftVelocity, double rightVelocity);

#endif