#include "Encoder_funcs.h"


void Wheels::init(int leftA, int leftB, int rightA, int rightB){

    this->deltaT = 100; // sampling time for the speed
    this-> countsperRev = 632;  // encoder counts per revolution
}

Wheels::Wheels(int leftA, int leftB, int rightA, int rightB):LeftEncoder(leftA,leftB),RightEncoder(rightA,rightB){
    this->init(leftA, leftB, rightA, rightB);
}

Wheels::~Wheels(){
    ~this->newLeft;
    ~this->newRight;
    ~this->startLeft;
    ~this->startRight;

    ~this->deltaT;
    ~this->startTime;
    ~this->countsperRev;
}

void Wheels::startTimer(){
    this->startTime = millis();
    this->startLeft = this->LeftEncoder.read();
    this->startRight = this->RightEncoder.read();
}

float* Wheels::speed(int unit){

    unsigned long now = millis();
    this->newLeft = this->LeftEncoder.read();
    this->newRight = this->RightEncoder.read();
    float speed[2];    // first element is left speed, second element is right speed
    float speedm[2];

    if (now - this->startTime >= this->deltaT){
        speed[0] = (this->newLeft - this->startLeft) / (float)(this->deltaT * 1e-3 * countsperRev);
        speed[1] = (this->newRight - this->startRight) / (float)(this->deltaT * 1e-3 * countsperRev);
        speedm[0] = speed[0] * 0.06 * M_PI;
        speedm[1] = speed[1] * 0.06 * M_PI;
        this->startTime = now;
        this->startLeft = this->newLeft;
        this->startRight = this->newRight;
    }

    if(unit == 0){
        return speed; // revolutions per second
    }
    else {
        return speedm; // metres per second
    }
}
