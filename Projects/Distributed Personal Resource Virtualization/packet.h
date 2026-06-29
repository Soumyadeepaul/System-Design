#ifndef PACKET_H
#define PACKET_H

#include <string>
#include "minimalDevice.h"

using namespace std;

class Packet{
public:
    virtual ~Packet() = default;
};

class Assign : public Packet{
private:
    Device* sender = nullptr;
    string type;
    string need;

public:
    void setSender(Device* deviceReference);
    void setType(const string& requestType);
    void setNeed(const string& deviceNeed);

    Device* getSender() const { return sender; }
    string getType() const { return type; }
    string getNeed() const { return need; }
};

class Connect : public Packet{
private:
    Device* sender = nullptr;
    Device* receiver = nullptr;
    string type;

public:
    void setSender(Device* deviceReference);
    void setReceiver(Device* deviceReference);
    void setType(const string& requestType);

    Device* getSender() const { return sender; }
    Device* getReceiver() const { return receiver; }
    string getType() const { return type; }
};

class Data : public Packet{
private:
    Device* sender = nullptr;
    Device* receiver = nullptr;
    string type;
    string need;
    string operand;

public:
    void setSender(Device* deviceReference);
    void setReceiver(Device* deviceReference);
    void setType(const string& requestType);
    void setNeed(const string& deviceNeed);
    void setOperand(const string& dataOperand);

    Device* getSender() const { return sender; }
    Device* getReceiver() const { return receiver; }
    string getType() const { return type; }
    string getNeed() const { return need; }
    string getOperand() const { return operand; }
};




#endif