#ifndef MOTOR_H
#define MOTOR_H

#include "init.h" // to access servo pinout and config
#include <Arduino.h> // for delay function

// check if joint positions are within defined limits
bool validateJointLimits(Joints joints);

// move joints to specified positions immediately
void move(Joints joints);

// move joints smoothly from current position to target position
void moveSmooth(Joints targetJoints, int steps = 20, int delayMs = 15);

// get current joint positions
Joints getCurrentJoints();

#endif