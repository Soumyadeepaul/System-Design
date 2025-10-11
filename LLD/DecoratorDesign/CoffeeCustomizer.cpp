#include <bits/stdc++.h>
using namespace std;

class Coffee{
    public:
        virtual string getCoffee()=0;
        virtual int getCost()=0;
        virtual ~Coffee(){}
};

class PlainCoffee: public Coffee{
    string getCoffee()override{
        return "Plain Coffee";
    }
    int getCost(){
        return 50;
    }
};

class Decorator: public Coffee{  //is a 
    protected:
        Coffee* yourCoffee;     //has a
    public:
        Decorator(Coffee* customize){
            this->yourCoffee=customize;
        }
};

class Milk:public Decorator{
    public:
        Milk(Coffee* customize):Decorator(customize){}
        string getCoffee()override{
            return yourCoffee->getCoffee()+", Milk";
        }
        int getCost()override{
            return yourCoffee->getCost()+15;
        }
};

class Sugar:public Decorator{
    public:
        Sugar(Coffee* customize):Decorator(customize){}
        string getCoffee()override{
            return yourCoffee->getCoffee()+", Sugar";
        }
        int getCost()override{
            return yourCoffee->getCost()+5;
        }
};

class ChocolateSyrup:public Decorator{
    public:
        ChocolateSyrup(Coffee* customize):Decorator(customize){}
        string getCoffee()override{
            return yourCoffee->getCoffee()+", Chocolate Syrup";
        }
        int getCost()override{
            return yourCoffee->getCost()+20;
        }
};






int main(){
    Coffee* myCoffee=new PlainCoffee();
    cout<<"Initial Coffee: "<<myCoffee->getCoffee()<<endl;


    myCoffee=new Sugar(new Milk(myCoffee));
    cout<<"Description: "<<myCoffee->getCoffee()<<endl;
    cout<<"Price: "<<myCoffee->getCost()<<endl;
    delete myCoffee;
    return 0;
}



/*
[Sugar]
   yourCoffee ──▶ [Milk]
                       yourCoffee ──▶ [PlainCoffee]

*/