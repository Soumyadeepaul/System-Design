#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

Person::Person(string name, string phoneNumber) {
    this->Name = name;
    this->PhoneNumber = phoneNumber;
}

string Person::name() {
    return Name;
}

string Person::phoneNumber() {
    return PhoneNumber;
}