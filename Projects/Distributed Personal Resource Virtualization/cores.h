#ifndef CORES_H
#define CORES_H

#include <bits/stdc++.h>
using namespace std;

class Operation {
public:
    virtual ~Operation() = default;

    virtual double compute(double a, double b, char op) = 0;
    virtual string feedIn(string postfix) = 0;
};

class ALU : public Operation {
public:
    double compute(double a, double b, char op) override;

    string feedIn(string postfix) override = 0;

    ~ALU() override = default;
};

class Render : public ALU {
public:
    string feedIn(string postfix) override;

    ~Render() override = default;
};

class Calculator : public ALU {
public:
    string feedIn(string postfix) override;

    ~Calculator() override = default;
};

class Core {
private:
    bool state = false;

public:
    Core()=default;
    ~Core()=default;

    void setState() { state = !state; }

    bool getState() const { return state; }

    bool status();
    string assign(string need, string operand);

    // Prevent shallow copying
    Core(const Core&) = delete;
    Core& operator=(const Core&) = delete;
};

#endif // CORES_H