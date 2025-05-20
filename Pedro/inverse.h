#ifndef INVERSE_H
#define INVERSE_H

#include "init.h"   
#include "motor.h"  

// check if a position is within the reachable workspace
bool isReachable(Position position);

// check if joint angles are within their allowable limits
bool checkJointLimits(Joints joints);

// check if inverse kine can be calculated
bool Inverse(Position position, Joints &joints);

// move to position if calculated
void Inverse(Position position); 

#endif