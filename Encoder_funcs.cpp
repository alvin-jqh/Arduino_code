#include "Encoder_funcs.h"

Wheels::Wheels(int leftA, int leftB, int rightA, int rightB):LeftEncoder(leftA,leftB),RightEncoder(rightA,rightB){
    this->deltaT = 100; // sampling time for the speed
    this-> countsperRev = 632;  // encoder counts per revolution
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
    Serial.begin(9600);
    this->startTime = millis();
    this->startLeft = this->LeftEncoder.read();
    this->startRight = this->RightEncoder.read();
}

void Wheels::computeSpeeds(){
    unsigned long now = millis();
    this->newLeft = this->LeftEncoder.read();
    this->newRight = this->RightEncoder.read();

    if( now - this->startTime >= this->deltaT) {

        this->leftSpeed = (this->newLeft - this->startLeft) / (float)(this->deltaT * 1e-3 * this->countsperRev);
        this->rightSpeed = (this->newRight - this->startRight) / (float)(this->deltaT * 1e-3 * this->countsperRev);

        Serial.print("Left Speed: ");
        Serial.print(this->leftSpeed);
        Serial.print("  Right Speed: ");
        Serial.println(this->rightSpeed);

        this->startTime = now;
        this->startLeft = this->newLeft;
        this->startRight = this->newRight;
    }
}

float Wheels::getLeftSpeed(bool unit){
    if(unit){
        return this->leftSpeed; // this is in revolutions per second
    }
    else{
        return this->leftSpeed * 0.06 * M_PI;   // in metres per second
    }
}

float Wheels::getRightSpeed(bool unit){
    if(unit){
        return this->rightSpeed; // this is in revolutions per second
    }
    else{
        return this->rightSpeed * 0.06 * M_PI;   // in metres per second
    }
}