#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

void ATM::TempleteMethod(Person* person, Card* card) {
    insertCard(card);
    cout<<"Enter Pin: ";
    int pin;
    cin>>pin;
    if(bank->validateCard(person,card) && bank->validatePin(card, pin)) {
        // Proceed with ATM operations
        cout<<"Validation Successfull\n";
        while(true){
            int choice;
            cout << "Card validated successfully. Enter 1 for withdrawal 2 for Deposit or 3 for balance enquiry: \n";
            cin>>choice;
            if(choice == 1) {
                double amount;
                cout<<"Enter the amount you want to withdraw: ";
                cin>>amount;
                transactionLogDisplayer->displayer(bank->WithdrawalMethod(amount,card));
            } 
            else if(choice == 2){
                double amount;
                cout<<"Enter the amount you want to deposit: ";
                cin>>amount;
                transactionLogDisplayer->displayer(bank->DepositMethod(amount,card));
            }
            else if(choice == 3) {
                transactionLogDisplayer->displayer(bank->BalanceEnquiry(card));
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
            cout<<"Want to get Full Transaction Log press 1 or partial Transaction log press 2 else 0: ";
            int log;
            cin>>log;
            if(log==1) {
                transactionLogDisplayer->displayer(bank->generateTransactionLog(card));
            }
            else if(log==2){
                transactionLogDisplayer->displayer(bank->generateMiniTransactionLog(card));
            }
            cout<<"Want to exit press 1 else 0: ";
            bool exit;
            cin>>exit;
            if(exit) break;
        }
    } else {
        cout << "Card validation failed. Please try again." << endl;
    }
}

void ATM::insertCard(Card* card) {
    currentCard = card;
    cout << "Card inserted: " << card->cardNumber() << endl;
}



void TransactionLogDisplayer:: displayer(vector<string> transactionHistory){
    for(auto transaction:transactionHistory){
        cout<<transaction<<endl;
    }
}