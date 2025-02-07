#include "motor.h"

// define joint mobility, servo and angle limits, colision and singularity checks based on the configuration before moving joints

void move(Joints joints) {
    servo1.write(joints.angle1); 
    servo2.write(joints.angle2); 
    servo3.write(joints.angle3); 
}

