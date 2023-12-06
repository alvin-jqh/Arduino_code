#ifndef Serial_comms_funcs_h
#define Serial_comms_funcs_h
#include <Arduino.h>

class Comms{
public:
    Comms();
    ~Comms();

    // listen for new data basically combine everything
    void listen();

    // data storing function
    void recvWithStartEndMarkers();   

    // data conversion function
    void parseData();

    void showParsedData(); 

    double getLeft();
    double getRight();

private:
    const byte numChars;
    char *receivedChars;
    char *tempChars;

    // checks if any newData has been received
    bool newData;

    // all received info will be stored in these variables
    char messageFromPC;
    double leftSpeed, rightSpeed;

};

#endif