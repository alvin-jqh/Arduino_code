#include "Encoder_funcs.h"

void Wheels::init(int leftA, int leftB, int rightA, int rightB){
    this->leftA = leftA;
    this->leftB = leftB;
    this->rightA = rightA;
    this->rightB = rightB;

    this->deltaT = 100;
    this-> countsperRev = 632;
}