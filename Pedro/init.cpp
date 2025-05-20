#include "init.h"
#include "forward.h"

Servo servo1;
Servo servo2;
Servo servo3;

// starting position
Joints joints = {90, 90, 90}; // default joint angles
Position position; // default position for 90, 90, 90 --- will calculate later

void initServos() {
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN); 
    servo3.attach(SERVO3_PIN);
}

void initRobotArm() {
    initServos();
    
    // center all servos at neutral position
    servo1.write(90); 
    servo2.write(90); 
    servo3.write(90);

    // calculate and update the default position using forward kinematics function
    position = calculatePosition(joints);
    
    // delay if needed
    delay(1000);
}

// single function init
void robotInit() {
    initRobotArm();
}