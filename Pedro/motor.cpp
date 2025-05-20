#include "motor.h"

// current joint positions - start at 90,90,90
Joints currentJoints = {90, 90, 90};

// check if joint positions are within limits
bool validateJointLimits(Joints joints) {
    // joint 1: 0 to 180 degrees (servo range)
    if (joints.angle1 < 0.0 || joints.angle1 > 180.0) {
        return false;
    }
    
    // joint 2: 0 to 180 degrees (servo range)
    if (joints.angle2 < 0.0 || joints.angle2 > 180.0) {
        return false;
    }
    
    // joint 3: 0 to 180 degrees (servo range)
    if (joints.angle3 < 0.0 || joints.angle3 > 180.0) {
        return false;
    }
    
    return true;
}

void move(Joints joints) {
    // validate joint limits
    if (!validateJointLimits(joints)) {
        // invalid joint configuration
        return;
    }
    
    // direct pass-through: joint angles = servo positions
    servo1.write(joints.angle1);
    servo2.write(joints.angle2);
    servo3.write(joints.angle3);
    
    // update current joint positions
    currentJoints = joints;
}

// smooth motion from current position to target position
void moveSmooth(Joints targetJoints, int steps, int delayMs) {
    // validate target position
    if (!validateJointLimits(targetJoints)) {
        return;
    }
    
    // calculate step sizes
    float step1 = (targetJoints.angle1 - currentJoints.angle1) / steps;
    float step2 = (targetJoints.angle2 - currentJoints.angle2) / steps;
    float step3 = (targetJoints.angle3 - currentJoints.angle3) / steps;
    
    // move in small increments
    Joints intermediateJoints = currentJoints;
    for (int i = 0; i < steps; i++) {
        intermediateJoints.angle1 += step1;
        intermediateJoints.angle2 += step2;
        intermediateJoints.angle3 += step3;
        
        move(intermediateJoints);
        delay(delayMs);
    }
    
    // ensure the target position is reached
    move(targetJoints);
}

// get current joint positions
Joints getCurrentJoints() {
    return currentJoints;
}