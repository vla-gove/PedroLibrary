#include "forward.h"

Position position;

void forward(Joints joints) {
    // forward kinematics computation function prototype
    // position.x = A2 * cos(theta1) * cos(theta2) + A3 * cos(theta1) * cos(theta2 + theta3);
    // position.y = A2 * sin(theta1) * cos(theta2) + A3 * sin(theta1) * cos(theta2 + theta3);
    // position.z = D1 + A2 * sin(theta2) + A3 * sin(theta2 + theta3);
    move(joints);
}

Position getPosition() {
    return position;  
}
