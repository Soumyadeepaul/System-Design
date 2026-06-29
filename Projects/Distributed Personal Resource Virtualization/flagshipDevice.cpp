#include "flagshipDevice.h"

using namespace std;

void FlagshipSamsong::addFlagshipDevice(Device* device){
    flagshipDevices.push_back(device);
}

void FlagshipSamsong::addMinimalDevice(Device* device){
    minimalDevices.push_back(device);
}

//-----------------------------------------------------
// Receive Assign Packet
//-----------------------------------------------------
Connect FlagshipSamsong::receiver(Assign packet){

    Connect connectPacket;

    // Check whether sender is a registered minimal device
    if(find(minimalDevices.begin(),
            minimalDevices.end(),
            packet.getSender()) == minimalDevices.end()){

        cout << "Unknown Device Request" << endl;
        return connectPacket;
    }

    int total = flagshipDevices.size();

    for(int i = 0; i < total; i++){

        int index = (nextDevice + i) % total;

        Device* device = flagshipDevices[index];

        if(device->checkCore()){

            connectPacket.setSender(packet.getSender());
            connectPacket.setReceiver(device);
            connectPacket.setType("Connect");

            // Round Robin
            nextDevice = (index + 1) % total;

            return connectPacket;
        }
    }

    cout << "No Free Flagship Device Available" << endl;

    return connectPacket;
}
//-----------------------------------------------------
// Receive Data Packet
//-----------------------------------------------------

Data FlagshipSamsong::receiver(Data packet){

    string result = packet.getReceiver()->performTask(
                        packet.getNeed(),
                        packet.getOperand());

    // Reuse the same packet as a reply
    packet.setSender(packet.getReceiver());
    packet.setReceiver(packet.getSender());
    packet.setOperand(result);

    return packet;
}