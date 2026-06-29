#include "packet.h"

using namespace std;

//---------------- Assign ----------------//

void Assign::setSender(Device* deviceReference){
    sender = deviceReference;
}

void Assign::setType(const string& requestType){
    type = requestType;
}

void Assign::setNeed(const string& deviceNeed){
    need = deviceNeed;
}

//---------------- Connect ----------------//

void Connect::setSender(Device* deviceReference){
    sender = deviceReference;
}

void Connect::setReceiver(Device* deviceReference){
    receiver = deviceReference;
}

void Connect::setType(const string& requestType){
    type = requestType;
}

//---------------- Data ----------------//

void Data::setSender(Device* deviceReference){
    sender = deviceReference;
}

void Data::setReceiver(Device* deviceReference){
    receiver = deviceReference;
}

void Data::setType(const string& requestType){
    type = requestType;
}

void Data::setNeed(const string& deviceNeed){
    need = deviceNeed;
}

void Data::setOperand(const string& dataOperand){
    operand = dataOperand;
}