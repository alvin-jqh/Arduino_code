#include "Encoder_funcs.h"
#include <math.h>

void Wheels::init(int leftA, int leftB, int rightA, int rightB){
    this->leftA = leftA;
    this->leftB = leftB;
    this->rightA = rightA;
    this->rightB = rightB;

    Encoder LeftEncoder(leftA,leftB);
    Encoder RightEncoder(rightA,rightB);

    this->deltaT = 100;
    this-> countsperRev = 632;

    this->startLeft = LeftEncoder.read();
    this->startRight = RightEncoder.read();
    this->startTime = millis();
}

Wheels::Wheels(int leftA, int leftB, int rightA, int rightB){
    this->init(leftA, leftB, rightA, rightB);
}

Wheels::~Wheels(){
    ~this->leftA;
    ~this->leftB;
    ~this->rightA;
    ~this->rightB;

    ~this->newLeft;
    ~this->newRight;
    ~this->startLeft;
    ~this->startRight;

    ~this->deltaT;
    ~this->startTime;
    ~this->countsperRev;
}

float Wheels::leftspeed(int unit){

    unsigned long now = millis();
    this->newLeft = LeftEncoder.read();
    float speed;

    if (now - this->startTime >= this->deltaT){
        speed = (this->newLeft - this->startLeft) / (float)(this->deltaT * 1e-3 * countsperRev);
        this->startTime = now;
        this->startLeft = this->newLeft;
    }

    if(unit == 0){
        return speed; // revolutions per second
    }
    else {
        return speed * 0.06 * M_PI; // metres per second
    }
}