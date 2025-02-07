#ifndef INIT_H
#define INIT_H

#include <Servo.h> 

// servo pins
#define SERVO1_PIN 9
#define SERVO2_PIN 10
#define SERVO3_PIN 11

// link lengths based on the 3d model
#define LINK1 1.0  
#define LINK2 1.0  
#define LINK3 1.0  

extern Servo servo1;
extern Servo servo2;
extern Servo servo3;

struct Joints {
    float angle1;
    float angle2;
    float angle3;
};

struct Position {
    float x;
    float y;
    float z;
};


void robotInit();

#endif
