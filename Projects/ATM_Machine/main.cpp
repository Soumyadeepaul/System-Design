#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    //Bank Instance
    Bank& HDFC = Bank::getInstance();
    //Person-Cards Instance
    PersonCardDatabase& personCardDatabase = PersonCardDatabase::getInstance();
    //Card-Transaction Instance
    BalanceDatabase& balanceDB = BalanceDatabase::getInstance();
    //TransactionFactory object responsible of creating transaction
    TransactionFactory transactionFactory;
    //Validator object responsible for validate card
    Validator validator;

    personCardDatabase.setBalanceDatabase(&balanceDB);

    HDFC.setTransactionFactory(&transactionFactory);
    HDFC.setValidator(&validator);
    HDFC.setBalanceDatabase(&balanceDB);
    HDFC.setPersonCardDatabase(&personCardDatabase);


    Person* person = new Person("John Doe", "123-456-7890");
    Card* platinumCard = new PlatinumCard("1234-5678-9012-3456", "John Doe", 1234);
    Card* fakeCard = new PlatinumCard("1234-5678-9012-3456", "John Doe", 1234); //duplicate card number but different instance  not in balanceDB
    Card* goldCard = new GoldCard("1234-5678-9101-1121","John Doe", 1234);
    personCardDatabase.addCard(person, platinumCard);
    personCardDatabase.addCard(person, goldCard);

    //TransactionLogDisplayer object to deplay transaction in ATM
    TransactionLogDisplayer transactionLogDisplayer;
    ATM* atm = new ATM();
    atm->setTransactionLogDisplayer(&transactionLogDisplayer);
    atm->setBank(&HDFC);


    // atm->TempleteMethod(person, fakeCard);
    atm->TempleteMethod(person, platinumCard);
    atm->TempleteMethod(person, goldCard);


    delete platinumCard;
    delete fakeCard;
    delete goldCard;

    return 0;
}


