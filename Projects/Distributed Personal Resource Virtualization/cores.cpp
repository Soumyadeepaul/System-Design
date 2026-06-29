#include "cores.h"
#include <bits/stdc++.h>
using namespace std;


double ALU::compute(double a, double b, char op){
    switch (op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            if(b==0) return 0;
            return a/b;
        default:
            return 0;
    }
    return 0;
}

string Render::feedIn(string frames) {
    stringstream ss(frames);
    string token;
    string result;

    while (ss >> token) {
        result += token;
    }

    return result;
}

string Calculator::feedIn(string postfix){
    stack<double> st;
    stringstream ss(postfix);
    string token;

    while(ss >> token){
        // Number
        if(isdigit(token[0]) || (token.size() > 1 && token[0] == '-')){
            st.push(stod(token));
        }
        else{
            if(st.size() < 2)
                throw runtime_error("Invalid Postfix Expression");

            double b = st.top(); st.pop();
            double a = st.top(); st.pop();

            st.push(compute(a, b, token[0]));
        }
    }

    if(st.size() != 1)
        throw runtime_error("Invalid Postfix Expression");

    return to_string(st.top());
}

bool Core::status(){
    return getState();
}

string Core:: assign(string need, string operand){
    setState(); //using   --- lock

    string result="";
    if(need=="Render"){
        Render r;
        result=r.feedIn(operand);
    }
    else if(need=="Calculator"){
        Calculator c;
        result=c.feedIn(operand);
    }
    // setState(); //free    --- unlock

    return result;
}