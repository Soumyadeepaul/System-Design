#include <bits/stdc++.h>
using namespace std;
class car{ //abstruction
public:
    virtual void getTopSpeed()=0;   //without this we cant access methods of child class in main
    virtual void startEngineSetInitialSpeed(int speed)=0;
    virtual void accelerate(int speed)=0;
    virtual void stopCar()=0;
    virtual ~car(){}
    
};
class Supercar:public car{
private: //encapslation -> cant be modified from outside
    string brand;
    int capacity;
    int topSpeed;
    bool start;
    bool stop;
    int speed;
public:
    Supercar(string brand,int capacity,int topSpeed){
        this->brand=brand;
        this->capacity=capacity;
        this->topSpeed=topSpeed;
        this->start=false;
        this->stop=true;
        this->speed=0;
    }
    void getTopSpeed(){ //getter
        cout<<"Top Speed: "<<this->topSpeed<<endl;;
    }
    void startEngineSetInitialSpeed(int speed){ //setter
        if(this->start!=true){
            this->start=true;
            this->speed=speed;
            cout<<"Car started"<<endl;
            this->stop=false;
        }
        else{
            cout<<"Car already started before\n";
        }
    }
    void accelerate(int speed){
        if(this->start==false){
            cout<<"Car not started\n";
        }
        else if(speed+this->speed>this->topSpeed){
            cout<<"Cant increase speed\n";
        }
        else{
            this->speed+=speed;
            cout<<"Current speed is: "<<this->speed<<endl;
        }
    }
    void stopCar(){
        if(this->stop==true){
            cout<<"Car was already stopped\n";
        }
        else{
            this->stop=true;
            this->start=false;
            this->speed=0;
            cout<<"Car Stopped\n";
        }
    }

};
int main(){
    car* car1=new Supercar("Tata",4,50);
    car1->getTopSpeed();
    car1->accelerate(10);
    car1->startEngineSetInitialSpeed(20);
    car1->startEngineSetInitialSpeed(20);
    car1->accelerate(20);
    car1->startEngineSetInitialSpeed(20);
    car1->accelerate(20);
    car1->accelerate(10);
    car1->stopCar();
    car1->stopCar();
    car1->startEngineSetInitialSpeed(10);
    car1->stopCar();
    delete car1;

    return 0;
}
