#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

Bank& Bank::getInstance() {
    static Bank instance; // Created once, thread-safe
    return instance;
}



vector<string> Bank::BalanceEnquiry(Card* card) {
    double balance = balanceDB->getBalance(card);
    return {"Ready to use balance: "+to_string(balance)};
}

vector<string> Bank::WithdrawalMethod(double amount, Card* card) {
    if(amount>=0 && amount <= balanceDB->getBalance(card)) { // Withdrawal amount is less than amount left
        Transaction* transaction = transactionFactory->createTransaction(amount, "Withdrawal", true, balanceDB->getBalance(card));
        balanceDB->updateBalance(card, transaction);
        return {"Withdrawal successful. Amount: "+to_string(amount)};
    } else {
        Transaction* transaction = transactionFactory->createTransaction(amount, "Withdrawal Failed", false, balanceDB->getBalance(card));
        balanceDB->updateBalance(card, transaction);
        return {"Insufficient balance. Please try again."};
    }
}



vector<string> Bank::DepositMethod(double amount, Card* card) {
    if(amount>0 && amount+balanceDB->getBalance(card)<=card->limit()) { // Withdrawal amount is less than amount left
        Transaction* transaction = transactionFactory->createTransaction(amount, "Deposit", true, balanceDB->getBalance(card));
        balanceDB->updateBalance(card, transaction);
        return {"Deposit successful. Amount: "+to_string(amount)};
    } else {
        Transaction* transaction = transactionFactory->createTransaction(amount, "Deposit Failed", false, balanceDB->getBalance(card));
        balanceDB->updateBalance(card, transaction);
        return {"Balance limit exceed. Can't Deposit."};
    }
}



bool Bank:: validateCard(Person* person, Card* card){
    return validator->validateCardNumber(person, card, personCardDatabase);
}
bool Bank:: validatePin(Card* card, int pin){
    return validator->validatePin(card,pin);
}

vector<string> Bank:: generateTransactionLog(Card* card){
    return balanceDB->createTransactionLog(card);
}

vector<string> Bank:: generateMiniTransactionLog(Card* card){
    return balanceDB->createTransactionLog(card,5);
}