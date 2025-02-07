#include "motor.h"

void move(Joints joints) {
    servo1.write(joints.angle1); 
    servo2.write(joints.angle2); 
    servo3.write(joints.angle3); 
}

