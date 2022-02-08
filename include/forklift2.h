#pragma once

const int downSetpoint2 = -770;
const int upSetpoint2 = -500;
const int middleSetpoint2 = -600;

void initForklift2();
void forklift2Up(bool waitForCompletion);
void forklift2Down(bool waitForCompletion);
void forklift2Middle(bool waitForCompletion);