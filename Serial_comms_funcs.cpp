#include "Serial_comms_funcs.h"

Comms::Comms():numChars(32){
    this->receivedChars = new char[numChars + 1];
    this->tempChars = new char[numChars + 1];

    this->leftSpeed = 0;
    this->rightSpeed = 0;
    this->messageFromPC = {0};

    this->newData = false;
}

Comms::~Comms(){
    delete[] receivedChars;
    delete[] tempChars;
}

void Comms::listen(){
    recvWithStartEndMarkers();
    if(newData == true){
        strcpy(tempChars, receivedChars);   // protects the original data
        parseData();
        // showParsedData();
        newData = false;
    }
}

void Comms::recvWithStartEndMarkers(){
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    } 
}

void Comms::parseData(){
    
    char * strtokIndx; // this is used by strtok() as an index

    // strtokIndx = strtok(tempChars,",");      // get the first part - the string
    // strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC
 
    strtokIndx = strtok(tempChars, ","); 
    leftSpeed = atof(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(NULL, ",");    // this continues where the previous call left off
    rightSpeed = atof(strtokIndx);     // convert this part to a float

}

void Comms::showParsedData(){
    // Serial.print("Message ");
    // Serial.println(messageFromPC);
    Serial.print("Left ");
    Serial.println(leftSpeed);
    Serial.print("Right ");
    Serial.println(rightSpeed);
}

double Comms::getLeft(){
    return this->leftSpeed;
}

double Comms::getRight(){
    return this->rightSpeed;
}