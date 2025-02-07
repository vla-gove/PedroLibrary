#include "inverse.h"

void Inverse(Position position) {
    Joints joints;
// inverse kinematics computation function prototype
// joint angle 1 calculation
// joints.angle1 = atan2(y, x) * 180.0 / PI;

// r = sqrt(x*x + y*y);
// s = z - d1;
// L = sqrt(r*r + s*s);

// + check for reachability

// joint angle 3 calculations
// cosAngle3 = (a2*a2 + a3*a3 - L*L) / (2 * a2 * a3);
// joint.angle3 = acos(cosAngle3) * 180.0 / PI;

// joint angle 2 calculations
// alpha = atan2(s, r) * 180.0 / PI;
// beta = acos((a2*a2 + L*L - a3*a3) / (2 * a2 * L)) * 180.0 / PI;
// joints.angle2 = alpha + beta;
    
    move(joints);
}
