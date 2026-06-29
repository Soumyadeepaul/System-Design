#ifndef MINIMALDEVICE_H
#define MINIMALDEVICE_H

#include "cores.h"
#include "display.h"
#include <bits/stdc++.h>

using namespace std;

// Forward Declarations
class FlagshipSamsong;
class Assign;
class Connect;
class Data;

class Device{
public:
    virtual void setSpecs(string model,
                          string staticIP,
                          int memory,
                          int totalCores) = 0;

    virtual string getModel() = 0;
    virtual string getIP() = 0;
    virtual string getMemory() = 0;
    virtual string useSpace(float memory) = 0;
    virtual string getSpace() = 0;
    virtual string releaseSpace(float memory) = 0;

    virtual bool checkCore() = 0;

    virtual string performTask(string need,
                               string operand) = 0;

    virtual void useDisplay(string output) = 0;

    // Template Method
    void requestTask(string need, string operand);

protected:

    virtual Assign createAssignPacket(string need) = 0;

    virtual Connect sendAssignPacket(Assign packet) = 0;

    virtual Data createDataPacket(Connect packet,
                                  string need,
                                  string operand) = 0;

    virtual string sendDataPacket(Data packet) = 0;

public:
    virtual ~Device() = default;
};

class Specification{
public:
    string model;
    string staticIP;
    float memory;
    float memoryUnderUse = 0.0;

    vector<Core*> cores;
};

class Samsong : public Device{
private:
    Specification specs;
    Display display;

    FlagshipSamsong* flagship = nullptr;

public:

    // Device Functions
    void setSpecs(string model,
                  string staticIP,
                  int memory,
                  int totalCores) override;

    string getModel() override;

    string getIP() override{
        return specs.staticIP;
    }

    string getMemory() override;

    bool checkCore() override;

    string useSpace(float memory) override;

    string getSpace() override;

    string releaseSpace(float memory) override;

    string performTask(string need,
                       string operand) override;

    void useDisplay(string output) override;

    // Template Method Steps
    Assign createAssignPacket(string need) override;

    Connect sendAssignPacket(Assign packet) override;

    Data createDataPacket(Connect packet,
                          string need,
                          string operand) override;

    string sendDataPacket(Data packet) override;

    // Utility
    void setFlagship(FlagshipSamsong* device);
};

#endif