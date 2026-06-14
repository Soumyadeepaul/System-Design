#include "classes.h"
#include <bits/stdc++.h>
using namespace std;


bool Validator::validateCardNumber(Person* person, Card* card, PersonCardDatabase* personCardDatabase) {
    vector<Card*> cards = personCardDatabase->getCards(person);
    if (cards.empty()) {
        return false; // No cards associated with the person
    }
    if(find(cards.begin(), cards.end(), card) != cards.end()) {
        return true; // Card is associated with the person
    }
    return false; // Card is not associated with the person
}

bool Validator::validatePin(Card* card, int pin) {
    return card->pin() == pin; // Check if the provided PIN matches the card's PIN
}
