#ifndef INIT_H
#define INIT_H

#include <Servo.h> 

// servo pins
#define SERVO1_PIN 9
#define SERVO2_PIN 10
#define SERVO3_PIN 11

// DH parameters
#define D1 34.0  // offset of the first joint along the z-axis 
#define A2 70.0  // length of link 2
#define A3 80.0  // length of link 3

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
