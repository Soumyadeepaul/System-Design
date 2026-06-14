#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

PlatinumCard::PlatinumCard(string cardNumber, string cardHolderName, int pin) {
    this->CardNumber = cardNumber;
    this->CardHolderName = cardHolderName;
    this->Pin = pin;
}

string PlatinumCard::cardNumber() {
    return CardNumber;
}

string PlatinumCard::cardHolderName() {
    return CardHolderName;
}

double PlatinumCard::limit() {
    return Limit;
}

int PlatinumCard::pin() {
    return Pin;
}


GoldCard::GoldCard(string cardNumber, string cardHolderName, int pin) {
    this->CardNumber = cardNumber;
    this->CardHolderName = cardHolderName;
    this->Pin = pin;
}

string GoldCard::cardNumber() {
    return CardNumber;
}

string GoldCard::cardHolderName() {
    return CardHolderName;
}

double GoldCard::limit() {
    return Limit;
}

int GoldCard::pin() {
    return Pin;
}