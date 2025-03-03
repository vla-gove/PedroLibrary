#include "inverse.h"

void Inverse(Position position) {
    Joints joints;
// inverse kinematics computation function prototype
// joint angle 1 calculation
// joints.angle1 = atan2(y, x) * 180.0 / PI;

// r = sqrt(x*x + y*y);
// s = z - D1;
// L = sqrt(r*r + s*s);

// + check for reachability

// joint angle 3 calculations
// cosAngle3 = (A2*A2 + A3*A3 - L*L) / (2 * A2 * A3);
// joint.angle3 = acos(cosAngle3) * 180.0 / PI;

// joint angle 2 calculations
// alpha = atan2(s, r) * 180.0 / PI;
// beta = acos((A2*A2 + L*L - A3*A3) / (2 * A2 * L)) * 180.0 / PI;
// joints.angle2 = alpha + beta;
    
    move(joints);
}
