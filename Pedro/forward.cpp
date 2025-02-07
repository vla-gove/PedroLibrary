#include "forward.h"

Position position;

void forward(Joints joints) {
    // forward kinematics computation function prototype
    // position.x = a2 * cos(theta1) * cos(theta2) + a3 * cos(theta1) * cos(theta2 + theta3);
    // position.y = a2 * sin(theta1) * cos(theta2) + a3 * sin(theta1) * cos(theta2 + theta3);
    // position.z = d1 + a2 * sin(theta2) + a3 * sin(theta2 + theta3);
    move(joints);
}

Position getPosition() {
    return position;  
}
