#ifndef FLAGSHIPDEVICE_H
#define FLAGSHIPDEVICE_H

#include "minimalDevice.h"
#include "packet.h"

#include <vector>
#include <string>

using namespace std;

class FlagshipSamsong : public Samsong{

private:
    vector<Device*> flagshipDevices;
    vector<Device*> minimalDevices;
    int nextDevice = 0;
public:

    FlagshipSamsong(){
        flagshipDevices.push_back(this);
    }

    void addFlagshipDevice(Device* device);
    void addMinimalDevice(Device* device);

    Connect receiver(Assign packet);
    Data receiver(Data packet);
};

#endif