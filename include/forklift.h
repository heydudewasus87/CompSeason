#pragma once

const int downSetpoint = -955;
const int upSetpoint = -625;
const int middleSetpoint = -725;

void initForklift();
void forkliftUp(bool waitForCompletion);
void forkliftDown(bool waitForCompletion);
void forkliftMiddle(bool waitForCompletion);
void forkliftBoost(bool waitForCompletion);
void forkliftSlowDown(bool waitForCompletion);