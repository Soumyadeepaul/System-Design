#include <bits/stdc++.h>
using namespace std;
class car{
    private:
        void privateMethod(){
            cout<<"PrivateMethod\n";
        }
    public:
        void publicMethod(){
            cout<<"Public Method\n";
        }
        void publicMethod(int x){
            cout<<"Overload\n";
        }
};
class Supercar:car{
public:
    void publicMethod(){
        cout<<"Override\n";
    }
    void privateMethod(){
        cout<<"Self Private\n";
    }

};
class Supercar1:public car{
public:

};
int main(){
    Supercar* car1=new Supercar();
    car1->publicMethod();
    car1->privateMethod();

    Supercar1* car2=new Supercar1();
    car2->publicMethod();
    car2->publicMethod(10);
    //car2->privateMethod(); // will give error private method cant be accessed by subclass

    return 0;
}
