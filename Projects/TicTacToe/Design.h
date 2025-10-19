#ifndef DESIGN_H
#define DESIGN_H
#include <bits/stdc++.h>
using namespace std;

class Board {
private:
    vector<vector<string>> board;
public:
    void createBoard(const int size);
    vector<vector<string>> getBoard();
    void updateBoard(vector<vector<string>> b);
;};

class DisplayBoard {
public:
    void displayBoard(Board b);
};

class Symbol{
private:
    string symbol;

public:
    Symbol(string s);
    string getSymbol();
};


class Manager;
class Players;

class GameStrategy{
    public:
        virtual int rules(Board b,Players p,int r,int c)=0;
        virtual ~GameStrategy() = default;
};

class Rule1:public GameStrategy{
    public:
        int rules(Board b,Players p,int r,int c)override;
};

class Rule2:public GameStrategy{
    public:
        int rules(Board b,Players p,int r,int c)override;
};


class Game{
private:
    int count=0;
    GameStrategy *strategy;   //object of abstruct class is not allowed
public:
    void setgameStrategy(GameStrategy &s);
    int play(Board &b,Players p,int r,int c);// & beacuse it need to be updated
    
};


class Players{
private:
    Symbol symbol;
    string name;
public:
    
    Players(string s,Symbol sym);
    string getName();
    string getSymbol();
};
class Manager{
private:
    deque<Players> turn;
    Board board;
    Game g;
    Rule1 r1;
    Rule2 r2;
    DisplayBoard display;
    int strategyNumber;
public:
    Manager(vector<Players> players,int size,int gs);
    void addPlayers(Players);
    void start();
};

class Initializer{
public:
    pair<vector<Players>,vector<int>> initializer();
};

class API{
public:
    void tictactoe();
};


#endif
