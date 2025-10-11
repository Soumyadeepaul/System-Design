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


class PlainCoffeeGenerator{
    public:
        Coffee* getIt(){
            return new PlainCoffee;
        }
};
class CoffeeGenerator{
    public:
        Coffee* getIt(string type, Coffee* customizer){
            if(type=="Milk") return new Milk(customizer);
            else if(type=="Sugar") return new Sugar(customizer);
            else if(type=="ChocolateSyrup") return new ChocolateSyrup(customizer);
            return nullptr;
        }
};


class CoffeeFactory{
    private:
        Coffee* customizer;
    public:
        Coffee* prepare(string type){
            if(type=="Plain Coffee"){
                PlainCoffeeGenerator pg;
                customizer=pg.getIt();
            }
            else{
                CoffeeGenerator cg;
                customizer=cg.getIt(type,customizer);
            }
            return customizer;
        }        

};




int main(){


    string coffee="Plain Coffee";
    string addon1="Milk";
    string addon2="Sugar";
    string addon3="ChocolateSyrup";
    CoffeeFactory* factory=new CoffeeFactory();
    Coffee* myCoffee=factory->prepare(coffee);
    cout<<"Description: "<<myCoffee->getCoffee()<<endl;
    cout<<"Price: "<<myCoffee->getCost()<<endl;
    delete myCoffee;

    Coffee* myCoffee1=factory->prepare(coffee);
    myCoffee1=factory->prepare(addon1);
    myCoffee1=factory->prepare(addon3);
    cout<<"Description: "<<myCoffee1->getCoffee()<<endl;
    cout<<"Price: "<<myCoffee1->getCost()<<endl;
    return 0;
}



