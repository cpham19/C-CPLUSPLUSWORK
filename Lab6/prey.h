#ifndef PREY_H
#define PREY_H

#include <string>
#include <iostream>
#include "animal.h"

using namespace std;

class Prey : public Animal {
public:
    Prey(string nameIn, double weightIn);
    virtual void flee();
};

#endif

