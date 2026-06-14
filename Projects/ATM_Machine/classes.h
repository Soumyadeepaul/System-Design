#ifndef CLASSES_H
#define CLASSES_H

#include <bits/stdc++.h>
using namespace std;

// Abstract Card class

class Card {
    public:
        virtual string cardNumber()=0;
        virtual string cardHolderName()=0;
        virtual double limit()=0;
        virtual int pin ()=0;
        virtual ~Card()=default;
};

class PlatinumCard: public Card{
    private:
        string CardNumber;
        string CardHolderName;
        double Limit= 100000;
        int Pin;
    public:
        PlatinumCard(string cardNumber, string cardHolderName, int pin);
        string cardNumber()override;
        string cardHolderName()override;
        double limit()override;
        int pin()override;
};

class GoldCard: public Card{
    private:
        string CardNumber;
        string CardHolderName;
        double Limit= 50000;
        int Pin;
    public:
        GoldCard(string cardNumber, string cardHolderName, int pin);
        string cardNumber()override;
        string cardHolderName()override;
        double limit()override;
        int pin()override;
};



// Person class

class Person {
    private:
        string Name;
        string PhoneNumber;
    public:
        Person(string name, string phoneNumber);
        string name();
        string phoneNumber();
};  

// Person-Card Database

class BalanceDatabase;
class Transaction;

class PersonCardDatabase {
    private:
        unordered_map<Person* , set<Card*>> database;
        PersonCardDatabase() {} 
        BalanceDatabase* balanceDB; // Instance of BalanceDatabase to manage balances
    public:
        PersonCardDatabase(const PersonCardDatabase&) = delete;
        static PersonCardDatabase& getInstance();
        void setBalanceDatabase(BalanceDatabase* db) { balanceDB = db; }
        void addCard(Person* person, Card* card);
        void removeCard(Person* person, Card* card);
        vector<Card*> getCards(Person* person);
        void updateBalance(Card* card);
};

// Validator

class Validator {
    public:
        bool validateCardNumber(Person* person, Card* card,PersonCardDatabase* personCardDatabase);
        bool validatePin(Card* card, int pin);
};

// Transaction class

class Transaction {
    private:
        double amount;
        string type;
        bool isSuccessful;
        double balanceRemaining=0.0;
    public:
        Transaction(double amount, string type, bool isSuccessful, double cardBalance);
        string getTransactionLog();
        void setAmount(double amount, string type, double cardBalance);
        double getAmount();
};

class TransactionFactory {
    public:
        Transaction* createTransaction(double amount, string type, bool isSuccessful, double cardBalance);
};

// Balance Database

class BalanceDatabase{
    private:
        unordered_map<Card*, vector<Transaction*>> balanceDatabase;
        BalanceDatabase() {}
    public:
        BalanceDatabase(const BalanceDatabase&) = delete;
        static BalanceDatabase& getInstance();
        void updateBalance(Card* card, Transaction* transaction);
        double getBalance(Card* card);
        vector<string> createTransactionLog(Card* card);
        vector<string> createTransactionLog(Card* card, int limit);
};

// ATM

class TransactionLogDisplayer {
    public:
        void displayer(vector<string> transactionHistory);
};

class Bank;

class ATM {
    private:
        Card *currentCard;
        int currentPin;
        TransactionLogDisplayer* transactionLogDisplayer;
        Bank* bank;
    public:
        void setBank(Bank* bank) { this->bank = bank; }
        void setTransactionLogDisplayer(TransactionLogDisplayer* transactionLogDisplayer) { transactionLogDisplayer=transactionLogDisplayer; }
        void TempleteMethod(Person* person, Card* card);
        void insertCard(Card* card);
        
        
        
};

class Bank {
    private:
        BalanceDatabase* balanceDB;
        PersonCardDatabase* personCardDatabase;
        Validator* validator;
        TransactionFactory* transactionFactory;
        Bank() {}
    public:
        Bank(const Bank&) = delete;
        static Bank& getInstance();
        void setBalanceDatabase(BalanceDatabase* db) { balanceDB = db; }
        void setPersonCardDatabase(PersonCardDatabase* db) { personCardDatabase = db; }
        void setValidator(Validator* val) { validator = val; }
        void setTransactionFactory(TransactionFactory* factory) { transactionFactory = factory; }
        vector<string> WithdrawalMethod(double amount, Card* card);
        vector<string> DepositMethod(double amount, Card* card);
        vector<string> BalanceEnquiry(Card* card);
        vector<string> generateTransactionLog(Card* card);
        vector<string> generateMiniTransactionLog(Card* card);
        bool validateCard(Person* person, Card* card);
        bool validatePin(Card* card, int pin);

};

#endif // CLASSES_H