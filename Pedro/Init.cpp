#include "init.h"

Servo servo1;
Servo servo2;
Servo servo3;

//starting position
Joints joints = {0.0, 0.0, 0.0}; // <- default joint angles will be updated
Position position = {0.0, 0.0, 0.0};

void initServos() {
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN); 
    servo3.attach(SERVO3_PIN);
}


void initRobotArm() {
   
    initServos();
    
    //write to default position
    servo1.write(joints.angle1); 
    servo2.write(joints.angle2); 
    servo3.write(joints.angle3); 
    
}

// single function init
void robotInit() {
    initRobotArm();
}
