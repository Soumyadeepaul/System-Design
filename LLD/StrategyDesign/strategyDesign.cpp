#include <bits/stdc++.h>
using namespace std;

class Vehicle{
public:
    virtual void drive(){};
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

class VehicleFactory{
    private:
        Vehicle* object;
    public:
    void get_vehicle(Vehicle* type){
        object=type;
        object->drive();
    }
};


int main(){
    Car c;
    Bike b;
    Truck t;
    VehicleFactory vechile;
    vechile.get_vehicle(&c);
    vechile.get_vehicle(&b);
    vechile.get_vehicle(&t);
    return 0;
}
