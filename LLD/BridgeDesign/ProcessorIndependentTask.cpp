#include <bits/stdc++.h>
using namespace std;

class Processors{
    public:
        virtual void perform()=0;
        virtual ~Processors(){}
};

class CPU: public Processors{
    public:
        void perform()override{
            cout<<"CPU performing Task\n";
        }
};

class GPU: public Processors{
    public:
        void perform()override{
            cout<<"GPU performing Task\n";
        }
};

class TPU: public Processors{
    public:
        void perform()override{
            cout<<"TPU performing Task\n";
        }
};


class Task{
    protected:
        Processors* assign;
    public:
        Task(Processors* p){
            assign=p;
        }
        virtual void perform()=0;
        virtual ~Task(){}
        
};
class UsualTask:public Task{
    public:
        UsualTask(Processors* p):Task(p){}
        void perform()override{
            assign->perform();
        }
};

class RenderTask:public Task{
    public:
        RenderTask(Processors* p):Task(p){}
        void perform()override{
            assign->perform();
        }
};

class DeepLearningTask:public Task{
    public:
        DeepLearningTask(Processors* p):Task(p){}
        void perform()override{
            assign->perform();
        }
};


int main(){
    Processors* cpu1=new CPU();
    Processors* gpu1=new GPU();

    Task* t1=new RenderTask(gpu1); //task creating and assign the processor
    t1->perform();

    Task* t2=new RenderTask(gpu1);
    t2->perform();

    

    delete cpu1;
    delete gpu1;
    delete t1;
    delete t2;
    return 0;
}