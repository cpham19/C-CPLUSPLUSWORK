#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

using namespace std;

class Animal {
public:
    Animal(string nameIn, double weightIn);
    void eat(double weightOfFood);
    virtual void call() = 0;
    string getName() const;
    double getWeight() const;

private:
    string name;
    double weight;
};


#endif

