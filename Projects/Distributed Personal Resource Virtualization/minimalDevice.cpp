#include "minimalDevice.h"
#include "packet.h"
#include "flagshipDevice.h"

using namespace std;

//---------------------------------------------------
// Device Information
//---------------------------------------------------

void Samsong::setSpecs(string model,
                       string staticIP,
                       int memory,
                       int totalCores){

    specs.model = model;
    specs.staticIP = staticIP;
    specs.memory = memory;
    specs.memoryUnderUse = 0;

    for(int i=0;i<totalCores;i++){
        specs.cores.push_back(new Core());
    }
}

string Samsong::getModel(){
    return "Model : " + specs.model;
}

string Samsong::getMemory(){
    return to_string(specs.memory);
}

string Samsong::getSpace(){
    return to_string(specs.memory - specs.memoryUnderUse);
}

string Samsong::useSpace(float memory){

    if(memory > specs.memory - specs.memoryUnderUse)
        return "Memory Full";

    specs.memoryUnderUse += memory;

    return "Memory Allocated";
}

string Samsong::releaseSpace(float memory){

    specs.memoryUnderUse -= memory;

    return "Memory Released";
}

bool Samsong::checkCore(){

    for(auto core : specs.cores){

        if(core->status()==0)
            return true;
    }

    return false;
}

string Samsong::performTask(string need,
                            string operand){
    int coreNum=1;
    for(auto core : specs.cores){

        if(core->status()==0){
            cout<<this->specs.model+" is using core "+to_string(coreNum)+"\n";
            return core->assign(need,operand);
        }
        coreNum++;
    }

    return "No Free Core";
}

void Samsong::useDisplay(string output){

    display.print(output);
}

//---------------------------------------------------
// Template Method Functions
//---------------------------------------------------

void Samsong::setFlagship(FlagshipSamsong* device){

    flagship = device;
}

Assign Samsong::createAssignPacket(string need){

    Assign packet;

    packet.setSender(this);
    packet.setNeed(need);
    packet.setType("Assign");

    return packet;
}

Connect Samsong::sendAssignPacket(Assign packet){

    return flagship->receiver(packet);
}

Data Samsong::createDataPacket(Connect packet,
                               string need,
                               string operand){

    Data dataPacket;

    dataPacket.setSender(this);
    dataPacket.setReceiver(packet.getReceiver());

    dataPacket.setNeed(need);
    dataPacket.setOperand(operand);

    dataPacket.setType("Data");

    return dataPacket;
}

string Samsong::sendDataPacket(Data packet){

    Data reply = flagship->receiver(packet);

    return reply.getOperand();
}


void Device::requestTask(string need, string operand){

    Assign assignPacket = createAssignPacket(need);

    Connect connectPacket = sendAssignPacket(assignPacket);

    Data dataPacket = createDataPacket(connectPacket,
                                       need,
                                       operand);

    string result = sendDataPacket(dataPacket);

    useDisplay(result);
}