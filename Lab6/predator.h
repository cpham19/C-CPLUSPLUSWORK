#ifndef PREDATOR_H
#define PREDATOR_H

#include <string>
#include <iostream>
#include "animal.h"
#include "prey.h"

using namespace std;

class Predator : public Animal {
public:
    Predator(string nameIn, double weightIn);
    virtual void predate(Prey &prey);
};

#endif

