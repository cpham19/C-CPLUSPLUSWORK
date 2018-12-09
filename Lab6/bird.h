#ifndef BIRD_H
#define BIRD_H

#include <string>
#include <iostream>
#include "prey.h"

using namespace std;

class Bird : public Prey {
public:
    Bird(string nameIn, double weightIn);
    void call();
    virtual void flee();
};

#endif

