#include "Design.h"
#include<bits/stdc++.h>
using namespace std;


void Board::createBoard(const int size) {
    vector<vector<string>> b(size, vector<string>(size, "_"));
    this->board=b;
}

void Board:: updateBoard(vector<vector<string>> b){
    this->board=b;
}

vector<vector<string>>Board:: getBoard(){
    return this->board;
}

void DisplayBoard::displayBoard(Board b){
    vector<vector<string>> boardMap=b.getBoard();
    for(int i=0;i<boardMap.size();i++){
        for(int j=0;j<boardMap[0].size();j++){
            cout<<boardMap[i][j]<<" ";
        }
        cout<<"\n";
    }
}

Symbol::Symbol(string s):symbol(s){}


string Symbol::getSymbol(){
    return this->symbol;
}


int Rule1::rules(Board b,Players p,int r,int c){
    // ALGO
    //row check
    int j=0;
    vector<vector<string>> board=b.getBoard();
    int l=board[0].size();
    while(j<l){
        if(board[r][j]!=p.getSymbol()){
            break;
        }
        j++;
    }
    if(j==l) return 1;
    //col check
    int i=0;
    while(i<l){
        if(board[i][c]!=p.getSymbol()){
            break;
        }
        i++;
    }
    if(i==l) return 1;

   
    //diagonal check
    //left up diagonal + right down diagonal
    i=0;
    while(i<l){
        if(board[i][i]!=p.getSymbol()){
            break;
        }
        i++;
    }
    if(i==l) return 1;
    //right up diagonal + left down diagonal
    j=l-1;
    while(j>-1){
        if(board[l-1-j][j]!=p.getSymbol()){
            break;
        }
        j--;
    }
    if(j==-1) return 1;
    return 0;
};


int Rule2::rules(Board b,Players p,int r,int c){
    // ALGO
    //row check
    int j=0;
    vector<vector<string>> board=b.getBoard();
    int l=board[0].size();
    while(j<l){
        if(board[r][j]!=p.getSymbol()){
            break;
        }
        j++;
    }
    if(j==l) return 1;
    //col check
    int i=0;
    while(i<l){
        if(board[i][c]!=p.getSymbol()){
            break;
        }
        i++;
    }
    if(i==l) return 1;
 
    return 0;
};

void Game::setgameStrategy(GameStrategy &s){
    strategy=&s;
}

int Game::play(Board &b,Players p,int r,int c){
    vector<vector<string>> boardMap=b.getBoard();
    if(r>-1 && c>-1 && r<boardMap.size() && c<boardMap[0].size()){
        if(boardMap[r][c]=="_"){
            boardMap[r][c]=p.getSymbol();
            count++;
            b.updateBoard(boardMap); // b is the reference by address
            int val=strategy->rules(b,p,r,c); //pointer  as object of constructor not allowed....
            if(val==1) return val;
            //draw condition
            else{
                if(count==pow(boardMap.size(),2)) return 4;
            }
        }
        else{
            cout<<"Foul..Lost your turn!\n";
            return 2;
        }
    }
    else{
        cout<<"Invalid Position..Try Again\n";
        return 3;
    }
    return false;
}



Players::Players(string s,Symbol sym):name(s),symbol(sym){
}

string Players::getSymbol(){
    return symbol.getSymbol();
}

string Players::getName(){
    return name;
}


void Manager::addPlayers(Players p){
    turn.push_back(p);
}



Manager::Manager(vector<Players> players,int size,int gs):strategyNumber(gs){
    //board created
    Board b;
    b.createBoard(size);
    board=b;
    //players added
    for(Players p:players){
        addPlayers(p);
    }

}
void Manager::start(){
    // manager sends the game with its strategy
    if(strategyNumber==2){
        g.setgameStrategy(r2);
    }
    else{
        g.setgameStrategy(r1);
    }

    while(!turn.empty()){
        Players p=turn.front();
        turn.pop_front();
        turn.push_back(p);
        cout<<"Its Your Turn "<<p.getName()<<endl;
        display.displayBoard(board);
        cout<<"Enter x coordinate: ";
        int x;
        cin>>x;
        cout<<"Enter y coordinate: ";
        int y;
        cin>>y;
        int valid=g.play(board,p,x,y);  //strategy has already defined
        if(valid==1){
            turn.clear();
            cout<<p.getName()<<" wins the match\n";
            display.displayBoard(board);
        }
        if(valid==3){
            turn.push_front(p);
            turn.pop_back();
        }
        if(valid==4){//draw
            turn.clear();
            cout<<"MATCH Draw!!\n";
            display.displayBoard(board);
        }
    }
    cout<<"\nThank You For Playing\n";
}



pair<vector<Players>,vector<int>>Initializer:: initializer(){
    cout<<"Welcome to Tic Tac Toe\n";
    cout<<"Enter the number of players want to play: ";
    int number;
    cin>>number;
    vector<Players> players;
    string p;
    string s;
    while(number){
        cout<<"Enter player name: ";
        cin>>p;
        cout<<"Enter your symbol: ";
        cin>>s;
        players.push_back(Players(p,Symbol (s)));
        number--;
    }
    int size;
    cout<<"Enter the board Size: ";
    cin>>size;
    cout<<"Select Strategy 1/2: ";
    int gs;
    cin>>gs;
    return {players,{size,gs}};
}


void API:: tictactoe(){
    Initializer i;
        auto [players, sgs] = i.initializer();
        Manager m(players,sgs.at(0),sgs.at(1));
        m.start();
}