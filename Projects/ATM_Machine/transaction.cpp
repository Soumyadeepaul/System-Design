#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

Transaction* TransactionFactory:: createTransaction(double amount, string type, bool isSuccessful, double cardBalance) {
    return new Transaction(amount, type, isSuccessful, cardBalance);
}

Transaction::Transaction(double amount, string type, bool isSuccessful, double cardBalance) {
    this->amount=amount;
    this->type=type;
    this->isSuccessful=isSuccessful;
    setAmount(amount, type, cardBalance);
}

void Transaction::setAmount(double amount, string type, double cardBalance){
    if(type=="Deposit" || type=="Initial Balance"){
        this->balanceRemaining=cardBalance+amount;
    }
    else if(type=="Withdrawal"){
        this->balanceRemaining=cardBalance-amount;
    }
    else{
        this->balanceRemaining=cardBalance;
    }
}

string Transaction::getTransactionLog() {
    string transactionHistory;
    if(isSuccessful){
        transactionHistory=this->type+": "+to_string(this->amount)+" Successfull";
    }
    else{
        transactionHistory=this->type+": "+to_string(this->amount)+" Failed";
    }
    return transactionHistory;
}

double Transaction::getAmount() {
    return balanceRemaining;
}