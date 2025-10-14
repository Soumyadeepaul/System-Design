#include <bits/stdc++.h>
using namespace std;

// Here we are treating Dish and Menu as MenuItem  as if like they are same
// Dish is leaf
// Menu is intermediate
class MenuItem{
    public:
        virtual void addDish(MenuItem* dish)=0;
        virtual void price()=0;
        virtual int getPrice(int show=0)=0;
        virtual void getMenu(int indent=0)=0;
        virtual ~MenuItem(){}
};

class Dish:public MenuItem{
    private:
        string name;
        int cost;
    public:
        Dish(string name,int price){
            this->name=name;
            cost=price;
        }
        void price()override{
            cout<<"Price: "<<cost<<endl;
        }
        int getPrice(int show)override{
            return cost;
        }
        void addDish(MenuItem* dish)override{
            cout<<"Cant add Dish under a Dish\n";
        }
        void getMenu(int indent)override{
            cout<<string(indent,' ')<<"-"<<name<<" ";
        }
};

class Menu: public MenuItem{
    private:
        string name;
        vector<MenuItem* > dishes;
    public:
        Menu(string name){
            this->name=name;
        }
        void addDish(MenuItem* dish)override{
            dishes.push_back(dish);
        }
        void price(){
        }
        int getPrice(int show=1)override{
            int cost=0;
            for(MenuItem* menu:dishes){
                cost+=menu->getPrice(0);
            }
            cout<<"Price for complete "<<name<<" menu: "<<cost<<endl;
            return cost;
        }
        void getMenu(int indent)override{
            cout<<string(indent,' ')<<"+"<<name<<endl;
            for(MenuItem* menu:dishes){
                menu->getMenu(indent+2);
                menu->price();
            }
        }

};

class Customer{
    public:
        virtual void order(vector<MenuItem*> order)=0;
        virtual void bill()=0;
        virtual ~Customer(){}
};

class ConcreteCustomer:public Customer{
    private:
        vector<MenuItem* > orderDishes;
        int cost=0;
    public:
        void order(vector<MenuItem*> order)override{
            this->orderDishes=order;
        }
        void bill()override{
            cout<<"-----Hotel Alakaza-----\n";
            for(MenuItem* dish:orderDishes){
                cost+=dish->getPrice();
                dish->getMenu(1);
                dish->price();
            }
            cout<<"  Bill Ammount: "<<cost<<endl;
            cout<<"-----Thank You-----";
            cost=0;
        }
};


int main(){
    MenuItem* menu=new Menu("Menu Alakaza");
    MenuItem* Breakfast=new Menu("Breakfast");
    MenuItem* salad=new Dish("Salad",120);
    MenuItem* oats=new Dish("Oats",100);
    Breakfast->addDish(salad);
    Breakfast->addDish(oats);
    menu->addDish(Breakfast);

    MenuItem* Lunch=new Menu("Lunch");
    MenuItem* rice=new Dish("Rice",80);
    MenuItem* dal=new Dish("Dal",50);
    MenuItem* sabji=new Dish("Sabji",140);
    Lunch->addDish(rice);
    Lunch->addDish(dal);
    Lunch->addDish(sabji);
    menu->addDish(Lunch);

    MenuItem* Dinner=new Menu("Dinner");
    MenuItem* roti=new Dish("Roti",10);
    MenuItem* panner=new Dish("Panner",200);
    Dinner->addDish(roti);
    Dinner->addDish(panner);

    MenuItem* Dessert=new Menu("Dessert");
    MenuItem* iceCream=new Dish("Ice Cream",60);
    MenuItem* soda=new Dish("Soda",30);
    Dessert->addDish(iceCream);
    Dessert->addDish(soda);
    Dinner->addDish(Dessert);
    menu->addDish(Dinner);

    /////////////////////////////////////////////////////////////////
    menu->getMenu();

    //menu->getPrice();
    ////////////////////////////////////////////////////////////////

    Customer* c1=new ConcreteCustomer();
    vector<MenuItem*> order={salad,rice,panner,iceCream};
    c1->order(order);
    c1->bill();








    ///////////////////////////////////////////////////////////////
    delete menu;
    delete Breakfast;
    delete salad;
    delete Lunch;
    delete sabji;
    delete Dinner;
    delete c1;
    delete rice;
    delete iceCream;
    delete soda;
    delete Dessert;
    delete panner;
    delete roti;
    delete oats;
    delete dal;
    return 0;
}