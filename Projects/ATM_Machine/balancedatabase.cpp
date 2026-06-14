#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

BalanceDatabase& BalanceDatabase::getInstance() {
    static BalanceDatabase instance;
    return instance;
}

void BalanceDatabase::updateBalance(Card* card, Transaction* transaction) {
    balanceDatabase[card].push_back(transaction);
}

double BalanceDatabase::getBalance(Card* card) {
    vector<Transaction*> transactionLog = balanceDatabase[card];
    int logLength= transactionLog.size();
    double amountLeft=transactionLog[logLength-1]->getAmount(); // Assuming the last transaction amount is the total amount used
    return amountLeft;
}


vector<string> BalanceDatabase::createTransactionLog(Card* card){
    vector<string> transactionHistory={"TransactionLog:"};
    for(auto transaction:balanceDatabase[card]){
        transactionHistory.push_back(transaction->getTransactionLog());
    }
    transactionHistory.push_back("End.");
    return transactionHistory;
}

vector<string> BalanceDatabase::createTransactionLog(Card* card, int limit){
    vector<string> transactionHistory={"-----Transaction Log-----"};
    vector<Transaction*> &store=balanceDatabase[card];
    int length=store.size();
    int skip=0;
    if(limit<length){
        skip=length-limit; //how many to skip from start
    }
    for(int idx=skip;idx<length;idx++ ){
        transactionHistory.push_back(store[idx]->getTransactionLog());
    }
    transactionHistory.push_back("-----Transaction End-----");
    return transactionHistory;
}