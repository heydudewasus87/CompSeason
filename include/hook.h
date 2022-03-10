#pragma once

const int hookDownSetpoint = -190;
const int hookUpSetpoint = 0;

void initHook();
void hookDown(bool waitForCompletion, uint32_t timeLimit = 0);
void hookUp(bool waitForCompletion, uint32_t timeLimit = 0);
