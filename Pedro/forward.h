#ifndef FORWARD_H
#define FORWARD_H

#include "init.h"   
#include "motor.h"  

void forward(Joints joints);  
Position getPosition();
Position calculatePosition(Joints joints);

#endif