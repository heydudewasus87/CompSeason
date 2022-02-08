#pragma once

const int flipDownPoint = -145;
const int flipUpPoint = -75;
const int flipSupportPoint = -60;

void initFlippy();
void flipDown(bool waitForCompletion);
void flipUp(bool waitForCompletion);
void flippyDrop(double Flipsetpoint, bool waitForCompletion);
void flipSupport(bool waitForCompletion);

