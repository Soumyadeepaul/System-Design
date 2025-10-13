#include <bits/stdc++.h>
using namespace std;
class Music{
public:
    virtual void start() = 0;
    virtual ~Music() {}
};
class MP3:public Music{
    private:
        string music;
    public:
        MP3(string s){
            music=s;
        }
        void start()override{
            cout<<"Now Playing: "+music+".mp3\n";
        }
};

class AdvanceMusic{
    public:
    virtual void start() = 0;
    virtual ~AdvanceMusic() {}
};
class MP4:public AdvanceMusic{
    private:
        string music;
    public:
        MP4(string s){
            music=s;
        }
        void start()override{
            cout<<"Now Playing: "+music+".mp4\n";
        }
};

class VLC:public AdvanceMusic{
    private:
        string music;
    public:
        VLC(string s){
            music=s;
        }
        void start()override{
            cout<<"Now Playing: "+music+".vlc\n";
        }
};

class MKV:public AdvanceMusic{
    private:
        string music;
    public:
        MKV(string s){
            music=s;
        }
        void start()override{
            cout<<"Now Playing: "+music+".mkv\n";
        }
};


//ADAPTER
class MediaPlayer{
    public:
    virtual void play(Music* m) = 0;
    virtual void play(AdvanceMusic* m)=0;
    virtual ~MediaPlayer() {}
};
//ADAPTER CONCRETE CLASS
class Remote : public MediaPlayer {
private:
    unordered_map<string, string> mapMusicType;
public:
    void play(Music* m) override {
        if (m) m->start();
        else cout << "No music to play!\n";
    }
    void play(AdvanceMusic* m) override{
        if (m) m->start();
        else cout << "No music to play!\n";
    }
};

int main() {
    Music* music1 = new MP3("Kal Ho Na Ho");
    AdvanceMusic* music2 = new MP4("Oh Khuda");
    AdvanceMusic* music3 = new VLC("Ek Din");
    AdvanceMusic* music4 = new MKV("Blue Eyes");

    MediaPlayer* myPlayer = new Remote();
    myPlayer->play(music1);

    myPlayer->play(music3);

    delete music1;
    delete music2;
    delete music3;
    delete music4;
    delete myPlayer;

    return 0;
}