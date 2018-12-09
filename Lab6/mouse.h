#ifndef MOUSE_H
#define MOUSE_H

#include <string>
#include <iostream>
#include "prey.h"

using namespace std;

class Mouse : public Prey {
public:
    Mouse(string nameIn, double weightIn);
    void call();
    virtual void flee();
};

#endif

