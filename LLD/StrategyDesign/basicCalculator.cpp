//SRATEGY DESIGN PATTERN

#include <bits/stdc++.h>

using namespace std;

class Operator{
    public:
        virtual int operation(int a,int b)=0;
        virtual ~Operator(){}

};
class Add: public Operator{
    public:
        int operation(int a,int b) override{
            cout<<"Added: "<<a+b<<endl;
            return a+b;
        }
};

class Sub: public Operator{
    public:
        int operation(int a,int b) override{
            cout<<"Sub: "<<a-b<<endl;
            return a-b;
        }
};

class Mul: public Operator{
    public:
        int operation(int a,int b) override{
            cout<<"Mul: "<<a*b<<endl;
            return a*b;
        }
};

class Calculator{
    private:
        Operator* operate; //which operator to use
        int a;
        int b;
    public:
        // int a;  
        Calculator(){
        }
        void Opt(Operator* newOperate){//setter of operator
            operate=newOperate;
        }
        void setA(int val){a=val;}
        void setB(int val){b=val;}
        void operation(){
            if(operate){
                a=operate->operation(a,b);//storing back in a
            }
            else{
                cout<<"Cant perform\n";
            }
        }
};
int main(){
    Add add;
    Sub sub;
    Mul mul;
    Calculator perform;
    perform.setA(10);
    perform.setB(20);
    perform.Opt(&add);
    perform.operation();
    perform.operation();
    perform.Opt(&sub);
    perform.operation();
    perform.Opt(&mul);
    perform.operation();
    // perform.a=100;
    // cout<<perform.a;
    // perform.Opt(&add);
    // perform.operation();
    return 0;

}