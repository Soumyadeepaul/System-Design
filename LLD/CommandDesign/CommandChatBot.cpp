#include <bits/stdc++.h>

using namespace std;

class Spotify{
    private:
        string music;
    public:
        void play(string music){
            this->music=music;
            cout<< "Spotify Playing "+music+"\n";
        }
        void pause(){
            this->music="";
            cout<< "Music Stopped\n";
        }
        void check(){
            if(music=="") cout<<"No Track\n";
            else
            cout<<"Playing: "+music<<endl;
        }
};

class Gmail{
    public:
        void sendMail(string text){
            cout<< "Mail sent\n";
        }
        void deleteMail(){
            cout<< "Mail Deleted\n";
        }
        void check(){
            cout<<"Mail Can't checked";
        }
};

class Alarm{
    private:
        string time;
    public:
        void set(string text){
            time=text;
            cout<< "Alarm Set at "+text+"\n";
        }
        void off(){
            time="";
            cout<< "Alarm off\n";
        }
        void check(){
            if(time=="") cout<<"No alram set\n";
            else
            cout<<"Alarm is setted at "+time+"\n";
        }
};

class App{
    private:
        string app;
    public:
        void open(string text){
            app=text;
            cout<< "App: "+text+"\n";
        }
        void close(){
            app="";
            cout<< "App closed\n";
        }
        void check(){
            if(app=="") cout<<"No app in use\n";
            else
            cout<<"App in use "+app+"\n";
        }
};

class Command{
    public:
        virtual void execute(string text)=0;
        virtual void undo()=0;
        virtual void check()=0;
        virtual ~Command(){}
};

class MusicCommand: public Command{
    private:
        Spotify* spotify;
    public:
        MusicCommand(Spotify* s) {this->spotify=s;}
        void execute(string text) override{
            spotify->play(text);
        }
        void undo() override{
            spotify->pause();
        }
        void check(){
            spotify->check();
        }

};

class MailCommand: public Command{
    private:
        Gmail* gmail;
    public:
        MailCommand(Gmail* g) {gmail=g;}
        void execute(string text) override{
            gmail->sendMail(text);
        }
        void undo() override{
            gmail->deleteMail();
        }
        void check(){
            gmail->check();
        }
};

class AlarmCommand: public Command{
    private:
        Alarm* alarm;
    public:
        AlarmCommand(Alarm* a) {alarm=a;}
        void execute(string text) override{
            alarm->set(text);
        }
        void undo() override{
            alarm->off();
        }
        void check(){
            alarm->check();
        }
};

class AppCommand: public Command{
    private:
        App* app;
    public:
        AppCommand(App* a) {app=a;}
        void execute(string text) override{
            app->open(text);
        }
        void undo() override{
            app->close();
        }
        void check(){
            app->check();
        }
};


class Controler{
    private:
        unordered_map<Command*,bool> tracker;
    public:
        void setCommand(Command* command){
            if(tracker.find(command)!=tracker.end()) cout<<"Command Already set.\n";
            else {
                tracker[command]=false;
                cout<<"Command Set.\n";
            }
        }
        void removeCommand(Command* command){
            tracker.erase(command);
            cout<<"Command Removed\n";
        }
        void useCommand(Command* command,string text){
            if(tracker[command]==true) cout<< "Command already in use.\n";
            else{
                tracker[command]=true;
                command->execute(text);
            }
        }
        void undoCommand(Command* command){
            if(tracker[command]==false) cout<< "Command not in use.\n";
            else{
                tracker[command]=false;
                command->undo();
            }
        }
        void check(Command* command){
            if(tracker.find(command)==tracker.end()) cout<<"Command Invalid.\n";
            else{
                command->check();
            }
        }
};


int main(){

    Spotify* mySpotify=new Spotify();
    App* myApp=new App();
    Alarm* myAlarm=new Alarm();
    Gmail* myMail=new Gmail();
    Command* m=new MusicCommand(mySpotify);
    Command *a=new AppCommand(myApp);
    Command* g=new MailCommand(myMail);
    Command* c=new AlarmCommand(myAlarm);

    Controler* remote=new Controler();
    remote->setCommand(m);
    remote->setCommand(a);
    remote->setCommand(g);
    remote->setCommand(m);

    remote->useCommand(m,"Kal Ho Na Ho");
    remote->useCommand(a,"LinkedIn");
    remote->useCommand(g,"");
    remote->check(m);
    remote->undoCommand(m);

    remote->check(a);
    remote->check(c); //invalid beacuse not set in remote
    remote->check(m);

    remote->removeCommand(m);
    remote->removeCommand(c);

    delete m;
    delete a;
    delete g;
    delete c;
    delete myAlarm;
    delete mySpotify;
    delete myApp;
    delete myMail;
    delete remote;

    return 0;
}
