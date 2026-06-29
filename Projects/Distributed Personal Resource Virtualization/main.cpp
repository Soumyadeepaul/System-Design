#include "minimalDevice.h"
#include "flagshipDevice.h"

using namespace std;

int main(){

    /**************************************************
     *      Distributed Personal Resource Virtualization
     **************************************************/

    //---------------- Controller ----------------//

    FlagshipSamsong controller;
    controller.setSpecs("Samsong S25 Controller",
                        "192.168.1.1",
                        64,
                        8);

    //---------------- Worker Devices ------------//

    FlagshipSamsong worker1;
    worker1.setSpecs("Samsong S25+",
                     "192.168.1.2",
                     64,
                     8);

    FlagshipSamsong worker2;
    worker2.setSpecs("Samsong S25 Ultra",
                     "192.168.1.3",
                     64,
                     8);

    //---------------- Client Devices ------------//

    Samsong client1;
    client1.setSpecs("Samsong M21",
                     "192.168.1.10",
                     32,
                     2);

    Samsong client2;
    client2.setSpecs("Samsong A54",
                     "192.168.1.11",
                     32,
                     2);

    //---------------- Registration --------------//

    controller.addFlagshipDevice(&worker1);
    controller.addFlagshipDevice(&worker2);

    controller.addMinimalDevice(&client1);
    controller.addMinimalDevice(&client2);

    client1.setFlagship(&controller);
    client2.setFlagship(&controller);

    //---------------- Cluster Information -------//

    client1.useDisplay("==============================================");
    client1.useDisplay(" Distributed Personal Resource Virtualization ");
    client1.useDisplay("==============================================");

    client1.useDisplay("Controller : " + controller.getModel());
    client1.useDisplay("Worker 1   : " + worker1.getModel());
    client1.useDisplay("Worker 2   : " + worker2.getModel());

    client1.useDisplay("----------------------------------------------");

    client1.useDisplay("Client 1 : " + client1.getModel());
    client1.useDisplay("Client 2 : " + client2.getModel());

    client1.useDisplay("==============================================");

    /**************************************************
     *                Task Execution
     **************************************************/

    client1.useDisplay("\n[Client-1] Requesting Calculation Task");
    client1.requestTask("Calculation",
                        "10 20 + 5 * 3 -");

    client2.useDisplay("\n[Client-2] Requesting Render Task");
    client2.requestTask("Render",
                        "1 1 3 4 1");

    client1.useDisplay("\n[Client-1] Requesting Render Task");
    client1.requestTask("Render",
                        "ab cd ef gh");

    client2.useDisplay("\n[Client-2] Requesting Calculation Task");
    client2.requestTask("Calculation",
                        "50 25 / 10 +");

    client1.useDisplay("\n[Client-1] Requesting Calculation Task");
    client1.requestTask("Calculation",
                        "8 2 * 5 +");

    client2.useDisplay("\n[Client-2] Requesting Render Task");
    client2.requestTask("Render",
                        "Distributed System");

    client1.useDisplay("\n==============================================");
    client1.useDisplay("     Demonstration Completed Successfully");
    client1.useDisplay("==============================================");

    return 0;
}