#ifndef MOTOR_H
#define MOTOR_H

class Motor {
  public:
    Motor(int pin1, int pin2, int pin3);
    void initialize(); 
    void moveJoint(int jointNumber, float angle);
  private:
    Servo servo1;
    Servo servo2;
    Servo servo3;
    int servoPins[3];
};

#endif
