#include <bits/stdc++.h>
using namespace std;

class Vehicle{
public:
    virtual void drive(){};
    virtual ~Vehicle(){}
};

class Car:public Vehicle{
    public:
    void drive(){
        cout<<"Car is ready;"<<endl;
    }
};

class Bike:public Vehicle{
    public:
    void drive(){
        cout<<"Bike is ready;"<<endl;
    }
};

class Truck:public Vehicle{
    public:
    void drive(){
        cout<<"Truck is ready;"<<endl;
    }
};
class objectGenerator{ //responsible of creating objects in runtime

    public:
        Vehicle* getType(string type){
            if(type=="Car"){
                return new Car;
            }
            if(type=="Bike"){
                return new Bike;
            }
            if(type=="Truck"){
                return new Truck;
            }
        }
};
class VehicleFactory{
    private:
        Vehicle* object;
        string type;
    public:
    Vehicle* get_vehicle(string type){
        this->type=type;
        objectGenerator o;
        return o.getType(this->type);
    }
};


int main(){
    string c="Car";
    string b="Bike";
    string t="Truck";
    VehicleFactory* vehicle=new VehicleFactory();
    Vehicle* newCar=vehicle->get_vehicle(c);
    newCar->drive();

    Vehicle* newBike=vehicle->get_vehicle(b);
    newBike->drive();

    Vehicle* newTruck=vehicle->get_vehicle(t);
    newTruck->drive();
    
    return 0;
}
