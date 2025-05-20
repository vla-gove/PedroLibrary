#ifndef INIT_H
#define INIT_H

#include <Servo.h>
#include <Arduino.h>

// servo pins
#define SERVO1_PIN 9
#define SERVO2_PIN 10
#define SERVO3_PIN 11

// DH parameters
#define D1 34.0  // offset of the first joint along the z-axis (mm)
#define A2 70.0  // length of link 2 (mm)
#define A3 80.0  // length of link 3 (mm)

extern Servo servo1;
extern Servo servo2;
extern Servo servo3;

struct Joints {
    float angle1;  // degrees
    float angle2;  // degrees
    float angle3;  // degrees
};

struct Position {
    float x;  // mm
    float y;  // mm
    float z;  // mm
};

// global variables for current state
extern Joints joints;
extern Position position;

// init servos
void initServos();

// init arm to starting position
void initRobotArm();

// complete initialization function
void robotInit();

#endif