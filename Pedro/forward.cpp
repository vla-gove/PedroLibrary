#include "forward.h"
#include <math.h>

#ifndef PI
#define PI 3.14159265358979323846
#endif

// External global position from init.cpp
extern Position position;

void forward(Joints joints) {
    float theta1 = joints.angle1 * PI / 180.0;
    float theta2 = joints.angle2 * PI / 180.0;
    float theta3 = joints.angle3 * PI / 180.0;
    
    // forward kinematics equations
    position.x = A2 * cos(theta1) * cos(theta2) + A3 * cos(theta1) * cos(theta2 + theta3);
    position.y = A2 * sin(theta1) * cos(theta2) + A3 * sin(theta1) * cos(theta2 + theta3);
    position.z = D1 + A2 * sin(theta2) + A3 * sin(theta2 + theta3);
    
    move(joints);
}

Position getPosition() {
    return position;  
}

// calculate the position without moving the robot
Position calculatePosition(Joints joints) {
    Position calculatedPosition;
    float theta1 = joints.angle1 * PI / 180.0;
    float theta2 = joints.angle2 * PI / 180.0;
    float theta3 = joints.angle3 * PI / 180.0;
    
    calculatedPosition.x = A2 * cos(theta1) * cos(theta2) + A3 * cos(theta1) * cos(theta2 + theta3);
    calculatedPosition.y = A2 * sin(theta1) * cos(theta2) + A3 * sin(theta1) * cos(theta2 + theta3);
    calculatedPosition.z = D1 + A2 * sin(theta2) + A3 * sin(theta2 + theta3);
    
    return calculatedPosition;
}