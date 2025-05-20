#include "inverse.h"
#include <math.h>

#ifndef PI
#define PI 3.14159265358979323846
#endif

bool isReachable(Position position) {
    // calculate distance from base to target position
    float r_xy = sqrt(position.x * position.x + position.y * position.y);
    float distance = sqrt(r_xy * r_xy + (position.z - D1) * (position.z - D1));
    
    // check if target is in the reachable workspace
    float min_reach = fabs(A2 - A3); // min reach (when links fold back)
    float max_reach = A2 + A3;       // max reach (when links are fully extended)
    
    return (distance >= min_reach && distance <= max_reach);
}

bool checkJointLimits(Joints joints) {

	
    if (joints.angle1 < 0 || joints.angle1 > 180) {
        return false;
    }
    
    if (joints.angle2 < 0 || joints.angle2 > 180) {
        return false;
    }
    
    
    if (joints.angle3 < 0 || joints.angle3 > 180) {
        return false;
    }
    
    return true;
}

bool Inverse(Position position, Joints &joints) {
    // calculate joint angle 1 (base rotation)
    joints.angle1 = atan2(position.y, position.x) * 180.0 / PI;
    
    // calculate the planar distance from the base axis to the target point
    float r = sqrt(position.x * position.x + position.y * position.y);
    float s = position.z - D1;
    
    // calculate the distance from joint 2 to the target point
    float L = sqrt(r * r + s * s);
    
    // check if the target is reachable
    if (!isReachable(position)) {
        return false;
    }
    
    // calculate joint angle 3 using law of cosines
    float cosAngle3 = (A2*A2 + A3*A3 - L*L) / (2 * A2 * A3);
    
    // handle potential numerical errors
    if (cosAngle3 > 1.0) cosAngle3 = 1.0;
    if (cosAngle3 < -1.0) cosAngle3 = -1.0;
    
    // calculate angle3 (elbow joint)
    joints.angle3 = acos(cosAngle3) * 180.0 / PI;
    
    // calculate joint angle 2 (shoulder)
    float alpha = atan2(s, r) * 180.0 / PI;
    float beta = acos((A2*A2 + L*L - A3*A3) / (2 * A2 * L)) * 180.0 / PI;
    joints.angle2 = alpha + beta;
    
    // check if the calculated joint angles are within limits
    if (!checkJointLimits(joints)) {
        return false;
    }
    
    return true;
}

void Inverse(Position position) {
    Joints joints;
    
    if (Inverse(position, joints)) {
        move(joints);
    } else {
        // position is not reachable or violates joint limits
        // add error handling? just move to the closest possible position?
    }
}