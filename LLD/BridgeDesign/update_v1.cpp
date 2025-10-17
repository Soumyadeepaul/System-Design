#include <bits/stdc++.h>
using namespace std;

class Processors{
    public:
        virtual void perform()=0;
        virtual void pause()=0;
        virtual ~Processors(){}
};

class CPU: public Processors{
    private:
        bool working=false;
    public:
        void perform()override{
            if(working==true){
                cout<<"CPU already in use\n";
            }
            else{
                working=true;
                cout<<"CPU performing Task\n";
            }
        }
        void pause()override{
            working=false;
            cout<<"Task Paused\n";
        }
};

class GPU: public Processors{
    private:
        bool working=false;
    public:
        void perform()override{
            if(working==true){
                cout<<"GPU already in use\n";
            }
            else{
                working=true;
                cout<<"GPU performing Task\n";
            }
        }
        void pause()override{
            working=false;
            cout<<"Task Paused\n";
        }
};

class TPU: public Processors{
    private:
        bool working=false;
    public:
        void perform()override{
            if(working==true){
                cout<<"TPU already in use\n";
            }
            else{
                working=true;
                cout<<"TPU performing Task\n";
            }
        }
        void pause()override{
            working=false;
            cout<<"Task Paused\n";
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
        virtual void pause()=0;
        virtual void freeProcessor()=0;
        virtual ~Task(){}
        
};
class UsualTask:public Task{
    public:
        UsualTask(Processors* p):Task(p){}
        void perform()override{
            assign->perform();
        }
        void pause()override{
            assign->pause();
        }
        void freeProcessor()override{
            assign->pause();
            assign=nullptr;
            cout<<"Detached.\n";
        }
};

class RenderTask:public Task{
    public:
        RenderTask(Processors* p):Task(p){}
        void perform()override{
            assign->perform();
        }
        void pause()override{
            assign->pause();
        }
        void freeProcessor()override{
            assign->pause();
            assign=nullptr;
            cout<<"Detached.\n";
        }
};

class DeepLearningTask:public Task{
    public:
        DeepLearningTask(Processors* p):Task(p){}
        void perform()override{
            assign->perform();
        }
        void pause()override{
            assign->pause();
        }
        void freeProcessor()override{
            assign->pause();
            assign=nullptr;
            cout<<"Detached.\n";
        }
};


int main(){
    Processors* cpu1=new CPU();
    Processors* gpu1=new GPU();

    Task* t1=new RenderTask(gpu1); //task creating and assign the processor
    t1->perform();

    Task* t2=new RenderTask(gpu1);
    t2->perform(); //gpu under use

    t1->pause(); //free gpu

    t2->perform(); //gpu was free

    t1->freeProcessor();

    t2->freeProcessor();

    t1->perform();


    

    delete cpu1;
    delete gpu1;
    delete t1;
    delete t2;
    return 0;
}