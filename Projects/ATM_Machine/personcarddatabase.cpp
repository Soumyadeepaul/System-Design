#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

PersonCardDatabase& PersonCardDatabase::getInstance() {
    static PersonCardDatabase instance; // Created once, thread-safe
    return instance;
}

void PersonCardDatabase::addCard(Person* person, Card* card) {
    database[person].insert(card);
    updateBalance(card); // Initialize balance for the new card
}

void PersonCardDatabase::removeCard(Person* person, Card* card) {
    database[person].erase(card);
}

vector<Card*> PersonCardDatabase::getCards(Person* person) {
    return vector<Card*>(database[person].begin(), database[person].end());
}

void PersonCardDatabase::updateBalance(Card* card) {
    Transaction* initialTransaction = new Transaction(0.0, "Initial Balance", true, card->limit());
    balanceDB->updateBalance(card, initialTransaction);
}
