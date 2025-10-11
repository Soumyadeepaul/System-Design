#include <bits/stdc++.h>
using namespace std;

/*Design a simple weather monitoring system using the Observer Design Pattern where multiple display elements (like current temperature, humidity, and pressure) update automatically when the weather data changes. Explain your design and how the Observer pattern helps in this scenario.*/



class Concrete;

class Observer{
    public:
        virtual void addLocation(Concrete*,string)=0;
        virtual void removeLocation(Concrete*)=0;
        virtual void notify(Concrete* )=0;
        virtual ~Observer(){}
};


class Location {
public:
    virtual void temperature(int) = 0;
    virtual void humidity(int) = 0;
    virtual void pressure(int) = 0;
    virtual void addFollowers(Observer*) = 0;
    virtual void removeFollowers(Observer*) = 0;
    virtual vector<int> updatedWeather()=0;
    virtual ~Location() {}
};

class Concrete:public Location{
    private:
        int temp;
        int humid;
        int pres;
        vector<Observer*> followers;
    public:
        Concrete(int temp,int humid,int pres){
            this->temp=temp;
            this->humid=humid;
            this->pres=pres;
        }
        void temperature(int temp)override{
            this->temp=temp;
            cout<<"Temperature is updated.\n";
            for(Observer* i:followers){
                i->notify(this);
            }
        }
        void humidity(int humid)override{
            this->humid=humid;
            cout<<"Humidity is updated.\n";
            for(Observer* i:followers){
                i->notify(this);
            }
        }
        void pressure(int pres)override{
            this->pres=pres;
            cout<<"Pressure is updated.\n";
            for(Observer* i:followers){
                i->notify(this);
            }
        }
        void addFollowers(Observer* a)override{
            if(find(followers.begin(),followers.end(),a)==followers.end()){
                followers.push_back(a);
                cout<<"New follower.\n";
            }
        }

        void removeFollowers(Observer* a)override{
            auto it=find(followers.begin(),followers.end(),a);
            if(it!=followers.end()){
                followers.erase(it);
                cout<<"Follower removed.\n";
            }
        }

        vector<int> updatedWeather(){
            return {this->temp,this->humid,this->pres};
        }
};





class A:public Observer{
    private:
        unordered_map<Concrete*,string> cart;
    public:
        void addLocation(Concrete* l,string loc)override{
            if(cart.find(l)==cart.end()){
                cart[l]=loc;
                l->addFollowers(this);
                cout<<"Added Successfully.\n";
            }
            else{
                cout<<"You already follow the location.\n";
            }
        }
        void removeLocation(Concrete* l)override{
            if(cart.find(l)!=cart.end()){
                cart.erase(l);
                l->removeFollowers(this);
                cout<<"Removed Successfully.\n";
            }
            else{
                cout<<"You dont follow the location.\n";
            }
        }
        void notify(Concrete* c)override{
            cout<<"NOTIFIED\n";
            vector<int> get;
            get=c->updatedWeather();
            cout<<cart[c]<<" "<<get[0]<<" "<<get[1]<<" "<<get[2]<<" "<<endl;

        }
        
};




int main(){
    Concrete* kolkata=new Concrete(30,80,1000);
    

    Concrete* delhi=new Concrete(50,70,1008);
    


    Observer* person1=new A();
    person1->addLocation(kolkata,"KOLKATA");

    kolkata->temperature(29);

    // person1->addLocation(kolkata);
    person1->removeLocation(kolkata);

    kolkata->temperature(30);

    person1->addLocation(delhi,"DELHI");

    



    Observer* person2=new A();
    person2->addLocation(delhi,"DELHI");
    delhi->temperature(55);
    person2->removeLocation(delhi);

    delete kolkata;
    delete delhi;
    delete person1;
    delete person2;

    return 0;
}